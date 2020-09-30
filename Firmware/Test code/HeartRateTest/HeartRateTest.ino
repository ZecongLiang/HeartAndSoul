#include <Math.h>
double threshold = 860;
double refractoryPeriod = 300;
double bpm = 0;
double lastTime = 0;
double pulse = 0;
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop()
{
  
  pulse = analogRead(A0);
  
  if(pulse > threshold && ((millis() - lastTime) > refractoryPeriod))
  {
    bpm = 60000.0 / ((millis() - lastTime));
    lastTime = millis();
  }
  
  Serial.print(bpm);
  Serial.print(" , ");
  Serial.println(pulse);
  delay(20);
}
