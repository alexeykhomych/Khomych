//
//  ICMacrosTest.c
//  Homework_lesson1
//
//  Created by Admin on 11.04.16.
//
//
#include <stdio.h>



#include "ICMacrosCreateFunction.h"

//ICMacrosCreatFunction(t, t);
//ICMacrosCreatFunction(double, %lf);
//ICMacrosCreatFunction(long, %ld);
//ICMacrosCreatFunction(char, %c);


void testfunc() {
//    char *charArray[7][2];
//    
//    charArray[0][0] = "int";
//    charArray[0][1] = "%d";
//    charArray[1][0] = "char";
//    charArray[1][1] = "%c";
//    charArray[2][0] = "long";
//    charArray[2][1] = "%l";
//    charArray[3][0] = "long double";
//    charArray[3][1] = "%L";
//    charArray[4][0] = "float";
//    charArray[4][1] = "%f";
//    charArray[5][0] = "long long int";
//    charArray[5][1] = "%ll";
//    charArray[6][0] = "short int";
//    charArray[6][1] = "%h";
//
//    for (int iteration = 0; iteration < 7; iteration++) {
//        for (int iteration1 = 0; iteration1 < 1; iteration1++) {
//            ICFunctionShowSizeOfTypes(charArray[iteration][iteration1], (char)charArray[iteration][iteration1 + 1]);
//        }
//    }
    
    ICFunctionShowSizeOfTypes(int, %d);
    ICFunctionShowSizeOfTypes(char, %c);
    ICFunctionShowSizeOfTypes(long, %l);
    ICFunctionShowSizeOfTypes(long double, %L);
    ICFunctionShowSizeOfTypes(float, %f);
    ICFunctionShowSizeOfTypes(long long int, %ll);
    ICFunctionShowSizeOfTypes(short int, %h);
}