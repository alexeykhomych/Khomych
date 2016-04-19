//
//  ICRunApplicationTask5.c
//  Homework_lesson1
//
//  Created by Admin on 12.04.16.
//
//

#include <stdio.h>
#include <string.h>

#include "ICRunApplication.h"

void ICRunApplicationTask5() {
    /* ex. 1 */
    ICBoolOperations(50, 70);
    
    /* ex. 2 */
    char *text = ICStringWithBool(true);
    puts(text);
    
    /* ex. 3 */
    ICMathematicOperations(50, 25);
    
    /* ex. 4 */
    ICBoolPrintMamaPapa(5, 2); //print Mama
    
    /* ex. 5 */
    ICBoolPrintMamaPapaIfElse(10, 50); //print Papa
    
    /* ex. 8 */
    ICCheckDeputyStatus(1500, 12524125);
    
    /* ex. 9-10 */
    ICPrintIntArray();
    
    /* ex. 12 */
    ICPrintString("text\0");
    
    /* ex. 13 */
    char* chars = "it's a null \0term string ";
    unsigned long strLength = strlen(chars) + 1;
//    ICPrintStringWithNullTerm(chars);
    ICPrintStringWithLength(chars, strLength);
    
    /* ex. 16 */
    ICPrintDoubleNullTerm("wsad \0sadxcz \0");
    
    /* ex. 17 */
    int array1[4] = {0, 5, 3};
    int lastElementNumber = sizeof(array1) / sizeof(*array1) - 1;
    
    /* ex. 18 */
    ICPrintCycleFor(10, 5, 10);
    
    /* ex. 19 */
    ICPrintMapaPapaTypes();
}
