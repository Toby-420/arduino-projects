/*

Arduino node script for Abandoned station lights

What to connect and where:

Follow the instructions in main.ino first

Connect pin 3 to a transistor on the main breadboard with cables leading to an LED (to act as a broken CRT monitor or similar)
Connect pin 5 and 6 to 2 transistors on the main breadboard with cables leading to 2 of the same or similar colours (white, light orange,  etc)

*/
enum Pins { Enable = 4, Flicker1 = 3, Flicker2 = 5, Flicker3 = 6 };

void setup() {
  pinMode(Enable, INPUT);
  pinMode(Flicker1, OUTPUT);
  pinMode(Flicker2, OUTPUT);
  pinMode(Flicker3, OUTPUT);
}

void loop() {
  if (digitalRead(Enable)) {
    analogWrite(Flicker1, random(5));
    analogWrite(Flicker2, random(30));
    analogWrite(Flicker3, random(70));
    delay(random(100));
  }
  else {
    digitalWrite(Flicker1, LOW);
    digitalWrite(Flicker2, LOW);
    digitalWrite(Flicker3, LOW);
  }
}
