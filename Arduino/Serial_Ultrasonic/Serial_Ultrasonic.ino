const int tresh = 10;
int sensorNum = 1;
bool isMapEnd = false;

bool detect = false;

const int trig1 = 1;
const int trig2 = 2;
const int trig3 = 3;
const int trig4 = 4;

const int echo1 = 8;
const int echo2 = 9;
const int echo3 = 10;
const int echo4 = 11;

long duration1 = 0;
long distance1 = 0;

long duration2 = 0;
long distance2 = 0;

long duration3 = 0;
long distance3 = 0;

long duration4 = 0;
long distance4 = 0;

void setup() 
{ 
  randomSeed(analogRead(0));
  
  pinMode(trig1 , OUTPUT);
  pinMode(trig2 , OUTPUT);
  pinMode(trig3 , OUTPUT);
  pinMode(trig4 , OUTPUT);
  
  pinMode(echo1 , INPUT);
  pinMode(echo2 , INPUT);
  pinMode(echo3 , INPUT);
  pinMode(echo4 , INPUT);
  
  Serial.begin(9600);
}

void loop() {
  
  if (Serial.available()) {
    
    char receivedString = Serial.read();

      //Serial.println(receivedString);
        
      if(receivedString == 'm') {
          isMapEnd = false;
          Serial.println("map_start");
          sensorNum = random(1,5); 
          delay(5000);
          Serial.println(sensorNum);
          if (sensorNum == 1) {
            sonic2();
          } else if (sensorNum == 2) {
            sonic3();  
          } else if (sensorNum == 3) {
            sonic4();  
          } else if (sensorNum == 4) {
            sonic1();  
          }
      }
  }

  if (detect && isMapEnd == false) {
    detect = false;
    Serial.println('n');
    isMapEnd = true;
  }
}

void sonic1(){

//  while(!detect) {
//    digitalWrite(trig1 , HIGH);
//    delayMicroseconds(10);
//    digitalWrite(trig1 , LOW);
//  
//    duration1 = pulseIn(echo1 , HIGH);
//    distance1 = (duration1/2) / 28.5 ; 
//    
//    if (distance1 < tresh && distance1 > 0) {
//      Serial.print("Sonic4: "); 
//      Serial.println(distance1);
//      detect = !detect;  
//    }
//  }
  delay(5000);
  detect = !detect;
}

void sonic2() {

  while(!detect) {
    digitalWrite(trig2 , HIGH);
    delayMicroseconds(10);
    digitalWrite(trig2 , LOW);
  
    duration2 = pulseIn(echo2 , HIGH);
    distance2 = (duration2/2) / 28.5 ;  
     
    if (distance2 < tresh && distance2 > 0) { 
      Serial.print("Sonic1: "); 
      Serial.println(distance2);
      detect = !detect;
    }
  }
}

void sonic3() {

  while(!detect) {
    digitalWrite(trig3 , HIGH);
    delayMicroseconds(10);
    digitalWrite(trig3 , LOW);
  
    duration3 = pulseIn(echo3 , HIGH);
    distance3 = (duration3/2) / 28.5 ;  
    
    if (distance3 < tresh && distance3 > 0) {
      Serial.print("Sonic2: "); 
      Serial.println(distance3);
      detect = !detect;
    }
  }
}

void sonic4() {
  
  while(!detect) {
    digitalWrite(trig4 , HIGH);
    delayMicroseconds(10);
    digitalWrite(trig4 , LOW);
  
    duration4 = pulseIn(echo4 , HIGH);
    distance4 = (duration4/2) / 28.5 ;  
    
    if (distance4 < tresh && distance4 > 0) {
      Serial.print("Sonic3: "); 
      Serial.println(distance4);
      detect = !detect;
    }
  }
}
