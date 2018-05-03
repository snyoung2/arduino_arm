int in1Pin = 13;
int in2Pin = 12;
int m21 = 11;
int m22 = 10;
int m31 = 9;
int m32 = 8;
int m41 = 7;
int m42 = 5;
int m51 = 4;
int m52 = 3;

 
void setup()
{
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(m22, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m32, OUTPUT);
  pinMode(m31, OUTPUT);
  pinMode(6, OUTPUT);
  
  
  Serial.begin(9600);
  while (! Serial);

  Serial.println("Enter the first number for the motor and the next 3 for the change in angle (Between 000 and 120)");
}
 
void loop()
{
  if (Serial.available())
    
  { int angle = Serial.parseInt();

    if (angle >= 1000 && angle <= 1120)
      {int speed = 225;
    
      analogWrite(6,speed);
      digitalWrite(in1Pin, LOW);
      digitalWrite(in2Pin, HIGH);
      Serial.println("Motor 1 Forward");

      int time = (int(angle)-1000) *50;
      //change last number for angle calibration
      delay(time);
      speed = 0;
      analogWrite(6,speed);
      digitalWrite(in1Pin, LOW);
      digitalWrite(in2Pin, LOW);
      }
    else if (angle >= -1120 && angle <= -1000)
      {int speed = 225;
    
      analogWrite(6,speed);
      digitalWrite(in1Pin, HIGH);
      digitalWrite(in2Pin, LOW);
      Serial.println("Motor 1 Reverse");

      int time = (-1*(int(angle))-1000) *50;
      //change last number for angle calibration
      delay(time);
      speed = 0;
      analogWrite(6,speed);
      digitalWrite(in1Pin, LOW);
      digitalWrite(in2Pin, LOW);
      }

    else if (angle >= 2000 && angle <= 2120)
      {int speed = 225;
    
      analogWrite(6,speed);
      digitalWrite(m21, LOW);
      digitalWrite(m22, HIGH);
      Serial.println("Motor 2 Forward");

      int time = (int(angle)-2000) *50;
      //change last number for angle calibration
      delay(time);
      speed = 0;
      analogWrite(6,speed);
      digitalWrite(m21, LOW);
      digitalWrite(m22, LOW);
      }
    else if (angle >= -2120 && angle <= -2000)
      {int speed = 225;
    
      analogWrite(6,speed);
      digitalWrite(m21, HIGH);
      digitalWrite(m22, LOW);
      Serial.println("Motor 2 Reverse");

      int time = (-1*(int(angle))-2000) *50;
      //change last number for angle calibration
      delay(time);
      speed = 0;
      analogWrite(6,speed);
      digitalWrite(m22, LOW);
      digitalWrite(m21, LOW);
      }

    else if (angle >= 3000 && angle <= 3120)
      {int speed = 225;
    
      analogWrite(6,speed);
      digitalWrite(m31, LOW);
      digitalWrite(m32, HIGH);
      Serial.println("Motor 3 Forward");

      int time = (int(angle)-3000) *50;
      //change last number for angle calibration
      delay(time);
      speed = 0;
      analogWrite(6,speed);
      digitalWrite(m31, LOW);
      digitalWrite(m32, LOW);
      }
    else if (angle >= -3120 && angle <= -3000)
      {int speed = 225;
    
      analogWrite(6,speed);
      digitalWrite(m31, HIGH);
      digitalWrite(m32, LOW);
      Serial.println("Motor 3 Reverse");

      int time = (-1*(int(angle))-3000) *50;
      //change last number for angle calibration
      delay(time);
      speed = 0;
      analogWrite(6,speed);
      digitalWrite(m31, LOW);
      digitalWrite(m32, LOW);
      }

    else if (angle >= 4000 && angle <= 4120)
      {int speed = 225;
    
      analogWrite(6,speed);
      digitalWrite(m41, LOW);
      digitalWrite(m42, HIGH);
      Serial.println("Motor 4 Forward");

      int time = (int(angle)-4000) *25;
      //change last number for angle calibration
      delay(time);
      speed = 0;
      analogWrite(6,speed);
      digitalWrite(m41, LOW);
      digitalWrite(m42, LOW);
      }
    else if (angle >= -4120 && angle <= -4000)
      {int speed = 225;
    
      analogWrite(6,speed);
      digitalWrite(m41, HIGH);
      digitalWrite(m42, LOW);
      Serial.println("Motor 4 Reverse");

      int time = (-1*(int(angle))-4000) *25;
      //change last number for angle calibration
      delay(time);
      speed = 0;
      analogWrite(6,speed);
      digitalWrite(m41, LOW);
      digitalWrite(m42, LOW);
      }




      else if (angle >= 5000 && angle <= 5120)
      {int speed = 225;
    
      analogWrite(6,speed);
      digitalWrite(m51, HIGH);
      digitalWrite(m52, LOW);
      Serial.println("Motor 5 Right");

      int time = (int(angle)-5000) *50;
      //change last number for angle calibration
      delay(time);
      speed = 0;
      analogWrite(6,speed);
      digitalWrite(m51, LOW);
      digitalWrite(m52, LOW);
      }
    else if (angle >= -5120 && angle <= -5000)
      {int speed = 225;
    
      analogWrite(6,speed);
      digitalWrite(m51, LOW);
      digitalWrite(m52, HIGH);
      Serial.println("Motor 5 Left");

      int time = (-1*(int(angle))-5000) *50;
      //change last number for angle calibration
      delay(time);
      speed = 0;
      analogWrite(6,speed);
      digitalWrite(m51, LOW);
      digitalWrite(m52, LOW);
      }
  }
}
