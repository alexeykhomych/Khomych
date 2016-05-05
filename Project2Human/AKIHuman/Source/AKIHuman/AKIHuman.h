//
//  AKIHuman.h
//  AKIHuman
//
//  Created by Alexey Khomych on 21.04.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#ifndef AKIHuman_h
#define AKIHuman_h

#include <stdio.h>

#include "AKIObject.h"

static const uint32_t kAKIChildrenCount = 20;

typedef enum {
    AKIGenderMale,
    AKIGenderFemale
} AKIGender;

typedef struct AKIHuman AKIHuman;
struct AKIHuman {
    AKIObject _super;
    
    AKIGender _gender;
    char *_name;
    uint8_t _age;
    
    AKIHuman *_partner;
    AKIHuman *_father;
    AKIHuman *_mother;
    
    AKIHuman *_children[kAKIChildrenCount];
    uint8_t _childrenCount;
};

extern
AKIHuman *AKICreateHuman();

extern
void AKIHumanSetName(AKIHuman *object, const char *name);

extern
char *AKIHumanGetName(AKIHuman *object);

extern
void AKIHumanSetAge(AKIHuman *object, uint8_t age);

extern
uint8_t AKIHumanGetAge(AKIHuman *object);

extern
void AKIHumanSetGender(AKIHuman *object, AKIGender gender);

extern
AKIGender AKIHumanGetGender(AKIHuman *object);

extern
void __AKIHumanDeallocate(void *object);

extern
void AKIHumanRetain(AKIHuman *object);

extern
void AKIHumanRelease(AKIHuman *object);

#endif /* AKIInitializeHuman_h */
