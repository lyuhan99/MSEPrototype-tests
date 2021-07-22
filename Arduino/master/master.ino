// this code will run on the arduiino that will SEND information 
#include<Wire.h>
int x = 10;  //the integer (for now hardcoded)that you want to send to the other arduino
void setup() 
{
  // Start the I2C Bus as Master
  Serial.begin(9600);
  Wire.begin(); 
}
void loop() 
{
  Wire.beginTransmission(9); // transmit to device #9
  Serial.print("sent value = ");
  Serial.println(x);         
  Wire.write(x);           // sends x 
  Wire.endTransmission();    // stop transmitting  
  delay(2000);
}
