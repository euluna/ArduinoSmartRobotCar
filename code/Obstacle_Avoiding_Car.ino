#include "CarMovementFunctions.h"

#define enA 3
#define in1 A1
#define in2 A2
#define in3 A3
#define in4 A4
#define enB 11
#define echo 12
#define trig 13

long duration, distance;

// Define the external variables used in CarMovementFunctions.h
int in1 = A1;
int in2 = A2;
int in3 = A3;
int in4 = A4;
int enA = 3;
int enB = 11;

void setup()
{
    Serial.begin(9600);
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(echo, INPUT);
    pinMode(trig, OUTPUT);
}

void loop()
{
    // 1. Send an ultrasonic pulse (Trigger Pin)
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    // 2. Measure the time taken for the echo to return (Echo Pin)
    duration = pulseIn(echo, HIGH);

    // 3. Calculate distance in CM
    // Distance (cm) = Time (us) / (2 * 29.1)
    distance = duration / 58;

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Logic: If object is closer than 20cm, reverse and turn right [cite: 351, 352]
    if (distance < 20)
    {
        // Reverse slightly
        motorReverse();
        analogWrite(enA, 100);
        analogWrite(enB, 100);
        delay(250);

        // Turn right (Motor A Forward, Motor B Reverse)
        motorAForward();
        motorBReverse();
        analogWrite(enA, 100); // Send PWM signal to motor A
        analogWrite(enB, 100); // Send PWM signal to motor B
        delay(100);
    }
    // If distance is > 20cm, move forward
    else
    {
        motorForward();
        analogWrite(enA, 80); // Send PWM signal to motor A
        analogWrite(enB, 80); // Send PWM signal to motor B
    }
}