/* HC-SR04 Sensor 
   The circuit:
  * VCC connection of the sensor attached to +5V
  * GND connection of the sensor attached to ground
  * TRIG connection of the sensor attached to digital pins
  * ECHO connection of the sensor attached to digital pins
 */
// SORRY FOR THE CANCER THIS CODE MIGHT GIVE YOU, it has been written by a beginer, :3
#include <Servo.h> 


int trigPin1 = 2;
int echoPin1 = 3;
int trigPin2 = A0;
int echoPin2 = A1;
int trigPin3 = 8;
int echoPin3 = 9;
int trigPin4 = 10;
int echoPin4 = 11;
int trigPin5 = 4;
int echoPin5 = 7;
int trigPin6 = 13;
int echoPin6 = 12;
float tol[6];

float cm[6];
float cm2[6];

float d[6];

int personas = 0;

int Ad = 0;

unsigned long tim = 0;
unsigned long t0 = 0;

unsigned long data = 0;

int n=25;
int m=0;
Servo myservo;


void setup() {
  // initialize serial communication:
  Serial.begin(9600);
    myservo.attach(6);
  myservo.write(55);
  Serial.print("Calibrating, please wait...    ");
 int x=0;
 while (x<200)
 {
  x++;
  // establish variables for duration of the ping, 
  // and the distance result in inches and centimeters:
  long duration,duration1,duration2,duration3;

  long cm[6];

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trigPin1, OUTPUT);
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(10);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin1, INPUT);
  duration1 = pulseIn(echoPin1, HIGH);

  delay(1);

   // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trigPin1, OUTPUT);
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(10);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin1, INPUT);
  duration2 = pulseIn(echoPin1, HIGH);

    delay(1);

   // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trigPin1, OUTPUT);
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(10);
  
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin1, INPUT);
  duration3 = pulseIn(echoPin1, HIGH);

 
  // convert the time into a distance
  cm[0] = ((duration1+duration2+duration3)/3) / 29 / 2;
  
 //   Serial.print(cm[0], 2);
 // Serial.print(" cm[0]  ");

  delay(1);
  


 pinMode(trigPin2, OUTPUT);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(10);
    
    pinMode(echoPin2, INPUT);
  duration1 = pulseIn(echoPin2, HIGH);

    delay(1);

   pinMode(trigPin2, OUTPUT);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(10);
    
    pinMode(echoPin2, INPUT);
  duration2 = pulseIn(echoPin2, HIGH);

    delay(1);

   pinMode(trigPin2, OUTPUT);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(10);
    
    pinMode(echoPin2, INPUT);
  duration3 = pulseIn(echoPin2, HIGH);
  
  delay(1);
  
    cm[1] = ((duration1+duration2+duration3)/3) / 29 / 2;

//  Serial.print(cm[1], 2);
// Serial.print(" cm[1]  ");
  
    pinMode(trigPin3, OUTPUT);
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(10);
  
    pinMode(echoPin3, INPUT);
  duration = pulseIn(echoPin3, HIGH);
    cm[2] = duration / 29 / 2;

//  Serial.print(cm[2], 2);
//  Serial.print(" cm[2]  ");

  
  delay(1);
  
  
    pinMode(trigPin4, OUTPUT);
  digitalWrite(trigPin4, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin4, LOW);
  delayMicroseconds(10);
  
    pinMode(echoPin4, INPUT);
  duration = pulseIn(echoPin4, HIGH);
    cm[3] = duration / 29 / 2;

 // Serial.print(cm[3], 2);
 // Serial.print(" cm[3]  ");

  
  delay(1);

    pinMode(trigPin5, OUTPUT);
  digitalWrite(trigPin5, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin5, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin5, LOW);
  delayMicroseconds(10);
    
    pinMode(echoPin5, INPUT);
  duration = pulseIn(echoPin5, HIGH);
    cm[4] = duration / 29 / 2;

 // Serial.print(cm[4], 2);
//  Serial.print(" cm[4]  ");

  
  delay(1);

    pinMode(trigPin6, OUTPUT);
  digitalWrite(trigPin6, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin6, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin6, LOW);
  delayMicroseconds(10);
    
    pinMode(echoPin6, INPUT);
  duration = pulseIn(echoPin6, HIGH);
    cm[5] = duration / 29 / 2;  

  d[0] += cm[0];
  d[1] += cm[1];
  d[2] += cm[2];
  d[3] += cm[3];
  d[4] += cm[4];
  d[5] += cm[5]; 
  
  delay(10);



}


for (int h = 0; h<6; h++)
{
  d[h] /= 200;
  tol[h]=0.2*d[h];
}
  
