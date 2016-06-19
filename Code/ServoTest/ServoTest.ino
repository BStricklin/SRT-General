int controlPin = 2;
int powerPin = 3;
int groundPin = 4;
int pulse = 1500;
int x = 0;

void setup() {
 
  Serial.begin(9600);
  pinMode(controlPin, OUTPUT);
  pinMode(powerPin, OUTPUT);
  pinMode(groundPin, OUTPUT);
    digitalWrite(groundPin, LOW);
  digitalWrite(powerPin, HIGH);

}

void loop() {


//  for (x = 0; x<=90; x+=1){
  digitalWrite(controlPin, HIGH);
  delayMicroseconds(pulse);
  digitalWrite(controlPin, LOW);
  delay(20);
//  }

//  delay(200);
//
//  digitalWrite(powerPin, LOW);
//  digitalWrite(groundPin, HIGH);
//  for (x = 0; x<=90; x+=1){
//  digitalWrite(controlPin, HIGH);
//  delayMicroseconds(pulse);
//  digitalWrite(controlPin, LOW);
//  delay(20);
//  }
//
//  delay(200);
}

