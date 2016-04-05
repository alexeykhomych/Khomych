//#include "ICPrint.h"
#include <stdio.h>
void ICPrint1();
void ICPrintParents();

int main(int argc, const char * argv[]) {
    // insert code here...
//    ICPrint();
    ICPrintParents();
    return 0;
}

//print text in cmd
void ICPrint1(){
    printf("Hello, mama\n");
}
void ICPrintParents(){
    ICPrint1();
    printf("Hello, papa!\n");
}