/*
  Serial.print("Calibration");
  Serial.print(d[0],2);
  Serial.print(",");
  Serial.print(d[1],2);
    Serial.print(",");
    
  Serial.print(d[2],2);
    Serial.print(",");
  Serial.print(d[3],2);
    Serial.print(",");
  Serial.print(d[4],2);
    Serial.print(",");
  Serial.println(d[5],2);
    Serial.println("--------------------------------------------------");
    
  */
    Serial.println("Calibration Complete");
  
}

void loop()
{
  int change = 0;
  
  // establish variables for duration of the ping, 
  // and the distance result in inches and centimeters:
  long duration,duration1,duration2,duration3;

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trigPin1, OUTPUT);
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(10);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin1, INPUT);
  duration1 = pulseIn(echoPin1, HIGH);

  delay(1);

   // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trigPin1, OUTPUT);
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(10);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin1, INPUT);
  duration2 = pulseIn(echoPin1, HIGH);

    delay(1);

   // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trigPin1, OUTPUT);
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(10);
  
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin1, INPUT);
  duration3 = pulseIn(echoPin1, HIGH);

 
  // convert the time into a distance
  cm[0] = ((duration1+duration2+duration3)/3) / 29 / 2;
  
 //   Serial.print(cm[0], 2);
 // Serial.print(" cm[0]  ");

  delay(1);
  


 pinMode(trigPin2, OUTPUT);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(10);
    
    pinMode(echoPin2, INPUT);
  duration1 = pulseIn(echoPin2, HIGH);

    delay(1);

   pinMode(trigPin2, OUTPUT);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(10);
    
    pinMode(echoPin2, INPUT);
  duration2 = pulseIn(echoPin2, HIGH);

    delay(1);

   pinMode(trigPin2, OUTPUT);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(10);
    
    pinMode(echoPin2, INPUT);
  duration3 = pulseIn(echoPin2, HIGH);
  
  delay(1);
  
    cm[1] = ((duration1+duration2+duration3)/3) / 29 / 2;

//  Serial.print(cm[1], 2);
// Serial.print(" cm[1]  ");
  
    pinMode(trigPin3, OUTPUT);
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(10);
  
    pinMode(echoPin3, INPUT);
  duration = pulseIn(echoPin3, HIGH);
    cm[2] = duration / 29 / 2;

//  Serial.print(cm[2], 2);
//  Serial.print(" cm[2]  ");

  
  delay(1);
  
  
    pinMode(trigPin4, OUTPUT);
  digitalWrite(trigPin4, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin4, LOW);
  delayMicroseconds(10);
  
    pinMode(echoPin4, INPUT);
  duration = pulseIn(echoPin4, HIGH);
    cm[3] = duration / 29 / 2;

 // Serial.print(cm[3], 2);
 // Serial.print(" cm[3]  ");

  
  delay(1);

    pinMode(trigPin5, OUTPUT);
  digitalWrite(trigPin5, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin5, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin5, LOW);
  delayMicroseconds(10);
    
    pinMode(echoPin5, INPUT);
  duration = pulseIn(echoPin5, HIGH);
    cm[4] = duration / 29 / 2;

 // Serial.print(cm[4], 2);
//  Serial.print(" cm[4]  ");

  
  delay(1);

    pinMode(trigPin6, OUTPUT);
  digitalWrite(trigPin6, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin6, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin6, LOW);
  delayMicroseconds(10);
    
    pinMode(echoPin6, INPUT);
  duration = pulseIn(echoPin6, HIGH);
    cm[5] = duration / 29 / 2;

    tim = millis();



for (int j =0; j<6; j++)
{
  cm2[j] = (cm2[j]*20 + cm[j])/21;
}

for (int i =0; i<6; i++)
{
  if ((cm[i]+tol[i] < d[i]) && (m == 0)) 
  {
    m = 1;
    t0 = millis();
    personas++;
    change = 1;
  }
  if (millis()-t0 >= 1100)
  {
    m = 0;
  }
}

if( change == 1)
  {
    /*
  Serial.print(cm[0],2);
  Serial.print(",");
  Serial.print(cm[1],2);
    Serial.print(",");
  Serial.print(cm[2],2);
    Serial.print(",");
  Serial.print(cm[3],2);
    Serial.print(",");
  Serial.print(cm[4],2);
    Serial.print(",");
  Serial.print(cm[5],2);
    Serial.print(",");*/
    Serial.print("Amount of people: ");
    Serial.print(personas);
    Serial.print("    Datelog: ");
    Serial.println(tim);
  }

  delay(10);
  /*
m=1+m;
  if (m<25){
    myservo.write(n);
    n=3+n;
    delay(100);
      }
  else if (m<50){
    myservo.write(n);
    n=n-3;
    delay(100);
    }
  else if (m>=50){
    m=0;
    n=25 ;
  }*/
}



