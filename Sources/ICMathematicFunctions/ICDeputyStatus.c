//
//  ICDeputyStatus.c
//  Homework_lesson1
//
//  Created by Admin on 08.04.16.
//
//

#include "ICDeputyStatus.h"

enum ICDeputyStatus{
    Angel,
    Dead,
    Thief,
    Honest,
};

enum ICDeputyStatus status;

void ICDeputyStatus(int salary, int allMoney) {
    if(allMoney == salary * 1000 * 1000) {
        status = Thief;
        puts("Deputy is thief");
    }
    else if(allMoney == salary * 120) {
        status = Honest;
        puts("Deputy is honest");
    }
    else if(allMoney == salary * 12) {
        status = Angel;
        puts("Deputy is angel");
    }
    else if(salary == 0) {
        status = Dead;
        puts("Deputy is dead");
    }
    else {
        status = Dead;
        puts("Deputy is dead");
    }
}
