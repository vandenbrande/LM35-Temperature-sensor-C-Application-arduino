const int analogIn = A0;

int RawValue= 0;
double Voltage = 0;
double tempC = 0;
double tempF = 0;

void setup(){  
  Serial.begin(9600); 
}

void loop(){
  
  RawValue = analogRead(analogIn);
  Voltage = (RawValue / 1023.0) * 5000; // 5000 to get millivots.
  tempC = Voltage * 0.1; // 500 is the offset
  tempF = (tempC * 1.8) + 32; // conver to F      
  

  Serial.println(tempC,1);
//  Serial.println(tempF,1);//uncomment for fahrenheit
  delay(500);  
}
