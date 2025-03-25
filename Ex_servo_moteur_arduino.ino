#include <Servo.h>  // Inclusion de la bibliothèque Servo

Servo monServo;  // Création d'un objet Servo

void setup() {
    monServo.attach(9);  // Connexion du servo sur la broche PWM 9
}

void loop() {
    monServo.write(0);   // Positionne le servo à 0°
    delay(1000);         // Pause d'1 seconde
    
    monServo.write(90);  // Positionne le servo à 90°
    delay(1000);         // Pause d'1 seconde
    
    monServo.write(180); // Positionne le servo à 180°
    delay(1000);         // Pause d'1 seconde
}
