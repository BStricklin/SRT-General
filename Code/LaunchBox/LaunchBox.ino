//All commands need to be accounted for in switch statement
//Should probably be "launching" state where launch box just
//reads data and passes it along (Comm Master checks for abort).

//Commands
//r - readys launch
//f - final launch ready
//l - LAUNCH
//a - abort
//s - returns state of variables

//Commands Meant for DAQ
//i - initialization: initializes SD card
//t - sensor test: sends sensor values ten times over 5 seconds
//c - collect data: collects data continuously. outputs over serial and saves. Also checks temp
//to make sure it's not too hot. Command to make pins go high to signal heat event are commented out
//e - exit data collect

char missionCMD;
String data;

void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);

}

void loop()
{
  missionCMD = Serial.read();
  Serial1.print(missionCMD);

  switch(missionCMD){
  case 'i':
    Serial1.println('i');
    Serial.println("LB: i passed");
    break;
  case 't':
    Serial1.println('t');
    Serial.println("LB: t passed");
    break;
  case 'c':
    Serial1.println('c');
    Serial.println("LB: c passed");
    break;
  case 'e':
    Serial1.println('e');
    Serial.println("LB: e passed");
    break;
  case 'r':
    Serial1.println('r');
    Serial.println("LB: r passed");
    break;
  case 'f':
    Serial1.println('f');
    Serial.println("LB: f passed");
    break;
  case 'l':
    Serial1.println('l');
    Serial.println("LB: l passed");
    break;
  case 's':
    Serial1.println('s');
    Serial.println("LB: s passed");
    break;
  case 'a':
    Serial1.println('s');
    Serial.println("LB: s passed");
    break;
  default:
    break;
  }

  if (Serial1.available())
  {
    data = Serial1.readStringUntil('\n');
    Serial.println(data);
  }
  
}
