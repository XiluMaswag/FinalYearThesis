// Digital Analytics
int TriggerPin = 2;
int EchoPin = 3;
int MotionSensor = 5;
int BAUD_RATE = 9600;

// Analogue Analtyics
int AnalogueMS = A1;
int AnalogueEcho = A2;
int AnalogueTrig = A3;

void setup() {
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  Serial.begin(BAUD_RATE);
}

void loop() {
  digitalWrite(TriggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TriggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TriggerPin, LOW);

  int  MS_val = (analogRead(AnalogueMS));;

  const unsigned long duration = pulseIn(EchoPin, HIGH);
  const unsigned long duration_in_ms = duration/29;
  int distance = duration_in_ms / 2;
  
  if (duration == 0) 
  {
    Serial.print("Warning: no pulse from sensor");
  }
  else 
  {
    if(digitalRead(MotionSensor)== HIGH )
     {
     Serial.print(MS_val);
     Serial.print(","); 
     Serial.print("Motion detected");
     Serial.print(",");
     }
    else if (digitalRead(MotionSensor)== LOW )
      {
      Serial.print(MS_val);
      Serial.print(",");
      Serial.print("No motion detected");
      Serial.print(",");
      }
    //Serial.print("distance to nearest object:");
    long speed_of_approach = duration_in_ms/distance;
    Serial.print(duration);
    Serial.print(",");
    Serial.print("duration");
    Serial.print(",");
    Serial.print(duration_in_ms);
    Serial.print(",");
    Serial.print("duration_in_ms");
    Serial.print(",");
    Serial.print(distance);
    Serial.print(",");
    Serial.print("cm");
    Serial.print(",");
    Serial.print(speed_of_approach);
    Serial.print(",");
    Serial.print("cm/ms");
    Serial.print(",");
    //Serial.print(Echo_val);
    //Serial.print(",");
    //Serial.println(" cm");
  }
  Serial.println();
  delay(1000);
}
