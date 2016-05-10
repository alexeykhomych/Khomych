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
void AKIHumanGiveBirthChild(AKIHuman *object, AKIHuman *child);

extern
void AKIHumanRemoveChild(AKIHuman *object, AKIHuman *child);

extern
void AKIHumanRemoveAllChildren(AKIHuman *parent);

extern
void AKIHumanSetParent(AKIHuman *object, AKIHuman *parent);

extern
AKIHuman *AKIHumanGetFather(AKIHuman *object);

extern
AKIHuman *AKIHumanGetMother(AKIHuman *object);

#endif /* AKIHuman_AKIParentHood_h */
