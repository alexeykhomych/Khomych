//
//  AKILinkedListPrivate.h
//  AKIHuman
//
//  Created by Alexey Khomych on 29.05.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#ifndef AKILinkedListPrivate_h
#define AKILinkedListPrivate_h

typedef struct AKILinkedList AKILinkedList; 

extern
void AKILinkedListSetHead(AKILinkedList *list, AKILinkedListNode *node);

extern
AKILinkedListNode *AKILinkedListGetHead(AKILinkedList *list);

extern
void AKILinkedListSetMutationsCount(AKILinkedList *list, uint64_t count);

#endif /* AKILinkedListPrivate_h */
