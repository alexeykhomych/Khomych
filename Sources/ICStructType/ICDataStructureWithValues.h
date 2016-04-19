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

//typedef struct {
//    long long longlongValue1; //8 bytes
//    float floatValue1;        //4 bytes
//    short shortValue3;        //2 byte
//    bool boolValue1;          //1 byte
//    
//    double doubleValue1;      //4 bytes
//    short shortValue2;
//    bool boolValue4;
//    
//    char *charValue1;         //4 bytes
//    bool boolValue2;
//    bool boolValue3;
//    bool boolValue5;
//
//    int intValue1;            //4 bytes
//    short shortValue1;
//    bool boolValue6;
//} ICStructValue;


typedef struct {
    long long longlongValue1;   //8 bytes
    float floatValue1;          //4 bytes
    short shortValue3;          //2 byte
    
    double doubleValue1;        //4 bytes
    short shortValue1;
    
    char *charValue1;           //4 or 8 bytes
    short shortValue2;
    
    int intValue1;              //4 bytes
    
    union {
        struct {
            bool boolValue1 :1;        //1byte
            bool boolValue2 :1;
            bool boolValue3 :1;
            bool boolValue4 :1;
            bool boolValue5 :1;
            bool boolValue6 :1;
        };
    }ICFlugs;
    char bitFields;
    
} ICStructValue;

#endif /* ICDataStructureWithValues_h */

size_t ICGetStructSizeof();
void ICPrintSizeof();
void ICArrangementOfElementsInStructure();
void ICBitFieldOutput(void *address, size_t size);
void ICByteValueOutput(char *address);
void ICByteValueOutputTest();