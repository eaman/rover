/*
  Rover

Autore: Andrea Manni

Link: http://aero.piffa.net
Licenza:    GPLv3

*/

#include "Arduino.h"
#include "rover.h"

#define dEBUG

// Configurazione parametri: variabili GLOBALI
// motor one
const int enA = 6;
const int in1 = 7;
const int in2 = 8;
byte speedA = 120; // DX
// motor two
const int enB = 5;
const int in3 = 4;
const int in4 = 3;
byte speedB = 100;

// Servo vars
int pos = 0;    // variable to store the servo position
const byte servoPIN =9 ;
const byte middle = 90; // Centratura servo
const int spausa = 10; // Pausa movimenti servo
const byte sx = 30;  // Min SX
const byte dx = 150; // Maz DX
Servo myservo; // Non c'e' bisogno di extern se e' dichiarato in questo scope

// Ultrasuoni
const byte trigPIN = 11;
const byte echoPIN= 12;
const byte ledPIN = 13;
long duration;
int distance;
const int minDistance = 20;

////////////////////////
// Funzioni:
//
void abilita() {
// Abilita i PINs come OUTPUTS e attacca un servo 
// Motors
    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
// Servo
    pinMode(servoPIN, OUTPUT);
    myservo.attach(servoPIN); //la libreria servo deve essere sempre inclusa
// Ultrasonic
	pinMode(trigPIN, OUTPUT);
    pinMode(echoPIN, INPUT);
    pinMode(ledPIN, OUTPUT);
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


// Ultrasuoni
boolean distanceCheck() {
// Verifica se la distanza di un oggetto e' minore di minDistance
    digitalWrite(trigPIN, LOW);  // Prepare for ping
    delayMicroseconds(2); //
    digitalWrite(trigPIN, HIGH); // Send a ping
    delayMicroseconds(10); //
    digitalWrite(trigPIN, LOW); // Set down ping
    duration = pulseIn(echoPIN, HIGH);
    //distance = (duration / 2) / 29.1; // Speed is ~300m/s,
    // so it takes ~29.1 milliseconds for a cm.
    distance = (duration / 58.2); // Atmegas are not found of divisions
    // Distance is half of (out + back)
    distance = constrain(distance,4,35);
#ifdef DEBUG
Serial.print("Distanza oggetto: ");    
Serial.println(distance);
#endif
    if (distance < minDistance) {  // This is where the LED On/Off happens
        return 1;
    }
    else {
        return 0;
    }
}

int distanceMonitor() {
// Ritorna la distanza di un oggetto in cm
    digitalWrite(trigPIN, LOW);  // Prepare for ping
    delayMicroseconds(2); //
    digitalWrite(trigPIN, HIGH); // Send a ping
    delayMicroseconds(10); //
    digitalWrite(trigPIN, LOW); // Set down ping
    duration = pulseIn(echoPIN, HIGH);
    //distance = (duration / 2) / 29.1; // Speed is ~300m/s,
    // so it takes ~29.1 milliseconds for a cm.
    distance = (duration / 58.2); // Atmegas are not found of divisions
    // Distance is half of (out + back)
    distance = constrain(distance,4,35);

    return distance;
}
