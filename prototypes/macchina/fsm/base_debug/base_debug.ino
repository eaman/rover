/* FSM  Base

Prototipo rozzo per il movimento utilizzando le funzioni
di base della libreria Rover e una FSM.


Schema: https://lab.piffa.net/schemi/2wd_car_bb.png
Codice: http://git.andreamanni.com/web?p=rove

*/


#include "rover.h"
#include "Servo.h"
#define dEBUG

int rotPausa = 500; // Pausa per una rotazione di ~90'

void setup()
{
    abilita();
#ifdef DEBUG
    Serial.begin(9600);
    Serial.println("Attivazione sketch");
#endif
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

const int giroPausa = 630 ; // Tempo necessario per rotazione
void loop()
{
    switch (stato) {
    case forward:
        servoMiddle();
        avanti();
        delay(10); // Movimento minimo, per stabilizzare
        // l'input del sensore
        if (distanceCheck()) {
#ifdef DEBUG
Serial.println("\t ###### Ostacolo! ######");       
#endif
            stato = check ;
        }

        break;

    case check:
        if (!distanceCheck()) {
            stato = forward ;
            break;
        }
        stop();
// check dx
        servoDX();
        if (!distanceCheck()) {
            stato = dx ;
            servoMiddle();
            break;
        }

// check sx
        servoSX();
        if (!distanceCheck()) {
            stato = sx ;
            servoMiddle();
            break;
        }
// Inversione
        servoMiddle();
        stato = inversione ;
#ifdef DEBUG
Serial.print("Stato: ");       
Serial.println(stato);       
#endif
        break;

    case sx:
#ifdef DEBUG
Serial.print("Stato: ");       
Serial.println(stato);       
#endif
        giraSX();
        delay(giroPausa);
            stato = forward ;
        break;

    case dx:
#ifdef DEBUG
Serial.print("Stato: ");       
Serial.println(stato);       
#endif
        giraDX();
        delay(giroPausa);
            stato = forward ;
        break;

    case ferma:
        stop();
        delay(1000);
        stato = check ;
        break;

    case inversione:
#ifdef DEBUG
Serial.print("Stato: ");       
Serial.println(stato);       
#endif
        stop();
        indietro(); // Why not? :)
        delay(giroPausa * 1);
        giraDX();
        delay(giroPausa * 3);
        stato = check ;
        break;

    default:
        stop();
        delay(2000);
        stato = check ;
        break;
    }

#ifdef DEBUG
//Serial.print("Stato: ");       
//Serial.println(stato);       
//Serial.print("Distanza: ");       
//Serial.println(distanceMonitor());       
#endif
}
