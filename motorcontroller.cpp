#include "motorcontroller.h"

MotorController::MotorController()
{
    pinMode(LEFT_MOTOR_DIRECTION, OUTPUT);
    pinMode(RIGHT_MOTOR_DIRECTION, OUTPUT);
    pinMode(LEFT_MOTOR_SPEED, OUTPUT);
    pinMode(RIGHT_MOTOR_SPEED, OUTPUT);
    leftMotorDirection = 0;
    rightMotorDirection = 0;
    leftMotorSpeed = 0;
    rightMotorSpeed = 0;
}

void MotorController::setLeftMotorDirection(Direction direction)
{
    if(direction == Direction::FRONT)
        leftMotorDirection = 0;
    else
        leftMotorDirection = 1;
}

void MotorController::setRightMotorDirection(Direction direction)
{
    if(direction == Direction::FRONT)
        rightMotorDirection = 0;
    else
        rightMotorDirection = 1;
}

void MotorController::setLeftMotorSpeed(unsigned char speed)
{
    leftMotorSpeed = speed;
}

void MotorController::setRightMotorSpeed(unsigned char speed)
{
    rightMotorSpeed = speed;
}

void MotorController::setLeftMotorAbsoluteSpeed(short speed)
{
    bool sign = speed > 0;
    speed = speed > 0 ? speed : -speed;
    setLeftMotorDirection(sign ? Direction::FRONT : Direction::BACK);
    setLeftMotorSpeed(speed);
}

void MotorController::setRightMotorAbsoluteSpeed(short speed)
{
    bool sign = speed > 0;
    speed = speed > 0 ? speed : -speed;
    setRightMotorDirection(sign ? Direction::FRONT : Direction::BACK);
    setRightMotorSpeed(speed);
}

void MotorController::update()
{
    digitalWrite(LEFT_MOTOR_DIRECTION, leftMotorDirection);
    digitalWrite(RIGHT_MOTOR_DIRECTION, rightMotorDirection);
    analogWrite(LEFT_MOTOR_SPEED, leftMotorSpeed);
    analogWrite(RIGHT_MOTOR_SPEED, rightMotorSpeed);
}