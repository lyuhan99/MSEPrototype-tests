//this code will run on the arduino that receives information
#include<Wire.h>
int receivedX = 0;
void setup() 
{
  Serial.begin(9600);
  // Start the I2C Bus as Slave on address 9
  Wire.begin(9); 
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
}
void receiveEvent(int bytes) 
{
  receivedX = Wire.read();    // read/receives one character from the I2C
}
void loop() 
{
   Serial.print("received value = ");
   Serial.println(receivedX);
   delay(2000);
}
