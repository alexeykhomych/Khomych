//
//  ICRunApplicationFunction.c
//  Homework_lesson1
//
//  Created by Admin on 08.04.16.
//
//
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#include "ICRunApplicationFunction.h"

void ICRunApplicationFunction() {

    
    //    ICPrint();
    //    ICPrintParents();
    //    PrintNumbers();
    //    PrintNumbersBack();

    /* TASK 4 */
    int intValue;
    double doubleValue;
    
    /* ex. 3 */
    char charArray[] = {'h', 'e', 'l', 'l', 'o'};
    
    ICOutputParamsInt(50);
    ICOutputParamsDouble(20.55);
    ICOutputParamsChar('q');
    ICOutputParamsString(charArray);
    ICOutputParamsBool(true);
    
    /* ex. 4 */
    intValue = ICDecrement(5);
    printf("%d", intValue);
    
    intValue = ICIncrement(10);
    printf("%d", intValue);
    
    /* ex. 5 */
    ICEquationPartition();
    
    /* ex. 6 */
    doubleValue = 5.5;
    short shortValue = 5.5;
    printf("%f\n", 5 / 2.5);
    printf("%f\n", 5.2 * 5);
    printf("%d\n", 5 / 3);
    printf("%d\n", 5 % 2);
    printf("%d\n", shortValue / 2);
    intValue = LONG_MAX;
    printf("%d\n", intValue);
    
    /* ex. 7 */
    int intEmpty1, intEmpty2;
    bool boolEmpty1, boolEmpty2;
    char charEmpty1, charEmpty2;
    short shortEmpty1, shortEmpty2;
    long longEmpty1, longEmpty2;
    
    printf("%d %d %c %c %c %c %d %d %ld %ld",
           intEmpty1,
           intEmpty2,
           boolEmpty1,
           boolEmpty2,
           charEmpty1,
           charEmpty2,
           shortEmpty1,
           shortEmpty2,
           longEmpty1,
           longEmpty2);
    
    /* ex. 8 */
    intValue = ICPostfixIncrement(50);
    printf("%d", intValue);
    
    intValue = ICPrefixIncrement(25);
    printf("%d", intValue);
    /* END TASK 4 */
    
    /* TASK 5 */
    
    /* ex. 1 */
    ICBoolOperations(50, 70);
    
    /* ex. 2 */
    char *text = ICCheckBoolReturnString(true);	
    puts(text);
    
    /* ex. 3 */
    ICMathematicOperations(50, 25);
    
    /* ex. 4 */
    ICBoolPrintMamaPapa(5, 2); //print Mama
    
    /* ex. 5 */
    ICBoolPrintMamaPapaIfElse(10, 50); //print Papa
    
    /* ex. 8 */
    ICDeputyStatus(200, 20000);
    
    /* ex. 9-10 */
    ICPrintIntArray();
    
    /* ex. 12 */
    ICPrintString("text\0");
    
    /* ex. 13 */
    char* chars = "null term string";
    ICPrintStringWithNullTerm(chars);
    
    /* ex. 16 */
    ICPrintDoubleNullTerm("wsad\0sadxcz\0");
    
    /* ex. 17 */
    int array1[4] = {0, 5, 3};
    int lastElementNumber = sizeof(array1) / sizeof(*array1) - 1;
    
    /* ex. 18 */
    ICPrintCycleFor(10, 5, 10);
    ICPrintCycleDoWhile(21, 15, 50);
    
    /* ex. 19 */
    int status = ICPrintIntFold(25);

    
    /* END TASK 5 */
}
