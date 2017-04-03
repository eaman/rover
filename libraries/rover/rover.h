/*
  Rover

Autore: Andrea Manni

Link: http://rover.piffa.net
Licenza:    GPLv3

*/

#include "Arduino.h"

#ifndef rover_h
#define rover_h

// Global vars
extern int enA ;
extern int in1 ;
extern int in2 ;
extern byte speedA ;
// motor two
extern int enB ;
extern int in3 ;
extern int in4 ;


// Funzioni

void abilita() ;
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

// Objects:


class car {
// Lettura delle variabili globali (per poter tenere un file
// di configurazione con tutti i PIN)
// motor one
    const int _enA = enA ;
    const int _in1 = in1 ;
    const int _in2 = in2 ;
// motor two
    const int _enB = enB ;
    const int _in3 = in3 ;
    const int _in4 = in4 ;

public:
    car () ;
    byte velA ;
    byte velB ;
    void avanti ();
    void indietro ();
    void stop ();
    void giraSX ();
    void giraDX ();
    void setSpeed ();
};
#endif
