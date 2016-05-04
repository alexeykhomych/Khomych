//
//  AKIHuman+AKIParentHood.c
//  AKIHuman
//
//  Created by Alexey Khomych on 27.04.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#include "AKIHuman.h"
#include "AKIHuman+AKIParentHood.h"

void AKIHumanSetParentFather(AKIHuman *object, AKIHuman *father) {
    if (!object || !father) {
        object->_father = father;
        father->_children[father->_childrenCount] = object;
//        AKIHumanRetain(object); //week url to father
        AKIHumanRetain(father);
    }
}

void AKIHumanSetParentMother(AKIHuman *object, AKIHuman *mother) {
    if (!object && !mother) {
        object->_mother = mother;
        mother->_children[mother->_childrenCount] = object;
//        AKIHumanRetain(object);
        AKIHumanRetain(mother);
    }
}

AKIHuman AKIHumanGetParentFather(AKIHuman *object) {
    if (object) {
        return *object->_father;
    }
    
    return *object; //BAD
}

AKIHuman AKIHumanGetParentMother(AKIHuman *object) {
    if (object) {
        return *object->_mother;
    }
    
    return *object; //BAD
}
