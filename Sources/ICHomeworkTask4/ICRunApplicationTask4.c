//
//  ICRunApplicationTask4.c
//  Homework_lesson1
//
//  Created by Admin on 12.04.16.
//
//

#include <stdio.h>
#include <limits.h>

#include "ICRunApplication.h"

void ICRunApplicationTask4() {
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

}
