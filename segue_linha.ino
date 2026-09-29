void segue_linha(bool subida){
  leitura(); //Faz as leituras dos sensores
  if(!subida) arena(false);
  if(!subida) cruzamento(); //Verifica se há um cruzamento, caso houver executa a sequência correta
  if(!subida) situacao('L'); //Indica a situação que o robô se encontra através dos dois leds RGBs
  
  if(leituraSf > Preto+110) avancar(velAvancar-10); //Verifica se o sensor da frente está sobre a linha, caso sim, o robô manterá sua posição e seguirá em frente
  else if(leituraS2 < Preto-100  && leituraS3 > Preto-100) curvaDir(velCurva-35); //Verifica se o sensor da direita está sobre a linha, caso sim, realiza uma curva para a direita
  else if(leituraS2 > Preto-100 && leituraS3 < Preto-100) curvaEsq(velCurva-35); //Verifica se o sensor da esquerda está sobre a linha, caso sim, realiza uma curva para a esquerda
  else avancar(velAvancar-10); //Caso nenhuma das verifições acima forem verdadeiras o robô manterá sua posição e seguirá reto
  delay(8); //Espera existente para possibilitar a execução mínima de um dos comandos acima
}
