//this code reads the value of the resistance on the potentiometer and prints them on the screen
int potmeterPin = A0;              // Slide potentiometer input on pin A0
int potmeterVal = 0;               // Slide potentiometer value

void setup() {
  Serial.begin(9600);              // Initialise the serial monitor
}

void loop() {
  
  potmeterVal = analogRead(potmeterPin);    // Read the analog value of the slide potentiometer
  
  Serial.println(potmeterVal);              // Show the value on the serial monitor

  delay(100);                               // Pause 100ms
  
}
