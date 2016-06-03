//
//  AKILinkedList.h
//  AKIHuman
//
//  Created by Alexey Khomych on 23.05.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#ifndef AKILinkedList_h
#define AKILinkedList_h

#include <stdio.h>
#include <stdbool.h>

#include "AKIObject.h"
#include "AKILinkedListNode.h"

typedef struct AKILinkedList AKILinkedList;

struct AKILinkedList{
    AKIObject _super;
    
    AKILinkedListNode *_head;
    uint64_t _count;
    uint64_t _mutationsCount;
};

extern
void __AKILinkedListDeallocate(void *object);

extern
AKIObject *AKILinkedListGetFirstObject(AKILinkedList *list);

extern
void AKILinkedListRemoveFirstObject(AKILinkedList *list);

extern
bool AKILinkedListIsEmpty(AKILinkedList *list);

extern
void AKILinkedListAddObject(AKILinkedList *list, void *object);

extern
void AKILinkedListRemoveObject(AKILinkedList *list, void *object);

extern
void AKILinkedListRemoveAllObject(AKILinkedList *list);

extern
bool AKILinkedListContainsObject(AKILinkedList *list, void *object);

extern
uint64_t AKILinkedListGetCount(AKILinkedList *list);

extern
uint64_t AKILinkedListGetMutationsCount(AKILinkedList *list);

extern
AKIObject *AKILinkedListGetObjectBeforeObject(AKILinkedList *list, AKIObject *object);

extern
AKIObject *AKILinkedListGetObjectAfterObject(AKILinkedList *list, AKIObject *object);

#endif /* AKILinkedList_h */
