// C++ code

/*
 *  Nome: Guilherme Fabiano Terra da Silva
 *  Testando LDR - Sensor de Luz
 * 
 */

// Luz - 380 p/ cima
// Escuro - 100 baixo ou 380 p baixo
void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop()
{
	int valor = analogRead(A0);
  	Serial.println(valor);
  	delay(100);
}
