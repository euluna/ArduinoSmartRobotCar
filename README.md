# 🤖 Smart Robot Car: Applied Engineering Construction Project (EEEE1027/EEEE1031)

This project documents the development of a versatile Smart Robot Car, focusing on applying foundational electronic and programming concepts to real-world control applications.

**Project Date:** December 2020
**Student:** Euluna Gotami
**Student ID:** 20113429
**Course:** Electrical and Electronic Engineering

---

## ⚙️ Core Hardware and Fabrication Highlights

The robot car is built around the **Arduino Uno** as its control brain, utilizing an **L298N Motor Driver** to manage the power requirements of the two 5V DC gear motors. The entire assembly is mounted on an acrylic frame and powered by a 7.4V Li-Po battery.

A key deliverable of this project was the fabrication of a custom sensor:

- **DIY IR Sensor:** A custom Infrared (IR) sensor was constructed using an **LM358 Dual Op-Amp** and a **Photodiode**. This assembly functions as a comparator to detect changes in light reflection, a foundational step before implementing the line following function.

| Component           | Functionality                                       |
| :------------------ | :-------------------------------------------------- |
| **Microcontroller** | Arduino Uno (ATmega328)                             |
| **Motor Driver**    | L298N Module                                        |
| **Line Sensors**    | 2 x IR Sensor Modules (for basic Line Following)    |
| **DIY IR Sensor**   | Custom comparator circuit (LM358 + Photodiode)      |
| **Distance Sensor** | Rotary Encoder Sensor (connected to Interrupt Pin)  |
| **Obstacle Sensor** | Ultrasonic Sensor (HC-SR04)                         |
| **Wireless Module** | Bluetooth Module HC-05 (requires a voltage divider) |
| **Display**         | LCD Shield (16x2)                                   |

---

## 🎯 Project Functionalities (Code Overview)

The project successfully implements multiple control modalities, demonstrating proficiency in sensor integration and non-blocking code execution.

| File Name                             | Functionality Summary     | Implementation Details                                                                                                                             |
| :------------------------------------ | :------------------------ | :------------------------------------------------------------------------------------------------------------------------------------------------- |
| `CarMovementFunctions.h`              | **Motor Control Library** | Reusable C++ functions defining low-level motor actions (Forward, Reverse, Stop, Turning motions).                                                 |
| `Line_Following_Car.ino`              | **Basic Line Follower**   | Uses a 2-sensor digital input logic (`if/else`) to follow a dark line on a light surface.                                                          |
| `Line_Following_Display_Time.ino`     | **Timed Run**             | Adds an accurate timer to the line following process using the non-blocking `millis()` function, avoiding the limitations of `delay()`.            |
| `Line_Following_Display_Distance.ino` | **Distance Measurement**  | Uses a Rotary Encoder on an interrupt pin to precisely measure the distance traveled and display it on the LCD.                                    |
| `Obstacle_Avoiding_Car.ino`           | **Obstacle Avoidance**    | Implements the Ultrasonic Sensor to detect objects. If an object is closer than 20 cm, the car executes a reverse-and-turn maneuver.               |
| `Bluetooth_Controlled_Car.ino`        | **Wireless Control**      | Enables wireless manual control by reading serial commands ('F', 'B', 'L', 'R', etc.) received from a smartphone application via the HC-05 module. |

---

## ✅ Key Analysis and Learning Outcomes

- **Accuracy:** The use of `millis()` provided high accuracy for the timer function. The distance measurement proved accurate to within less than 2% after implementing a necessary software correction factor for the rotary encoder's output.
- **Problem Solving:** Adjustments were needed to handle track imperfections and sharp S-curves, which was solved by widening the sensor span and implementing a **reverse-wheel turn** function.
- **Reliability:** Testing showed that wired connections were inherently more reliable than the Bluetooth link. This led to the conclusion that combining the **Bluetooth** and **Obstacle Avoidance** capabilities would enhance safety and usability by preventing collisions during connection drops.
