//
//  AKILinkedListEnumerator.c
//  AKIHuman
//
//  Created by Alexey Khomych on 25.05.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#include <stdbool.h>

#include "AKILinkedListEnumerator.h"
#include "AKILinkedListNode.h"
#include "AKILinkedList.h"
#include "AKIConstants.h"
#include "AKILinkedListPrivate.h"

#pragma mark -
#pragma mark Private Declarations

static
void AKILinkedListEnumeratorSetList(AKILinkedListEnumerator *enumerator, AKILinkedList *list);

static
AKILinkedList *AKILinkedListEnumeratorGetList(AKILinkedListEnumerator *enumerator);

static
void AKILinkedListEnumeratorSetNode(AKILinkedListEnumerator *enumerator, AKILinkedListNode *node);

static
void AKILinkedListEnumeratorSetMutationsCount(AKILinkedListEnumerator *enumerator, uint64_t count);

static
uint64_t AKILinkedListEnumeratorGetMutationsCount(AKILinkedListEnumerator *enumerator);

static
void AKILinkedListEnumeratorSetIsValid(AKILinkedListEnumerator *enumerator, bool valid);

static
bool AKILinkedListEnumeratorMutationsCountValidate(AKILinkedListEnumerator *enumerator);

#pragma mark -
#pragma mark Public Implementations

void __AKILinkedListEnumeratorDeallocate(void *object) {
    __AKIObjectDeallocate(object);
}

AKILinkedListEnumerator *AKILinkedListEnumeratorCreateWithList(AKILinkedList *list) {
    if (!list || !AKILinkedListGetHead(list)) {
        return NULL;
    }
    
    AKILinkedListEnumerator *enumerator = AKIObjectCreateOfType(AKILinkedListEnumerator);
    AKILinkedListEnumeratorSetList(enumerator, list);
    AKILinkedListEnumeratorSetMutationsCount(enumerator, AKILinkedListGetMutationsCount(list));
    AKILinkedListEnumeratorSetIsValid(enumerator, true);
    
    return enumerator;
}

void *AKILinkedListEnumeratorGetNextObject(AKILinkedListEnumerator *enumerator) {
    if (enumerator && AKILinkedListEnumeratorMutationsCountValidate(enumerator)) {
        AKILinkedListNode *node = AKILinkedListEnumeratorGetNode(enumerator);
        
        node = node ? AKILinkedListNodeGetNextNode(node) : AKILinkedListGetHead(AKILinkedListEnumeratorGetList(enumerator));
        
        if (!node) {
            AKILinkedListEnumeratorSetIsValid(enumerator, false);
        }
        
        AKILinkedListEnumeratorSetNode(enumerator, node);
        
        return AKILinkedListNodeGetObject(node);
    }
    
    
    return NULL;
}

bool AKILinkedListEnumeratorIsValid(AKILinkedListEnumerator *enumerator) {
    return enumerator && enumerator->_isValid;
}

#pragma mark -
#pragma mark Private Implementations

void AKILinkedListEnumeratorSetList(AKILinkedListEnumerator *enumerator, AKILinkedList *list) {
    AKIObjectSetStrong(enumerator, _list, list);
}

AKILinkedList *AKILinkedListEnumeratorGetList(AKILinkedListEnumerator *enumerator) {
    return enumerator ? enumerator->_list : NULL;
}

void AKILinkedListEnumeratorSetNode(AKILinkedListEnumerator *enumerator, AKILinkedListNode *node) {
    AKIObjectSetStrong(enumerator, _currentNode, node);
}

AKILinkedListNode *AKILinkedListEnumeratorGetNode(AKILinkedListEnumerator *enumerator) {
    return enumerator ? enumerator->_currentNode : NULL;
}

void AKILinkedListEnumeratorSetMutationsCount(AKILinkedListEnumerator *enumerator, uint64_t count) {
    AKIObjectAssignSetter(enumerator, _mutationsCount, count);
}

uint64_t AKILinkedListEnumeratorGetMutationsCount(AKILinkedListEnumerator *enumerator) {
    return enumerator ? enumerator->_mutationsCount : kAKINotFound;
}

void AKILinkedListEnumeratorSetIsValid(AKILinkedListEnumerator *enumerator, bool valid) {
    AKIObjectAssignSetter(enumerator, _isValid, valid);
}

bool AKILinkedListEnumeratorMutationsCountValidate(AKILinkedListEnumerator *enumerator) {
    if (enumerator && AKILinkedListEnumeratorIsValid(enumerator)) {
        uint64_t enumeratorMutationsCount = AKILinkedListEnumeratorGetMutationsCount(enumerator);
        uint64_t linkedListMutationsCount = AKILinkedListGetMutationsCount(AKILinkedListEnumeratorGetList(enumerator));
        
        if (enumeratorMutationsCount == linkedListMutationsCount) {
            return true;
        }
    }
    
    return false;
}
