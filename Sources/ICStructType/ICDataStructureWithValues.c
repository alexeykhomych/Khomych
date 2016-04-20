//
//  ICDataStructureWithValues.c
//  Homework_lesson1
//
//  Created by Alexey Khomych on 17.04.16.
//
//
#include <stdio.h>

#include "ICDataStructureWithValues.h"

static const uint8_t kICBitCount = 8;
ICEndianness endianness;

void ICTurnBytes(bool flag, char *address, size_t size) {
    if(flag) {
        char bytes[size];
        uint8_t value = *address;
//        for (uint8_t j = 0; j < kICBitCount; j++) {
//            uint8_t shiftedValue = value >> (kICBitCount - j - 1);
//            printf("%d", (shiftedValue & 1));
//        }
    }
}

size_t ICGetStructSizeof() {
    return sizeof(ICStructValue);
}

void ICPrintSizeof() {
    printf("sizeof: %lu\n", ICGetStructSizeof());
}

void ICTestPrintByteValue() {
    int value = 5;
    printf("int value = %d\n", value);
    ICPrintBitField(&value, sizeof(value));
    puts("");
}

void ICPrintBitField(void *address, size_t size) {
    endianness = ICIdentifyEndianness();
    
    switch (endianness) {
        case ICBigEndian:
            for (size_t i = 0; i < size; i++) {
                char byte = ((char *) address)[i];
                ICPrintByteValue(&byte);
                printf(" ");
            }
            
            break;
            
        case ICLittleEndian:
            for (size_t i = 0; i < size; i++) {
                char byte = ((char *) address)[size - i - 1];
                ICPrintByteValue(&byte);
                printf(" ");
            }
        default:
            break;
    }
}

void ICPrintByteValue(char *address) {
    uint8_t value = *address;
    for (uint8_t j = 0; j < kICBitCount; j++) {
        uint8_t shiftedValue = value >> (kICBitCount - j - 1);
        printf("%d", (shiftedValue & 1));
    }
}

ICEndianness ICIdentifyEndianness() {
    unsigned short value = 1;
    return *((unsigned char *)&value) == 0 ? 0 : 1;
}

void ICArrangementOfElementsInStructure() {
//    ICStructValue value;
//
//    printf("[0]%lu\n"
//           "[1]%lu\n"
//           "[2]%lu\n"
//           "[3]%lu\n"
//           "[4]%lu\n"
//           "[5]%lu\n"
//           "[6]%lu\n"
//           "[7]%lu\n"
//           "[8]%lu\n"
//           "[9]%lu\n"
//           "[10]%lu\n"
//           "[11]%lu\n"
//           "[12]%lu\n"
//           "[13]%lu\n\n",
//           offsetof(ICStructValue, value.flags.boolValue1),
//           offsetof(ICStructValue, value.flags.boolValue2),
//           offsetof(ICStructValue, value.flags.boolValue3),
//           offsetof(ICStructValue, value.floatValue1),
//           offsetof(ICStructValue, value.intValue1),
//           offsetof(ICStructValue, value.flags.boolValue6),
//           offsetof(ICStructValue, value.flags.boolValue4),
//           offsetof(ICStructValue, value.flags.boolValue5),
//           offsetof(ICStructValue, value.shortValue3),
//           offsetof(ICStructValue, value.doubleValue1),
//           offsetof(ICStructValue, value.charValue1),
//           offsetof(ICStructValue, value.shortValue2),
//           offsetof(ICStructValue, value.longlongValue1),
//           offsetof(ICStructValue, value.shortValue1));
}
