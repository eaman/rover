/* Ultrasonic rilevatore distanza

Rilevatore distanza minore di 5cm.
funzione

HC-SR04 Ping distance sensor
VCC to arduino 5v - GND to arduino GND

 */
#define dEBUG
#include "rover.h"
#include "Servo.h"


void setup() {
    abilita();
    //Debug
#ifdef DEBUG
Serial.begin(9600);
#endif
Serial.begin(9600); // Need for distanceMonitor
}

void loop() {
if (distanceCheck()) { // Verifica se la distanza di un oggetto e' minore di minDistance = 10cm
    digitalWrite(13,HIGH);
} else {
    digitalWrite(13,LOW);
}
Serial.println(distanceMonitor()); // Ritorna la distanza di un oggetto in cm
delay(50);
}
