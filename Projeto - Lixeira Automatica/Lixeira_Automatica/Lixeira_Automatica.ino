// Nome: Guilherme Fabiano Terra da Silva

int sensor_1 = 3;   // Sensor que verifica se a lixeira tem sacola
float distancia_1;  // Variável de verificação de distância

float segunda_etapa; // Variável que controla segunda parte do Projeto

int sensor_2 = 5;   // Sensor que verifica se a lixeira tem sacola
float distancia_2;  // Variável de verificação de distância

int controle = 6; // Controle de Velocidade do Motor1 para Selar sacola
int M1 = 2;     // Contorle de Sentido de Rotação
int M2 = 4;     // Controle de Sentido de Rotação

int controle_2 = 9; // Controle de Velocidade do Motor1 para Selar sacola
int M1_2 = 7;   // Contorle de Sentido de Rotação
int M2_2 = 8;   // Controle de Sentido de Rotação

int botao_FDC1 = 10;  // FDC simulada do Motor 1
int botao_FDC2 = 12;  // FDC2 simulada do Motor 1

int botao_2_FDC1 = 0; // FDC simulada do Motor 2 
int botao_2_FDC2 = 14; // FDC simulada do Motor 2 

int bot_remove = 15; // Botão que retira sacola 

int V_Resistencia = 11; // Controle da Tensão da Porta 11
int temp;       // Controle de Temperatura da R

float rem = 0.0;
int altura = 110 * 0.1;
void teste_1();   // Pegando valor da distância
void teste_2();   // Pegando valor da distância 2

void setup()
{
  Serial.begin(9600);
  pinMode(sensor_1, OUTPUT);
  digitalWrite(sensor_1, LOW);
  pinMode(sensor_2, OUTPUT);
  digitalWrite(sensor_2, LOW);
  
  pinMode(controle, OUTPUT);
  digitalWrite(controle,LOW);
  analogWrite(controle, 0);
  pinMode(M1, OUTPUT);
  digitalWrite(M1,LOW);
  pinMode(M2, OUTPUT);
  digitalWrite(M2,LOW);
  
  digitalWrite(controle_2,LOW);
  analogWrite(controle_2, 0);
  pinMode(M1_2, OUTPUT);
  digitalWrite(M1_2,LOW);
  pinMode(M2_2, OUTPUT);
  digitalWrite(M2_2,LOW);
  
  pinMode(botao_FDC1, INPUT_PULLUP);
  pinMode(botao_FDC2, INPUT_PULLUP);
  
  pinMode(botao_2_FDC1, INPUT_PULLUP);
  pinMode(botao_2_FDC2, INPUT_PULLUP);
  
  pinMode(bot_remove, INPUT_PULLUP);
  
  pinMode(V_Resistencia, OUTPUT);
  digitalWrite(V_Resistencia, LOW);
}

