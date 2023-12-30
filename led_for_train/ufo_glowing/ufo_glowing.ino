/*

Arduino node script for UFO glowing lights

What to connect and where:

Follow the instructions in main.ino first

Connect pin 3 to a range of green/blue (or other alien colour) LEDs inside the UFO casing

*/

enum Pins { GlowingLight = 3, Enable = 4 };

int brightness = 0;
int fadeAmount = 5;

void setup() {
  pinMode(GlowingLight, OUTPUT);
  pinMode(Enable, INPUT);
}

void loop() {
  if (digitalRead(Enable) == HIGH) {
    analogWrite(GlowingLight, brightness);
    brightness += fadeAmount;
    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;                   // Reverse incrementation direction
    }
    delay(30);
  } else {
    digitalWrite(GlowingLight, LOW);
  }
}
