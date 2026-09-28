
const unsigned long sampleTime = 1000;
const int maxRPM = 10000;       
int rpmMaximum = 0;

void setup() 
{
  pinMode(5,INPUT);
  Serial.begin(9600);
}

void loop() 
{

  int rpm = getRPM();
  Serial.print(rpm);
  Serial.print("\n");
  delay(400);
}

 
int getRPM()
{
  int count = 0;
  boolean countFlag = LOW;
  unsigned long currentTime = 0;
  unsigned long startTime = millis();
  while (currentTime <= sampleTime)
  {
    if (digitalRead(5) == HIGH)
    {
      countFlag = HIGH;
    }
    if (digitalRead(5) == LOW && countFlag == HIGH)
    {
      count++;
      countFlag=LOW;
    }
    currentTime = millis() - startTime;
  }
  int countRpm = int(60000/float(sampleTime))*count;
  return countRpm;
}
    
