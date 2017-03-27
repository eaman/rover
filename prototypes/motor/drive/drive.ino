/* L298n motor
Aggiunta

Guida 2WD composta da 2 motori

- 2 motori DC
- L298n module
- Batteria > 6v

*/

#include <rover.h>

void setup() {
    abilita();
}


void loop() {
// Avanti
    avanti();
    delay(2000);
// Stop
    stop();
    delay(1000);

// TurnSX
    turnSX();
    delay(1000);

// Avanti
    avanti();
    delay(2000);
// Stop
    stop();
    delay(1000);


// TurnDX
    turnDX();
    delay(1000);

// Stop
    stop();
    delay(1000);
}

// Functions
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

void turnDX() {
    // Gira a DX
    forwardB() ;
    backwardA();
}

void turnSX() {
    // Gira a DX
    forwardA() ;
    backwardB();
}

void stop() {
    stopA();
    stopB();
}
