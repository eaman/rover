/* Ultrasonic rilevatore distanza

Rilevatore distanza minore di 5cm.

HC-SR04 Ping distance sensor
VCC to arduino 5v - GND to arduino GND


 */

// Ultrasuoni
const byte trig = 11;
const byte echo = 12;
const byte led = 13;
long duration, distance;

void setup() {
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    pinMode(led, OUTPUT);


    //Debug
    Serial.begin (9600);
}

void loop() {
    digitalWrite(trig, LOW);  // Prepare for ping
    delayMicroseconds(2); //
    digitalWrite(trig, HIGH); // Send a ping
    delayMicroseconds(10); //
    digitalWrite(trig, LOW); // Set down ping
    duration = pulseIn(echo, HIGH);
    distance = (duration/2) / 29.1; // Speed is ~300m/s,
    // so it takes ~29.1 milliseconds for a cm.
    // Distance is half of (out + back)
    if (distance < 5) {  // This is where the LED On/Off happens
        digitalWrite(led,HIGH); // When the Red condition is met, the Green LED should turn off
    }
    else {
        digitalWrite(led,LOW);
    }
    delay(200);
    Serial.println(distance);
}

