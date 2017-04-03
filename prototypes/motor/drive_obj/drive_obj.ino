/* L298n motor
Aggiunta

Guida 2WD composta da 2 motori

- 2 motori DC
- L298n module
- Batteria > 6v

*/

#include <rover.h>

void setup() {
}

car macchina ;

void loop() {
//// Avanti
    macchina.avanti();
    delay(2000);
// Stop
    macchina.stop();
    delay(1000);

//// TurnSX
//    macchina.giraSX();
//    delay(1000);
//
//// Indietro
//    macchina.indietro();
//    delay(2000);
//// Stop
//    macchina.stop();
//    delay(1000);
//
//// TurnDX
//    macchina.giraDX();
//    delay(1000);
//
//// Stop
//    macchina.stop();
//    delay(1000);
}

