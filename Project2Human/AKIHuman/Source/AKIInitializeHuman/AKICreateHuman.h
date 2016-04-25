//
//  AKIInitializeHuman.h
//  AKIHuman
//
//  Created by Alexey Khomych on 21.04.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#ifndef AKIInitializeHuman_h
#define AKIInitializeHuman_h

#include <stdio.h>
#include <stdbool.h>

typedef enum {
    AKIGenderMale,
    AKIGenderFemale
} AKIGender;

typedef struct AKIHuman AKIHuman;
struct AKIHuman {
    char *_name;
    uint8_t _age;
    bool _isMarried; //?
    AKIGender _gender;
    uint8_t _childrenCount;
    AKIHuman *children[20];
    AKIHuman *partner;
    AKIHuman *parents;
    uint16_t _referenceCount;
};

extern
AKIHuman AKICreateHuman(AKIHuman *object);

extern
void AKIHumanSetName(AKIHuman *object, const char *name);

extern
char *AKIHumanGetName(AKIHuman *object);

extern
void AKIHumanSetAge(AKIHuman *object, uint8_t age);

extern
uint8_t AKIHumanGetAge(AKIHuman *object);

extern
void AKIHumanSetPartner(AKIHuman *object, AKIHuman *partner);

extern
AKIHuman AKIHumanGetPartner(AKIHuman *object);

extern
void AKIHumanSetParents(AKIHuman *object, AKIHuman *parents);

extern
void AKIHumanSetGender(AKIHuman *object, AKIGender gender);

extern
AKIGender AKIHumanGetGender(AKIHuman *object);

extern
void AKIHumanSetChild(AKIHuman *partner1, AKIHuman *partner2, AKIHuman *child);

extern
AKIHuman *AKIHumanGetChild(AKIHuman *object);

extern
void AKIHumanDivorcePartners(AKIHuman *partner1, AKIHuman *partner2);

#endif /* AKIInitializeHuman_h */
