//
//  ICPrintCycleFor.c
//  Homework_lesson1
//
//  Created by Admin on 08.04.16.
//
//
#include <stdio.h>

#include "ICRunApplication.h"

void ICPrintCycleFor(int countPrint, int min, int max) {
    countPrint = countPrint > 20 ? 20 : countPrint;
    int iterCount = max - min;
    
    for (int i = 0; i < iterCount; i++) {
        int number = min + i - 1;
        if(50 == number) {
            return;
        }
        
        if(i % 3 == 0) {
            continue;
        } else {
            for (int j = 0; j < countPrint; j++) {
                printf("%d", number);
            }
            
            puts("");
        }
    }
    
    int iterationFirst = 1;
    while(iterationFirst < iterCount) {
        iterationFirst++;
        int number = min + iterationFirst - 1;
        if(50 == number) {
            return;
        }
        
        if(iterationFirst % 3 == 0) {
            continue;
        } else {
            int iterationSecond = 0;
            while(iterationSecond < countPrint) {
                iterationSecond++;
                printf("%d", number);
            }
            
            puts("");
        }
    }
    
    iterationFirst = 1;
    do {
        iterationFirst++;
        int number = min + iterationFirst - 1;
        if(50 == number) {
            return;
        }
        
        if(iterationFirst % 3 == 0) {
            continue;
        } else {
            int iterationSecond = 0;
            do {
                iterationSecond++;
                printf("%d", number);
            } while(iterationSecond < countPrint);
            puts("");
        }
    } while(iterationFirst < iterCount);
}
