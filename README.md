# Arduino-TH-Recorder
- Hardware for Recording Temperature-Humidity data and Visualization on firebase Cloud  
- 구역의 온습도를 측정하고 클라우드로 기록하여 시각화.    


>교수님 연구에 사용할 수 있도록 자동화한 기기를 만들자.  
>오랜만에 토이 프로젝트...       

--------------------------------------------------------    
## 0. Enviroment

- Window10-Arduino 64x
- VSC, Arduino IDE (DHT.h , )        
--------------------------------------------------------    


## 1. Have To Do
1. ~~hardware로 사용할 아두이노 보드 및 센서, 빵판 등등~~  
2. 온습도 센서 보드로 제어 & Serial output 확인  
3. LCD 기판에 값(temperature, humidity, and so on) 뿌리기  
4. 적외선 센서로 거리가 근접하면 LCD에 전화번호? 출력  
5. WIFI 모듈 연결하고 NoSQL(Firebase realtime DB)에 접근 및 테스트  
6. raw data를 firebase server를 DB에 저장  
7. 저장된 \*.json 파일을 \*.xml 혹은 \*.csv로 export  
8. 파일을 excel로 불러와 시계열적 그래프로 표현  
9. 자동화(이건 좀 모르겠따.)         

--------------------------------------------------------    

    
## 2. Purchase List
| 품목 | 목적 | 비고 |
|---|:---:|---:|
| Arduino Pro micro ATmega32u4 | MCU 컴퓨터 보드 | ✔ |
| 빵판(bread board) | 몸통 역할 | ✔ |
| 점퍼선, 절연 전선 | 전기를 흐르게 해. | ✔ |
| 적외선 센서 | 거리를 측정하거나 물체 인지 | ✔ |
| ESP-8266  | WIFI를 사용할 수 있게 해줘 | ✔ |
| DHT-22 | 정밀 온습도 센서  | ✔ |
| LCD 20x4 | 데이터 간단하게라도 봐야지 |  |
| | |
