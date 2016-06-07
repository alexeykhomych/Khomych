//
//  AKIAutoreleasingPool.c
//  AKIHuman
//
//  Created by Alexey Khomych on 02.06.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "AKIAutoreleasingPool.h"
#include "AKIAutoreleasingStack.h"
#include "AKIConstants.h"

static AKIAutoreleasingPool *__pool = NULL;

#pragma mark -
#pragma mark Private Declarations

static
void AKIAutoreleasingPoolRemoveAllObject();

static
void AKIAutoreleasingPoolRemoveObject();

static
void *AKIAutoreleasingPoolGetObject();

static
bool AKIAutoreleasingPoolIsValid(AKIAutoreleasingPool *pool);

static
void AKIAutoreleasingPoolSetStackList(AKIAutoreleasingPool *pool, AKILinkedList *list);

static
AKIAutoreleasingStack *AKIAutoreleasingPoolGetStackList(AKIAutoreleasingPool *pool);

static
void AKIAutoreleasingPoolSetIsValid(AKIAutoreleasingPool *pool, bool isValid);

static
bool AKIAutoreleasingPoolGetIsValid(AKIAutoreleasingPool *pool);

static
void *AKIAutoreleasingPoolGetStackAfterStack(AKIAutoreleasingPool *pool, AKIAutoreleasingStack *list);

static
void *AKIAutoreleasingPoolAddStack(AKIAutoreleasingPool *pool);

static
void AKIAutoreleasingPoolRemoveLastStack(AKIAutoreleasingPool *pool);

static
void AKIAutoreleasingPoolSetCount(AKIAutoreleasingPool *pool, uint64_t count);

static
uint64_t AKIAutoreleasingPoolGetCount(AKIAutoreleasingPool *pool);
#pragma mark -
#pragma mark Public Implementations

void __AKIAutoreleasingPoolDeallocate(void *object) {
    AKIAutoreleasingPool *pool = object;
    AKIAutoreleasingPoolSetStackList(pool, NULL);
    
    __AKIObjectDeallocate(object);
}

AKIAutoreleasingPool *AKIAutoreleasingPoolCreate() {
    __pool = AKIObjectCreateOfType(AKIAutoreleasingPool);
    AKIAutoreleasingPoolAddObject(__pool, NULL);
    AKIAutoreleasingPoolSetIsValid(__pool, true);
    
    return __pool;
}

void AKIAutoreleasingPoolAddObject(AKIAutoreleasingPool *pool, void *object) {
    if (!pool) {
        return;
    }
    
    AKIAutoreleasingStack *stack = AKIAutoreleasingPoolGetStackList(pool);
    
    if (AKIAutoreleasingStackIsFull(stack) || !AKIAutoreleasingPoolGetIsValid(pool)) {
        return;
    }
    
    AKIAutoreleasingStackPushObject(stack, object);
    AKIAutoreleasingPoolSetCount(pool, AKIAutoreleasingPoolGetCount(pool) + 1);
}

void AKIAutoreleasingPoolDrain() {
    AKIAutoreleasingPool *pool = AKIAutoreleasingPoolGet();
    //xz
}

AKIAutoreleasingPool *AKIAutoreleasingPoolGet() {
    return __pool;
}

#pragma mark -
#pragma mark Private Implementations

void AKIAutoreleasingPoolRemoveAllObject() {
    
}

void AKIAutoreleasingPoolRemoveObject() {
    
}

void *AKIAutoreleasingPoolGetObject() {
    return NULL;
}

bool AKIAutoreleasingPoolIsValid(AKIAutoreleasingPool *pool) {
    return pool ? pool->_isValid : false;
}

void AKIAutoreleasingPoolInitStackList(AKIAutoreleasingPool *pool) {
    AKILinkedList *stackList = AKIObjectCreateOfType(AKILinkedList);
    AKIObjectSetStrong(pool, _stack, stackList);
}

AKIAutoreleasingStack *AKIAutoreleasingPoolGetStackList(AKIAutoreleasingPool *pool) {
    return NULL;
}

void AKIAutoreleasingPoolSetIsValid(AKIAutoreleasingPool *pool, bool isValid) {
    AKIObjectAssignSetter(pool, _isValid, isValid);
}

void *AKIAutoreleasingPoolGetStackAfterStack(AKIAutoreleasingPool *pool, AKIAutoreleasingStack *list) {
    return NULL;
}

void *AKIAutoreleasingPoolAddStack(AKIAutoreleasingPool *pool) {
    return NULL;
}

void AKIAutoreleasingPoolRemoveLastStack(AKIAutoreleasingPool *pool) {
    
}

void AKIAutoreleasingPoolSetCount(AKIAutoreleasingPool *pool, uint64_t count) {
    AKIObjectAssignSetter(pool, _count, count);
}

uint64_t AKIAutoreleasingPoolGetCount(AKIAutoreleasingPool *pool) {
    return pool ? pool->_count : kAKINotFound;
}

bool AKIAutoreleasingPoolGetIsValid(AKIAutoreleasingPool *pool) {
    return pool && pool->_isValid;
}

void AKIAutoreleasingPoolSetStackList(AKIAutoreleasingPool *pool, AKILinkedList *list) {
    
}