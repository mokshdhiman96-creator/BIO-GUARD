#include <Wire.h>
#include <DHT.h>
#include <DIYables_LCD.h>

// ----- SENSOR PINS -----
#define DHTPIN 2
#define DHTTYPE DHT11

const int SOIL_PIN = A0;
const int LDR_PIN  = A1;

// ----- I2C LCD -----
DIYables_LCD_I2C lcd(0x27, 16, 2);

DHT dht(DHTPIN, DHTTYPE);

// ----- SOIL CALIBRATION -----
const int DRY_VALUE = 900;
const int WET_VALUE = 300;

unsigned long lastUpdate = 0;
const unsigned long updateInterval = 2000;
int screen = 0;

void setup() {
  Serial.begin(9600);

  dht.begin();

  lcd.begin();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("BIOGUARD SYSTEM");
  lcd.setCursor(0, 1);
  lcd.print("Starting...");
  delay(2000);
  lcd.clear();
}

void loop() {
  if (millis() - lastUpdate >= updateInterval) {
    lastUpdate = millis();

    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    int soilRaw = analogRead(SOIL_PIN);
    int lightRaw = analogRead(LDR_PIN);

    int moisture = map(soilRaw, DRY_VALUE, WET_VALUE, 0, 100);
    moisture = constrain(moisture, 0, 100);

    Serial.print("Soil: ");
    Serial.print(moisture);
    Serial.print("% | Temp: ");
    Serial.print(temperature);
    Serial.print(" C | Humidity: ");
    Serial.print(humidity);
    Serial.print("% | Light: ");
    Serial.println(lightRaw);

    if (screen == 0) {
      lcd.setCursor(0, 0);
      lcd.print("Soil: ");
      lcd.print(moisture);
      lcd.print("%       ");

      lcd.setCursor(0, 1);
      if (moisture < 30) {
        lcd.print("Status: DRY      ");
      } else if (moisture < 70) {
        lcd.print("Status: NORMAL   ");
      } else {
        lcd.print("Status: WET      ");
      }
    } else {
      if (isnan(temperature) || isnan(humidity)) {
        lcd.setCursor(0, 0);
        lcd.print("DHT11 Error      ");
        lcd.setCursor(0, 1);
        lcd.print("Check wiring     ");
      } else {
        lcd.setCursor(0, 0);
        lcd.print("Temp:");
        lcd.print(temperature, 1);
        lcd.print("C       ");

        lcd.setCursor(0, 1);
        lcd.print("Hum:");
        lcd.print(humidity, 0);
        lcd.print("% L:");
        lcd.print(lightRaw);
        lcd.print("   ");
      }
    }

    screen = 1 - screen;
  }
}
