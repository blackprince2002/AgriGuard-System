# AgriGuard-System (Smart Cultivation Management System)

This project is an Arduino-based smart cultivation management system that includes two main components:
1. Soil Moisture Monitoring and Automatic Watering System
2. Motion Detection System

## Overview

### 1. Soil Moisture Monitoring and Automatic Watering System
This component uses multiple soil moisture sensors to detect the moisture levels in the soil. If the soil moisture level drops below a specified threshold, the system automatically activates a water pump to irrigate the soil.

### 2. Motion Detection System
This component uses a PIR sensor to detect motion near the fence. If motion is detected, an alert is triggered, and an SMS message is sent using a GSM module.

![Complete System Diagram](images/Complete%20System.jpg)


## Installation Instructions

### Hardware Required
- Arduino Uno or compatible board
- Soil moisture sensors (4 units)
- PIR sensor
- Motor driver (H-Bridge or similar)
- Water pump
- GSM module
- Buzzer
- Jumper wires
- Breadboard

### Software Required
- Arduino IDE
- SoftwareSerial library (usually included with Arduino IDE)

## Usage Instructions

### 1. Soil Moisture Monitoring and Automatic Watering System

1. **Upload the Code to Arduino:**
   - Open the Arduino IDE.
   - Load the `SoilMoistureSystem.ino` file from the `soil-moisture-system` directory.
   - Select the appropriate board and port.
   - Upload the code to your Arduino board.

2. **Connect the Hardware:**
   - Assemble the circuit as per the soil moisture schematic.
   - Ensure the motor driver is correctly connected to the water pump.

3. **Run the System:**
   - Once the code is uploaded and the hardware is set up, the system will start monitoring soil moisture levels.
   - When the average soil moisture level drops below the threshold, the water pump will activate to irrigate the soil.

### 2. Motion Detection System

1. **Upload the Code to Arduino:**
   - Open the Arduino IDE.
   - Load the `MotionDetectionSystem.ino` file from the `motion-detection-system` directory.
   - Select the appropriate board and port.
   - Upload the code to your Arduino board.

2. **Connect the Hardware:**
   - Assemble the circuit as per the motion detection schematic.
   - Ensure the GSM module and buzzer are connected correctly.

3. **Run the System:**
   - Once the code is uploaded and the hardware is set up, the system will start detecting motion.
   - When motion is detected, the buzzer will sound, and an SMS alert will be sent.

## Project Structure

- `soil-moisture-system/`: Contains the Arduino sketch for the soil moisture monitoring system.
  - `SoilMoistureSystem.ino`: Main Arduino source code for soil moisture system.
- `motion-detection-system/`: Contains the Arduino sketch for the motion detection system.
  - `MotionDetectionSystem.ino`: Main Arduino source code for motion detection system.
- `images/`: Directory for images and schematics.
  - `soil_moisture_schematic.png`: Schematic diagram of the soil moisture system circuit.
  - `motion_detection_schematic.png`: Schematic diagram of the motion detection system circuit.
- `LICENSE`: MIT License for this project.
- `README.md`: This file.

## Credits and Acknowledgments

- [Arduino](https://www.arduino.cc/): Open-source electronics platform.
- [SoftwareSerial Library](https://www.arduino.cc/en/Reference/SoftwareSerial): Library for serial communication on Arduino.
- Various online resources and tutorials for guidance and inspiration.
