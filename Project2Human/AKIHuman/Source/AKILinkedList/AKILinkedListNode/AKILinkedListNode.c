//
//  AKILinkedListNode.c
//  AKIHuman
//
//  Created by Alexey Khomych on 23.05.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#include "AKILinkedListNode.h"

void __AKILinkedListNodeDeallocate(void *object) {
    AKILinkedListNodeSetObject(object, NULL);
    AKILinkedListNodeSetNextNode(object, NULL);

    __AKIObjectDeallocate(object);
}

AKILinkedListNode *AKILinkedListCreateWithObject(void *object) {
    AKILinkedListNode *node = AKIObjectCreateOfType(AKILinkedListNode);
    AKILinkedListNodeSetObject(node, object);
    
    return node;
}

void AKILinkedListNodeSetNextNode(AKILinkedListNode *node, AKILinkedListNode *nextNode) {
    AKIObjectSetStrong(node, _nextNode, nextNode);
}

AKILinkedListNode *AKILinkedListNodeGetNextNode(AKILinkedListNode *node) {
    return node ? node->_nextNode : NULL;
}

void AKILinkedListNodeSetObject(AKILinkedListNode *node, void *object) {
    AKIObjectSetStrong(node, _object, object);
}

AKIObject *AKILinkedListNodeGetObject(AKILinkedListNode *node) {
    return node ? node->_object : NULL;
}
