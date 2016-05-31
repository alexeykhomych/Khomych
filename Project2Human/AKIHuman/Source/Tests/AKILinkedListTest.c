//
//  AKILinkedListTest.c
//  AKIHuman
//
//  Created by Alexey Khomych on 25.05.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#include <assert.h>

#include "AKILinkedListTest.h"
#include "AKILinkedList.h"
#include "AKIString.h"
#include "AKIHuman.h"
#include "AKILinkedListEnumerator.h"

static
void AKILinkedListEnumeratorTest(AKILinkedList *list, uint64_t count);

void AKILinkedListTest() {
    AKILinkedList *list = AKIObjectCreateOfType(AKILinkedList);
    AKIString *string = AKIObjectCreateOfType(AKIString);
    AKIHuman *human = AKIObjectCreateOfType(AKIHuman);
    
    assert(AKILinkedListIsEmpty(list));
    
    uint8_t count = 10;
    
    for (uint8_t i = 0; i < count; i++) {
        if (i % 2 == 0) {
            AKILinkedListAddObject(list, string);
        } else {
            AKILinkedListAddObject(list, human);
        }
    }
    
    AKILinkedListEnumeratorTest(list, count);
    
    assert(count == AKILinkedListGetCount(list));
    assert(AKILinkedListContainsObject(list, human));
    assert(AKILinkedListContainsObject(list, string));
    
    AKILinkedListRemoveObject(list, human);
    assert(count - 1 == AKILinkedListGetCount(list));
    
    AKILinkedListAddObject(list, human);
    assert(count == AKILinkedListGetCount(list));
    
    assert((AKIString *)AKILinkedListGetFirstObject(list) == string);
    
    AKILinkedListRemoveAllObject(list);
    assert(0 == AKILinkedListGetCount(list));
    
    AKIObjectRelease(string);
    AKIObjectRelease(human);
    AKIObjectRelease(list);
    
}

void AKILinkedListEnumeratorTest(AKILinkedList *list, uint64_t count) {
    if (!list) {
        return;
    }
    AKILinkedListEnumerator *enumerator = AKILinkedListEnumeratorCreateWithList(list);
    AKIObject *object = AKILinkedListEnumeratorGetNextObject(enumerator);
    
    uint64_t i = 0;
    
    while (AKILinkedListEnumeratorIsValid(enumerator)) {
        object = AKILinkedListEnumeratorGetNextObject(enumerator);
        i += 1;
    }
    
    assert(i == count);
    
    AKIObjectRelease(enumerator);
}
