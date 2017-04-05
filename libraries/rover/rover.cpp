/*
  Rover

Autore: Andrea Manni

Link: http://aero.piffa.net
Licenza:    GPLv3

*/

#include "Arduino.h"
#include "rover.h"

#define dEBUG

// Configurazione con OUTPUT digitali
// motor one
const int enA = 6;
const int in1 = 7;
const int in2 = 8;
byte speedA = 255;
// motor two
const int enB = 5;
const int in3 = 4;
const int in4 = 3;
byte speedB = 255;

// Servo vars
int pos = 0;    // variable to store the servo position
const byte servoPIN =9 ;
const byte middle = 90; // Centratura servo
const int spausa = 10; // Pausa movimenti servo
const byte sx = 10;  // Min SX
const byte dx = 170; // Maz DX
Servo myservo; // Non c'e' bisogno di extern se e' dichiarato in questo scope

////////////////////////
// Funzioni:
//
void abilita() {
// Abilita i PINs come OUTPUTS
    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);


    pinMode(servoPIN, OUTPUT);
    myservo.attach(servoPIN);
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


// Entrambi i motori
void avanti() {
    // Drive ahead: funzione composita
    forwardA() ;
    forwardB() ;
}
void indietro() {
    // Drive backward: funzione composita
    backwardA();
    backwardB();
}
void giraSX() {
    // Gira a DX
    forwardB() ;
    backwardA();
}
void giraDX()  {
    // Gira a DX
    forwardA() ;
    backwardB();
}
void stop()  {
    stopA();
    stopB();
}



// Servo
void servoDX() {
    // TurnDX
    while (pos < dx) {
        myservo.write(pos++);
        delay(spausa);
    }
}

void servoSX() {
    // TurnSX
    while (pos > sx) {
        myservo.write(pos--);
        delay(spausa);
    }
}

void servoMiddle() {
    // Middle
    while (pos > middle) {
        myservo.write(pos--);
        delay(spausa);
    }
    while (pos < middle) {
        myservo.write(pos++);
        delay(spausa);
    }
}
