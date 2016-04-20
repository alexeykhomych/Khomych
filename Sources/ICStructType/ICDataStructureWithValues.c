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

size_t ICGetStructSizeof() {
    return sizeof(ICStructValue);
}

void ICPrintSizeof() {
    printf("sizeof: %lu\n", ICGetStructSizeof());
}

void ICArrangementOfElementsInStructure() {
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
//           offsetof(ICStructValue, boolValue1),
//           offsetof(ICStructValue, boolValue2),
//           offsetof(ICStructValue, boolValue3),
//           offsetof(ICStructValue, floatValue1),
//           offsetof(ICStructValue, intValue1),
//           offsetof(ICStructValue, boolValue4),
//           offsetof(ICStructValue, boolValue5),
//           offsetof(ICStructValue, boolValue6),
//           offsetof(ICStructValue, shortValue3),
//           offsetof(ICStructValue, doubleValue1),
//           offsetof(ICStructValue, charValue1),
//           offsetof(ICStructValue, shortValue2),
//           offsetof(ICStructValue, longlongValue1),
//           offsetof(ICStructValue, shortValue1));
}

void ICTestPrintByteValue() {
    int value = 5;
    printf("int value = %d\n", value);
    ICPrintBitField(&value, sizeof(value)); //передаю ссылку на адрес в памяти + кол-во байт (инт = 4)
    puts("");
}

void ICPrintBitField(void *address, size_t size) {
    endianness = ICIdentifyEndianness();
    
    switch (endianness) {
        case ICBigEndian:
            for (uint16_t i = 0; i < size; i++) {
                char byte = ((char *) address)[i]; //получаю последний элемент, биг-эндиан
                ICPrintByteValue(&byte);
                printf(" ");
            }
            
            break;
            
        case ICLittleEndian:
            for (uint16_t i = 0; i < size; i++) {
                char byte = ((char *) address)[size - i - 1]; //получаю последний элемент, биг-эндиан
                ICPrintByteValue(&byte);
                printf(" ");
            }
            
        default:
            break;
    }
}

void ICPrintByteValue(char *address) {
    uint8_t value = *address; //получаю значение с адреса памяти
    for (uint8_t j = 0; j < kICBitCount; j++) {
        uint8_t shiftedValue = value >> (kICBitCount - j - 1); //сдвиг вправо на кол-во элементов - дж
        printf("%d", (shiftedValue & 1)); //побитовый вывод
    }
}

ICEndianness ICIdentifyEndianness() {
    unsigned short value = 1;
    return *((unsigned char *)&value) == 0 ? 0 : 1;
}
