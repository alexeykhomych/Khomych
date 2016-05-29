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
AKILinkedListNode *AKILinkedListEnumeratorGetNode(AKILinkedListEnumerator *enumerator);

static
void AKILinkedListEnumeratorSetMutationsCount(AKILinkedListEnumerator *enumerator, uint64_t count);

static
uint64_t AKILinkedListEnumeratorGetMutationsCount(AKILinkedListEnumerator *enumerator);

static
void AKILinkedListEnumeratorSetIsValid(AKILinkedListEnumerator *enumerator, bool valid);

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
    AKILinkedListEnumeratorSetMutationsCount(enumerator, AKILinkedListEnumeratorGetMutationsCount(enumerator));
    
    return enumerator;
}

void *AKILinkedListEnumeratorGetNextObject(AKILinkedListEnumerator *enumerator) {
    uint64_t enumeratorMutationsCount = 0;
    uint64_t linkedListMutationsCount = 0;
    
    if (enumerator) {
        enumeratorMutationsCount = AKILinkedListEnumeratorGetMutationsCount(enumerator);
        linkedListMutationsCount = AKILinkedListGetMutationsCount(enumerator->_list);
    
        if (enumeratorMutationsCount != linkedListMutationsCount) {
            return NULL;
        }
        
        AKILinkedListNode *node = AKILinkedListEnumeratorGetNode(enumerator);
        
        if (!node) {
            
            AKILinkedList *list = AKILinkedListEnumeratorGetList(enumerator);
            
            AKILinkedListNode *head = AKILinkedListGetHead(list);
            AKILinkedListEnumeratorSetMutationsCount(enumerator, enumeratorMutationsCount + 1);
            AKILinkedListSetMutationsCount(list, linkedListMutationsCount + 1);
            
            return head;
        }
    }
    
    
    return NULL;
}

bool AKILinkedListEnumeratorIsValid(AKILinkedListEnumerator *enumerator) {
    return enumerator && enumerator->_isValid;
}

#pragma mark -
#pragma mark Private Implementations

void AKILinkedListEnumeratorSetList(AKILinkedListEnumerator *enumerator, AKILinkedList *list) {
    
}

AKILinkedList *AKILinkedListEnumeratorGetList(AKILinkedListEnumerator *enumerator) {
    return enumerator ? enumerator->_list : NULL;
}

void AKILinkedListEnumeratorSetNode(AKILinkedListEnumerator *enumerator, AKILinkedListNode *node) {
    
}

AKILinkedListNode *AKILinkedListEnumeratorGetNode(AKILinkedListEnumerator *enumerator) {
    return enumerator ? enumerator->_currentNode : NULL;
}

void AKILinkedListEnumeratorSetMutationsCount(AKILinkedListEnumerator *enumerator, uint64_t count) {
    if (enumerator) {
        enumerator->_mutationsCount = count;
    }
}

uint64_t AKILinkedListEnumeratorGetMutationsCount(AKILinkedListEnumerator *enumerator) {
    return enumerator ? enumerator->_mutationsCount : kAKINotFound;
}

void AKILinkedListEnumeratorSetIsValid(AKILinkedListEnumerator *enumerator, bool valid) {
    AKIObjectAssignSetter(enumerator, _isValid, valid);
}
