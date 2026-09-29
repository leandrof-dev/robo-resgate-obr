bool verde() {
  mediaVerde();
  Serial.println(String(mediaVerdeE) + " " + String(mediaVerdeD));
  if ((verde_D() || verde_E())) {
    situacao('V'); //Indica a situação de verde (Verde)
    if(mediaVerdeD > 210 && mediaVerdeD < 390 && mediaVerdeE > 210 && mediaVerdeE < 390){
      situacao('R'); //Indica a situação em que o robô deve dar uma meia volta (Vermelho)
      Serial.println("180");
      curva180(velCurva);
      delay(1500); //Realiza a curva por 1,5s
      leitura();
      if (leituraSf < Preto+100) { //Verifica se o sensor está em cima da linha, caso não, realiza a mesma curva até encontrar a linha preta
        while (leituraSf < Preto+50) {
          curva180(velCurva);
          leitura();
        }
      }
      parar();
    }
    else if (mediaVerdeD > 210 && mediaVerdeD < 390) { // Verifica se a media realizada está entre os valores de verde para o sensor da direita
      situacao('D'); //Indica a situação de verde na direita
      Serial.println("Verde na direita");
      Serial.println(String(mediaVerdeE) + "  " + String(mediaVerdeD));
      avancar(velAvancar);
      delay(400); //Avança o robô por 300ms (Isso é feito para que após a curva, o robô se localize no centro da linha preta)
      parar();
      curvaDir(velCurva);
      delay(700); //Realiza a curva por 500ms
      leitura();
      if (leituraSf < Preto+50) { //Verifica se o sensor está em cima da linha, caso não, realiza a mesma curva até encontrar a linha preta
        while (leituraSf < Preto+50) {
          curvaDir(velCurva);
          leitura();
        }
      }
      parar();
    } else if (mediaVerdeE > 210 && mediaVerdeE < 390) { // Verifica se a media realizada está entre os valores de verde para o sensor da esquerda
      situacao('E'); //Indica a situação de verde na esquerda
      Serial.println("Verde na esquerda");
      Serial.println(String(mediaVerdeE) + "  " + String(mediaVerdeD));
      avancar(velAvancar);
      delay(210); //Avança o robô por 210ms (Isso é feito para que após a curva, o robô se localize no centro da linha preta)
      parar();
      curvaEsq(velCurva);
      delay(500); //Realiza a curva por 500ms
      leitura();
      if (leituraSf < Preto+50) { //Verifica se o sensor está em cima da linha, caso não, realiza a mesma curva até encontrar a linha preta
        while (leituraSf < Preto+50) {
          curvaEsq(velCurva);
          leitura();
        }
      }
      parar();
    }
    return true; //Retorna verdadeiro para indicar que havia verde(s)
  }
  return false; //Retorna falso para indicar que não há verde(S)
}

bool verde_D() { //Verifica se o sensor de cor da direita está sobre o verde, caso sim, retorna verdadeiro
  mediaVerde();
  if (mediaVerdeD > 210 && mediaVerdeD < 390) return true;
  return false;
}
bool verde_E() { //Verifica se o sensor de cor da esquerda está sobre o verde, caso sim, retorna verdadeiro
  mediaVerde();
  if (mediaVerdeE > 210 && mediaVerdeE < 390) return true;
  return false;
}

//Faz a média das leituras para alcançar valores mais seguros
void mediaVerde() {
  int divisor = 0;
  int md = 0; //Variavel da somatória da leitura do sensor da direita
  int me = 0; //Variável da somatória da leitura do sensor da esquerda
  mediaVerdeD = 0; //Variável da média final das leituras da direita
  mediaVerdeE = 0; //Variável da média final das leituras da esquerda

  for (int i = 0; i < 10; i++) { //Faz 10 leituras diferentes e soma seus resultados
    md += analogRead(scd);
    me += analogRead(sce);
    divisor = divisor + 1;
  }

  //Realiza a média final das leituras
  mediaVerdeD = md / divisor; 
  mediaVerdeE = me / divisor;
}