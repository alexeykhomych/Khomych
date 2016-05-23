//
//  AKILinkedListNode.c
//  AKIHuman
//
//  Created by Alexey Khomych on 23.05.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#include "AKILinkedListNode.h"

void __AKILinkedListNodeDeallocate(void *list) {
    __AKIObjectDeallocate(list);
}

AKILinkedListNode *AKILinkedListCreateWithObject(void *object) {
    AKILinkedListNode *node = AKIObjectCreateOfType(AKILinkedListNode);
    
    
    
    return node;
}

void AKILinkedListNodeSetNextNode(AKILinkedListNode *node, AKILinkedListNode *nextNode) {
    if (node) {
        
    }
}


AKILinkedListNode *AKILinkedListNodeGetNextNode(AKILinkedListNode *node) {
    if (!node) {
        return NULL;
    }
    
    return NULL;
}

void AKILinkedListNodeSetObject(AKILinkedListNode *node, void *object) {
    if (node) {
        
    }
}

AKIObject *AKILinkedListGetObject(AKILinkedListNode *node) {
    return node ? node->_nextNode : NULL;
}