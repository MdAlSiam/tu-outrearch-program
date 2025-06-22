#include "NewPing.h"
#include "TimerFreeTone.h"

#define TRIGGER_PIN 12
#define ECHO_PIN 11
#define MAX_DISTANCE 200

const int led = 10;
const int buzzer = 13;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int distance = sonar.ping_cm();
  Serial.println(distance);

  int buzzerdelay = distance*10;

  if (distance != 0) {
    Serial.println(distance);
    if (distance < 10 && distance != 0) {
      Serial.println("IT IS CLOSE!!!");
      digitalWrite(led, HIGH);
      TimerFreeTone(buzzer, 1000, buzzerdelay);
      digitalWrite(led, LOW);
      TimerFreeTone(buzzer, 1000, buzzerdelay);
      delay(buzzerdelay);
    }
  }
  delay(10);
}