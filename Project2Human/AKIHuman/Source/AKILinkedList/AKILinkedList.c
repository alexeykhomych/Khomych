//
//  AKILinkedList.c
//  AKIHuman
//
//  Created by Alexey Khomych on 23.05.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "AKILinkedList.h"
#include "AKILinkedListNode.h"

#pragma mark -
#pragma mark Private Declarations

static
void AKILinkedListSetCount(AKILinkedList *list, AKILinkedListNode *node);

static
void AKILinkedListSetHead(AKILinkedList *list, AKILinkedListNode *node);

static
AKILinkedListNode *AKILinkedListGetHead(AKILinkedList *list);

#pragma mark -
#pragma mark Public Implementations

void __AKILinkedListDeallocate(void *object) {
    AKILinkedListRemoveAllObject(object);
    __AKIObjectDeallocate(object);
}

AKIObject *AKILinkedListGetFirstObject(AKILinkedList *list) {
    AKILinkedListNode *head = AKILinkedListGetHead(list);
    
    return AKILinkedListGetObject(head);
}

void AKILinkedListRemoveFirstObject(AKILinkedList *list) {
    if (!list) {
        return;
    }
    
    AKILinkedListNode *node = AKILinkedListGetHead(list);
    AKILinkedListSetHead(list, AKILinkedListNodeGetNextNode(node));
}

bool AKILinkedListIsEmpty(AKILinkedList *list) {
    return list && 0 == list->_count;
}

void AKILinkedListAddObject(AKILinkedList *list, void *object) {
    if (list) {
        AKILinkedListNode *node = AKILinkedListCreateWithObject(object);
        AKILinkedListNodeSetNextNode(node, AKILinkedListGetHead(list));
        AKILinkedListSetHead(list, node);
        
        list->_count += 1;
        
        AKIObjectRetain(node);
    }
}

void AKILinkedListRemoveObject(AKILinkedList *list, void *object);

void AKILinkedListRemoveAllObject(AKILinkedList *list) {
    if (list) {
        AKILinkedListSetHead(list, NULL);
        list->_count = 0;
    }
}

bool AKILinkedListContainsObject(AKILinkedList *list, void *object) {
    return list ? AKILinkedListGetObject(AKILinkedListGetHead(list)) : false; //check
}

uint64_t AKILinkedListGetCount(AKILinkedList *list) {
    return list ? list->_count : kAKINotFound;
}

AKIObject *AKILinkedListGetObjectBeforeObject(AKILinkedList *list, AKIObject *object) {
    return NULL;
}

#pragma mark -
#pragma mark Private Implementations

void AKILinkedListSetHead(AKILinkedList *list, AKILinkedListNode *node) {
    AKILinkedListNode *head = AKILinkedListGetHead(list);
    
    if (list && head != node) {
        AKIObjectRetain(node);
        AKIObjectRelease(list->_head);
        list->_head = node;
    }
}

AKILinkedListNode *AKILinkedListGetHead(AKILinkedList *list) {
    return list ? list->_head : NULL;
}
