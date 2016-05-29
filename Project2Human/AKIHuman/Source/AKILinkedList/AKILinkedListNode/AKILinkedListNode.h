//
//  AKILinkedListNode.h
//  AKIHuman
//
//  Created by Alexey Khomych on 23.05.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#ifndef AKILinkedListNode_h
#define AKILinkedListNode_h

#include <stdio.h>

#include "AKIObject.h"

typedef struct AKILinkedListNode AKILinkedListNode;

struct AKILinkedListNode{
    AKIObject _super;
    
    AKILinkedListNode *_nextNode;
    void *_object;
};

extern
void __AKILinkedListNodeDeallocate(void *list);

extern
AKILinkedListNode *AKILinkedListCreateWithObject(void *object);

extern
void AKILinkedListNodeSetNextNode(AKILinkedListNode *node, AKILinkedListNode *nextNode);

extern
AKILinkedListNode *AKILinkedListNodeGetNextNode(AKILinkedListNode *node);

extern
void AKILinkedListNodeSetObject(AKILinkedListNode *node, void *object);

extern
AKIObject *AKILinkedListNodeGetObject(AKILinkedListNode *node);

#endif /* AKILinkedListNode_h */
