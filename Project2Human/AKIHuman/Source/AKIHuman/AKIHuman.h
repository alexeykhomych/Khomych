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
#include <stdbool.h>

static const uint8_t kchildrenCount = 20;

typedef enum {
    AKIGenderMale,
    AKIGenderFemale
} AKIGender;

typedef struct AKIHuman AKIHuman;
struct AKIHuman {
    AKIGender _gender;
    AKIHuman *_children[kchildrenCount];
    AKIHuman *_partner;
    AKIHuman *_father;
    AKIHuman *_mother;
    
    uint32_t _hardReferenceCount;
    char *_name;
    
    uint8_t _age;
    uint8_t _childrenCount;
};

extern
void AKICreateHuman();

extern
void AKIHumanDivorcePartners(AKIHuman *object);

#endif /* AKIInitializeHuman_h */
