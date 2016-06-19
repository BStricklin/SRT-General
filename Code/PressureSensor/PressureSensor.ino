int dataPin = A3;
int data;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(dataPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  data = analogRead(dataPin);
  Serial.println(data);
  delay(200);
}
