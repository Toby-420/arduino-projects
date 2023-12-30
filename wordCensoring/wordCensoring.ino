#include <SD.h>
#include <AudioZero.h>

#define userInput 0

void setup() {
  pinMode(userInput, INPUT);

  SD.begin(4);
  // 44100kHz stereo => 88200 sample rate
  AudioZero.begin(2*44100);
}

void loop() {

  if (digitalRead(userInput) == HIGH) {
    int randomFileNumber = rand() % 4;
    const char *fileName = NULL;
    switch(randomFileNumber) {
      case 0:
        fileName = "thousandHerzBeep.wav";
        break;
      case 1:
        fileName = "fartLikeSound.wav";
        break;
      case 2:
        fileName = "metalPipe.wav";
        break;
      case 3:
        fileName = "augh.wav";
        break;
      default:
        fileName = NULL;
        break;
    }
      if (fileName != NULL) {
        File myFile = SD.open(fileName);
        AudioZero.play(myFile);
      }
  }
}
