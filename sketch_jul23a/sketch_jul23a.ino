#include <IRremote.hpp>  //library add for Remote

const int IR_RECEIVE_PIN = 12;  // IR pin

#include <Servo.h>  //library add for servo motor

// Servo objects for four servo motors
Servo s1;
Servo s2;
Servo s3;
Servo s4;

void setup() {
  // put your setup code here, to run once:
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // start IR receiver
  s1.attach(9);                                           // Attach servo s1 to pin 9
  s2.attach(3);                                           // Attach servo s2 to pin 3
  s3.attach(5);                                           // Attach servo s3 to pin 5
  s4.attach(6);                                           // Attach servo s4 to pin 6
  Serial.begin(9600);                                     // Start serial communication
}

void loop() {
  // put your main code here, to run repeatedly:

  if (IrReceiver.decode()) {
    int irt = IrReceiver.decodedIRData.command;  // Read the command from the IR remote
    Serial.println(irt);                         // Print the command to the serial monitor

    if (irt == 69) {

      int pos = s1.read();  // Read the current position of servo s1

      for (int i = 0; i < 10; i++) {  //Decrease the position of servo s1 by 10 steps.

        pos--;
        s1.write(pos);
        delay(10);
      }

    } else if (irt == 70) {

      int pos = s1.read();

      for (int i = 0; i < 10; i++) {  //Increase the position of servo s1 by 10 steps.

        pos++;
        s1.write(pos);
        delay(10);
      }

    } else if (irt == 71) {

      int pos = s2.read();

      for (int i = 0; i < 10; i++) {

        pos--;
        s2.write(pos);
        delay(10);
      }

    } else if (irt == 68) {

      int pos = s2.read();

      for (int i = 0; i < 10; i++) {

        pos++;
        s2.write(pos);
        delay(10);
      }

    } else if (irt == 64) {

      int pos = s3.read();

      for (int i = 0; i < 10; i++) {

        pos--;
        s3.write(pos);
        delay(10);
      }

    } else if (irt == 67) {
      int pos = s3.read();

      for (int i = 0; i < 10; i++) {

        pos++;
        s3.write(pos);
        delay(10);
      }

    } else if (irt == 7) {

      int pos = s4.read();

      for (int i = 0; i < 10; i++) {

        pos--;
        s4.write(pos);
        delay(10);
      }

    } else if (irt == 21) {

      int pos = s4.read();

      for (int i = 0; i < 10; i++) {

        pos++;
        s4.write(pos);
        delay(10);
      }
    }
  }
  IrReceiver.resume();  // Prepare for the next value
}