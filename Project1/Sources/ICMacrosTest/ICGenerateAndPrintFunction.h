//  Created by Admin on 11.04.16.
//
//

#ifndef ICGenerateAndPrintFunction_h
#define ICGenerateAndPrintFunction_h

#define ICFunctionPrintSizeOfType(type) \
    do { \
        type field; \
        printf("The sizeof: " #type " = %lu\n", sizeof(field));  \
    } while(0)

#define ICGeneratePrintValueFunctionWithTypeAndSpecifier(type, specifier) \
    void ICOutput_##type(type value) { \
        printf(#type " value = " #specifier "\n", value); \
    }

#define ICOutputFunctionWithTypeAndValue(type, value) \
    ICOutput_##type(value)

void ICPrintSizeOfTypes();
void ICCallOutputFunction();

#endif /* ICMacrosTest_h */
