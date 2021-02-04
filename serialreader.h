#ifndef SERIALREADER_H
#define SERIALREADER_H

#include "Arduino.h"

class SerialReader
{
public:
    SerialReader();
    void update();
    int getValue1();
    int getValue2();
private:
    int value1;
    int value2;
    int temp1;
    int temp2;
    bool sign1;
    bool sign2;
    bool readFirstValue;
    bool readM;
};

#endif