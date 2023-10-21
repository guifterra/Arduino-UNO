/*
 *  Nome: Guilherme Fabiano Terra da Silva
 *  Projeto Semaforo Simples - 3 LEDs
 * 
 */

#define LED_VER 1
#define LED_AMA 3
#define LED_VRD 5


void setup() {
  // put your setup code here, to run once:
  pinMode(LED_VER, OUTPUT);
  pinMode(LED_AMA, OUTPUT);
  pinMode(LED_VRD, OUTPUT);

  digitalWrite(LED_VER, LOW);
  digitalWrite(LED_AMA, LOW);
  digitalWrite(LED_VRD, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_VER, LOW);
  digitalWrite(LED_AMA, LOW);
  digitalWrite(LED_VRD, HIGH);

  delay(7000);

  digitalWrite(LED_VER, LOW);
  digitalWrite(LED_AMA, HIGH);
  digitalWrite(LED_VRD, LOW);

  delay(2000);

  digitalWrite(LED_VER, HIGH);
  digitalWrite(LED_AMA, LOW);
  digitalWrite(LED_VRD, LOW);

  delay(7000);
}
