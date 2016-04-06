//
//  ICPrinting.c
//  Homework_lesson1
//
//  Created by Admin on 06.04.16.
//
//
#include <stdio.h>

#include "ICPrinting.h"

void ICPrint() {
    printf("Hello, world\n");
}

void ICPrintParents() {
    ICPrintMama();
    ICPrintPapa();
}

void ICPrintMama() {
    printf("Hello, mama!\n");
}

void ICPrintPapa() {
    printf("Hello, papa\n");
}