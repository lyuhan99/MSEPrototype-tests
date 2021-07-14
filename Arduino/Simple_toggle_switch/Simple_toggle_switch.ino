//this code uses the on/off function of the switch to turn an led on or off and print on or off on serial monitor. it can be made to do anythng instead of that

int switch_pin = 4;
int led_pin = 5;

byte leds = 0;

void setup() {
  pinMode(switch_pin, INPUT);
  pinMode(led_pin, OUTPUT);
  Serial.begin(9600)
}

void loop() {
  if(digitalRead(switch_pin) == HIGH){
    digitalWrite(led_pin, LOW);
    Serial.println("off")
  }
  if(digitalRead(switch_pin) == LOW){
    digitalWrite(led_pin, HIGH);
    Serial.println("on")
  }

}
