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


#ifndef __NSCATEGORYDYNAMICPROPERTIES_INLINEOBJC_H__
#define __NSCATEGORYDYNAMICPROPERTIES_INLINEOBJC_H__ 1



#import <objc/runtime.h>


/// NSObject
#define CATEGORY_PROPERTY_GET(type, property) - (type) property { return objc_getAssociatedObject(self, @selector(property)); } \
 \


#define CATEGORY_PROPERTY_SET(type, property, setter) - (void) setter (type) property { objc_setAssociatedObject(self, @selector(property), property, OBJC_ASSOCIATION_RETAIN_NONATOMIC); } \
 \


#define CATEGORY_PROPERTY_GET_SET(type, property, setter) CATEGORY_PROPERTY_GET(type, property) \
 \
CATEGORY_PROPERTY_SET(type, property, setter) \
 \



/// NSNumber
#define CATEGORY_PROPERTY_GET_NSNUMBER_PRIMITIVE(type, property, valueSelector) - (type) property { return [objc_getAssociatedObject(self, @selector(property)) valueSelector]; } \
 \


#define CATEGORY_PROPERTY_SET_NSNUMBER_PRIMITIVE(type, property, setter, numberSelector) - (void) setter (type) property { objc_setAssociatedObject(self, @selector(property), [NSNumber numberSelector: property], OBJC_ASSOCIATION_RETAIN_NONATOMIC); } \
 \


/// BOOL
#define CATEGORY_PROPERTY_GET_BOOL(property) CATEGORY_PROPERTY_GET_NSNUMBER_PRIMITIVE(BOOL, property, boolValue) \
 \


#define CATEGORY_PROPERTY_SET_BOOL(property, setter) CATEGORY_PROPERTY_SET_NSNUMBER_PRIMITIVE(BOOL, property, setter, numberWithBool) \
 \


#define CATEGORY_PROPERTY_GET_SET_BOOL(property, setter) CATEGORY_PROPERTY_GET_BOOL(property) \
 \
CATEGORY_PROPERTY_SET_BOOL(property, setter) \
 \



/// NSInteger
#define CATEGORY_PROPERTY_GET_INTEGER(property) CATEGORY_PROPERTY_GET_NSNUMBER_PRIMITIVE(NSInteger, property, integerValue) \
 \


#define CATEGORY_PROPERTY_SET_INTEGER(property, setter) CATEGORY_PROPERTY_SET_NSNUMBER_PRIMITIVE(NSInteger, property, setter, numberWithInteger) \
 \


#define CATEGORY_PROPERTY_GET_SET_INTEGER(property, setter) CATEGORY_PROPERTY_GET_INTEGER(property) \
 \
CATEGORY_PROPERTY_SET_INTEGER(property, setter) \
 \



/// NSUInteger
#define CATEGORY_PROPERTY_GET_UINTEGER(property) CATEGORY_PROPERTY_GET_NSNUMBER_PRIMITIVE(NSUInteger, property, unsignedIntegerValue) \
 \


#define CATEGORY_PROPERTY_SET_UINTEGER(property, setter) CATEGORY_PROPERTY_SET_NSNUMBER_PRIMITIVE(NSUInteger, property, setter, numberWithUnsignedInteger) \
 \


#define CATEGORY_PROPERTY_GET_SET_UINTEGER(property, setter) CATEGORY_PROPERTY_GET_UINTEGER(property) \
 \
CATEGORY_PROPERTY_SET_UINTEGER(property, setter) \
 \



/// float
#define CATEGORY_PROPERTY_GET_FLOAT(property) CATEGORY_PROPERTY_GET_NSNUMBER_PRIMITIVE(float, property, floatValue) \
 \


#define CATEGORY_PROPERTY_SET_FLOAT(property, setter) CATEGORY_PROPERTY_SET_NSNUMBER_PRIMITIVE(float, property, setter, numberWithFloat) \
 \


#define CATEGORY_PROPERTY_GET_SET_FLOAT(property, setter) CATEGORY_PROPERTY_GET_FLOAT(property) \
 \
CATEGORY_PROPERTY_SET_FLOAT(property, setter) \
 \



/// double
#define CATEGORY_PROPERTY_GET_DOUBLE(property) CATEGORY_PROPERTY_GET_NSNUMBER_PRIMITIVE(double, property, doubleValue) \
 \


#define CATEGORY_PROPERTY_SET_DOUBLE(property, setter) CATEGORY_PROPERTY_SET_NSNUMBER_PRIMITIVE(double, property, setter, numberWithDouble) \
 \


#define CATEGORY_PROPERTY_GET_SET_DOUBLE(property, setter) CATEGORY_PROPERTY_GET_DOUBLE(property) \
 \
CATEGORY_PROPERTY_SET_DOUBLE(property, setter) \
 \




#endif
