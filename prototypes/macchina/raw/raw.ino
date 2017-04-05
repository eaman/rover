/* Raw

Prototipo rozzo per il movimento utilizzando le funzioni
di base della libreria Rover.


Schema: https://lab.piffa.net/schemi/2wd_car_bb.png
Codice: http://git.andreamanni.com/web?p=rove

*/


#include "rover.h"
#include "Servo.h"

int rotPausa = 100; // Pausa per una rotazione di ~90'

void setup()
{
    abilita();
    servoMiddle();
}


void loop()
{
// Fintanto che non ci sono ostacoli: avanti
    while (check() = 0) {
        avanti()
    }
// Se c'e' un ostacolo: ferma e gira
    stop();
    giraSX;
    delay(rotPausa);
}
