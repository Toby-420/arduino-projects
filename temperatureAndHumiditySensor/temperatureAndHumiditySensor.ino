/*

Arduino script for Temperature and Humidity sensing

*/

#include <DHT.h>
#include <SoftwareSerial.h>
#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

#define Thermometer "1" // These are for the weather fonts to make it easier to understand
#define Droplet "2"

DHT dht(2, DHT22);
U8G2_SSD1306_128X64_NONAME_F_SW_I2C screen(U8G2_R0, A5, A4, U8X8_PIN_NONE);

char temperatureString[32] = "\0";
char humidityString[32] = "\0";
float temperature = 0;
float oldTemperature = 0;
float humidity = 0;
float oldHumidity = 0;

void setup() {
  dht.begin();
  screen.begin();
  screen.clearBuffer();
}

void loop() {
  oldTemperature = temperature;
  oldHumidity = humidity;

  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    // Resets the number in the rare case that it is needed
    temperature = oldTemperature;
    humidity = oldHumidity;
  } else {
    // Load the 1dp float values into strings for displaying later
    char tempBuffer[10];
    char humBuffer[10];
  
    dtostrf(temperature, 5, 1, tempBuffer);
    dtostrf(humidity, 5, 1, humBuffer);

    snprintf(temperatureString, sizeof(temperatureString), "%s%cC", tempBuffer, 176);
    snprintf(humidityString, sizeof(humidityString), "%s%%", humBuffer);
    screen.clearBuffer();
  }

  // These seemingly random numbers were chosen to make the text appear at the correct points on the display
  screen.setFont(u8g2_font_unifont_t_weather);
  screen.drawStr(-5, 12, Thermometer);
  screen.drawStr(66, 12, Droplet);
  screen.setFont(u8g2_font_helvB08_tf); // Helvetica at a usable size
  screen.drawStr(10, 12, "Temp: ");
  screen.drawStr(80, 12, "Hum: ");
  screen.drawStr(18, 24, temperatureString);
  screen.drawStr(82, 24, humidityString);
  screen.sendBuffer();
  delay(2000); // Lowest is 2000 as the DHT22 only supports Max of 0.5Hz (every 2 seconds or 2000 milliseconds) sample rate
}
