// CarMovementFunctions.h

#ifndef CAR_MOVEMENT_FUNCTIONS_H
#define CAR_MOVEMENT_FUNCTIONS_H

extern int in1, in2, in3, in4; // External declaration for motor control pins
extern int enA, enB;           // External declaration for PWM pins

void motorAForward()
{
    // Set Motor A Forward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
}

void motorBForward()
{
    // Set Motor B Forward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

void motorAReverse()
{
    // Set Motor A Reverse
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
}

void motorBReverse()
{
    // Set Motor B Reverse
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}

void motorForward()
{
    // Set Motor Forward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

void motorReverse()
{
    // Set Motor Reverse
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}

void motorSetSpeed(int motorSpeed)
{
    // Set Motor Speed
    analogWrite(enA, motorSpeed); // Send PWM signal to motor A
    analogWrite(enB, motorSpeed); // Send PWM signal to motor B
}

void motorStop()
{
    // Set Motor Stop
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(enA, 0);
    analogWrite(enB, 0);
}

#endif