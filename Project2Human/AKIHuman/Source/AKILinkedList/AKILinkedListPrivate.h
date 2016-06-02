//
//  AKILinkedListPrivate.h
//  AKIHuman
//
//  Created by Alexey Khomych on 29.05.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#ifndef AKILinkedListPrivate_h
#define AKILinkedListPrivate_h

#include <stdbool.h>

typedef struct AKILinkedList AKILinkedList;

typedef struct {
    void *object;
    void *previousNode;
    void *node;
} AKILinkedListContext;

typedef bool (*AKILinkedListComparisonFunction)(AKILinkedListNode *node, AKILinkedListContext *context);

extern
void AKILinkedListSetHead(AKILinkedList *list, AKILinkedListNode *node);

extern
AKILinkedListNode *AKILinkedListGetHead(AKILinkedList *list);

extern
void AKILinkedListSetMutationsCount(AKILinkedList *list, uint64_t count);

extern
AKILinkedListNode *AKILinkedListFindNodeWithContext(AKILinkedList *list, AKILinkedListComparisonFunction comparator, AKILinkedListContext *context);

extern
bool AKILinkedListNodeContainsObject(AKILinkedListNode *node, AKILinkedListContext *context);

extern
AKILinkedListNode *AKILinkedListEnumeratorGetNode(AKILinkedListEnumerator *enumerator);

#endif /* AKILinkedListPrivate_h */
