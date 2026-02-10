# MotorControl_GDP
Code to control a motors speed and direction using two sensors and an Arduino written for a Group Design Project
## Exoskeleton Hand Control – Arduino Nano Every

## Project Overview
This project uses two force‑sensitive resistors (one in palm, one on side of hand under the pinkie finger) to determine the direction of a DC motor which is used to open or close the hand of an exoskeleton.

## Hardware
- Arduino Nano Every  
- 2 × Force Sensitive Resistors  
- 2 × 10Kohm fixed value resistors  
- H-Bridge motor driver + N20 DC motor

## Method
Each FSR is paired with a resistor to create two separate voltage dividers.  
The Arduino reads the analogue voltages from these dividers, allowing it to read the signals from the sensors.
When the signal surpasses a predetermined threshold the motor activates in a direction determined by the last sensor to pass the threshold
- Increased force on palm sensor -> motor turns clockwise (hand closes) 
- Increased force on the other -> motor turns anti-clockwise (hand opens)

## Features
The code uses rising‑edge logic to prevent the motor from running continuously or stalling. This helps avoid:
- Excessive current draw damaging circuit components   
- Motor overheating
- Strain on mechanical systems

## Purpose
This control system is intended for use in a hand exoskeleton, allowing users to decide the motion of the hand through touching a sensor to an object instead of use of a button or switch.
  
