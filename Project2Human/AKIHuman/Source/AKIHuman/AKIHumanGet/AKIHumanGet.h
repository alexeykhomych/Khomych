//
//  AKIHumanGet.h
//  AKIHuman
//
//  Created by Alexey Khomych on 26.04.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#ifndef AKIHumanGet_h
#define AKIHumanGet_h

#include "AKIHuman.h"

extern
char *AKIHumanGetName(AKIHuman *object);

extern
uint8_t AKIHumanGetAge(AKIHuman *object);

extern
AKIHuman AKIHumanGetPartner(AKIHuman *object);

extern
AKIGender AKIHumanGetGender(AKIHuman *object);

extern
AKIHuman *AKIHumanGetChild(AKIHuman *object);

#endif /* AKIHumanGet_h */
