//
//  AKIInitializeHuman.c
//  AKIHuman
//
//  Created by Alexey Khomych on 21.04.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#include "AKIInitializeHuman.h"

#include <string.h>

void AKIInitializeHuman(char *name, uint8_t age, bool isMarried, AKIGender gender, uint8_t childrenCount, AKIHuman *partner, AKIHuman *parents) {
    AKIHuman human;
    human._name = AKISetHumanName(human);
    human._age = AKISetHumanAge(human);
//    Jon._gender = AKISetHumanGender(human);
    
}

char *AKISetHumanName(AKIHuman human) {
    return "Jon";
}

uint8_t AKISetHumanAge(AKIHuman human) {
    return 50;
}

//AKIGender AKISetHumanGender(AKIHuman human) {
//    return
//}

//AKIHuman AKISetHumanPartner(AKIHuman human) {
//    return human;
//}