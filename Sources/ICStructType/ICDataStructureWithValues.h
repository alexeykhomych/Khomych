//
//  ICDataStructureWithValues.h
//  Homework_lesson1
//
//  Created by Alexey Khomych on 17.04.16.
//
//

#ifndef ICDataStructureWithValues_h
#define ICDataStructureWithValues_h

#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    bool boolValue1;
    bool boolValue2;
    bool boolValue3;
    
    float floatValue1;
    int intValue1;
    
    bool boolValue4;
    bool boolValue5;
    bool boolValue6;
    
    short shortValue3;
    double doubleValue1;
    char *charValue1;
    
    short shortValue2;
    long long longlongValue1;
    short shortValue1;
} ICStructValue;

#endif /* ICDataStructureWithValues_h */

size_t ICGetStructSizeof();
void ICPrintSizeof();
void ICArrangementOfElementsInStructure();
void ICBitFieldOutput(void *address, size_t size);
void ICByteValueOutput(char *address);
void ICByteValueOutputTest();