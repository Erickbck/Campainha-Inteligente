#include <NewPing.h>
#include <TimerFreeTone.h>

int ledverm = 4;
int ledverd = 6;
int echo = 9;
int trig = 11;
int buzzer = 7;

#define MAX_DISTANCE 200
#define DISTANCE_CM 20

NewPing sonar(trig, echo, MAX_DISTANCE);
int distancia;

void setup() {
  pinMode(ledverm, OUTPUT);
  pinMode(ledverd, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  distancia = sonar.ping_cm();

  Serial.print("Distance: ");
  Serial.println(distancia);

  if (distancia > 0 && distancia <= DISTANCE_CM) {
    digitalWrite(ledverm, HIGH);
    TimerFreeTone(buzzer, 440, 500);
    delay(1000);
    digitalWrite(ledverm, LOW);
    delay(100);

    digitalWrite(ledverd, HIGH);
    TimerFreeTone(buzzer, 349, 300);
    delay(300);
    digitalWrite(ledverd, LOW);
    delay(100);
  }

  delay(50);
}
