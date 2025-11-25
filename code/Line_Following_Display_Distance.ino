#include <LiquidCrystal.h>
#include <TimerOne.h>
#include "CarMovementFunctions.h"

// LCD Pin Definitions
#define pin_RS 8
#define pin_EN 9
#define pin_d4 4
#define pin_d5 5
#define pin_d6 6
#define pin_d7 7
#define pin_BL 10
LiquidCrystal lcd(pin_RS, pin_EN, pin_d4, pin_d5, pin_d6, pin_d7);

// Motor and Sensor Pin Definitions
#define enA 3
#define in1 A1
#define in2 A2
#define in3 A3
#define in4 A4
#define enB 11
#define sensorA 12 // Left IR Sensor
#define sensorB 13 // Right IR Sensor
#define encoder 2  // Encoder connected to Interrupt Pin 0 (D2)

// Constants for Distance Calculation
#define pi 3.142
#define diskSlots 20.00 // Number of slots in encoder disk
#define diameter 6.40   // Wheel diameter in cm

volatile int counter = 0;

// Define the external variables used in CarMovementFunctions.h
int in1 = A1;
int in2 = A2;
int in3 = A3;
int in4 = A4;
int enA = 3;
int enB = 11;

// Function to calculate distance in CM
int distanceInCM(int currentCounter)
{
    float result;
    float circumference = diameter * pi;

    // Calculated distance traveled per slot (CMPerSlot)
    float CMPerSlot = circumference / diskSlots;

    // Correction factor (as per report analysis)
    // for unknown reasons, when tested, 1 rotation adds 80 to counter. to correct for this error, result is divided by 4 below.
    CMPerSlot = CMPerSlot / 4.00;

    float f_result = currentCounter * CMPerSlot;
    result = (int)f_result; // Rounded down
    return result;
}

// ISR for Timer1: updates the distance display on the LCD
void ISR_timer()
{
    Timer1.detachInterrupt();
    lcd.setCursor(0, 1);
    int distance = distanceInCM(counter);
    lcd.print(distance);
    lcd.setCursor(4, 1);
    lcd.print("CM");
    Timer1.attachInterrupt(ISR_timer);
}

// ISR for Encoder: increments the step counter on RISING edge
void ISR_count()
{
    counter++;
}

void setup()
{
    Serial.begin(9600);
    // Initialize Timer1 for interrupt every 1 second (1,000,000 microseconds)
    Timer1.initialize(1000000);

    // Attach interrupt to encoder pin on RISING edge
    attachInterrupt(digitalPinToInterrupt(encoder), ISR_count, RISING);
    Timer1.attachInterrupt(ISR_timer);

    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(sensorA, INPUT);
    pinMode(sensorB, INPUT);

    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("Distance:");
}

void loop()
{
    Serial.println(digitalRead(sensorA));
    Serial.println(digitalRead(sensorB));

    // L=0, R=0 -> Forward
    if (digitalRead(sensorA) == LOW && digitalRead(sensorB) == LOW)
    {
        motorForward();
        analogWrite(enA, 70); // Send PWM signal to motor A
        analogWrite(enB, 70); // Send PWM signal to motor B
    }
    // L=1, R=0 -> Turn left (Reverse one wheel)
    else if (digitalRead(sensorA) == HIGH && digitalRead(sensorB) == LOW)
    {
        motorAReverse();
        motorBForward();
        analogWrite(enA, 70); // Send PWM signal to motor A
        analogWrite(enB, 80); // Send PWM signal to motor B
    }
    // L=0, R=1 -> Turn right (Reverse one wheel)
    else if (digitalRead(sensorA) == LOW && digitalRead(sensorB) == HIGH)
    {
        motorAForward();
        motorBReverse();
        analogWrite(enA, 80); // Send PWM signal to motor A
        analogWrite(enB, 70); // Send PWM signal to motor B
    }
    // L=1, R=1 -> Stop
    else if (digitalRead(sensorA) == HIGH && digitalRead(sensorB) == HIGH)
    {
        motorStop();
        // motorForward();
        // motorSetSpeed(100);
        // delay(200);
    }
}