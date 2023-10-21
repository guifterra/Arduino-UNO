/*
 *  Nome: Guilherme Fabiano Terra da Silva
 *  Testando LCD - Display para exibir mensagens
 * 
 */

#include <LiquidCrystal.h> // inclui a biblioteca para uso do Display LCD
// inicializa um objeto nos pinos para acesso as funções do LCD
const int RS = 12, EN = 11, D4 = 10, D5 = 9, D6 = 8, D7 = 7;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup(){
  // Configura o LCD com os número de colunas e linhas
  lcd.begin(16, 2); // 16 colunas e 2 linhas

  // Limpa o LCD
  lcd.clear();
  
  // posiciona o cursor do LCD
  lcd.setCursor(0, 0); // (coluna 0, linha 0)
  lcd.print("Master Kit RC"); // Imprime mensagem
}

void loop(){
  
  lcd.print("Master Kit RC"); // Imprime mensagem
  delay(2000);
  lcd.clear();
  
  lcd.print("Feliz natal"); // Imprime mensagem
  delay(2000);
  lcd.clear();
  
  lcd.print("Merry Christmas"); // Imprime mensagem
  delay(2000);
  lcd.clear();
  
}
