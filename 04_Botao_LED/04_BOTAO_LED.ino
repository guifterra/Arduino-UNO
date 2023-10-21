/*
 *  Nome: Guilherme Fabiano Terra da Silva
 *  Liga LED somente enquanto está pressionado
 * 
 */

#define LED 8
#define BOTAO 10

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(BOTAO, INPUT);

  digitalWrite(LED, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(BOTAO) == HIGH){

    digitalWrite(LED, 1);

  }else{

    digitalWrite(LED, 0);

  }

}
