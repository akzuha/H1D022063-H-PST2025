#include <Arduino.h>
#include <Servo.h>

Servo myServo;
int echoPin = D2;
int trigPin = D3;
long duration;
int distance;
bool objectDetected = false;

void setup() {
  myServo.attach(D0);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.write(0);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if (distance <= 15) {
    if (!objectDetected) {
      myServo.write(90);
      Serial.println("Kendaraan terdeteksi, pintu terbuka");
      objectDetected = true;   
    }
  } else {
    if (objectDetected) {
      myServo.write(0);
      Serial.println("Kendaraan sudah lewat, pintu menutup");    
      objectDetected = false;
    }
  }

  delay(100);
}
