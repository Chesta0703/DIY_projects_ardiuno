/* This code is for a LASER Tripwire Alarm based on a light sensor, LASER module and a push button
 * The LASER is constantly sending beams to the sensor, when someone passes the light is not detected
 * and the alarm goes off, and will not stop until you press the button
 * Refer to www.surtrtech.com for more details
 */
 
#define Rec 0      //Light sensor output
#define Laser 2    //Laser module 
#define Button 3   //Push button input
#define LED 13
#define buzzer 12

bool detection;

void setup() {
  pinMode(buzzer,OUTPUT);
  pinMode(Laser, OUTPUT);
  pinMode(LED,OUTPUT);
  digitalWrite(Laser, HIGH); //Turning on the laser
  delay(2000);
}

void loop() {
  
 
 short Detect = analogRead(Rec);            //Constanly reading the module value
 bool  Button_state = digitalRead(Button);  //And the button value (1-0)
 
 Serial.println(analogRead(Rec));
 if(Detect < 700)              //The Max value is 760, if someone passes it goes below that (every value lower than 700 can do the work)
  {  detection = true; //The detection is triggered
    digitalWrite(LED,HIGH);
   tone(buzzer,2000);
   delay(50);
   tone(buzzer,1000);
   delay(50);
  }
 else {detection = false;
 digitalWrite(LED,LOW);
 noTone(buzzer);
 }

 

  
}
