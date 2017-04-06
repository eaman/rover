/* FSM  Base

Prototipo rozzo per il movimento utilizzando le funzioni
di base della libreria Rover e una FSM.


Schema: https://lab.piffa.net/schemi/2wd_car_bb.png
Codice: http://git.andreamanni.com/web?p=rove

*/


#include "rover.h"
#include "Servo.h"

int rotPausa = 500; // Pausa per una rotazione di ~90'

void setup()
{
    abilita();
    servoMiddle();
}


// FSM
enum  { // Stati della FMS
    forward,
    check,	  // Cerca percorso libero
    sx,       // sx
    dx,        // dx
    ferma,
    inversione
} stato  = forward;

const int giroPausa = 500 ; // Tempo necessario per rotazione
void loop()
{
    switch (stato) {
    case forward:
        servoMiddle();
        avanti();
        delay(50); // Movimento minimo, per stabilizzare
        // l'input del sensore
        if (distanceCheck()) {
            stato == check ;
        }

        break;

    case check:
        if (!distanceCheck()) {
            stato == forward ;
            break;
        }
        stop();
// check dx
        servoDX();
        if (!distanceCheck()) {
            stato == dx ;
            servoMiddle();
            break;
        }

// check sx
        servoSX();
        if (!distanceCheck()) {
            stato == sx ;
            servoMiddle();
            break;
        }
// Inversione
        servoMiddle();
        stato == inversione ;
        break;

    case sx:
        giraSX();
        delay(giroPausa);
        break;

    case dx:
        giraDX();
        delay(giroPausa);
        break;

    case ferma:
        stop();
        delay(1000);
        stato == check ;
        break;

    case inversione:
        stop();
        indietro(); // Why not? :)
        delay(1000);
        delay(giroPausa * 2);
        stato == check ;
        break;

    default:
        stop();
        delay(2000);
        stato == check ;
        break;
    }
}
