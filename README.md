# LM35-Temperature-sensor-C-Application-arduino
C# Windows application to read a value from a sensor. In this case the LM35 Temp sensor, you can add any sensor you like and simply send the value from arduino to the Serial COM Port.

Hello world! Today i made a Windows C# Application to read the temperature from a LM35 Temperature sensor.
The source is open to modify and included in the instructable downloads. The code is very simple and can read any sensor data written from arduino to serial, in this case Serial.println(tempC,1); If you want to use fahrenheit just uncomment the arduino part in the code Serial.println(tempF,1); You should now see fahrenheit without doing anything in the C# App. So, If you want to use another Arduino code that belongs to another Sensor all you need to do is print the value to serial and the app will read it. You might need to change the C# application a bit to fit the sensor data.
Files you modify in the C# source are the following. Form1.cs & Form.1Designer.cs To modify the look of the Application you simply double click on Form1.cs and the Form1.cs [Design] should pop up. You can now drag and drop buttons and whatever you want from the toolbox, and change background in the properties etc. If adding a button for example, double click the button to give it a function, Double clicking it will bring you to the part of the code that belongs to the button.
You can also change the about box by double clicking on the about box AboutBox1.cs, You can change background, font, colors etc. To change company name, version etc. you can double click Properties in the [solution explorer]. And then at [application] click on [assembly information], you can also modify AssemblyInfo.cs directly.

Below is the arduino code:

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

