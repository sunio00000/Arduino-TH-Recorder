
#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>
//#include <WiFi.h>

#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <DHT_U.h>
#include <DHT.h> 

#define DHTPIN D3 
#define DHTTYPE DHT22 

// Firebase
#define FIREBASE_HOST "arduino-th-firebase.firebaseio.com"
#define FIREBASE_AUTH "LDhCaZIEG94a8il5N4JOGjsjxEcQDXxMC7S6P5vE"

// WIFI
#define WIFI_SSID "U+Net4D48"
#define WIFI_PASSWORD "47C0559#5J"
//swRTC rtc;
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
String humidity = "Humidity: ";
String temperature = "Temperat: ";
String hValue, tValue, currentTime;
int timeStamp = 1, freq = 0;
void setup()
{
  lcd.init();
  lcd.begin(20,4);
  lcd.backlight();
  dht.begin();
  Serial.begin(9600);
  Serial.println("DHT22 Sensor"); 
  Serial.println("I2C Scanner");
  // WIFI
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected.");
  Serial.print(WiFi.localIP());

  //Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  delay(500);
  
}
 
void loop() {
  dht.read();
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  //currentTime = rtc.getYear()+rtc.getMonth()+rtc.getDay()+rtc.getHours()+rtc.getMinutes()+rtc.getSeconds()+"/";
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
    lcd.print("Failed to read from DHT");
  } 
  else {
    hValue = String(h,2); tValue = String(t,2);
    lcd.setCursor(0,0);
    lcd.print(humidity + hValue + "%");
    Serial.println("humidity :: "+ hValue + " / temperature :: "+ tValue);
    lcd.setCursor(0,1);
    lcd.print(temperature + tValue + "'C");
    lcd.setCursor(7,2);
    lcd.print("HI. I'm Sunio");
    lcd.setCursor(3,3);
    lcd.print("Call: 01091512551");
    if(!(freq%= 5)){
      Firebase.setString(String(timeStamp)+"/temperature/teValue",tValue);
      delay(500);
      Firebase.setString(String(timeStamp++)+"/humidity/huValue",hValue);
      delay(500);
    }
    else{
      delay(1000);
    }
    freq++;
  }
  delay(1000);
  lcd.clear();
 }
