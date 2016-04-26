//
//  AKIHumanGet.c
//  AKIHuman
//
//  Created by Alexey Khomych on 26.04.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#include "AKIHumanGet.h"

char *AKIHumanGetName(AKIHuman *object) {
    return NULL == object ? NULL : object->_name;
}



uint8_t AKIHumanGetAge(AKIHuman *object) {
    return NULL == object ? NULL : object->_age;
}



AKIGender AKIHumanGetGender(AKIHuman *object) {
    return NULL == object ? NULL : object->_gender;
}


AKIHuman AKIHumanGetPartner(AKIHuman *object) {
    return *(NULL == object ? NULL : object->_partner);
}
