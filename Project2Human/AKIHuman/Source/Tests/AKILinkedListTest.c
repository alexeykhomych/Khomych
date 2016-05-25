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
}
