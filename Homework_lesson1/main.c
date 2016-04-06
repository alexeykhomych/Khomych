#include <stdio.h>

#include "ICPrinting.h"
#include "PrintNumbers.h"

int main(int argc, const char * argv[]) {
    ICPrint();
    ICPrintParents();
    PrintNumbers();
    PrintNumbersBack();
    
    return 0;
}
