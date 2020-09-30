/****************************************************************************************************
Author: Zecong Liang
Date of Creation: 9/29/2020

Description: Main file that calls upon sensors and executes functions

****************************************************************************************************/

int tempLogicPin = 0; //Sets the logic pin for temp sensor to A0

void setup()
{
  Serial.begin(9600);
  analogReference(EXTERNAL);
}

void loop()
{
 //TBD
}


/****************************************************************************************************
Function Name: getTemp
Parameters:
  1) N/A

Description: Reads TMP36 sensor, converts analog value, and returns the temperature in degrees F

****************************************************************************************************/
float getTemp()
{
  int tempRead = analogRead(tempLogicPin); //reads temp sensor output connected to pin A0
  float tempC = ((tempRead * 3.3 / 1024) - 0.5 ) * 100; //conversion from analog value to Celsius
  float tempF = tempC * 1.8 + 32; //conversion to Farenheit from Celsius
  
  return tempF;
}
