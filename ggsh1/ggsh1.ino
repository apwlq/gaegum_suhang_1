void setup() {
  pinMode(A0, INPUT);          // MQ-3 센서
  pinMode(12, INPUT_PULLUP);   // 버튼
  pinMode(8, OUTPUT);          // 릴레이
  pinMode(5, OUTPUT);          // 파랑
  pinMode(4, OUTPUT);          // 빨강
  Serial.begin(9600);
}

void loop() {
  int a = analogRead(A0);
  int b = digitalRead(12);
  int is = 0;
  
  Serial.print(a);
  Serial.print(" ");
  Serial.print(b);
  Serial.print(" ");
  
  if (a > 512 && b == 0) {
    is = 1;
    Serial.print("ON");
  } else {
    is = 0;
    Serial.print("OFF");
  }
  Serial.println();

  if (is == 1) {
    digitalWrite(8, LOW);
    digitalWrite(5, HIGH);
    delay(100);
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    delay(100);
    digitalWrite(4, LOW);
  } else {
    digitalWrite(8, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
  }

  delay(1000);

}
