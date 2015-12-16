/* Threads.c -- multithreading library
 2014-09-21 : Igor Pavlov : Public domain */

#include "Precomp.h"

#if !defined(UNDER_CE) && !defined(__APPLE__)
#include <process.h>
#endif

#include "Threads.h"

static WRes GetError()
{
	DWORD res = GetLastError();
	return (res) ? (WRes)(res) : 1;
}

WRes HandleToWRes(HANDLE h) { return (h != 0) ? 0 : GetError(); }
WRes BOOLToWRes(BOOL v) { return v ? 0 : GetError(); }

#if defined(__APPLE__)
WRes Thread_Wait(CThread *thread)
{
	void *thread_return;
	int ret;
	if (thread->_created == 0)
		return EINVAL;
	ret = pthread_join(thread->_tid,&thread_return);
	thread->_created = 0;

	return ret;
}
WRes Thread_Close(CThread *thread)
{
	if (!thread->_created) return SZ_OK;

	pthread_detach(thread->_tid);
	thread->_tid = 0;
	thread->_created = 0;
	return SZ_OK;
}
#else
WRes HandlePtr_Close(HANDLE *p)
{
	if (*p != NULL)
		if (!CloseHandle(*p))
			return GetError();
	*p = NULL;
	return 0;
}

WRes Handle_WaitObject(HANDLE h) { return (WRes)WaitForSingleObject(h, INFINITE); }
#endif

WRes Thread_Create(CThread *p, THREAD_FUNC_TYPE func, LPVOID param)
{
#if defined(__APPLE__)
	pthread_attr_t attr;
	int ret;
	p->_created = 0;
	ret = pthread_attr_init(&attr);
	if (ret) return ret;
	ret = pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
	if (ret) return ret;
	ret = pthread_create(&p->_tid, &attr, (void * (*)(void *))func, param);
	/* ret2 = */ pthread_attr_destroy(&attr);
	if (ret) return ret;

	p->_created = 1;
	return 0; // SZ_OK;
#else
	/* Windows Me/98/95: threadId parameter may not be NULL in _beginthreadex/CreateThread functions */

#ifdef UNDER_CE

	DWORD threadId;
	*p = CreateThread(0, 0, func, param, 0, &threadId);

#else

	unsigned threadId;
	*p = (HANDLE)_beginthreadex(NULL, 0, func, param, 0, &threadId);

#endif

	/* maybe we must use errno here, but probably GetLastError() is also OK. */
	return HandleToWRes(*p);
#endif
}

WRes Event_Create(CEvent *p, BOOL manualReset, int signaled)
{
#if defined(__APPLE__)
	pthread_mutex_init(&p->_mutex,0);
	pthread_cond_init(&p->_cond,0);
	p->_manual_reset = manualReset;
	p->_state        = (signaled ? True : False);
	p->_created = 1;
	return 0;
#else
	*p = CreateEvent(NULL, manualReset, (signaled ? TRUE : FALSE), NULL);
	return HandleToWRes(*p);
#endif
}

WRes Event_Set(CEvent *p)
{
#if defined(__APPLE__)
	pthread_mutex_lock(&p->_mutex);
	p->_state = True;
	pthread_cond_broadcast(&p->_cond);
	pthread_mutex_unlock(&p->_mutex);
	return 0;
#else
 return BOOLToWRes(SetEvent(*p));
#endif
}

WRes Event_Reset(CEvent *p)
{
#if defined(__APPLE__)
	pthread_mutex_lock(&p->_mutex);
	p->_state = False;
	pthread_mutex_unlock(&p->_mutex);
	return 0;
#else
 return BOOLToWRes(ResetEvent(*p));
#endif
}

#if defined(__APPLE__)
WRes Event_Wait(CEvent *p)
{
	pthread_mutex_lock(&p->_mutex);
	while (p->_state == False)
	{
		pthread_cond_wait(&p->_cond, &p->_mutex);
	}
	if (p->_manual_reset == False)
	{
		p->_state = False;
	}
	pthread_mutex_unlock(&p->_mutex);
	return 0;
}

WRes Event_Close(CEvent *p)
{
	if (p->_created)
	{
		p->_created = 0;
		pthread_mutex_destroy(&p->_mutex);
		pthread_cond_destroy(&p->_cond);
	}
	return 0;
}
#endif

WRes ManualResetEvent_Create(CManualResetEvent *p, int signaled) { return Event_Create(p, TRUE, signaled); }
WRes AutoResetEvent_Create(CAutoResetEvent *p, int signaled) { return Event_Create(p, FALSE, signaled); }
WRes ManualResetEvent_CreateNotSignaled(CManualResetEvent *p) { return ManualResetEvent_Create(p, 0); }
WRes AutoResetEvent_CreateNotSignaled(CAutoResetEvent *p) { return AutoResetEvent_Create(p, 0); }


WRes Semaphore_Create(CSemaphore *p, UInt32 initCount, UInt32 maxCount)
{
#if defined(__APPLE__)
	pthread_mutex_init(&p->_mutex,0);
	pthread_cond_init(&p->_cond,0);
	p->_count    = initCount;
	p->_maxCount = maxCount;
	p->_created  = 1;
	return 0;
#else
	*p = CreateSemaphore(NULL, (LONG)initCount, (LONG)maxCount, NULL);
	return HandleToWRes(*p);
#endif
}

#if defined(__APPLE__)
WRes Semaphore_Wait(CSemaphore *p)
{
	pthread_mutex_lock(&p->_mutex);
	while (p->_count < 1)
	{
		pthread_cond_wait(&p->_cond, &p->_mutex);
	}
	p->_count--;
	pthread_mutex_unlock(&p->_mutex);
	return 0;
}

WRes Semaphore_Close(CSemaphore *p)
{
	if (p->_created)
	{
		p->_created = 0;
		pthread_mutex_destroy(&p->_mutex);
		pthread_cond_destroy(&p->_cond);
	}
	return 0;
}
#endif

#if defined(__APPLE__)
WRes Semaphore_ReleaseN(CSemaphore *p, UInt32 num)
{
	uint32_t newCount;
	if (num < 1) return EINVAL;
	pthread_mutex_lock(&p->_mutex);
	newCount = p->_count + num;
	if (newCount > p->_maxCount)
	{
		pthread_mutex_unlock(&p->_mutex);
		return EINVAL;
	}
	p->_count = newCount;
	pthread_cond_broadcast(&p->_cond);
	pthread_mutex_unlock(&p->_mutex);
	return 0;
}

WRes CriticalSection_Init(CCriticalSection * lpCriticalSection)
{
	return pthread_mutex_init(&(lpCriticalSection->_mutex),0);
}
#else
static WRes Semaphore_Release(CSemaphore *p, LONG releaseCount, LONG *previousCount)
{ return BOOLToWRes(ReleaseSemaphore(*p, releaseCount, previousCount)); }
WRes Semaphore_ReleaseN(CSemaphore *p, UInt32 num)
{ return Semaphore_Release(p, (LONG)num, NULL); }
WRes Semaphore_Release1(CSemaphore *p) { return Semaphore_ReleaseN(p, 1); }

WRes CriticalSection_Init(CCriticalSection *p)
{
	/* InitializeCriticalSection can raise only STATUS_NO_MEMORY exception */
#ifdef _MSC_VER
	__try
#endif
	{
		InitializeCriticalSection(p);
		/* InitializeCriticalSectionAndSpinCount(p, 0); */
	}
#ifdef _MSC_VER
	__except (EXCEPTION_EXECUTE_HANDLER) { return 1; }
#endif
	return 0;
}
#endif
