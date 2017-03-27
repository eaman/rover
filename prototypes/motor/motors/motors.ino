/* L298n motor
Aggiunta

Pilotare 2 motore DC con un modulo l928n
Enable in PWM per settare velocita' massima

- 2 motori DC
- L298n module
- Batteria > 6v

*/
#include <rover.h>


void setup() {
    abilita();
}


void loop() {
// Forward
    forwardA();
    forwardB();
    delay(2000);

// Stop
    stopA();
    stopB();
    delay(1000);

// Backward
    backwardA();
    backwardB();
    delay(2000);

// Stop
    stopA();
    stopB();
    delay(1000);
}
