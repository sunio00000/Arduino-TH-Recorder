int RXLED = 17;

void setup() {
  pinMode(RXLED, OUTPUT);
  Serial.begin(9600);
  Serial1.begin(9600);
  while(!Serial)
  Serial.print("??");
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RXLED, LOW);
  TXLED0;
  delay(250);
  digitalWrite(RXLED, HIGH);
  TXLED1;
  delay(250);
}
