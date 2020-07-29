# Arduino-TH-Recorder 📟  
- Hardware for Recording Temperature-Humidity data and Visualization on firebase Cloud  
- 구역의 온습도를 측정하고 클라우드로 기록하여 시각화.    

 > ISSUE LIST  
 > [200717] Arduino Pro micro 가 DHT 랑 안맞는지 작동을 안함  
 > [200719] 하나더 구매 했는데 이것도 안됨, 이젠 안되는건지 못하는건지 모르겟음  
 > [200722] 빵판이 너무 작아서 쓰기가 어려움 - 배터리, WIFI모듈이 들어갈 자리가 없음  
 > [200728] 납땜기 구하기, 참고 자료 (https://www.youtube.com/watch?v=XeQXK0BkjIo)  
 > [200729] 아두이노 보드 변경 (-> WeMos D1 R2, WIFI 모듈을 이용할 경우 low-level 접근이 요구됨)

--------------------------------------------------------    
## 0. Enviroment
### SOFTWARE
- Window10-Arduino 64x
- VSC, Arduino IDE  
- <b>사용된 라이브러리</b>  
  - [DHT-sensor](https://github.com/adafruit/DHT-sensor-library)         
  - [Adafruit-sensor](https://github.com/adafruit/Adafruit_Sensor)
  - [LiquidCrystal](https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library)
  - [Firebase-ArudinoESP8266](https://github.com/FirebaseExtended/firebase-arduino)
  - [ESP8266 & Driver](http://blog.daum.net/rockjjy99/2453)
### HARDWARE
- (2. 구매 목록 참고)
- <img src="https://user-images.githubusercontent.com/26760693/88066284-8c7a7000-cba8-11ea-86d3-01b5af752ef0.jpg"  width="300" height="150">  
- <img src="https://user-images.githubusercontent.com/26760693/88080089-8b9e0a00-cbb9-11ea-8283-2d7a3851af7d.png"  width="300" height="150">  
- <img src="https://user-images.githubusercontent.com/26760693/88070811-10832680-cbae-11ea-8fa9-01a02a447c5f.png"  width="300" height="150">  

------------------ --------------------------------------    


## 1. Have To Do
1. ~~hardware로 사용할 아두이노 보드 및 센서, 빵판 등등~~  
2. ~~온습도 센서 보드로 제어 & Serial output 확인~~  
3. ~~LCD 기판에 값(temperature, humidity, and so on) 뿌리기~~  
*  <img src="https://user-images.githubusercontent.com/26760693/88080350-e9caed00-cbb9-11ea-97f4-aa4d692da0cf.jpg"  width="500" height="250">    
4. 3D 모델링 및 HW 구조 고민(보조 전원 장치 및 Frame을 어떻게)
5. ~~WIFI 모듈 연결하고 NoSQL(Firebase realtime DB)에 접근 및 테스트~~
6. ~~raw data를 firebase server를 DB에 저장~~    
7. 저장된 \*.json 파일을 \*.xml 혹은 \*.csv로 export  
8. 파일을 excel로 불러와 시계열적 그래프로 표현  
9. 자동화(이건 좀 모르겠따.)         

--------------------------------------------------------    

    
## 2. Purchase List
| 품목 | 목적 | 비고 |
|---|:---:|---:|
| Arduino Pro micro ATmega32u4 | MCU 컴퓨터 보드 | ❌ 2개 샀는데 실패야 |
| Arduino Nano ATmega328P | MCU 컴퓨터 보드 | ❌ |
| WeMos D1 R2 (ESP8266 in chip) | MCU | ✔ |
| 빵판(bread board) | 몸통 역할 | ✔ |
| 점퍼선, 절연 전선 | 전기를 흐르게 해. | ✔ |
| 적외선 센서 | 거리를 측정하거나 물체 인지 | ✔ |
| ESP-8266  | WIFI를 사용할 수 있게 해줘 | ❌ AT-command 조작 요구됨 |
| DHT-22 | 정밀 온습도 센서  | ✔ |
| LCD 20x4 | 데이터 간단하게라도 봐야지 | ✔ |
| | |
