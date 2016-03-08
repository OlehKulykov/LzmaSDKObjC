/* Threads.h -- multithreading library
 2013-11-12 : Igor Pavlov : Public domain */

#ifndef __7Z_THREADS_H
#define __7Z_THREADS_H

#ifdef _WIN32
#include <windows.h>
#endif

#include "7zTypes.h"

EXTERN_C_BEGIN

#if !defined(__APPLE__)
WRes HandlePtr_Close(HANDLE *h);
WRes Handle_WaitObject(HANDLE h);
#endif

#if defined(__APPLE__)
typedef struct _CThread
{
	pthread_t _tid;
	int _created;
} CThread;
#define Thread_Construct(thread) (thread)->_created = 0
#define Thread_WasCreated(thread) ((thread)->_created != 0)
WRes Thread_Close(CThread *thread);
WRes Thread_Wait(CThread *thread);
#else
typedef HANDLE CThread;
#define Thread_Construct(p) *(p) = NULL
#define Thread_WasCreated(p) (*(p) != NULL)
#define Thread_Close(p) HandlePtr_Close(p)
#define Thread_Wait(p) Handle_WaitObject(*(p))
#endif

typedef
#ifdef UNDER_CE
DWORD
#else
unsigned
#endif
THREAD_FUNC_RET_TYPE;

#define THREAD_FUNC_CALL_TYPE MY_STD_CALL
#define THREAD_FUNC_DECL THREAD_FUNC_RET_TYPE THREAD_FUNC_CALL_TYPE
typedef THREAD_FUNC_RET_TYPE (THREAD_FUNC_CALL_TYPE * THREAD_FUNC_TYPE)(void *);
#if defined(__APPLE__)
WRes Thread_Create(CThread *p, THREAD_FUNC_TYPE func, LPVOID param);
#else
WRes Thread_Create(CThread *p, THREAD_FUNC_TYPE func, LPVOID param);
#endif

#if defined(__APPLE__)
typedef struct _CEvent
{
	int _created;
	int _manual_reset;
	int _state;
	pthread_mutex_t _mutex;
	pthread_cond_t _cond;
} CEvent;
typedef CEvent CAutoResetEvent;
typedef CEvent CManualResetEvent;
#define Event_Construct(event) (event)->_created = 0
#define Event_IsCreated(event) ((event)->_created)
WRes Event_Wait(CEvent *event);
WRes Event_Close(CEvent *event);
#else
typedef HANDLE CEvent;
typedef CEvent CAutoResetEvent;
typedef CEvent CManualResetEvent;
#define Event_Construct(p) *(p) = NULL
#define Event_IsCreated(p) (*(p) != NULL)
#define Event_Close(p) HandlePtr_Close(p)
#define Event_Wait(p) Handle_WaitObject(*(p))
#endif

WRes Event_Set(CEvent *p);
WRes Event_Reset(CEvent *p);
WRes ManualResetEvent_Create(CManualResetEvent *p, int signaled);
WRes ManualResetEvent_CreateNotSignaled(CManualResetEvent *p);
WRes AutoResetEvent_Create(CAutoResetEvent *p, int signaled);
WRes AutoResetEvent_CreateNotSignaled(CAutoResetEvent *p);

#if defined(__APPLE__)
typedef struct _CSemaphore
{
	int _created;
	uint32_t _count;
	uint32_t _maxCount;
	pthread_mutex_t _mutex;
	pthread_cond_t  _cond;
} CSemaphore;
#define Semaphore_Construct(p) (p)->_created = 0
WRes Semaphore_Wait(CSemaphore *p);
WRes Semaphore_Close(CSemaphore *p);
#define Semaphore_Release1(p) Semaphore_ReleaseN(p, 1)
#else
typedef HANDLE CSemaphore;
#define Semaphore_Construct(p) (*p) = NULL
#define Semaphore_Close(p) HandlePtr_Close(p)
#define Semaphore_Wait(p) Handle_WaitObject(*(p))
WRes Semaphore_Release1(CSemaphore *p);
#endif
WRes Semaphore_Create(CSemaphore *p, UInt32 initCount, UInt32 maxCount);
WRes Semaphore_ReleaseN(CSemaphore *p, UInt32 num);

#if defined(__APPLE__)
typedef struct {
	pthread_mutex_t _mutex;
} CCriticalSection;
#define CriticalSection_Delete(p) pthread_mutex_destroy(&((p)->_mutex))
#define CriticalSection_Enter(p)  pthread_mutex_lock(&((p)->_mutex))
#define CriticalSection_Leave(p)  pthread_mutex_unlock(&((p)->_mutex))
#else
typedef CRITICAL_SECTION CCriticalSection;
#define CriticalSection_Delete(p) DeleteCriticalSection(p)
#define CriticalSection_Enter(p) EnterCriticalSection(p)
#define CriticalSection_Leave(p) LeaveCriticalSection(p)
#endif
WRes CriticalSection_Init(CCriticalSection *p);


EXTERN_C_END

#endif
