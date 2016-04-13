//
//  ICMacrosTest.h
//  Homework_lesson1
//
//  Created by Admin on 11.04.16.
//
//

#ifndef ICMacrosTest_h
#define ICMacrosTest_h

#define CallPrintMacroTest(type) \
do { \
printf("The sizeof : " #type " = %d\n", sizeof(type));  \
} \
while(0)

#define ICMacrosGenerateFunction(type, specifier)\
void output_##type(type value) {\
printf(#type " - " #specifier, value);\
}

#define ICFunctionShowSizeOfTypes(type, qualifier) \
do { \
printf("The sizeof : " #type " = %d\n", sizeof(type));  \
} \
while(0)


void testfunc();

#endif /* ICMacrosTest_h */
