// C++ code

/*
 *  Nome: Guilherme Fabiano Terra da Silva
 *  Testando LED RGB 
 * 
 */

// Declaração de LED RGB
#define LRGB_RED 11
#define LRGB_BLUE 10
#define LRGB_GREEN 9

// Variáveis de controle de COR do LED RGB
int controle_RED = 0;
int controle_BLUE = 0;
int controle_GREEN = 0;
int auxiliar_RGB = 0;

void setup()
{
  pinMode(LRGB_RED, OUTPUT);
  pinMode(LRGB_BLUE, OUTPUT);
  pinMode(LRGB_GREEN, OUTPUT);
  
  analogWrite(LRGB_RED, 0);
  analogWrite(LRGB_BLUE, 0);
  analogWrite(LRGB_GREEN, 0);
}

void loop()
{
  analogWrite(LRGB_RED, controle_RED);
  analogWrite(LRGB_GREEN, controle_BLUE);
  analogWrite(LRGB_BLUE, controle_GREEN);
  
  progressao_RGB();
  delay(500);
  
}

void progressao_RGB(){
 
  // Reinicialização do RGB
  if (auxiliar_RGB == 6){
   
    auxiliar_RGB = 0;
    
  }
  
  // Tomada de decisão da cor
  if(auxiliar_RGB == 0){
    
  	analogWrite(LRGB_RED, 255);
  	analogWrite(LRGB_BLUE, 0);
  	analogWrite(LRGB_GREEN, 0);
    
  } else if(auxiliar_RGB == 1){
    
    analogWrite(LRGB_RED, 0);
  	analogWrite(LRGB_BLUE, 255);
  	analogWrite(LRGB_GREEN, 0);
    
  } else if(auxiliar_RGB == 2){
    
    analogWrite(LRGB_RED, 0);
  	analogWrite(LRGB_BLUE, 0);
  	analogWrite(LRGB_GREEN, 255);
    
  } else if(auxiliar_RGB == 3){
    
    analogWrite(LRGB_RED, 255);
  	analogWrite(LRGB_BLUE, 255);
  	analogWrite(LRGB_GREEN, 0);
    
  } else if(auxiliar_RGB == 4){
    
    analogWrite(LRGB_RED, 255);
  	analogWrite(LRGB_BLUE, 0);
  	analogWrite(LRGB_GREEN, 255);
    
  } else if(auxiliar_RGB == 5){
    
    analogWrite(LRGB_RED, 0);
  	analogWrite(LRGB_BLUE, 255);
  	analogWrite(LRGB_GREEN, 255);
    
  }
  
  auxiliar_RGB++;
  
}
