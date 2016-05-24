//
//  AKIString.h
//  AKIHuman
//
//  Created by Alexey Khomych on 15.05.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#ifndef AKIString_h
#define AKIString_h

#include "AKIObject.h"

typedef struct {
    AKIObject _super;
    char *_value;
} AKIString;

extern
AKIString *AKIStringCreate(char *value);

extern
void __AKIStringDeallocate(void *object);

extern
size_t AKIStringGetLength(AKIString *string);

extern
AKIString *AKIStringCopy(AKIString *string);

extern
AKIString *AKIStringGetValue(AKIString *object);

#endif /* AKIString_h */
