# Parking-Sensor-ATMEGA32

[Parking Sensor using HC-SR04 (ATMEGA32) - YouTube](https://www.youtube.com/watch?v=_CBrciw4Yfw&list=PLC3Wwc_IeCN8d-kV1xPaiXWGpabYQGxY_&index=6)

## Description:
 
#### The project has a very simple operation, it periodically checks for HC-SR04 sensor reading, and according to the value it takes decisions.

##### If the reading is 5cm or less, the buzzer stays on for a high-risk alarm
##### If the reading is more than 5 but is less than 11, high-frequency beep is generated from the buzzer
##### If the reading is more than  10 but is less than 16, a lower frequency beep is generated from the buzzer
##### If the reading is more than 15 but is less than 21, a much lower frequency beep is generated from the buzzer
##### If the reading is more than 20 but is less than 31, a very low-frequency beep is generated from the buzzer
##### If the reading is more than 30, the buzzer is turned off

**Components used:**
- HC-SR04 Ultrasonic Sensor
- 16x2 LCD
- 5V Buzzer

**Peripherals used:**
- DIO
- ICU
- Timer1 (16-bit)

## Project design:

![Project Design](https://github.com/Piistachyoo/Parking-Sensor-ATMEGA32/blob/main/design.png?raw=true)
