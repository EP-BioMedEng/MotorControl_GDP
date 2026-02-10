# MotorControl_GDP
Code to control a motors speed and direction using two sensors and an Arduino written for a Group Design Project
## Exoskeleton Hand Control – Arduino Nano Every

## Project Overview
This project uses two force‑sensitive resistors (FSRs) to determine the direction of a DC motor, which is used to open or close the hand of an exoskeleton device.

## Hardware
- Arduino Nano Every  
- 2 × Force Sensitive Resistors (FSRs)  
- 2 × Fixed resistors (forming voltage dividers)  
- Motor driver + DC motor (for hand actuation)

## How It Works
Each FSR is paired with a resistor to create two separate voltage dividers.  
The Arduino reads the analogue voltages from these dividers, allowing it to read the signals from the sensors.

- Increased force on one sensor → motor turns in one direction  
- Increased force on the other → motor turns the opposite way  

## Motor Safety Features
The code uses rising‑edge logic to prevent the motor from running continuously or stalling. This helps avoid:
- Excessive current draw  
- Motor overheating  
- Damage to the Arduino from overcurrent conditions  

## Purpose
This control system is intended for use in a hand exoskeleton, allowing users to decide the motion of the hand through touching a sensor to an object instead of use of a button or switch.
