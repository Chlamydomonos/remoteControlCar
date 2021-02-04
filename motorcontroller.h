#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include "arduino.h"

#define LEFT_MOTOR_DIRECTION 8
#define LEFT_MOTOR_SPEED 9
#define RIGHT_MOTOR_DIRECTION 11
#define RIGHT_MOTOR_SPEED 10

enum Direction
{
    FRONT,
    BACK
};

class MotorController
{
public:
    MotorController();
    void update();
    void setLeftMotorDirection(Direction direction);
    void setRightMotorDirection(Direction direction);
    void setLeftMotorSpeed(unsigned char speed);
    void setRightMotorSpeed(unsigned char speed);
    void setLeftMotorAbsoluteSpeed(short speed);
    void setRightMotorAbsoluteSpeed(short speed);
private:
    bool leftMotorDirection;
    bool rightMotorDirection;
    unsigned char leftMotorSpeed;
    unsigned char rightMotorSpeed;
};

#endif