/*
  Rover 

Autore: Andrea Manni

Link: http://aero.piffa.net
Licenza:    GPLv3

*/

#include "Arduino.h"
#include "rover.h"

#define dEBUG

// motor one
extern int enA = 6;
extern int in1 = 7;
extern int in2 = 8;
extern byte speedA = 255;
// motor two
extern int enB = 5;
extern int in3 = 4;
extern int in4 = 3;
extern byte speedB = 255;

// Oggetti
car::car () {
// Abilita i PINs come OUTPUTS
    pinMode(_enA, OUTPUT);
    pinMode(_in1, OUTPUT);
    pinMode(_in2, OUTPUT);
    pinMode(_enB, OUTPUT);
    pinMode(_in3, OUTPUT);
    pinMode(_in4, OUTPUT);
    velA = speedA;
    velB = speedB;
}

void car::avanti () {
// Motor A
    digitalWrite(_in1,LOW);
    digitalWrite(_in2,HIGH);
    analogWrite(_enA,velA);
// Motor B
    digitalWrite(_in3,LOW);
    digitalWrite(_in4,HIGH);
    analogWrite(_enB,velB);
}


// Funzioni

void abilita() {
// Abilita i PINs come OUTPUTS
    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
}


// MotorA
void forwardA() {
    // Avanzamento motore
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    analogWrite(enA,speedA);
}

void forwardA(byte speedA) {
    // Avanzamento motore
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    analogWrite(enA,speedA);
}

void backwardA() {
    // Reverse motore
    digitalWrite(in2,LOW);
    digitalWrite(in1,HIGH);
    analogWrite(enA,speedA);
}

void backwardA(byte speedA) {
    // Reverse motore
    digitalWrite(in2,LOW);
    digitalWrite(in1,HIGH);
    analogWrite(enA,speedA);
}

void stopA() {
    // Stop
    digitalWrite(enA,LOW);
}

// MotorB
void forwardB() {
    // Avanzamento motore
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    analogWrite(enB,speedB);
}

void forwardB(byte speedB) {
    // Avanzamento motore
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    analogWrite(enB,speedB);
}

void backwardB() {
    // Reverse motore
    digitalWrite(in4,LOW);
    digitalWrite(in3,HIGH);
    analogWrite(enB,speedB);
}

void backwardB(byte speedB) {
    // Reverse motore
    digitalWrite(in4,LOW);
    digitalWrite(in3,HIGH);
    analogWrite(enB,speedB);
}

void stopB() {
    // Stop
    digitalWrite(enB,LOW);
}
