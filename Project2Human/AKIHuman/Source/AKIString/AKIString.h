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

typedef struct{
    AKIObject _super;
    char *_value;
    size_t _length;
}AKIString;

extern
AKIString *AKIStringCreate(char *object);

extern
void __AKIStringDeallocate(void *object);

extern
void AKIStringSetValue(AKIString *object, char *value);

extern
size_t AKIStringGetLength(char *object);

extern
AKIString *AKIStringCopy(char *value);

#endif /* AKIString_h */
