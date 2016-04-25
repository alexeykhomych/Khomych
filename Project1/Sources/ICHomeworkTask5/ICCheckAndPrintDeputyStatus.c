//
//  ICDeputyStatus.c
//  Homework_lesson1
//
//  Created by Admin on 08.04.16.
//
//

#include <stdio.h>
#include <string.h>

#include "ICRunApplication.h"

void ICCheckDeputyStatus(int salary, int allMoney) {
    ICDeputyStatus status = ICDeputyStatusNull;
    
    if (allMoney < salary * 12 || !salary) {
        status = ICDeputyStatusDead;
    } else if(allMoney < salary * 120) {
        status = ICDeputyStatusAngel;
    } else if(allMoney < salary * 1000 * 1000) {
        status = ICDeputyStatusHonest;
    } else if(allMoney >= salary * 1000 * 1000) {
        status = ICDeputyStatusThief;
    }
    
    ICPrintDeputyStatus(status);
}

void ICPrintDeputyStatus(ICDeputyStatus status) {
    switch(status) {
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
