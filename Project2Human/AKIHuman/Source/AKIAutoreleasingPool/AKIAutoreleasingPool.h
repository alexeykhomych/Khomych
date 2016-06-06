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
    uint64_t _count;
    bool _isValid;
};

extern
void __AKIAutoreleasingPoolDeallocate(void *object);

extern
AKIAutoreleasingPool * AKIAutoreleasingPoolCreate();

extern
void AKIAutoreleasingPoolAddObject(AKIAutoreleasingPool *pool, void *object);

extern
void AKIAutoreleasingPoolDrain();

extern
AKIAutoreleasingPool *AKIAutoreleasingPoolGet();

#endif /* AKIAutoreleasingPool_h */
