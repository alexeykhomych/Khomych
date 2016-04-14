//  Created by Admin on 11.04.16.
//
//
#include <stdio.h>
#include "ICMacrosGenerateAndPrintFunction.h"

ICMacroGenerateFunction(int, %d)
ICMacroGenerateFunction(short, %d)
ICMacroGenerateFunction(char, %c)

static
void ICListGeneratedMacroFuntions();

void ICListGeneratedMacroFuntions() {
    output_int(151);
    output_char('c');
    output_short(111);
}

void ICMacroCallGeneratedFunction() {
    CallPrintMacroTest(int, 15);
    CallPrintMacroTest(short, 11);
    CallPrintMacroTest(char, 'g');
}

void ICMacroPrintSizeOfTypes() {
    ICFunctionShowSizeOfTypes(int);
    ICFunctionShowSizeOfTypes(char);
    ICFunctionShowSizeOfTypes(long);
    ICFunctionShowSizeOfTypes(long double);
    ICFunctionShowSizeOfTypes(float);
    ICFunctionShowSizeOfTypes(long long int);
    ICFunctionShowSizeOfTypes(short int);
    ICFunctionShowSizeOfTypes(double);
    ICFunctionShowSizeOfTypes(short);	
}