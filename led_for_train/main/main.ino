/*

Arduino controller script for train set lights

Initial setup:

Have a breadboard or similar with an input from a high current capable 5V power supply.

What to connect and where:

Connect pin 4 on the Arduino Nano running ufo_glowing.ino to pin 2.
Connect pin 4 on the Arduino Nano running abandoned_station.ino to pin 3.
Connect pin 2 on this Arduino Uno through a NOT gate / inverter to a transistor controlling the day lights

PINS:

A lot of these are surplus and only to make it easier to understand.
A more optimised version could be written, but this makes it easy to wire and read.

STREET_LIGHT  - Controls when street lights will be on as well as UFO (on Arduino Nano) and the inverse is used to decide when Day is as lights will come on at night
STATION_LIGHT - Controls when the station and abandoned station lights will be on. Currently just stays on
HOME_LIGHT    - Controls when the lights in people's homes turn on
SHOP_LIGHT    - Controls when the shop lights turn on
TV_LIGHT      - Controls when the light from TVs in houses will be on
ARCH_LIGHT    - Controls when the archeology / dig site lights will be on
DISCO_LIGHT   - Controls when the pub's disco lights will be on
NUM_LIGHTS    - Defines the number of lights (not currently used, just for scalability)

DELAYS:

STREET_DELAY and HOME_DELAY are the same, just different to maximise readability

*/


enum Lights { STREET_LIGHT = 2,  STATION_LIGHT = 3,  HOME_LIGHT = 4,  SHOP_LIGHT = 5,  TV_LIGHT = 6,  ARCH_LIGHT = 7,  DISCO_LIGHT = 8,  NUM_LIGHTS };

enum Delays { MORNING_LENGTH = 2000,  EVENING_LENGTH = 2000,  NIGHT_LENGTH = 6000,  NUM_DELAYS = 3};

int lightsPins[NUM_LIGHTS] = {STREET_LIGHT, STATION_LIGHT, HOME_LIGHT, SHOP_LIGHT, TV_LIGHT, ARCH_LIGHT, DISCO_LIGHT};
unsigned long delays[NUM_DELAYS] = {MORNING_LENGTH, EVENING_LENGTH, NIGHT_LENGTH};

void setup() {
  for (int i = 0; i < NUM_LIGHTS; i++) {
    pinMode(lightsPins[i], OUTPUT);        // Set all pins to outputs
  }
  digitalWrite(STATION_LIGHT, HIGH);       // Turn station lights on (always on)
}

void loop() {
  //  Start of day
  digitalWrite(STREET_LIGHT, LOW);         // Turn street lights and UFO off (therefore it is day)
  digitalWrite(HOME_LIGHT, LOW);           // Turn house lights off
  digitalWrite(TV_LIGHT, LOW);             // Turn light from TVs off (as it would not stand out against sunlight)
  digitalWrite(SHOP_LIGHT, HIGH);          // Turn shop lights on
  digitalWrite(ARCH_LIGHT, LOW);           // Turn archeology lights off
  digitalWrite(DISCO_LIGHT, LOW);          // Turn disco lights off

  delay(MORNING_LENGTH);                   // Wait until evening in this state

  digitalWrite(STREET_LIGHT, HIGH);        // Turn street lights on
  digitalWrite(DISCO_LIGHT, HIGH);         // Turn disco / pub lights on

  delay(EVENING_LENGTH);                   // Wait until night in this state

  digitalWrite(SHOP_LIGHT, LOW);           // Turn shop lights off
  digitalWrite(TV_LIGHT, HIGH);            // Turn lights from TVs in houses on
  digitalWrite(HOME_LIGHT, HIGH);          // Turn house lights on
  digitalWrite(ARCH_LIGHT, HIGH);          // Turn archeology lights on

  delay(NIGHT_LENGTH);                     // Wait until morning in this state
}
