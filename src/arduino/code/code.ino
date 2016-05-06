/*
ADXL335
note:vcc-->5v ,but ADXL335 Vs is 3.3V
The circuit:
      5V: VCC
analog 1: x-axis
analog 2: y-axis
analog 3: z-axis
*/

#include <Wire.h>

const int xpin = 1;                  // x-axis of the accelerometer
const int ypin = 2;                  // y-axis
const int zpin = 3;                  // z-axis (only on 3-axis models)

float x_adjusted;
float y_adjusted;
float z_adjusted;

void setup()
{
  // initialize the serial communications:
  Serial.begin(9600);

  // Initialize i2c
  Wire.begin(0x8);
  Wire.onRequest(requestEvent);
}
void loop()
{
  int x = analogRead(xpin);  //read from xpin
  delay(1);
  int y = analogRead(ypin);  //read from ypin
  delay(1);  
  int z = analogRead(zpin);  //read from zpin

  x_adjusted = ((float)x - 331.5)/65*9.8;
  y_adjusted = ((float)y - 329.5)/68.5*9.8;
  z_adjusted = ((float)z - 340)/68*9.8;
  
  Serial.print(x);  //print x value on serial monitor
  Serial.print("\t");
  Serial.print(y);  //print y value on serial monitor
  Serial.print("\t");
  Serial.print(z);  //print z value on serial monitor
  Serial.print("\n");
  delay(1000);  //wait for 1 second 
}

void requestEvent() {
  Serial.println("i2c!");
  Wire.write("hello ");
}

