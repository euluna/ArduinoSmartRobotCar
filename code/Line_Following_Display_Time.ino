#include <LiquidCrystal.h>
#include "CarMovementFunctions.h"

// LCD Pin Definitions
#define pin_RS 8
#define pin_EN 9
#define pin_d4 4
#define pin_d5 5
#define pin_d6 6
#define pin_d7 7
#define pin_BL 10

// Motor and Sensor Pin Definitions
#define enA 3
#define in1 A1
#define in2 A2
#define in3 A3
#define in4 A4
#define enB 11
#define sensorA 12 // Left Sensor
#define sensorB 2  // Right Sensor

LiquidCrystal lcd(pin_RS, pin_EN, pin_d4, pin_d5, pin_d6, pin_d7);
float time1;

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
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("Timer:");

    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(sensorA, INPUT);
    pinMode(sensorB, INPUT);
}

void loop()
{
    Serial.println(digitalRead(sensorA));
    Serial.println(digitalRead(sensorB));

    // L=0 (White), R=0 (White) -> Forward
    if (digitalRead(sensorA) == LOW && digitalRead(sensorB) == LOW)
    {
        motorForward();
        analogWrite(enA, 60); // Send PWM signal to motor A
        analogWrite(enB, 60); // Send PWM signal to motor B
    }
    // L=1 (Black), R=0 (White) -> Turn left
    else if (digitalRead(sensorA) == HIGH && digitalRead(sensorB) == LOW)
    {
        // Turn left
        motorAReverse();
        motorBForward();
        analogWrite(enA, 72); // Send PWM signal to motor A
        analogWrite(enB, 87); // Send PWM signal to motor B
    }
    // L=0 (White), R=1 (Black) -> Turn right
    else if (digitalRead(sensorA) == LOW && digitalRead(sensorB) == HIGH)
    {
        // Turn right
        motorAForward();
        motorBReverse();
        analogWrite(enA, 72); // Send PWM signal to motor A
        analogWrite(enB, 87); // Send PWM signal to motor B
    }
    // L=1 (Black), R=1 (Black) -> Stop and Freeze LCD
    else if (digitalRead(sensorA) == HIGH && digitalRead(sensorB) == HIGH)
    {
        motorStop();
        exit(0);
    }

    lcd.setCursor(0, 1);
    time1 = (float)millis() / 1000.0;
    lcd.print(int(time1));
    lcd.setCursor(3, 1);
    lcd.print("Seconds");
}