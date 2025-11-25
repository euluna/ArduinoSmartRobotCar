#include "CarMovementFunctions.h"

#define enA 85
#define in1 A1
#define in2 A2
#define in3 A3
#define in4 A4
#define enB 85

char command;

// Define the external variables used in CarMovementFunctions.h
int in1 = A1;
int in2 = A2;
int in3 = A3;
int in4 = A4;
int enA = 3;  // The original code uses analogWrite(enA, 85) but the define is 3
int enB = 11; // The original code uses analogWrite(enB, 85) but the define is 11

void setup()
{
    Serial.begin(9600);
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);

    // Set default speed
    analogWrite(enA, 85); // Send PWM signal to motor A
    analogWrite(enB, 85); // Send PWM signal to motor B
}

void loop()
{
    // Check if data is available from the Bluetooth module (Serial)
    if (Serial.available() > 0)
    {
        command = Serial.read();
        Serial.println(command);
    }

    // Use a switch case statement for motor control based on the command
    switch (command)
    {
    case 'F': // Forward
        motorForward();
        break;
    case 'B': // Backward
        motorReverse();
        break;
    case 'L': // Turn Left (Motor A Reverse, Motor B Forward)
        motorAReverse();
        motorBForward();
        break;
    case 'R': // Turn Right (Motor A Forward, Motor B Reverse)
        motorAForward();
        motorBReverse();
        break;
    case 'I':
    case 'T':
        motorForward();
        /
            // Set Motor A Forward, Motor B Reverse (which is turning right)
            motorAForward();
        motorBReverse();
        break;
    case 'G': // Forward Left (Motor A Reverse, Motor B Forward)
        motorAReverse();
        motorBForward();
        break;
    case 'J': // Backward Right (Motor A Forward, Motor B Reverse)
        motorAForward();
        motorBReverse();
        break;
    case 'H': // Backward Left (Motor A Reverse, Motor B Forward)
        motorAReverse();
        motorBForward();
        break;
    case 'S': // Stop
        motorStop();
        break;
    default:
        break;
    }
}