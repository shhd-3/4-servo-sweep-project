#include <Servo.h>

Servo servo1, servo2, servo3, servo4;

void setup() {
  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(4);
  servo4.attach(5);

  unsigned long startTime = millis();

  // Sweep for exactly 2 seconds
  while (millis() - startTime < 2000) {
    // Wave Forward (0 to 180) - Fast
    for (int pos = 0; pos <= 180; pos++) {
      if (millis() - startTime >= 2000) break; 
      servo1.write(pos); servo2.write(pos); servo3.write(pos); servo4.write(pos);
      delay(3); // Fast wave
    }
    // Wave Backward (180 to 0) - Fast
    for (int pos = 180; pos >= 0; pos--) {
      if (millis() - startTime >= 2000) break; 
      servo1.write(pos); servo2.write(pos); servo3.write(pos); servo4.write(pos);
      delay(3); // Fast wave
    }
  }

  // Hold all at 90°
  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  servo4.write(90);
}

void loop() {
  // Empty
} 