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

#define AKILinkedListNodeSet(node, object) { \
    if (node) {\
        AKIObjectRelease(node->_##object);\
        AKIObjectRetain(object);\
        node->_##object = object;\
    }\
}

#undef AKILinkedListSetNode

void AKILinkedListNodeSetNextNode(AKILinkedListNode *node, AKILinkedListNode *nextNode) {
    if (node && AKILinkedListNodeGetNextNode(node) != nextNode) {
        AKILinkedListNodeSet(node, nextNode);
    }
}

AKILinkedListNode *AKILinkedListNodeGetNextNode(AKILinkedListNode *node) {
    return node ? node->_nextNode : NULL;
}

void AKILinkedListNodeSetObject(AKILinkedListNode *node, void *object) {
    if (node && AKILinkedListGetObject(node)) {
        AKILinkedListNodeSet(node, object);
    }
}

AKIObject *AKILinkedListGetObject(AKILinkedListNode *node) {
    return node ? node->_object : NULL;
}