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

typedef enum {
    ICBigEndian,
    ICLittleEndian
} ICEndianness;


typedef struct {
    long long longlongValue1;   //8 bytes
    char *charValue1;           //4 or 8 bytes
    float floatValue1;          //4 bytes
    double doubleValue1;        //4 bytes
    int intValue1;              //4 bytes
    short shortValue3;          //2 byte
    short shortValue1;
    short shortValue2;
    
    union {
        struct {
            bool boolValue1 :1;        //1byte
            bool boolValue2 :1;
            bool boolValue3 :1;
            bool boolValue4 :1;
            bool boolValue5 :1;
            bool boolValue6 :1;
        };
        char bitFields;
    }flags;
} ICStructValue;

#endif /* ICDataStructureWithValues_h */

extern
size_t ICGetStructSizeof();

extern
void ICPrintSizeof();

extern
void ICArrangementOfElementsInStructure();

extern
void ICPrintBitField(void *address, size_t size);

extern
void ICPrintByteValue(char *address);

extern
void ICTestPrintByteValue();

extern
ICEndianness ICIdentifyEndianness();
