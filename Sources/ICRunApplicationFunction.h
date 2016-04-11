//
//  ICRunApplicationFunction.h
//  Homework_lesson1
//
//  Created by Admin on 08.04.16.
//
//

#ifndef ICRunApplicationFunction_h
#define ICRunApplicationFunction_h

#include <stdbool.h>

void ICRunApplicationFunction();
int ICDecrement(int param);
int ICIncrement(int param);
int ICPrintIntFold(int value);
void ICPrintCycleFor(int count, int min, int max);
void ICPrintString(char text[]);
void ICPrintIntArray();
void ICBoolPrintMamaPapaIfElse(int value1, int value2);
char *ICCheckBoolReturnString(bool value);
void ICBoolPrintMamaPapa(int value1, int value2);
void ICPrintDoubleNullTerm(char text[]);
void ICDeputyStatus();
void ICEquationPartition();
int ICPostfixIncrement(int postfixIncrementValue);
int ICPrefixIncrement(int prefixIncrementValue);
void ICOutputParamsInt(int value);
void ICOutputParamsDouble(double value);
void ICOutputParamsChar(char chars);
void ICOutputParamsString(char charsArray[]);
void ICOutputParamsBool(bool boolValue);
void ICBoolOperations(int value1, int value2);
bool ICMathematicOperations(int value1, int value2);
void ICPrintStringWithNullTerm(char* chars);

#endif /* ICRunApplicationFunction_h */
