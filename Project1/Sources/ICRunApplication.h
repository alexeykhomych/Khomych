//
//  ICRunApplication.h
//  Homework_lesson1
//
//  Created by Admin on 08.04.16.
//
//

#ifndef ICRunApplication_h
#define ICRunApplication_h

#include <stdbool.h>
#include <stdio.h>

typedef enum {
    ICDeputyStatusAngel,
    ICDeputyStatusDead,
    ICDeputyStatusThief,
    ICDeputyStatusHonest,
    ICDeputyStatusNull
} ICDeputyStatus;

typedef enum {
    ICPrintTypeNothing,
    ICPrintTypeMama,
    ICPrintTypePapa,
    ICPrintTypeMamaPapa
}ICPrintType;

int ICPrintTypeWithInt(int value);
void ICPrintCycleFor(int count, int min, int max);
void ICPrintString(const char *text);
void ICPrintIntArray();
void ICListIntArrays(int iterator);
void ICBoolPrintMamaPapaIfElse(int value1, int value2);
void ICPrintDoubleNullTerm(char text[]);
void ICPrintStringWithLength(const char* text, size_t length);
void ICBoolPrintMamaPapa(int value1, int value2);
void ICPrintStringWithNullTerm(char* chars);
void ICPrintMapaPapaTypes();

void ICOutputParamsInt(int value);
void ICOutputParamsDouble(double value);
void ICOutputParamsChar(char chars);
void ICOutputParamsString(char charsArray[]);
void ICOutputParamsBool(bool boolValue);

int ICDecrement(int param);
int ICIncrement(int param);
char *ICStringWithBool(bool value);
void ICBoolOperations(int value1, int value2);
bool ICMathematicOperations(int value1, int value2);

void ICCheckDeputyStatus(int salary, int allMoney);
void ICPrintDeputyStatus(ICDeputyStatus status);
void ICEquationPartition();
int ICPostfixIncrement(int postfixIncrementValue);
int ICPrefixIncrement(int prefixIncrementValue);

void ICRunApplication();
void ICRunApplicationTask3();
void ICRunApplicationTask4();
void ICRunApplicationTask5();

#endif /* ICRunApplication_h */
