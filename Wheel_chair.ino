#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// Replace with your network credentials
char auth[] = "YOUR_BLYNK_AUTH_TOKEN";
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

// Motor pins
const int ENA = 26; // PWM pin for motor A
const int IN1 = 27; 
const int IN2 = 14;
const int ENB = 25; // PWM pin for motor B
const int IN3 = 33;
const int IN4 = 32;

BLYNK_WRITE(V1) { // Forward button
  int val = param.asInt();
  if(val == 1){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else {
    stopMotors();
  }
}

BLYNK_WRITE(V2) { // Reverse button
  int val = param.asInt();
  if(val == 1){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  } else {
    stopMotors();
  }
}

BLYNK_WRITE(V3) { // Left button
  int val = param.asInt();
  if(val == 1){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else {
    stopMotors();
  }
}

BLYNK_WRITE(V4) { // Right button
  int val = param.asInt();
  if(val == 1){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  } else {
    stopMotors();
  }
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void setup() {
  Serial.begin(115200);
  
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
}
