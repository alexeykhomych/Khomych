//
//  ICMacrosTest.h
//  Homework_lesson1
//
//  Created by Admin on 11.04.16.
//
//

#ifndef ICMacrosTest_h
#define ICMacrosTest_h

#define ICMacrosCreatFunction(type, specifier) \
    void output_##type() { \
        printf(#type " - " #specifier); \
    }

#endif /* ICMacrosTest_h */
