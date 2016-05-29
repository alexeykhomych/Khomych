//
//  AKILinkedListEnumerator.h
//  AKIHuman
//
//  Created by Alexey Khomych on 25.05.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#ifndef AKILinkedListEnumerator_h
#define AKILinkedListEnumerator_h

#include <stdio.h>
#include <stdbool.h>

#include "AKIObject.h"

typedef struct AKILinkedList AKILinkedList;
typedef struct AKILinkedListNode AKILinkedListNode;

typedef struct {
    AKIObject *_super;
    AKILinkedList *_list;
    AKILinkedListNode *_currentNode;
    uint64_t _mutationsCount;
    bool _isValid;
} AKILinkedListEnumerator;

extern
void _AKILinkedListEnumeratorDeallocate(void *object);

extern
AKILinkedListEnumerator *AKILinkedListEnumeratorCreateWithList(AKILinkedList *list);

extern
void *AKILinkedListEnumeratorGetNextObject(AKILinkedListEnumerator *enumerator);

extern
bool AKILinkedListEnumeratorIsValid(AKILinkedListEnumerator *enumerator);

#endif /* AKILinkedListEnumerator_h */
