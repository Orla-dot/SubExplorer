#include "dataManipulator.h"



template<typename T>
String dataRoller(T data) {
    // beging main variable
    int size = sizeof(data); // number of bytes
    Srting segment = "";     // return variable


    // inf the type is like a float
    if (size > 4) {data *= 1E5}

    // packeting in main spool
    for (int i = 0; i < size; i++) { 
        // convert and add byte per byte from end to begin
        segment += char(((unsigned long)(realData) >> 8 * (size - (i+1))) & 0xFF);
    }

    return segment;
}

template<typename T>
void  daraSolidifier(String* roll,T* var) {
    // beging bariables 
    int size = sizeOf(*var); // number of bytes
    String cutLine = *roll;  // copy of the line
    T pack = 0; // copy of the storager variable

    // loop of size
    for ( int i = 0; i < size; i++) {
        pack <<= 8;         // add a byte on the empty value
        pack |= cutline[i]; // add the char in this byte opened
    }
    
    // ending with the line
    cutLine.remove(0, size); // remuve the used part
    *roll = cutLine; // retorning to the original line

    *var = pack; // pass for the variable
}