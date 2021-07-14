bool isTouched = false;

void setup() 
{ 
  pinMode(7, INPUT);
  pinMode(0, OUTPUT);
  digitalWrite(0, HIGH);
  Serial.begin(9600);
}

void loop() {
  
  if (Serial.available()) {
    
    char receivedString = Serial.read();

      //Serial.println(receivedString);
        
      if(receivedString == 'm') {
          isTouched = false;
          Serial.println("map_start");
      }
  }

  if (digitalRead(7) == HIGH && isTouched == false) {
    Serial.println('n');
    isTouched = true;
  }

}
