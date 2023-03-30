#include <Servo.h>

Servo myServo;

void setup() {
  myServo.attach(pin); // définir la broche appropriée pour le signal de contrôle
}

void loop() {
  myServo.write(angle); // définir l'angle souhaité (entre 0 et 180 degrés)
  delay(15); // attendre 15 millisecondes pour permettre au moteur de se déplacer
}
