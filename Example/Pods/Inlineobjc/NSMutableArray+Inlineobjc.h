/*
 *   Copyright (c) 2015 - 2016 Kulykov Oleh <info@resident.name>
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"), to deal
 *   in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in
 *   all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *   THE SOFTWARE.
 */


#import <Foundation/Foundation.h>


#ifndef __NSMUTABLEARRAY_INLINEOBJC_H__
#define __NSMUTABLEARRAY_INLINEOBJC_H__ 1

#if defined(DEBUG) || defined(_DEBUG)
#ifndef DEBUG
#define DEBUG 1
#endif
#endif


/**
 @brief Append(add) some object to the end of the mutable array if it's not already contained.
 @param array The mutable array object, should NOT be nil.
 @param object The object for adding to the array, should NOT be nil.
 @warning This is unsafe function so, all parameters should NOT be nil.
 */
NS_INLINE void NSMutableArrayAppendUniqObjectUnsafe(NSMutableArray * array, id object)
{
#if defined(DEBUG)
	assert(array != nil);
	assert(object != nil);
#endif
	if (![array containsObject:object]) [array addObject:object];
}


/**
 @brief Prepend(add first) some object to the beginning of the mutable array if it's not already contained.
 @param array The mutable array object, should NOT be nil.
 @param object The object for adding to the array, should NOT be nil.
 @warning This is unsafe function so, all parameters should NOT be nil.
 */
NS_INLINE void NSMutableArrayPrependUniqObjectUnsafe(NSMutableArray * array, id object)
{
#if defined(DEBUG)
	assert(array != nil);
	assert(object != nil);
#endif
	if (![array containsObject:object]) [array insertObject:object atIndex:0];
}


/**
 @brief Append(add) some object to the end of the mutable array if it's not already contained.
 @param array The mutable array object. If array is nil - do nothing.
 @param object The object for adding to the array. If object is nil - do nothing.
 */
NS_INLINE void NSMutableArrayAppendUniqObjectSafe(NSMutableArray * array, id object)
{
	if (array && object)
	{
#if defined(DEBUG)
		assert([array isKindOfClass:[NSMutableArray class]]);
#endif
		NSMutableArrayAppendUniqObjectUnsafe(array, object);
	}
}


/**
 @brief Append(add) to the end of the mutable array objects from 'NSFastEnumeration' container, of cource if objects not already contained.
 @param array The mutable array object. If array is nil - do nothing.
 @param from 'NSFastEnumeration' container objects which append(add) to array. If container is nil - do nothing.
 */
NS_INLINE void NSMutableArrayAppendUniqSafe(NSMutableArray * array, id<NSFastEnumeration> from)
{
	if (array && from)
	{
#if defined(DEBUG)
		assert([array isKindOfClass:[NSMutableArray class]]);
#endif
		for (id object in from)
		{
			NSMutableArrayAppendUniqObjectUnsafe(array, object);
		}
	}
}


/**
 @brief Prepend(add first) some object to the beginning of the mutable array if it's not already contained.
 @param array The mutable array object. If array is nil - do nothing.
 @param object The object for adding to the array. If object is nil - do nothing.
 @warning This is unsafe function so, all parameters should NOT be nil.
 */
NS_INLINE void NSMutableArrayPrependUniqObjectSafe(NSMutableArray * array, id object)
{
	if (array && object)
	{
#if defined(DEBUG)
		assert([array isKindOfClass:[NSMutableArray class]]);
#endif
		NSMutableArrayPrependUniqObjectUnsafe(array, object);
	}
}


/**
 @brief Prepend(add first) to to the beginning of the mutable array objects from 'NSFastEnumeration' container, of cource if objects not already contained.
 @param array The mutable array object. If array is nil - do nothing.
 @param from 'NSFastEnumeration' container objects which Prepend(add first) to array. If container is nil - do nothing.
 */
NS_INLINE void NSMutableArrayPrependUniqSafe(NSMutableArray * array, id<NSFastEnumeration> from)
{
	if (array && from)
	{
#if defined(DEBUG)
		assert([array isKindOfClass:[NSMutableArray class]]);
#endif
		for (id object in from)
		{
			NSMutableArrayPrependUniqObjectUnsafe(array, object);
		}
	}
}


/**
 @brief Append(add) to the end of the mutable array objects from 'NSFastEnumeration' container.
 @param array The mutable array object. If array is nil - do nothing.
 @param from 'NSFastEnumeration' container objects which append(add) to array. If container is nil - do nothing.
 */
NS_INLINE void NSMutableArrayAppendSafe(NSMutableArray * array, id<NSFastEnumeration> from)
{
	if (array && from)
	{
#if defined(DEBUG)
		assert([array isKindOfClass:[NSMutableArray class]]);
#endif
		for (id object in from) [array addObject:object];
	}
}


/**
 @brief Prepend(add first) to the mutable array objects from 'NSFastEnumeration' container.
 @param array The mutable array object. If array is nil - do nothing.
 @param from 'NSFastEnumeration' container objects which prepend(add first) to array. If container is nil - do nothing.
 */
NS_INLINE void NSMutableArrayPrependSafe(NSMutableArray * array, id<NSFastEnumeration> from)
{
	if (array && from)
	{
#if defined(DEBUG)
		assert([array isKindOfClass:[NSMutableArray class]]);
#endif
		for (id object in from) [array insertObject:object atIndex:0];
	}
}

#endif

