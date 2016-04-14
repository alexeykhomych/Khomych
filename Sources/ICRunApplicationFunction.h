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

typedef enum {
    ICDeputyStatusAngel,
    ICDeputyStatusDead,
    ICDeputyStatusThief,
    ICDeputyStatusHonest,
} ICDeputyEntity;

typedef enum {
    ICPrintTypeNothing,
    ICPrintTypeMama,
    ICPrintTypePapa,
    ICPrintTypeMamaPapa
}ICPrintType;

int ICPrintTypeWithInt(int value);
void ICPrintCycleFor(int count, int min, int max);
void ICPrintString(char text[]);
void ICPrintIntArray();
void ICListIntArrays(int iterator);
void ICBoolPrintMamaPapaIfElse(int value1, int value2);
void ICPrintDoubleNullTerm(char text[]);
void ICPrintNonNullTermString(char text[], int length);
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
char *ICCheckBoolReturnString(bool value);
void ICBoolOperations(int value1, int value2);
bool ICMathematicOperations(int value1, int value2);

void ICCheckDeputyStatus();
void ICPrintDeputyStatus(ICDeputyEntity entity);
void ICEquationPartition();
int ICPostfixIncrement(int postfixIncrementValue);
int ICPrefixIncrement(int prefixIncrementValue);

void ICRunApplicationFunction();
void ICRunApplicationTask3();
void ICRunApplicationTask4();
void ICRunApplicationTask5();

#endif /* ICRunApplicationFunction_h */
