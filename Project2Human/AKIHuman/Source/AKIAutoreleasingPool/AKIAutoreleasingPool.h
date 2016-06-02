//
//  AKIAutoreleasingPool.h
//  AKIHuman
//
//  Created by Alexey Khomych on 02.06.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#ifndef AKIAutoreleasingPool_h
#define AKIAutoreleasingPool_h

#include <stdio.h>

#include "AKIObject.h"
#include "AKILinkedList.h"

typedef struct AKIAutoreleasingPool AKIAutoreleasingPool;

struct AKIAutoreleasingPool {
    AKIObject _super;
    AKILinkedList *_stack;
    bool _isValid;
};

extern
void __AKIAutoreleasingPoolDeallocate(void *object);

extern
void AKIAutoreleasingPoolCreate();

#endif /* AKIAutoreleasingPool_h */
