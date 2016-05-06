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
AKIHuman *AKIHumanGetParent(AKIHuman *child, AKIHuman *parent);

extern
uint8_t AKIHumanGetChildrenCount(AKIHuman *object);

extern
void AKIHumanAddChild(AKIHuman *object, AKIHuman *child);

extern
void AKIHumanRemoveChild(AKIHuman *object, AKIHuman *child);

extern
void AKIHumanSetParents(AKIHuman *child, AKIHuman *father, AKIHuman *mother);

#endif /* AKIHuman_AKIParentHood_h */
