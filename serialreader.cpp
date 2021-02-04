#include "serialreader.h"

SerialReader::SerialReader()
{
    value1 = 0;
    value2 = 0;
    temp1 = 0;
    temp2 = 0;
    sign1 = true;
    sign2 = true;
    readFirstValue = false;
    readM = false;
}

void SerialReader::update()
{
    while (Serial.available())
    {
        char i = Serial.read();
        if(i == 'm')
        {
            if(!readM)
                readM = true;
            else
            {
                readM = false;
                value1 = sign1 ? temp1 : -temp1;
                value2 = sign2 ? temp2 : -temp2;
            }
            temp1 = 0;
            temp2 = 0;
            sign1 = true;
            sign2 = true;
            readFirstValue = false;
        }
        else if(i == '-')
        {
            if(readFirstValue)
                sign2 = false;
            else
                sign1 = false;
        }
        else if(i == ';')
        {
            readFirstValue = true;
        }
        else
        {
            if(readFirstValue)
            {
                temp2 *= 10;
                temp2 += i - '0';
            }
            else
            {
                temp1 *= 10;
                temp1 += i - '0';
            }
        }
    }
}

int SerialReader::getValue1()
{
    return value1;
}

int SerialReader::getValue2()
{
    return value2;
}