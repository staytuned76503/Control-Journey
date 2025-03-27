// Déclaration des broches
const int potPin = A0;  // Potentiomètre
const int enA = 9;      // PWM L293D
const int in1 = 4;      // Direction moteur
const int in2 = 5;

int targetPos = 512;  // Position cible (milieu de la plage 0-1023)

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enA, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int pos = analogRead(potPin);  // Lire la position
  int error = targetPos - pos;   // Calculer l'erreur

  int speed = map(abs(error), 0, 1023, 0, 255);  // Adapter vitesse

  if (error > 10) {  // Si trop loin de la cible
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  } else if (error < -10) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  } else {
    speed = 0;  // Stop moteur si proche de la cible
  }

  analogWrite(enA, speed);  // Appliquer vitesse

  Serial.print("Position: "); Serial.println(pos);
  delay(50);  // délai pour la stabilité
}
