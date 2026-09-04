# ☀️ Light Tracker

A simple **2-axis Light Tracking System** built using an **Arduino Nano**, **four LDR sensors**, and **two servo motors**. The system automatically detects the direction of the strongest light source and adjusts its position accordingly.

## 🔧 Project Overview

The project uses four **LDR (Light Dependent Resistor)** sensors arranged in a homemade mount:

```text
┌─────────────┐
│  LDR    LDR │
│   TL     TR │
│             │
│  LDR    LDR │
│   BL     BR │
└─────────────┘
```

The four sensors continuously measure the surrounding light intensity. The Arduino compares the readings from opposite sensors and calculates the difference.

Based on the calculated difference and a predefined **tolerance value**, two servo motors control the movement:

* ↔️ **Left–Right Servo** — adjusts the horizontal direction
* ↕️ **Up–Down Servo** — adjusts the vertical direction

The tracker keeps moving until the light intensity detected by the corresponding LDR pairs is approximately balanced.

## 🧰 Components Used

* **Arduino Nano**
* **4 × LDR Sensors**
* **2 × Servo Motors**
* Resistors for LDR voltage-divider circuits
* Homemade sensor mounting mechanism
* Jumper wires / breadboard
* External power supply if required for the servos

## ⚙️ Working Principle

1. Four LDR sensors measure the intensity of incoming light.
2. Arduino Nano reads the analog values from all four sensors.
3. The readings are divided into two pairs:

   * **Top vs Bottom** → controls vertical movement
   * **Left vs Right** → controls horizontal movement
4. The difference between the sensor readings is calculated.
5. A **tolerance/dead-zone** prevents unnecessary servo movement caused by small variations in light.
6. If the difference exceeds the tolerance, the corresponding servo moves toward the brighter side.
7. This process continuously repeats, allowing the tracker to automatically follow the light source.

## 📐 Two-Axis Tracking

```text
             LIGHT
               ↓
        ┌─────────────┐
        │ TL       TR │
        │      ☀      │
        │ BL       BR │
        └─────────────┘
             │   │
       Horizontal  Vertical
          Servo      Servo
```

The combination of the two servo axes allows the sensor platform to follow the light source in **both horizontal and vertical directions**.

## 🚀 Future Improvements

* Add a solar panel to create a functional solar tracker
* Improve the mechanical mounting system
* Add automatic calibration
* Store the last servo position
* Add an LCD/OLED display for sensor readings and servo angles
* Optimize the tracking algorithm for smoother movement

## 📜 License

This project is open-source and available for learning, experimentation, and personal projects.
