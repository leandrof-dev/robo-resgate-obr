void situacao(char s) {
  switch (s) {
    case 'L': //Seguindo linha
      desligaLeds();
      roxoFuncao(3);
      break;
    case 'O': //Obstáculo
      desligaLeds();
      analogWrite(ledAzul1, 255);
      analogWrite(ledAzul2, 255);
      break;
    //------------------CRUZAMENTO-------------------//
    case 'T': //Cruzamento em T
      desligaLeds();
      analogWrite(ledVermelho1, 255);
      analogWrite(ledAzul2, 255);
      break;
    case 'C': //Cruzamento
      desligaLeds();
      analogWrite(ledVermelho1, 255);
      analogWrite(ledVermelho2, 255);
      break;
    case 'k': //Cruzamento direita
      desligaLeds();
      analogWrite(ledVermelho1, 255);
      brancoFuncao(2);
      break;
    case 'i': //Cruzamento esquerda
      desligaLeds();
      analogWrite(ledVermelho1, 255);
      roxoFuncao(2);
      break;
  //---------------------- VERDE --------------------//
    case 'V': //Tem verde
      desligaLeds();
      analogWrite(ledVerde1, 255);
      analogWrite(ledVerde2, 255);
      break;
    case 'D': //Verde na direita
      desligaLeds();
      analogWrite(ledVerde1, 255);
      brancoFuncao(2);
      break;
    case 'E': //Verde na esquerda
      desligaLeds();
      analogWrite(ledVerde1, 255);
      roxoFuncao(2);
      break;
    case 'R': // Verde nos dois lados
      desligaLeds();
      brancoFuncao(3);
      break;
  //-----------------ARENA----------------//
  case 'A':
    desligaLeds();
    analogWrite(ledAzul1, 255);
    analogWrite(ledVerde1, 255);

    analogWrite(ledVermelho2, 150);
    analogWrite(ledAzul2, 120);
    analogWrite(ledVerde2, 120);
    break;
  //----------------FIM----------------//
  case 'F':
    piscaPisca();
    break;
  }
}

void desligaLeds() {
  analogWrite(ledVerde1, 0);
  analogWrite(ledAzul1, 0);
  analogWrite(ledVermelho1, 0);
  analogWrite(ledVerde2, 0);
  analogWrite(ledAzul2, 0);
  analogWrite(ledVermelho2, 0);
}

void amareloFuncao(int led) {
  if (led == 1) {
    analogWrite(ledAzul1, 0);
    analogWrite(ledVerde1, 50);
    analogWrite(ledVermelho1, 255);
  } else if (led == 2) {
    analogWrite(ledAzul2, 0);
    analogWrite(ledVerde2, 180);
    analogWrite(ledVermelho2, 255);
  } else {
    analogWrite(ledAzul1, 0);
    analogWrite(ledVerde1, 50);
    analogWrite(ledVermelho1, 255);
    analogWrite(ledAzul2, 0);
    analogWrite(ledVerde2, 50);
    analogWrite(ledVermelho2, 255);
  }
}
void roxoFuncao(int led) {
  if (led == 1) {
    analogWrite(ledAzul1, 207);
    analogWrite(ledVerde1, 0);
    analogWrite(ledVermelho1, 255);
  } else if (led == 2) {
    analogWrite(ledAzul2, 207);
    analogWrite(ledVerde2, 0);
    analogWrite(ledVermelho2, 255);
  } else {
    analogWrite(ledAzul1, 207);
    analogWrite(ledVerde1, 0);
    analogWrite(ledVermelho1, 255);
    analogWrite(ledAzul2, 207);
    analogWrite(ledVerde2, 0);
    analogWrite(ledVermelho2, 255);
  }
}
void brancoFuncao(int led) {
  if (led == 1) {
    analogWrite(ledAzul1, 255);
    analogWrite(ledVerde1, 255);
    analogWrite(ledVermelho1, 255);
  } else if (led == 2) {
    analogWrite(ledAzul2, 255);
    analogWrite(ledVerde2, 255);
    analogWrite(ledVermelho2, 255);
  } else {
    analogWrite(ledAzul1, 255);
    analogWrite(ledVerde1, 255);
    analogWrite(ledVermelho1, 255);
    analogWrite(ledAzul2, 255);
    analogWrite(ledVerde2, 255);
    analogWrite(ledVermelho2, 255);
  }
}

void setColor(int red, int green, int blue) {
  analogWrite(ledVermelho1, red);
  analogWrite(ledVerde1, green);
  analogWrite(ledAzul1, blue);

  analogWrite(ledVermelho2, red);
  analogWrite(ledVerde2, green);
  analogWrite(ledAzul2, blue);
}

// Função para pisca-pisca
void piscaPisca() {
  // Cores para pisca-pisca
  int colors[7][3] = {
    {255, 0, 0},   // Vermelho
    {0, 255, 0},   // Verde
    {0, 0, 255},   // Azul
    {255, 255, 0}, // Amarelo
    {0, 255, 255}, // Ciano
    {255, 0, 255}, // Magenta
    {255, 255, 255} // Branco
  };

  while (true) {
    for (int i = 0; i < 7; i++) {
      setColor(colors[i][0], colors[i][1], colors[i][2]);
      delay(300); // Espera por 1 segundo
    }
  }
}