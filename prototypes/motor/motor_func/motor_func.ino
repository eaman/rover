/* L298n motor
Aggiunta

Pilotare 2 motore DC con un modulo l928n
Enable in PWM per settare velocita' massima

- 2 motori DC
- L298n module
- Batteria > 6v

*/


// Configurazione con OUTPUT digitali
// motor one
const int enA = 6;
const int in1 = 7;
const int in2 = 8;
byte speedA = 255;
// motor two
const int enB = 5;
const int in3 = 4;
const int in4 = 3;
byte speedB = 255;

void setup() {
    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
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

// Functions

// MotorB
void forwardA() {
    // Avanzamento motore
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    analogWrite(enA,speedA);
}

void backwardA() {
    // Reverse motore
    digitalWrite(in2,LOW);
    digitalWrite(in1,HIGH);
    analogWrite(enA,speedA);
}

void stopA() {
    // Stop
    digitalWrite(enA,LOW);
}

// MotorB
void forwardB() {
    // Avanzamento motore
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    analogWrite(enB,speedB);
}

void backwardB() {
    // Reverse motore
    digitalWrite(in4,LOW);
    digitalWrite(in3,HIGH);
    analogWrite(enB,speedB);
}

void stopB() {
    // Stop
    digitalWrite(enB,LOW);
}
