# 4-Servo Sweep Controller

## Objective
The primary objective of this project is to implement a synchronized control sequence for four servo motors using an Arduino Uno. The project demonstrates:
*   Sequential Logic: Executing a time-based task (a 2-second sweep) followed by a state transition to a neutral 90° position.
*   Hardware Interfacing: Managing multiple actuators simultaneously using both digital and analog pin assignments.
*   Simulation Proficiency: Utilizing Tinkercad to validate circuit design and software logic.

## Project Execution Steps

### 1. Circuit Assembly
*   Place Components: Drag an Arduino Uno R3 and 4 Micro Servos onto the workplane.
*   Power Connections:
    *   Connect the Red wire (Power) of all 4 servos directly to the 5V pin on the Arduino.
    *   Connect the Black wire (Ground) of all 4 servos directly to the GND pin on the Arduino.
*   Signal Connections:
    *   Connect the signal wire of Servo 1 to Digital Pin 2.
    *   Connect the signal wire of Servo 2 to Digital Pin 3.
    *   Connect the signal wire of Servo 3 to Digital Pin 4.
    *   Connect the signal wire of Servo 4 to Digital Pin 5.

### 2. Programming
*   Click on the Code button in the Tinkercad top menu.
*   Change the mode from "Blocks" to Text.
*   Paste the source code below.

### 3. Simulation & Validation
*   Click the Start Simulation button.
*   Observe: The four servos will begin a simultaneous sweeping motion.
*   Verify: After exactly 2 seconds, the sweep motion will stop, and all four servo arms will rotate to and lock at 90°.

## Source Code
```cpp
#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(4);
  servo4.attach(5);

  unsigned long startTime = millis();

  // Sweep for 2 seconds
  while (millis() - startTime < 2000) {

    // 0° to 180°
    for (int pos = 0; pos <= 180 && (millis() - startTime < 2000); pos++) {
      servo1.write(pos);
      servo2.write(pos);
      servo3.write(pos);
      servo4.write(pos);
      delay(15);
    }

    // 180° to 0°
    for (int pos = 180; pos >= 0 && (millis() - startTime < 2000); pos--) {
      servo1.write(pos);
      servo2.write(pos);
      servo3.write(pos);
      servo4.write(pos);
      delay(15);
    }
  }

  // Hold all servos at 90°
  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  servo4.write(90);
}

void loop() {
  // Keep the servos at 90°
}
