//
//  ICDeputyStatus.c
//  Homework_lesson1
//
//  Created by Admin on 08.04.16.
//
//

#include <stdio.h>

#include "ICRunApplicationFunction.h"

typedef enum {
    ICDeputyStatusAngel,
    ICDeputyStatusDead,
    ICDeputyStatusThief,
    ICDeputyStatusHonest,
} ICDeputyEntity;

void ICDeputyStatus(ICDeputyEntity entity) {
//    enum ICDeputyStatus status;
    long allMoney = 250000120;
    int salary = 50000;
    
    if(allMoney > salary * 120 && allMoney >= salary * 1000 * 1000) {
        entity = ICDeputyStatusThief;
    } else if(allMoney >= salary * 120 && allMoney < salary * 1000 * 1000) {
        entity = ICDeputyStatusHonest;
    } else if(allMoney >= salary * 12 && allMoney < salary * 120) {
        entity = ICDeputyStatusAngel;
    } else if(salary == 0 && allMoney < salary * 12) {
        entity = ICDeputyStatusDead;
    } else {
        entity = ICDeputyStatusDead;
    }
    
    switch(entity) {
        case ICDeputyStatusDead:
            puts("Deputy is dead");
            break;
        case ICDeputyStatusAngel:
            puts("Deputy is angel");
            break;
        case ICDeputyStatusThief:
            puts("Deputy is thief");
            break;
        case ICDeputyStatusHonest:
            puts("Deputy is honest");
            break;
        default:
            puts("Deputy is dead");
            break;
    }    
}
