/* L298n motor
Aggiunta

Pilotare 1 motore DC con un modulo l928n
Enable in PWM per settare velocita' massima

- 1 motori DC
- L298n module
- Batteria > 6v

*/


// Configurazione con OUTPUT digitali
// motor one
const int enA = 6;
const int in1 = 7;
const int in2 = 8;
byte speedA = 255
// motor two
const int enB = 5;
const int in3 = 4;
const int in4 = 3;
byte speedB = 0;

void setup() {
    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
//  pinMode(enB, OUTPUT);
//  pinMode(in3, OUTPUT);
//  pinMode(in4, OUTPUT);
}


void loop() {
// Forward
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    analogWrite(enA,speed);
    delay(2000);

// Stop
    digitalWrite(enA,LOW);
    delay(1000);

// Backward
    digitalWrite(in2,LOW);
    digitalWrite(in1,HIGH);
    analogWrite(enA,speed);
    delay(2000);

// Stop
    digitalWrite(enA,LOW);
    delay(1000);
}
