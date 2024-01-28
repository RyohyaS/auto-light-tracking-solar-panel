#include <Servo.h>

Servo myservo;

//for arduino
int ldrPin1 = A0; 
int ldrPin2 = A1; 
int ldrPin3 = A2; 

//for esp32
// int ldrPin1 = 36;   //UP
// int ldrPin2 = 39;   //UN
// int ldrPin3 = 34;   //D34


int threshold = 100;  // adjust this threshold to set the sensitivity of light detection

void setup() {
  myservo.attach(9);  // attach servo on arduino pin 9    
  //myservo.attach(12); // attach servo on esp32 pin D12

  Serial.begin(9600);
  moveServo(90);
}

void loop() {
  int ldrValue1 = analogRead(ldrPin1) * 2;
  int ldrValue2 = analogRead(ldrPin2) * 1.2;
  int ldrValue3 = analogRead(ldrPin3) * 1.2;

  Serial.print("   ");
  Serial.print("LDR1-> ");
  Serial.print(ldrValue1);
  Serial.print("    ,    ");
  Serial.print("LDR2-> ");
  Serial.print(ldrValue2);
  Serial.print("    ,    ");
  Serial.print("LDR3-> ");
  Serial.println(ldrValue3);

 if (ldrValue1 > threshold && ldrValue1 > ldrValue2 && ldrValue1 > ldrValue3) {
    Serial.print("val1");
    moveServo(85); // Move servo towards LDR 1
  } else if (ldrValue2 > threshold && ldrValue2 > ldrValue1 && ldrValue2 > ldrValue3) {
    Serial.print("val2");
    moveServo(90); // Move servo towards LDR 2
  } else if (ldrValue3 > threshold && ldrValue3 > ldrValue1 && ldrValue3 > ldrValue2) {
    Serial.print("val3");
    moveServo(93); // Move servo towards LDR 3
  } else {
    Serial.print("none");
  }

  delay(100); // Adjust the delay according to your requirements
}

void moveServo(int angle) {
    myservo.write(angle);
    delay(100);
}
