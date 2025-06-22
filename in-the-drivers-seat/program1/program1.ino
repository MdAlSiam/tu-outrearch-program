#include "NewPing.h"
#define TRIGGER_PIN 12 
#define ECHO_PIN 11
#define MAX_DISTANCE 200 

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
void setup() {
 Serial.begin(9600);
}

void loop() {
 int distance = sonar.ping_cm(); 
 if (distance != 0){
  Serial.print("Ping: ");
  Serial.print(distance); 
  Serial.println("cm");
 }
 doADelay();
}

void doADelay(){
 delay(500);
}