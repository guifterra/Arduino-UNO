/*
 *  Nome: Guilherme Fabiano Terra da Silva
 *  Utilização de sensor ultrassônico + LED
 * 
 */

int trigger = 4;
int echo = 5;
int LED = 7;
int Buzzer = 13;

int tempo = 100;
int frequencia = 150;

float distancia;
float duracao;
float velocidade = 0.0172316; // cm/s

void setup()
{
  pinMode(trigger, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(Buzzer, OUTPUT);
  
  digitalWrite(Buzzer,LOW);
  digitalWrite(LED, LOW);

  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigger, 0);
  delayMicroseconds(5);
  digitalWrite(trigger, 1);
  delayMicroseconds(10);
  digitalWrite(trigger, 0);
  
  duracao = pulseIn(echo,1);
  
  distancia = duracao * velocidade;
  
  Serial.print("Distancia :");
  Serial.print(distancia);
  Serial.println(" cm");

  if(distancia < 30){

    digitalWrite(LED, HIGH);
    digitalWrite(Buzzer,HIGH);
    som();        
    
  }else{

    digitalWrite(LED, LOW);
    digitalWrite(Buzzer,LOW);

  }
  
  delay(100);
}

void som(){

   for(frequencia = 150; frequencia <= 900; frequencia++){
   
    tone(Buzzer, frequencia, tempo);
    delay(1);
    
  }
  
  for(frequencia = 900; frequencia >= 150; frequencia--){
   
    tone(Buzzer, frequencia, tempo);
    delay(1);
    
  }
  
}
