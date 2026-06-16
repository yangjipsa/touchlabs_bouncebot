int SWL = 8;
int SWR = 7;

void setup() 
{
  Serial.begin(9600);
  pinMode(SWL, INPUT);
  pinMode(SWR, INPUT);
}

void loop() 
{
  int BumperL = digitalRead(SWL);
  int BumperR = digitalRead(SWR);
  Serial.print("Bumper L :"); 
  Serial.print(BumperL);
  Serial.print(", Bumper R :");
  Serial.println(BumperR);
  delay(100);
}
