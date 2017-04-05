/*
  Rover 

Autore: Andrea Manni

Link: http://rover.piffa.net
Licenza:    GPLv3

*/

#include "Arduino.h"
#include "Servo.h" 

#ifndef rover_h
#define rover_h

// Global vars


// Funzioni

void abilita() ; // Abilita tutti i PIN
void forwardA(); // speedA e' dato dalla variabile golabale speedA
void forwardA(byte speedA); // Overloading
void backwardA() ;
void backwardA(byte speedA) ;
void stopA() ;
void forwardB() ;
void forwardB(byte speedB) ;
void backwardB() ;
void backwardB(byte speedB) ;
void stopB() ;

// Entrambi i motori
void avanti();
void indietro();
void giraSX();
void giraDX() ;
void stop() ;


void servoDX() ;
void servoSX() ;
void servoMiddle() ;
#endif
