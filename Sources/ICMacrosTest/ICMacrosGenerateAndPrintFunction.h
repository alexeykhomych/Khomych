//  Created by Admin on 11.04.16.
//
//

#ifndef ICMacrosGenerateAndPrintFunction_h
#define ICMacrosGenerateAndPrintFunction_h

#define ICFunctionShowSizeOfTypes(type) \
    do { \
        printf("The sizeof: " #type " = %d\n", sizeof(type));  \
    } while(0)

#define ICMacroGenerateFunction(type, specifier) \
void output_##type(type value) { \
printf(#type " value = " #specifier "\n", value); \
}

#define CallPrintMacroTest(type, value) \
output_##type(value)



void ICMacroPrintSizeOfTypes();
void ICMacroCallGeneratedFunction();




#endif /* ICMacrosTest_h */
