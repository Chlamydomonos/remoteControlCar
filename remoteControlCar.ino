#include "serialreader.h"
#include "motorcontroller.h"

#define PI 3.1415926536

SerialReader *serialReader;
MotorController *motorController;

void setup()
{
    Serial.begin(115200);
    serialReader = new SerialReader();
    motorController = new MotorController();
}

long value1, value2;

void loop()
{
    serialReader->update();
    motorController->update();
    int temp1 = serialReader->getValue1();
    int temp2 = serialReader->getValue2();
    temp2 = - temp2;
    if(temp1 != value1 || temp2 != value2)
    {
        value1 = temp1;
        value2 = temp2;
        double a = atan2(value2, value1);
        double r = sqrt(value1 * value1 + value2 * value2) / 150;

        double ls, rs;

        if(a < -PI)
        {
            ls = -1;
            rs = 1;
        }
        else if(a < -PI / 2)
        {
            ls = -1;
            rs = -4 / PI * a - 3;
        }
        else if(a < 0)
        {
            ls = 4 / PI * a + 1;
            rs = -1;
        }
        else if(a < PI / 2)
        {
            ls = 1;
            rs = 4 / PI * a - 1;
        }
        else if(a < PI)
        {
            ls = -4 / PI * a + 3;
            rs = 1;
        }
        else
        {
            ls = -1;
            rs = 1;
        }
        int lSpeed = ls * r * 255, rSpeed = rs * r * 255;

        motorController->setLeftMotorAbsoluteSpeed(lSpeed);
        motorController->setRightMotorAbsoluteSpeed(rSpeed);
    }
}
