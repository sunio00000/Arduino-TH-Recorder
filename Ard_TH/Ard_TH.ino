//#include <DHT.h>
#include <DHT_U.h>

#include <DHT.h> 
#define DHTPIN 2    // 온습도 센서가 4번에 연결
 
#define DHTTYPE 22   // DHT22 온습도 센서 사용
 
DHT dht(DHTPIN, DHTTYPE); // DHT 설정 (4,DHT22)
 
void setup()
{
 //dht.begin();
 Serial.begin(9600); // 통신속도 9600으로 통신 시작
 while(!Serial);
 Serial.println("DHT22 test!"); // 문자 출력
 dht.begin();
 
}
 
void loop() {
    float h = dht.readHumidity();
  float t = dht.readTemperature();
 
  if (isnan(t) || isnan(h)) {
    //값 읽기 실패시 시리얼 모니터 출력
    Serial.println("Failed to read from DHT");
  } else {
    //온도, 습도 표시 시리얼 모니터 출력
    Serial.print("Humidity: "); 
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.println(" *C");
  }
  delay(2000);
 }
