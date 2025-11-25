# Arduino Smart Robot Car Project (EEEE1027/EEEE1031)

This repository contains the Arduino code and documentation for the Smart Robot Car project, focusing on fundamental electronic and programming concepts realized using the **Arduino Uno** platform.

**Project Date:** December 2020
**Student:** Euluna Gotami
**Student ID:** 20113429
**Course:** Electrical and Electronic Engineering

---

## Core Hardware and Fabrication Highlights

The robot car is structurally built on an acrylic frame, powered by a 7.4V Li-Po battery. The **Arduino Uno (ATmega328)** serves as the control unit, interfacing with all sensors and motors via an **L298N Motor Driver**.

### Custom Fabrication: The DIY IR Sensor

A key component of this project was the fabrication of a custom infrared sensor module.

* The sensor was built using discrete components including an **LM358 Dual Op-Amp**, a **Photodiode**, an IR LED, and various resistors.
* The circuit was transferred from a breadboard to a permanent **stripboard**. This process, which involved soldering, resulted in a compact and durable comparator circuit capable of outputting a digital signal for line detection.

![DIY IR Sensor on stripboard](euluna/arduinolinefollowingrobot/ArduinoLineFollowingRobot-86600c9f11186cd15d528e74023328f976165953/imgs/DIY IR Sensor.png)

### Component Overview

| Component | Functionality |
| :--- | :--- |
| **Microcontroller** | Arduino Uno (ATmega328) |
| **Motor Driver** | L298N Module |
| **Line Sensors** | 2 x IR Sensor Modules (for primary line tracking) |
| **DIY IR Sensor** | Custom comparator circuit (LM358 + Photodiode) |
| **Distance Sensor** | Rotary Encoder Sensor (Measures distance via interrupt pin) |
| **Obstacle Sensor** | Ultrasonic Sensor (HC-SR04) |
| **Wireless Module** | Bluetooth Module HC-05 (for remote control) |
| **Display** | LCD Shield (16x2) |

![Assembled Arduino robot car](euluna/arduinolinefollowingrobot/ArduinoLineFollowingRobot-86600c9f11186cd15d528e74023328f976165953/imgs/car.png)

---

## Project Functionalities (Code Overview)

| File Name | Functionality Summary | Implementation Details |
| :--- | :--- | :--- |
| `CarMovementFunctions.h` | **Motor Control Library** | Header file containing inline functions for motor primitives (`motorForward()`, `motorStop()`, etc.). |
| `Line_Following_Car.ino` | **Basic Line Follower** | Implements the core 2-sensor digital logic to follow a line. |
| `Line_Following_Display_Time.ino` | **Timed Run** | Adds an accurate timer to the line follower using the **`millis()`** function for non-blocking time measurement. |
| `Line_Following_Display_Distance.ino` | **Distance Measurement** | Uses a Rotary Encoder on an interrupt pin (D2) to calculate and display total distance traveled. |
| `Obstacle_Avoiding_Car.ino` | **Obstacle Avoidance** | Uses the Ultrasonic Sensor to ensure the path is clear. If an obstacle is closer than 20 cm, the car automatically reverses and turns. |
| `Bluetooth_Controlled_Car.ino` | **Wireless Control** | Enables wireless manual control by reading serial commands ('F', 'B', 'L', 'R', etc.) received from a smartphone remote app via the HC-05 module. |

---

## Key Analysis and Learning Outcomes

* **Timing Accuracy:** The shift from the problematic `delay()` function to the **`millis()`** function was crucial for accurate, independent timing.
* **Distance Correction:** The rotary encoder required a pragmatic correction factor (dividing the output by 4) to ensure the calculated distance closely matched the actual distance.
* **Reliability:** Testing showed that wired connections were inherently more reliable than the Bluetooth link. This led to the suggestion of combining the **Bluetooth** and **Obstacle Avoidance** capabilities to enhance safety during connection drops.
