/* Rotazione

   Rotazione di un servomotore tramite la librerio Servo.h .

L'utilizzo della libreria Servo rende inutilizzabile analogWrite()
sui pin 9 e 10 dato che utilizza i timer associati a questi PIN.

Power: un servo da 9g puo' arrivare ad impegnare 750mA sotto carico
(se viene opposta resistenza al movimento del servo), un  SG90 prende 
~52mA se il movimento e' libero. Quindi in fase di test il servo puo'
essere alimentato direttamente da una scheda Arduino (200ma dal PIN 5v)
ma per l'uso finale dovra' essere alimentato autonomamente.


Rotazione a SX di 90'
Rotazione a DC di 90'

Schema: https://www.arduino.cc/en/uploads/Tutorial/sweep_bb.png
        http://microbotlabs.com/images/mearm-uno-servo-1.jpg
   */

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
// Servo vars
int pos = 0;    // variable to store the servo position 
const byte servo =9 ;
const byte middle = 90; // Centratura servo
const int pausa = 1000; // Centratura servo
 
void setup() 
{ 
  myservo.attach(servo);  // attaches the servo on pin 9 to the servo object 
    myservo.write(middle);              // tell servo to go to position in variable 'pos' 
    delay(2000);
} 
 
 
void loop() 
{ 
// Turn DX
    myservo.write(170);
    delay(pausa);     
    myservo.write(middle);              
    delay(1000);     
// Turn SX
    myservo.write(10);
    delay(pausa);      
    myservo.write(middle);              
    delay(1000);     
} 
