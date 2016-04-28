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

static const uint32_t kchildrenCount = 20;

typedef enum {
    AKIGenderMale,
    AKIGenderFemale
} AKIGender;

typedef struct AKIHuman AKIHuman;
struct AKIHuman {
    uint32_t _referenceCount;
    
    AKIGender _gender;
    char *_name;
    
    AKIHuman *_children[kchildrenCount];
    AKIHuman *_partner;
    AKIHuman *_father;
    AKIHuman *_mother;
    
    uint8_t _age;
    uint8_t _childrenCount;
};

extern
AKIHuman AKICreateHuman();

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
void __AKIHumanDeallocate(AKIHuman *object);

extern
void AKIHumanRetain(AKIHuman *object);

extern
void AKIHumanRelease(AKIHuman *object);

#endif /* AKIInitializeHuman_h */
