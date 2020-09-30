int tempLogicPin = 0;

void setup()
{
  Serial.begin(9600);
  analogReference(EXTERNAL);
}

void loop()
{
 
  Serial.print(getTemp()); Serial.println(" degrees F");
}

float getTemp()
{
  int tempRead = analogRead(tempLogicPin);
  float tempC = ((tempRead * 3.3 / 1024) - 0.5 ) * 100;
  float tempF = tempC * 1.8 + 32;
  
  return tempF;
}
