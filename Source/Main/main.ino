#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <DHT_U.h>
#include <DHT.h> 

#define DHTPIN 2 
#define DHTTYPE DHT22 
 
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
String humidity = "Humidity: ";
String temperature = "Temperat: ";
String hValue, tValue;
void setup()
{
  lcd.init();
  lcd.begin(20,4);
  lcd.backlight();
  dht.begin();
  Serial.begin(9600);
  Serial.println("DHT22 Sensor"); 
  Serial.println("I2C Scanner");
}
 
void loop() {
  dht.read();
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } 
  else {
    hValue = String(h,2); tValue = String(t,2);
    lcd.setCursor(0,0);
    lcd.print(humidity + hValue + "%");
    lcd.setCursor(0,1);
    lcd.print(temperature + tValue + "'C");
    lcd.setCursor(7,2);
    lcd.print("HI. I'm Sunio");
    lcd.setCursor(3,3);
    lcd.print("Call: 01091512551");
  }
  delay(2000);
  lcd.clear();
 }
