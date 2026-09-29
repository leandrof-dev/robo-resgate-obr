//Caso seja identificado uma rampa essa função é executada, alterando a velocidade dos motores e realizando a mesma
void rampa(bool subida) {
  Serial.println("Rampa");
  desligaLeds();
  if (subida && contador != 0) { //Verifica se trata de subida ou descida
    velAvancar = 170;
    velCurva = 90;
    while (digitalRead(sensorSubida) < 1) segue_linha(true); //Segue linha com a velocidade pré selecionada
    velAvancar = 118;
    velCurva = velCurvaI;
    arena(true);
    return;
  }else if(subida && contador == 0){
    while (digitalRead(sensorSubida) < 1) segue_linha(true); //Segue linha com a velocidade pré selecionada
    contador++;
  } else if (!subida) {
    while (digitalRead(sensorDescida) < 1) {
      avancar(80);
    }
  }
  //Enquanto os dois ultrassônicos identificarem parede, o while irá impedir que a velocidade volte para a padrão
}

