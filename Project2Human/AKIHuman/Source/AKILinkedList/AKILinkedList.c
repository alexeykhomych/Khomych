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
#include "AKILinkedListEnumerator.h"
#include "AKIConstants.h"
#include "AKILinkedListPrivate.h"

#pragma mark -
#pragma mark Private Declarations

static
void AKILinkedListSetCount(AKILinkedList *list, uint64_t count);

#pragma mark -
#pragma mark Public Implementations

void __AKILinkedListDeallocate(void *object) {
    AKILinkedListRemoveAllObject(object);
    
    __AKIObjectDeallocate(object);
}

AKIObject *AKILinkedListGetFirstObject(AKILinkedList *list) {
    AKILinkedListNode *head = AKILinkedListGetHead(list);
    
    return AKILinkedListNodeGetObject(head);
}

void AKILinkedListRemoveFirstObject(AKILinkedList *list) {
    if (!list) {
        return;
    }
    
    AKILinkedListNode *node = AKILinkedListGetHead(list);
    AKILinkedListSetHead(list, AKILinkedListNodeGetNextNode(node));
}

bool AKILinkedListIsEmpty(AKILinkedList *list) {
    return list && !AKILinkedListGetCount(list);
}

void AKILinkedListAddObject(AKILinkedList *list, void *object) {
    if (list) {
        AKILinkedListNode *node = AKILinkedListCreateWithObject(object);
        AKILinkedListNodeSetNextNode(node, AKILinkedListGetHead(list));
        AKILinkedListSetHead(list, node);
        
        AKILinkedListSetCount(list, AKILinkedListGetCount(list) + 1);
        
        AKIObjectRetain(node);
    }
}

void AKILinkedListRemoveObject(AKILinkedList *list, void *object) {
    AKILinkedListNode *node = AKILinkedListGetHead(list);
    AKILinkedListNode *previousNode = NULL;
    
    while (node) {
        AKIObject *currentObject = AKILinkedListNodeGetObject(node);
        
        if (currentObject == object) {
            AKILinkedListNodeSetNextNode(previousNode, AKILinkedListNodeGetNextNode(node));
            AKILinkedListSetCount(list, AKILinkedListGetCount(list) - 1);
            
            break;
        }
        
        previousNode = node;
        node = AKILinkedListNodeGetNextNode(node);
    }
}

void AKILinkedListRemoveAllObject(AKILinkedList *list) {
    if (list) {
        AKILinkedListSetHead(list, NULL);
        AKILinkedListSetCount(list, 0);
    }
}

bool AKILinkedListContainsObject(AKILinkedList *list, void *object) {
    if (list) {
        AKILinkedListNode *node = AKILinkedListGetHead(list);
        
        while (node) {
            if (object == AKILinkedListNodeGetObject(node)) {
                return true;
            }
            
            node = AKILinkedListNodeGetNextNode(node);
        }
    }
    
    return false;
}

uint64_t AKILinkedListGetCount(AKILinkedList *list) {
    return list ? list->_count : kAKINotFound;
}

AKIObject *AKILinkedListGetObjectBeforeObject(AKILinkedList *list, AKIObject *object) {
    if (list && !AKILinkedListIsEmpty(list)) {
        AKILinkedListNode *currentNode = AKILinkedListGetHead(list);
        AKIObject *previousObject = NULL;
        
        do {
            AKIObject *currentObject = AKILinkedListNodeGetObject(currentNode);
            
            if (object == currentObject) {
                return previousObject;
            }
            
            previousObject = currentObject;
        } while (!(currentNode = AKILinkedListNodeGetNextNode(currentNode)));
    }
    
    return NULL;
}

uint64_t AKILinkedListGetMutationsCount(AKILinkedList *list) {
    return list ? list->_mutationsCount : kAKINotFound;
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

void AKILinkedListSetCount(AKILinkedList *list, uint64_t count) {
    if (list) {
        list->_count = count;
        AKILinkedListSetMutationsCount(list, AKILinkedListGetMutationsCount(list) + 1);
    }
}

void AKILinkedListSetMutationsCount(AKILinkedList *list, uint64_t count) {
    if (list) {
        list->_mutationsCount = count;
    }
}
