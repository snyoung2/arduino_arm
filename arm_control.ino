// VarSpeedServo - Version: Latest 

/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Social networks:            http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  =>
  =>          USB HOWTO: http://tiny.cc/BlynkUSB
  =>

  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT DebugSerial
// You could use a spare Hardware Serial on boards that have it (like Mega)
#include <SoftwareSerial.h>
SoftwareSerial DebugSerial(2, 3); // RX, TX

#include <BlynkSimpleStream.h>
#include <VarSpeedServo.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "61f5c717e6e14e22bc142d3384115a1d";

VarSpeedServo servo1;
VarSpeedServo servo2;
VarSpeedServo servo3;

int motorpin =9;
int angle1 = 0;
int angle2 = 0;
int angle3 = 0;

void setup() 
{ // Debug console
  DebugSerial.begin(9600);
  // Blynk will work through Serial
  // Do not read or write this serial manually in your sketch 
  Serial.begin(9600);
  Blynk.begin(Serial, auth);

  Blynk.syncVirtual(V1);  
  Blynk.syncVirtual(V2);  
  Blynk.syncVirtual(V3);  

  servo1.attach(9);// attach the signal pin of servo to pin9 of arduino
  servo1.write(angle1);
  servo2.attach(8);// attach the signal pin of servo to pin9 of arduino
  servo2.write(angle2);
  servo3.attach(7);// attach the signal pin of servo to pin9 of arduino
  servo3.write(angle3);
} 

BLYNK_WRITE(V1)
{
 angle1 = param.asInt(); // assigning incoming value from pin V1 to a variable 
}

BLYNK_WRITE(V2)
{
 angle2 = param.asInt(); // assigning incoming value from pin V1 to a variable 
}

 BLYNK_WRITE(V3)
{
 angle3 = param.asInt(); // assigning incoming value from pin V1 to a variable 
}

 
void loop() 
{ 
  if(angle1>2*(180-angle2))
  {
    angle1=2*(180-angle2))
  } //Position limitation
  
  Blynk.run();
   servo1.write(angle1,50); 
   servo2.write(angle2,50);
   servo3.write(angle3,50);
}
