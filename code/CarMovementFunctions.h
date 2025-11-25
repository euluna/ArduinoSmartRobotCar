// CarMovementFunctions.h

#ifndef CAR_MOVEMENT_FUNCTIONS_H
#define CAR_MOVEMENT_FUNCTIONS_H

// This line resolves the "squiggly lines" by including the core Arduino function definitions (digitalWrite, analogWrite, etc.)
#include <Arduino.h>

// Declare motor pin variables as external, defined in each .ino file.
extern int in1, in2, in3, in4;
extern int enA, enB;

// Use 'inline' for all functions defined in the header to prevent multiple definition errors.
inline void motorAForward()
{
    // Set Motor A Forward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
}

inline void motorBForward()
{
    // Set Motor B Forward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

inline void motorAReverse()
{
    // Set Motor A Reverse
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
}

inline void motorBReverse()
{
    // Set Motor B Reverse
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}

inline void motorForward()
{
    // Set Motor Forward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

inline void motorReverse()
{
    // Set Motor Reverse
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}

inline void motorSetSpeed(int motorSpeed)
{
    // Set Motor Speed
    analogWrite(enA, motorSpeed); // Send PWM signal to motor A
    analogWrite(enB, motorSpeed); // Send PWM signal to motor B
}

inline void motorStop()
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