#include <Servo.h> //Include Servo Library

  const int stepPin = 2; //Set Arduino pins used for Stepper driver
  const int dirPin = 4;
  const long interval = (1000);
  unsigned long previousMillis = 0;

  Servo Xservo; //Assign Servos to names
  Servo Yservo;

  int Xpin=A0;
  int Ypin=A1;
  int Spin=6;
  int XSpin=9;
  int YSpin=10;
  int buzzPin=7;
  int WVx;
  int WVy;
  int Xval;
  int Yval;
  int Sval;
  int dt=200;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Xpin,INPUT);
  pinMode(Ypin,INPUT);
  pinMode(Spin,INPUT);
  pinMode(XSpin,OUTPUT);
  pinMode(YSpin,OUTPUT);
  pinMode(buzzPin,OUTPUT);
 
  Xservo.attach(XSpin);
  Yservo.attach(YSpin);
 
  digitalWrite(Spin,HIGH);

  pinMode(stepPin,OUTPUT);  //Makes Stepper pins output pins
  pinMode(dirPin,OUTPUT);
}
 
void loop() {
 Xval=analogRead(Xpin);
 WVx=(120./1023.)*Xval;
 Yval=analogRead(Ypin);
 WVy=(120./1023.)*Yval;
 Sval=digitalRead(Spin);
 
 
 Xservo.write(WVx);
 Yservo.write(WVy);
 
 if (Sval==0){
  digitalWrite(buzzPin, HIGH);
 }
 else {
  digitalWrite(buzzPin, LOW);
 }
 
 
 
 delay(dt);
 Serial.print("X Value = ");
 Serial.print(Xval);
 Serial.print(" Y Value = ");
 Serial.print(Yval);
 Serial.print(" Switch State is ");
 Serial.println(Sval);


 //STEPPER MOTOR CODE

    /*unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
        
    digitalWrite(dirPin,HIGH);
    for(int x = 0; x < 1600; x++)
    {
      digitalWrite(stepPin,HIGH);
      delayMicroseconds(300);
      digitalWrite(stepPin,LOW);
      delayMicroseconds(300);
    }
    
    digitalWrite(dirPin,LOW);
    for(int x = 0; x < 6400; x++)
    {
      digitalWrite(stepPin,HIGH);
      delayMicroseconds(300);
      digitalWrite(stepPin,LOW);
      delayMicroseconds(300);
    }
    }*/
}
