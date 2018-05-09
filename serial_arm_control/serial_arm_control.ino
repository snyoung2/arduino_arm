// VarSpeedServo - Version: Latest

/*************************************************************

 *************************************************************

/* Comment this out to disable prints and save space */
//#define BLYNK_PRINT DebugSerial
// You could use a spare Hardware Serial on boards that have it (like Mega)
#include <SoftwareSerial.h>
//SoftwareSerial DebugSerial(2, 3); // RX, TX

#include <VarSpeedServo.h>
// Do not use Servo.h and VarSpeedServo.h at the same time, causes conflicts.

VarSpeedServo servoBase;
VarSpeedServo servoElbow;
VarSpeedServo servoGrip;

int angleBase = 140; // 100 and 40 initialize the arm straight down position
int angleElbow = 180; // 140 and 180 put it in "stow" position
int angleGrip = 70; //initialize gripper open (~20 is closed)

byte servoBasePin = 9;
byte servoElbowPin = 8;
byte servoGripPin = 7;

byte servoMin = 10;
byte servoMax = 170;
byte servoPosBase = 0;
byte servoPosElbow = 0;
byte servoPosGrip = 0;
byte newServoPos = servoMin;

const byte buffSize = 40;
char inputBuffer[buffSize];
const char startMarker = '<';
const char endMarker = '>';
byte bytesRecvd = 0;
boolean readInProgress = false;
boolean newDataFromPC = false;

char messageFromPC[buffSize] = {0};
int servoCommand = 0; // goal position of servo to move to

unsigned long curMillis;
unsigned long replyToPCinterval = 1000;

void setup()
{ // Debug console
  //DebugSerial.begin(9600);
  Serial.begin(9600);

  servoBase.attach(servoBasePin);// attach the signal pin of servo to arduino
  servoBase.write(angleBase);
  servoElbow.attach(servoElbowPin);// attach the signal pin of servo to arduino
  servoElbow.write(angleElbow);
  servoGrip.attach(servoGripPin);// attach the signal pin of servo to arduino
  servoGrip.write(angleGrip);

  // tell the PC we are ready
  Serial.println("<Arduino is ready>");

}

//=============

void loop() {

    curMillis = millis(); // current time in milliseconds since beginning of sketch
    getDataFromPC();
    updateServoPos();
    replyToPC();

}

//=============

void getDataFromPC() {

    // receive data from PC and save it into inputBuffer
    // Expects '<' and '>' as start and end markers, respectively.
  if(Serial.available() > 0) {

    char x = Serial.read();

      // the order of these IF clauses is significant

    if (x == endMarker) {
      readInProgress = false;
      newDataFromPC = true;
      inputBuffer[bytesRecvd] = 0;
      parseData();
    }

    if(readInProgress) {
      inputBuffer[bytesRecvd] = x;
      bytesRecvd ++;
      if (bytesRecvd == buffSize) {
        bytesRecvd = buffSize - 1;
      }
    }

    if (x == startMarker) {
      bytesRecvd = 0;
      readInProgress = true;
    }
  }
}


//=============

void parseData() {

    // split the data into its parts

  char * strtokIndx; // this is used by strtok() as an index

  strtokIndx = strtok(inputBuffer,","); // get the first part - the string
  strcpy(messageFromPC, strtokIndx); // copy it to messageFromPC

  strtokIndx = strtok(NULL, ",");
  servoCommand = atoi(strtokIndx);     // convert this part to an integer

}

//=============


void replyToPC() {
// creates a message & shows if data is parsed correctly
  if (newDataFromPC) {
    newDataFromPC = false;
    Serial.print("<Msg ");
    Serial.print(messageFromPC);
    Serial.print(" SrvCmd ");
    Serial.print(servoCommand);
    Serial.print(" SrvPos ");
    Serial.print(newServoPos);
    Serial.print(" Time ");
    Serial.print(curMillis >> 9); // divide by 512 is approx = half-seconds
    Serial.println(">");
  }
}

//============

void updateServoPos() {

  byte servoRange = servoMax - servoMin;
  //if (servoFraction >= 0 && servoFraction <= 1) {
   // newServoPos = servoMin + ((float) servoRange * servoFraction);
 // }
  newServoPos = servoCommand;
  // this illustrates using different inputs to call different functions
  if (strcmp(messageFromPC, "Base") == 0) {
    moveBase();
  }
  if (strcmp(messageFromPC, "Elbow") == 0) {
    moveElbow();
  }
  if (strcmp(messageFromPC, "Grip") == 0) {
    moveGrip();
  }

}

//=============

void moveBase() {
  if (servoPosBase != newServoPos) {
    servoPosBase = newServoPos;
    servoBase.write(servoPosBase,20);
  }
}

void moveElbow() {
  if (servoPosElbow != newServoPos) {
    servoPosElbow = newServoPos;
    servoElbow.write(servoPosElbow,20);
  }
}

void moveGrip() {
  if (servoPosGrip != newServoPos) {
    servoPosGrip = newServoPos;
    servoGrip.write(servoPosGrip);
  }
}
