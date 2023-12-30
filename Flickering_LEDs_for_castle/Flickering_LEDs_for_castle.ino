// LED Fire Effect

int ledPin1 = 9;
int ledPin2 = 7;
int ledPin3 = 6;
int ledPin4 = 5;
int ledPin5 = 4;
int ledPin6 = 3;


void setup()
{
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
pinMode(ledPin4, OUTPUT);
pinMode(ledPin5, OUTPUT);
pinMode(ledPin6, OUTPUT);
}

void loop() {
analogWrite(ledPin1, random(10)+5);
analogWrite(ledPin2, random(50)+135);
analogWrite(ledPin3, random(100)+135);
analogWrite(ledPin4, random(100)+135);
analogWrite(ledPin5, random(120)+135);
analogWrite(ledPin6, random(120)+135);
delay(random(100));
}
