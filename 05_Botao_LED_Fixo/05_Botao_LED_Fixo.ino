/*
 *  Nome: Guilherme Fabiano Terra da Silva
 *  Trocar estado do LED por botão
 * 
 */

#define LED 8
#define BOTAO 10

bool controle_Led = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(BOTAO, INPUT);

  digitalWrite(LED, 0);
}

void loop() {
  
  // put your main code here, to run repeatedly:
  while(controle_Led == false){

    if(pulseIn(BOTAO, HIGH, 10000)){

      digitalWrite(LED, 1);
      controle_Led = true;

    }

  }

  while(controle_Led == true){

    if(pulseIn(BOTAO, HIGH, 10000)){

      digitalWrite(LED, 0);
      controle_Led = false;

    }

  }  

}
  
