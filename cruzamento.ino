void cruzamento() {
  leitura();  //Faz as leituras dos sensores
  //Verifica quais os possiveis cruzamentos o robô se encontra
  bool t_cruz = t_cruzamento();    //Cruzamento em formato de T (Robô deve verificar se há verdes)
  bool cruz_dr = cruzamento_DR();  //Cruzamento em formato de | com interseção no meio para a direita (Robô deve verificar se há verde, caso não, seguir reto)
  bool cruz_er = cruzamento_ER();  //Cruzamento em formato de | com interseção no meio para a esquerda (Robô deve verificar se há verde, caso não, seguir reto)
  bool cruz_d = cruzamento_D();    //Cruzamento em formato de L (Robô deve virar a direita)
  bool cruz_e = cruzamento_E();    //Cruzamento em formato de ꓶ (Robô deve virar a esquerda)
  bool cruz_r = cruzamento_R();    //Cruzamento em formarto de + (Robô deve verificar se há verde(s), caso não, seguir reto)

  if (t_cruz) {  // Caso o cruzamento seja em T
    Serial.println("Cruzamento em T");
    parar();
    situacao('T');  //Indica a situação de cruzamento (Azul)
    voltar(velAvancar);
    delay(150);
    parar();
    delay(400);
    verde();            //Verifica as condições dos sensores de cor (Se estão sobre o verde)
    avancar(velAvancar);
    delay(200);
  } else if (cruz_d) {  //Caso o cruzamento seja para a direita
    Serial.println("Cruzamento Direita");
    situacao('k');  //Indica a situação de cruzamento (Azul)
    avancar(velAvancar);
    delay(180);  //Avança o robô por 180ms (Isso é feito para que após a curva, o robô se localize no centro da linha preta)
    parar();
    curvaDir(velCurva);
    delay(500);                    //Realiza a curva para a direita por 500ms
    if (leituraSf < Preto + 50) {  //Verifica se o robô chegou na linha, caso não, realiza a mesma curva até o sensor da frente se localizar no centro da linha preta
      while (leituraSf < 600) {
        curvaDir(velCurva - 20);
        leitura();
      }
    }
    parar();
    avancar(velAvancar);
    delay(170);
    parar();
  } else if (cruz_e) {  // Caso o cruzamento seja para a esquerda
    Serial.println("Cruzamento Esquerda");
    situacao('i');  //Indica a situação de cruzamento (Azul)
    avancar(velAvancar);
    delay(100);  //Avança o robô por 180ms (Isso é feito para que após a curva, o robô se localize no centro da linha preta)
    parar();
    curvaEsq(velCurva);
    delay(500);                    //Realiza a curva para a esquerda por 500ms
    if (leituraSf < Preto + 50) {  //Verifica se o robô chegou na linha, caso não, realiza a mesma curva até o sensor da frente se localizar no centro da linha preta
      while (leituraSf < Preto) {
        curvaEsq(velCurva);
        leitura();
      }
    }
    parar();
    avancar(velAvancar);
    delay(180);
    parar();
  } else if (cruz_dr || cruz_er || cruz_r) {  //Caso seja um dos três cruzamentos em que se deve verificar o verde ou então seguir reto
    situacao('C');                            //Indica a situação de cruzamento (Azul)
    parar();
    voltar(velAvancar);
    delay(200);
    parar();
    delay(200);
    if (verde()) return;  //Verifica se há verde(s), caso sim, realiza a curva para o lado correto e encerra a função cruzamento
    avancar(velAvancar);
    Serial.println("Cruzamento Frente");
    delay(400);  //Avança o robô por 400ms para garantir que passará o cruzamento e os possiveis verdes, que se encontram após o cruzamento e devem ser ignorados
  }
}

//Funções que verificam os sensores e entendem se o tipo de cruzamento que se referem é possivel ser real naquela situação
bool cruzamento_DR() {
  if (leituraS1 < Preto && leituraS3 > Preto && leituraS4 > Preto && leituraSf > Preto - 50) return true;  //O sensor 2 não é verificado pois pode estar vendo uma faixa cinza e confundindo com preto
  return false;
}

bool cruzamento_ER() {
  if (leituraS1 > Preto && leituraS2 > Preto && leituraS4 < Preto && leituraSf > Preto - 50) return true;  //O sensor 3 não é verificado pois pode estar vendo uma faixa cinza e confundindo com preto
  return false;
}

bool cruzamento_D() {
  if ((leituraS1 < Preto + 40 && leituraS3 > Preto + 40 && leituraS4 > Preto + 40 && leituraSf < Preto - 40) || (leituraS1 < Preto + 40 && leituraS2 < Preto + 40 && leituraS3 < Preto + 40 && leituraS4 > Preto + 40 && leituraSf < Preto - 40)) return true;
  return false;
}

bool cruzamento_E() {
  if ((leituraS1 > Preto + 50 && leituraS2 > Preto + 50 && leituraS4 < Preto + 50 && leituraSf < Preto - 50) || (leituraS1 > Preto + 50 && leituraS2 < Preto + 50 && leituraS3 < Preto + 50 && leituraS4 < Preto + 50 && leituraSf < Preto - 50)) return true;
  return false;
}

bool cruzamento_R() {
  if (leituraS1 > Preto + 50 && leituraS2 > Preto + 50 && leituraS3 > Preto + 50 && leituraS4 > Preto + 50 && leituraSf > Preto - 50) return true;
  return false;
}

bool t_cruzamento() {
  if (leituraS1 > Preto - 150 && leituraS2 > Preto - 150 && leituraS3 > Preto - 150 && leituraS4 > Preto - 150 && leituraSf < Preto + 100) return true;
  return false;
}