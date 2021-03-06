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


#include "rover.h"
#include "Servo.h" 

// a maximum of eight servo objects can be created 


void setup() 
{ 
  abilita();

} 


void loop() 
{ 
  // servo DX
  servoDX(); // Gira il servo a DX (il verso dipende anche da come e' stato montato)
  delay(1000);     

  servoMiddle(); // Torna al centro
  delay(1000);     

  // servo SX
  servoSX(); // Gira il servo a SX (il verso dipende anche da come e' stato montato)
  delay(1000);     

  servoMiddle();
  delay(1000);     
} 