void loop()
{
  // Primeira etapa do Projeto
  teste_1();
  distancia_1 = distancia_1 / 2;      // Calculando dist
  distancia_1 = distancia_1 * 0.034029;   // Calculando dist 
  
  if (distancia_1 < 5){
    Serial.println("Tem sacola na Lixeira");
    segunda_etapa = 1.0;
  }else{
    Serial.println("NAO Tem sacola na lixeira");
    segunda_etapa = 0.0;
  }
  delay(300);
  
  while (segunda_etapa == 1.0){
     
    // Segunda Etapa do Projeto
    teste_2();
    
    distancia_2 = distancia_2 / 2;      // Calculando dist
    distancia_2 = distancia_2 * 0.034029; // Calculando dist
  
    if (distancia_2 <= altura || rem == 1.0){ // 110 (Tamanho máximo da lixeira) - 90% da capacidade = 11cm
     
      Serial.println("Hora de tirar o Lixo !!");
      
      // Esquentar resistência
      
      for(temp=0; temp <= 255; temp++){
        
        analogWrite(V_Resistencia, temp);
        delay(60);
        
      }  
      
      // Selar a Sacola (Motor)
      analogWrite(controle, 100);
      digitalWrite(M1, HIGH);
      digitalWrite(M2, LOW);
      
      // Levar a resistência até a sacola
      float F_ctrl = 0.0;
      while (F_ctrl == 0.0){
        if(digitalRead(botao_FDC1) == 0){
          Serial.println("Resistencia chegou");
          F_ctrl = 1.0;
        }else{
          Serial.println("Resistencia indo ate a sacola ...");
        }
      }  
      // Fim da ida
      
      Serial.println("Selando a sacola . . .");
      analogWrite(controle, 0);
      digitalWrite(M1, LOW);
      digitalWrite(M2, LOW);
      
      delay(3000);        // Tempo de selamento
      
      temp = 0;
      analogWrite(V_Resistencia, temp);
      analogWrite(controle, 100);
      digitalWrite(M1, LOW);
      digitalWrite(M2, HIGH);
      
      // Retorna a Resistência ao ponto inicial
      float F_ctrl2 = 0.0;
      while (F_ctrl2 == 0.0){
        if(digitalRead(botao_FDC2) == 0){
          Serial.println("Resistencia voltou ao ponto inicial");
          F_ctrl2 = 1.0;
        }else{
          Serial.println("Resistencia voltando ...");
        }
      } 
      // Fim da volta 
      
      analogWrite(controle, 0);
      digitalWrite(M1, LOW);
      digitalWrite(M2, LOW);
      
      delay(3000);
      
      // Empurrar para Fora
      analogWrite(controle_2, 100);
      digitalWrite(M1_2, HIGH);
      digitalWrite(M2_2, LOW);
      
      // Inicio da ida
      float F2_ctrl1 = 0.0;
      while (F2_ctrl1 == 0.0){
        if(digitalRead(botao_2_FDC1) == 0){
          Serial.println("Sacola fora");
          F2_ctrl1 = 1.0;
        }else{
          Serial.println("Empurrando para fora ...");
        }
      } 
      // Fim da ida
      
      analogWrite(controle_2, 0);
      digitalWrite(M1_2, LOW);
      digitalWrite(M2_2, LOW);
      
      delay(3000);
      
      analogWrite(controle_2, 100);
      digitalWrite(M1_2, LOW);
      digitalWrite(M2_2, HIGH);
      
      // Inicio da volta
      float F2_ctrl2 = 0.0;
      while (F2_ctrl2 == 0.0){
        if(digitalRead(botao_2_FDC2) == 0){
          Serial.println("Retornou a posicao inicial");
          F2_ctrl2 = 1.0;
        }else{
          Serial.println("Voltando ao ponto inicial ...");
        }
      } 
      // Fim da volta
      
      analogWrite(controle_2, 0);
      digitalWrite(M1_2, LOW);
      digitalWrite(M2_2, LOW);
      
      delay(3000);
      
      // Reiniciar o Projeto
      segunda_etapa = 0.0;
      rem = 0.0;
      
    }else{
      
      Serial.println("Ainda tem espaco suficiente !! ");
      
      // Retirar lixo na hora
      if(digitalRead(bot_remove) == 0){
          Serial.println("Remover lixo agora");
          rem = 1.0;
        }else{
          Serial.println("Nao remover Lixo");
        }
      
    }
    
    delay(300);
  } 
}

void teste_1()    // Pegando valor da distância
{
  pinMode(sensor_1,OUTPUT);
  digitalWrite(sensor_1, HIGH);
  delayMicroseconds(5);
  digitalWrite(sensor_1,LOW);
  
  pinMode(sensor_1, INPUT);
  distancia_1 = pulseIn(sensor_1,HIGH);
}

void teste_2()    // Pegando valor da distância
{
  pinMode(sensor_2,OUTPUT);
  digitalWrite(sensor_2, HIGH);
  delayMicroseconds(5);
  digitalWrite(sensor_2,LOW);
  
  pinMode(sensor_2, INPUT);
  distancia_2 = pulseIn(sensor_2,HIGH);
}
