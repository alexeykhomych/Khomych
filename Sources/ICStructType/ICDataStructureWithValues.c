//
//  ICDataStructureWithValues.c
//  Homework_lesson1
//
//  Created by Alexey Khomych on 17.04.16.
//
//

#include "ICDataStructureWithValues.h"
#

/*Требования:
 - создать тестовый метод, который бы с помощью offsetof выводил расположение каждого из элементов;
 - создать тестовый метод, который бы выводил размер всей структуры;
 - перекомпоновать структуру так, чтобы она занимала наименьшее количество места;
 - поместить bool значения в битовое поле и создать union;
*/

size_t ICGetStructSizeof() {
    return sizeof(ICStructValue);
}

void ICPrintSizeof() {
    printf("sizeof: %lu\n", ICGetStructSizeof());
}

void ICArrangementOfElementsInStructure() {
    ICStructValue ICSValue = {true, true, false, 5.0, 1, false, false, false, 4, 2.5, 'c', 2, 22, 12};
    
    printf("%d\n", offsetof(<#t#>, <#d#>))
}
