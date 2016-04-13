//
//  ICMacrosTest.h
//  Homework_lesson1
//
//  Created by Admin on 11.04.16.
//
//

#ifndef ICMacrosTest_h
#define ICMacrosTest_h

#define CallPrintMacroTest(type, specifier) \
ICMacroGenerateFunction(type, specifier)

#define ICMacroGenerateFunction(type, specifier) \
    void output_##type(type specifier) { \
        printf("hi123"); \
}

#define ICFunctionShowSizeOfTypes(type) \
    do { \
        printf("The sizeof: " #type " = %d\n", sizeof(type));  \
    } while(0)

void ICMacroOutputGeneratedFunction();
void ICMacroPrintSizeOfTypes();

#endif /* ICMacrosTest_h */
