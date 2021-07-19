  // this is used to turn on or off 2 leds based on turning direction of knob and it prints on serial monitor a value that increases or decreases contiuously based on turning direction of knob
 #define inputCLK2 8
 #define inputDT2 9
 #define inputCLK1 4
 #define inputDT1 5

int potmeterPin = A5;              // Slide potentiometer input on pin A0
int potmeterVal = 0;               // Slide potentiometer value
int potmeterValprev = 0; 

int switch_pin = 11;
int counter=1;
 
 int counter1 = 0; 
 int counter2 = 0; 
 int currentStateCLK1;
 int previousStateCLK1;
 int currentStateCLK2;
 int previousStateCLK2; 

 String encdir1 ="";
 String encdir2 ="";
 
 void setup() 
 { 
   pinMode(switch_pin, INPUT);  
   // Set encoder pins as inputs  
   pinMode (inputCLK1,INPUT);
   pinMode (inputDT1,INPUT);
   pinMode (inputCLK2,INPUT);
   pinMode (inputDT2,INPUT);

   
   // Setup Serial Monitor
   Serial.begin (9600);
   
   // Read the initial state of inputCLK
   // Assign to previousStateCLK variable
   previousStateCLK2 = digitalRead(inputCLK2);
   previousStateCLK1 = digitalRead(inputCLK1);
 } 

 void loop() 
 { 
  
  // Read the current state of inputCLK
   currentStateCLK2 = digitalRead(inputCLK2);
   currentStateCLK1 = digitalRead(inputCLK1);
   // If the previous and the current state of the inputCLK are different then a pulse has occured
   if (currentStateCLK1 != previousStateCLK1)
   { 
    //Serial.print("knob 1 has rotated");
     // If the inputDT state is different than the inputCLK state then 
     // the encoder is rotating counterclockwise
     if (digitalRead(inputDT1) != currentStateCLK1) 
     { 
       counter1++;
       encdir1 ="heat_up";
     } 
     else 
     {
       // Encoder is rotating clockwise
       counter1--;
       encdir1 ="heat_down";
     }
     //Serial.print(" Direction: ");
     Serial.println(encdir1);
//     Serial.print(" -- Value: ");
//     Serial.println(counter1);
   }

   
   if (currentStateCLK2 != previousStateCLK2)
   { 
     //Serial.print("knob 2 has rotated");
     // If the inputDT state is different than the inputCLK state then 
     // the encoder is rotating counterclockwise
     if (digitalRead(inputDT2) != currentStateCLK2) 
     { 
       counter2++;
       encdir2 ="tap_up";
     } 
     else 
     {
       // Encoder is rotating clockwise
       counter2--;
       encdir2 ="tap_down";
     }
     //Serial.print(" Direction: ");
     Serial.println(encdir2);
 //     Serial.print(" -- Value: ");
//     Serial.println(counter2);
   } 
   // Update previousStateCLK with the current state
   previousStateCLK1 = currentStateCLK1;
   previousStateCLK2 = currentStateCLK2; 
/////////////////////////////////////////////////////////////////

  if(digitalRead(switch_pin) == LOW)
  {
    if (counter == 1)
    {
        Serial.println("switch_off");
        delay(100);   
        counter=0;
    }

  }
  if(digitalRead(switch_pin) == HIGH)
  {
    if (counter == 0)
    {
        Serial.println("switch_on");
        delay(100);   
        counter=1;
    }
  }
///////////////////////////////////////////////////////////////

  potmeterVal = analogRead(potmeterPin);    // Read the analog value of the slide potentiometer
  potmeterVal = map(potmeterVal,0,1000,1,8);
  if (potmeterVal != potmeterValprev)
  {
    Serial.print("slide_");              // Show the value on the serial monitor
    Serial.println(potmeterVal);
    delay(100);
  }
  potmeterValprev = potmeterVal;
  
 }
