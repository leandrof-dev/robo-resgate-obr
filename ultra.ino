//Definição de duas variaveis essenciais para a verificação da distância
float tempo;         // para armazenar o tempo de ida e volta do sinal em microsegundos
float distancia_cm;  // para armazenar a distância em centímetros

//Função responsável por verificar o ultrassônico solicitado
int ultrassonico_cm(char lado) {
  //Verifica qual sensor será lido (F: Ultra Frente, D: Ultra Direita e E: Ultra Esquerda)
  switch (lado) {
    case 'F':
      tempo = 0; //Zera o tempo para não haver interferências de outras verificações ("Tempo" se refere ao tempo que o pulso demora para voltar)
      digitalWrite(trigF, HIGH); //Envia um pulso
      delayMicroseconds(5);
      digitalWrite(trigF, LOW);
      tempo = pulseIn(echoF, HIGH); //Verifica o tempo que demorou para o pulso retornar
      distancia_cm = tempo / 29.4 / 2; //Converte o tempo do pulso em unidade de medida (CM)
    break;
    case 'D':
      tempo = 0;
      digitalWrite(trigD, HIGH);
      delayMicroseconds(5);
      digitalWrite(trigD, LOW);
      tempo = pulseIn(echoD, HIGH);
      distancia_cm = tempo / 29.4 / 2;
    break;
    case 'E':
      tempo = 0;
      digitalWrite(trigE, HIGH);
      delayMicroseconds(5);
      digitalWrite(trigE, LOW);
      tempo = pulseIn(echoE, HIGH);
      distancia_cm = tempo / 29.4 / 2;
    break;
  }

  return distancia_cm; //Retorna a distância que foi lida
}