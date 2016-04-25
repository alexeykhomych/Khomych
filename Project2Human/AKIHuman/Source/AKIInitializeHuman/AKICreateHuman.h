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
    void *children[20];
    AKIHuman *partner;
    AKIHuman *parents;
};

extern
void AKICreateHuman(char *name, uint8_t age, bool isMarried, AKIGender gender, uint8_t childrenCount, AKIHuman *partner, AKIHuman *parents);

extern
void AKIDeinitializeHuman();

extern
char *AKISetHumanName(AKIHuman human);

extern
uint8_t AKISetHumanAge(AKIHuman human);

//extern
//AKIHuman AKISetHumanPatner(AKIHuman human); //?

//extern
//AKIGender AKISetHumanGender(AKIHuman human);

//extern
//void AKISetHumanPartner(AKIHuman humanName1, AKIHuman humanName2);

//extern
//void AKIGetHumanPartner(AKIHuman name);


#endif /* AKIInitializeHuman_h */
