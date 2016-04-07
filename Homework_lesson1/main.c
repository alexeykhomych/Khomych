#include <stdio.h>

#include "ICPrinting.h"
#include "PrintNumbers.h"

void PrintDouble(double result) {
    printf("double = %f\n", result);
}

void PrintChar(char result) {
    printf("char = %c\n", result);
}

void PrintInt(int result) {
    printf("int = %d\n", result);
}

void ICIncrement(int param) {
    param++;
}

void ICDecrement(int param) {
    param--;
}


int main(int argc, const char * argv[]) {
    //    ICPrint();
    //    ICPrintParents();
    //    PrintNumbers();
    //    PrintNumbersBack();
    
    /* Lection 4-5 */
    
    /* task 5 */
//    double doubleResult = 3.0;
//    
//    double first = doubleResult * doubleResult;
//    first = first / 4;
//    first = (int)first % 7;
//    
//    double second = 4.0 * doubleResult;
//    second = second - 1.5;
//    second = second + 'A';
//    
//    first = first + second;
//    
//    PrintDouble(first);
    
    /* task 6 */
    
//    int first = 5 / 2.5;
//    PrintInt(first);
//    
//    int second = 2.5 * 5;
//    PrintInt(second);
//    
//    int third = 5 / 3;
//    PrintInt(third);
//    
//    int fourth = 13 % 3;
//    PrintInt(fourth);
//    
//    short fifth = 2.5 + first;
//    PrintInt(fifth);
    
    /* task 7 */
    
//    int i;
//    short s;
//    char c;
//    double d;
//    float f;
//    
//    printf("%d\n%d\n%c\n%f\n%f\n", i, s, c, d, f);
    
    /* task 8 */
    int i = 5;
    printf("%d\n", --i);
    printf("%d\n", ++i);
    
    return 0;
}
