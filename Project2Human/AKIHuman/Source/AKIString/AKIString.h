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

typedef struct AKIString AKIString;

struct AKIString{
    AKIObject _super;
    char *_name;
};

extern
AKIString *AKIStringCreate();

#endif /* AKIString_h */
