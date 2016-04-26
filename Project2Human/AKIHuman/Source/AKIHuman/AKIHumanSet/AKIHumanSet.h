//
//  AKIHumanSet.h
//  AKIHuman
//
//  Created by Alexey Khomych on 26.04.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#ifndef AKIHumanSet_h
#define AKIHumanSet_h

#include "AKIHuman.h"

extern
void AKIHumanSetName(AKIHuman *object, const char *name);

extern
void AKIHumanSetAge(AKIHuman *object, uint8_t age);

extern
void AKIHumanSetPartner(AKIHuman *object, AKIHuman *partner);

extern
void AKIHumanSetParentFather(AKIHuman *object, AKIHuman *father);

extern
void AKIHumanSetParentMother(AKIHuman *object, AKIHuman *mother);

extern
void AKIHumanSetGender(AKIHuman *object, AKIGender gender);

extern
void AKIHumanSetChild(AKIHuman *partner, AKIHuman *child);

#endif /* AKIHumanSet_h */
