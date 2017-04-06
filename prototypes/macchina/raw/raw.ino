/* Raw

Prototipo rozzo per il movimento utilizzando le funzioni
di base della libreria Rover.


Schema: https://lab.piffa.net/schemi/2wd_car_bb.png
Codice: http://git.andreamanni.com/web?p=rove

*/


#include "rover.h"
#include "Servo.h"

int rotPausa = 200; // Pausa per una minima rotazione 

void setup()
{
    abilita();
    servoMiddle();
}


void loop()
{
// Fintanto che non ci sono ostacoli: avanti
    while (distanceCheck() == 0) {
        avanti();
        delay(50); // Movimento minimo, per stabilizzare
        // l'input del sensore
    }
// Se c'e' un ostacolo: gira
    giraDX();
    delay(rotPausa);
}
