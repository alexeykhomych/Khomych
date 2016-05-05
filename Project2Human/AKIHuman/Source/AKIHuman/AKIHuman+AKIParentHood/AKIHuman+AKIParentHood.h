//
//  AKIHuman+AKIParentHood.h
//  AKIHuman
//
//  Created by Alexey Khomych on 27.04.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#ifndef AKIHuman_AKIParentHood_h
#define AKIHuman_AKIParentHood_h

#include "AKIHuman.h"

extern
void AKIHumanSetParentFather(AKIHuman *object, AKIHuman *father);

extern
void AKIHumanSetParentMother(AKIHuman *object, AKIHuman *mother);

extern
AKIHuman *AKIHumanGetParentFather(AKIHuman *object);

extern
AKIHuman *AKIHumanGetParentMother(AKIHuman *object);

extern
uint8_t AKIHumanGetChildrenCount(AKIHuman *object);

extern
void AKIHumanAddChild(AKIHuman *object, AKIHuman *child);

extern
void AKIHumanDeallocateChild(AKIHuman *object, AKIHuman *child);

#endif /* AKIHuman_AKIParentHood_h */
