#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

// Motor driver pins (L298N or similar)
#define IN1 27
#define IN2 26
#define IN3 25
#define IN4 33

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_VoiceBot");  // Bluetooth device name

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopMotors();

  Serial.println("Voice Controlled Robot Ready!");
  Serial.println("Connect Bluetooth and give voice commands...");
}

void loop() {
  if (SerialBT.available()) {
    String command = SerialBT.readStringUntil('\n');
    command.toLowerCase();
    command.trim();

    Serial.print("Command: ");
    Serial.println(command);

    if (command == "forward") {
      forward();
    } else if (command == "backward") {
      backward();
    } else if (command == "left") {
      left();
    } else if (command == "right") {
      right();
    } else if (command == "stop") {
      stopMotors();
    } else {
      Serial.println("Unknown command!");
    }
  }
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Moving Forward");
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Moving Backward");
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Turning Left");
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Turning Right");
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("Stopped");
}
