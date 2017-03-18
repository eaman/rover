/*
  Rover 

Autore: Andrea Manni

Link: http://rover.piffa.net
Licenza:    GPLv3

*/

#include "Arduino.h"

#ifndef rover_h
#define rover_h

//////////////////////
// OBJ


class engine {
// Gestione di un singolo motore
private:
    byte enablePIN1;
    byte enablePIN2;
    byte min;   // Minimo per partire
    byte val;   // 8bit PWM

public:
    Engine (byte PIN1, byte PIN2, byte PINPWM);
    void Forward ();
    void Backward ();
    void SetSpeed (); // imposta un valore preciso per il PWM

}

class motors {
// classe composta da due engines
// Composition is better than inheritance here

public:
    motors (engine enginesx, engine enginedx) {
    void Forward ();
    void Backward ();
    void TurnLeft ();
    void TurnRight ();
    void TurnU ();
}
}
//////////////////////
// Funzioni


#endif
