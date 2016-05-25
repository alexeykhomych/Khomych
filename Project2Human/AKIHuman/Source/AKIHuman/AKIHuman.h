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
#include "AKIString.h"
#include "AKIConstants.h"

//const uint32_t kAKIChildrenCount = 20;

typedef enum {
    AKIGenderUndefined,
    AKIGenderMale,
    AKIGenderFemale
} AKIGender;

typedef struct AKIHuman AKIHuman;
struct AKIHuman {
    AKIObject _super;
    AKIString _name;
    
    AKIGender _gender;
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
void __AKIHumanDeallocate(void *object);

extern
void AKIHumanSetName(AKIHuman *human, AKIString *name);

extern
AKIString *AKIHumanGetName(AKIHuman *object);

extern
void AKIHumanSetAge(AKIHuman *object, uint8_t age);

extern
uint8_t AKIHumanGetAge(AKIHuman *object);

extern
void AKIHumanSetGender(AKIHuman *object, AKIGender gender);

extern
AKIGender AKIHumanGetGender(AKIHuman *object);

#endif /* AKIInitializeHuman_h */
