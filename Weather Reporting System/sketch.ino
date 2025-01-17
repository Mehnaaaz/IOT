#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Define the pin for DHT sensor
#define DHTPIN 7           // Pin where the DHT22 is connected
#define DHTTYPE DHT22      // Specify DHT22 sensor

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

// Initialize LCD (I2C address 0x27 is common)
LiquidCrystal_I2C lcd(0x27, 16, 2);  // 16 columns, 2 rows

void setup() {
  // Start the serial monitor (optional, for debugging)
  Serial.begin(9600);
  
  // Initialize the DHT sensor
  dht.begin();
  
  // Initialize the LCD
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Weather Report");
  delay(2000);  // Wait for 2 seconds before starting to display data
}

void loop() {
  // Reading temperature and humidity from DHT22 sensor
  float temperature = dht.readTemperature();  // Read temperature in Celsius
  float humidity = dht.readHumidity();        // Read humidity in percentage

  // Check if any read failed
  if (isnan(temperature) || isnan(humidity)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Failed to read");
    lcd.setCursor(0, 1);
    lcd.print("sensor data");
    return;
  }

  // Display temperature and humidity on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: " + String(temperature) + " C");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: " + String(humidity) + " %");

  // Wait for a while before the next update
  delay(2000);
}
