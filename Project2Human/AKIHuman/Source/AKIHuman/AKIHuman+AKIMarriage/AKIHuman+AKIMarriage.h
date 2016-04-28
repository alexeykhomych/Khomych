//
//  AKIHuman+AKIMarriage.h
//  AKIHuman
//
//  Created by Alexey Khomych on 27.04.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#ifndef AKIHuman_AKIMarriage_h
#define AKIHuman_AKIMarriage_h

#include <stdbool.h>

extern
void AKIHumanSetPartner(AKIHuman *object, AKIHuman *partner);

extern
AKIHuman AKIHumanGetPartner(AKIHuman *object);

extern
void AKIHumanDivorcePartners(AKIHuman *object);

extern
bool AKIHumanCanMarry(AKIHuman *object, AKIHuman *partner);

#endif /* AKIHuman_AKIMarriage_h */