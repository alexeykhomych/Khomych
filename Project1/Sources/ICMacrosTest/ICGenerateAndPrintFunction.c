//  Created by Admin on 11.04.16.
//
//
#include <stdio.h>
#include "ICGenerateAndPrintFunction.h"

ICGeneratePrintValueFunctionWithTypeAndSpecifier(int, %d);
ICGeneratePrintValueFunctionWithTypeAndSpecifier(short, %d);
ICGeneratePrintValueFunctionWithTypeAndSpecifier(char, %c);

static
void ICListGeneratedFuntions() {
    ICoutput_int(151);
    ICoutput_char('c');
    ICoutput_short(111);
}

void ICCallOutputFunction() {
    ICOutputFunctionWithTypeAndValue(int, 15);
    ICOutputFunctionWithTypeAndValue(short, 11);
    ICOutputFunctionWithTypeAndValue(char, 'g');
}

void ICPrintSizeOfTypes() {
    ICFunctionPrintSizeOfType(int);
    ICFunctionPrintSizeOfType(char);
    ICFunctionPrintSizeOfType(long);
    ICFunctionPrintSizeOfType(long double);
    ICFunctionPrintSizeOfType(float);
    ICFunctionPrintSizeOfType(long long int);
    ICFunctionPrintSizeOfType(short int);
    ICFunctionPrintSizeOfType(double);
    ICFunctionPrintSizeOfType(short);
}
