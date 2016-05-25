//
//  AKILinkedListEnumerator.c
//  AKIHuman
//
//  Created by Alexey Khomych on 25.05.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#include "AKILinkedListEnumerator.h"
#include "AKILinkedListNode.h"
#include "AKIConstants.h"

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

#pragma mark -
#pragma mark Public Implementations

void __AKILinkedListEnumeratorDeallocate(void *object) {
    __AKIObjectDeallocate(object);
}

AKILinkedListEnumerator *AKILinkedListEnumeratorCreateWithList(AKILinkedList *list) {
    AKILinkedListEnumerator *enumerator = AKIObjectCreateOfType(AKILinkedListEnumerator);
    AKILinkedListEnumeratorSetList(enumerator, list);
    AKILinkedListEnumeratorSetMutationsCount(enumerator, 0);
    
    return enumerator;
}

AKILinkedListNode *AKILinkedListEnumeratorGetNextNode(AKILinkedListEnumerator *enumerator) {
    return NULL;
}

bool AKILinkedListEnumeratorIsValid(AKILinkedList *list) {
    return NULL;
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
