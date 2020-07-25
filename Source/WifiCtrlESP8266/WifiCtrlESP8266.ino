#include <SoftwareSerial.h>
#include <ArduinoJson.h>

#define RX 10
#define TX 11
String WIFI_SSID = "your wifi name here.";
String PASSWORD = "your wifi password here.";
String DEVICE_SECRET_KEY = "your wia secret key from the dashboard here";

String HOST = "";
String PATH = "";
String PORT = "";

int countTrueCommand;
int countTimeCommand;
boolean found = false;

SoftwareSerial esp8266(RX, TX);

StaticJsonBuffer<200> jsonBuffer;
JsonObject& root = jsonBuffer.createObject();

void setup(){
  Serial.begin(9600);
  esp8266.begin(115200);
  esp8266.println("AT");
  Serial.println(esp8266.read());
  sendCommandToESP8266("AT", 5, "OK");
  sendCommandToESP8266("AT+CWMODE=1", 5, "OK");
  sendCommandToESP8266("AT+CWJAP=\"" + WIFI_SSID + "\",\"" + PASSWORD + "\"", 20, "OK");
}

void loop(){
  root["name"] = "temperature";
  root["data"] = 21.5;
  String data;
  root.printTo(data);

  String postRequest = "POST " + PATH + " HTTP/1.1\r\n" +
                        "HOST: " + HOST + "\r\n" +
                        "Accept: *" + "/" "*\r\n" +
                        "Content-Length: " + data.length() + "\r\n" +
                        "Content-Type: application/json\r\n" +
                        "Authorization: Bearer " + DEVICE_SECRET_KEY + "\r\n" +
                        "\r\n" + data;

  sendCommandToESP8266("AT+CIPMUX=1", 5, "OK");
  sendCommandToESP8266("AT+CIPSTART=0,\"TCP\",\"" + HOST + "\"," + PORT, 15, "OK");
  String cipSend = "AT+CIPSEND=0," + String(postRequest.length());
  sendCommandToESP8266(cipSend, 4, ">");
  sendData(postRequest);
  sendCommandToESP8266("AT+CIPCLOSE=0", 5, "OK");
}

void sendCommandToESP8266(String command, int maxTime, char readReplay[]){
  Serial.print(countTrueCommand);
  Serial.print(". at command >= ");
  Serial.print(command);
  Serial.print(" ");
  while(countTimeCommand < (maxTime * 1)){
    esp8266.println(command);
    if(esp8266.find(readReplay)){
      found = true; break;
    }
    countTimeCommand++;
  }

  if(found == true){
    Serial.println("Success");
    countTrueCommamd++;
    countTimeCommand = 0;
  }

  if(found == false){
    Serial.println("Fail");
    countTrueCommand = 0;
    countTimeCommand = 0;
  }

  found = false;
}

void sendData(String postRequest){
  Serial.println(postRequest);
  esp8266.println(postRequest);
  delay(1500);
  countTrueCommand++;
}
