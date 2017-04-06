/* Ultrasonic rilevatore distanza

Rilevatore distanza minore di 5cm.
funzione

HC-SR04 Ping distance sensor
VCC to arduino 5v - GND to arduino GND

 */
# define dEBUG

// Ultrasuoni
const byte trig = 11;
const byte echo = 12;
const byte led = 13;
long duration;
int distance;
const int minDistance = 10;

void setup() {
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    pinMode(led, OUTPUT);


    //Debug
#ifdef DEBUG
Serial.begin(9600);
#endif
Serial.begin(9600); // Need for distanceMonitor
}

void loop() {
if (distanceCheck()) {
    digitalWrite(led,HIGH);
} else {
    digitalWrite(led,LOW);
}
Serial.println(distanceMonitor());
delay(50);

}

boolean distanceCheck() {
    digitalWrite(trig, LOW);  // Prepare for ping
    delayMicroseconds(2); //
    digitalWrite(trig, HIGH); // Send a ping
    delayMicroseconds(10); //
    digitalWrite(trig, LOW); // Set down ping
    duration = pulseIn(echo, HIGH);
    //distance = (duration / 2) / 29.1; // Speed is ~300m/s,
    // so it takes ~29.1 milliseconds for a cm.
    distance = (duration / 58.2); // Atmegas are not found of divisions
    // Distance is half of (out + back)
    distance = constrain(distance,4,35);
#ifdef DEBUG
Serial.print("Distanza oggetto: ");    
Serial.println(distance);
#endif
    if (distance < minDistance) {  // This is where the LED On/Off happens
        return 1;
    }
    else {
        return 0;
    }
}

int distanceMonitor() {
    digitalWrite(trig, LOW);  // Prepare for ping
    delayMicroseconds(2); //
    digitalWrite(trig, HIGH); // Send a ping
    delayMicroseconds(10); //
    digitalWrite(trig, LOW); // Set down ping
    duration = pulseIn(echo, HIGH);
    //distance = (duration / 2) / 29.1; // Speed is ~300m/s,
    // so it takes ~29.1 milliseconds for a cm.
    distance = (duration / 58.2); // Atmegas are not found of divisions
    distance = constrain(distance,4,35);
    // Distance is half of (out + back)

    return distance;
}
