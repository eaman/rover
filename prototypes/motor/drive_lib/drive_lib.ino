/* L298n motor

Inclusione delle funzioni nella libreria rover.

Guida 2WD composta da 2 motori

- 2 motori DC
- L298n module
- Batteria > 6v

*/

#include <rover.h>
#include <Servo.h>

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
    giraSX();
    delay(1000);

// Avanti
    avanti();
    delay(2000);
// Stop
    stop();
    delay(1000);

// TurnDX
    giraDX();
    delay(1000);

// Stop
    stop();
    delay(1000);
}
