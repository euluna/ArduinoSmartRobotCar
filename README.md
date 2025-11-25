# 🤖 Smart Robot Car Project (EEEE1027/EEEE1031)

This repository contains the Arduino code and documentation for the Smart Robot Car project, completed for the Applied Engineering Construction course. The project focuses on building an Arduino Uno-controlled robot car with various functionalities, including line following, distance measurement, obstacle avoidance, and Bluetooth control.

**Student:** Euluna Gotami
**Student ID:** 20113429
**Course:** Electrical and Electronic Engineering

---

## 🎯 Project Objectives

[cite_start]The primary goal was to build a smart robot car using an Arduino Uno (ATmega328) and an L298N motor driver[cite: 23, 133]. The specific objectives achieved were:

1.  [cite_start]**DIY IR Sensor:** Construction and verification of a custom IR sensor using a photodiode and LM358 Op-Amp[cite: 27, 81].
2.  [cite_start]**Line Following:** Programming the car to follow a black line using two IR sensor modules[cite: 28].
3.  [cite_start]**Time Display:** Displaying the time taken to complete the track on an LCD Shield using the `millis()` function for accuracy[cite: 29, 266, 433].
4.  [cite_start]**Distance Measurement:** Measuring and displaying the distance traveled using a Rotary Encoder Sensor attached to an interrupt pin[cite: 30, 294, 303].
5.  [cite_start]**Obstacle Avoidance:** Designing the car to avoid obstacles using an Ultrasonic Sensor[cite: 31, 341].
6.  [cite_start]**Bluetooth Control:** Enabling wireless control of the car via a Bluetooth module (HC-05) and a smartphone app[cite: 32, 365].

---

## ⚙️ Hardware Components

| Component           | Purpose                                             |
| :------------------ | :-------------------------------------------------- |
| **Microcontroller** | Arduino Uno (ATmega328)                             |
| **Motor Driver**    | L298N Motor Driver Module                           |
| **Power**           | 7.4V Li-Po Battery                                  |
| **Motors**          | 2 x 5V DC Gear Motors                               |
| **Display**         | LCD Shield (16x2)                                   |
| **Line Sensors**    | 2 x IR Sensor Modules (or DIY IR Sensors)           |
| **Distance Sensor** | Rotary Encoder Sensor                               |
| **Obstacle Sensor** | Ultrasonic Sensor                                   |
| **Wireless Module** | Bluetooth Module HC-05 (requires a voltage divider) |

---

## 📁 Repository Structure and Code Overview

The code is organized into five main Arduino sketches (`.ino` files) and one reusable header file (`.h`).

| File Name                             | Functionality Summary                                                                                                                              |
| :------------------------------------ | :------------------------------------------------------------------------------------------------------------------------------------------------- |
| `CarMovementFunctions.h`              | [cite_start]Contains reusable motor functions (`motorForward()`, `motorStop()`, `motorAReverse()`, etc.) included in all main sketches[cite: 932]. |
| `Line_Following_Car.ino`              | [cite_start]Basic logic for line following (Forward, Turn Left, Turn Right, Stop).                                                                 |
| `Line_Following_Display_Time.ino`     | Adds a timer to the line following code using the non-blocking `millis()` function.                                                                |
| `Line_Following_Display_Distance.ino` | [cite_start]Integrates distance calculation logic using the rotary encoder interrupt and LCD display.                                              |
| `Obstacle_Avoiding_Car.ino`           | Uses the ultrasonic sensor to detect objects. [cite_start]If distance `< 20 cm`, the car reverses and turns right[cite: 796].                      |
| `Bluetooth_Controlled_Car.ino`        | [cite_start]Reads serial commands ('F', 'B', 'L', 'R', etc.) sent wirelessly from a smartphone app via the HC-05 module[cite: 393, 808].           |

---

## ✅ Results and Analysis Highlights

- [cite_start]**Line Following:** Required adjustments to wheel speeds and sensor spacing to handle sharp turns (S-curves)[cite: 421, 423].
- [cite_start]**Timing:** Switched from `delay()` to the **`millis()`** function to ensure accurate timing independent of code execution time[cite: 429, 433].
- [cite_start]**Distance:** The encoder required a software correction factor (dividing by 4) to convert raw counts to accurate centimeters[cite: 442, 443]. [cite_start]Final inaccuracy was less than 2%[cite: 472].
- [cite_start]**Bluetooth:** Connection reliability was an issue, leading to the recommendation of combining it with **Obstacle Avoidance** for collision protection[cite: 462, 465].
