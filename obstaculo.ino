int tempoEsperado = 0;
bool temObstaculoEm90 = false;

bool obstaculo(int lado, bool curvaEm90) {
  int tempoEsperado;
  temObstaculoEm90 = curvaEm90;
  situacao('O');
  parar();
  delay(100);
  voltar(velAvancar);
  delay(900);
  parar();
  delay(100);
  if (lado == 'D') desvioD();
  else if (lado == 'E') desvioE();
}

void desvioD() {
  curvaDir(velCurva);
  delay(950);
  parar();
  delay(100);
  avancar(velAvancar);
  delay(1100);
  parar();
  delay(100);
  curvaEsq(velCurva);
  delay(950);
  parar();
  avancar(velAvancar);
  delay(500);
  while (true) {
    if (ultrassonico_cm('E') < 20 && ultrassonico_cm('E') > 0) break;
    avancar(velAvancar);
    Serial.println(ultrassonico_cm('E'));
  }
  avancar(velAvancar);
  if (!temObstaculoEm90) {
    delay(1700);
  } else {
    while (leituraSf < 700) {
      leitura();
      avancar(velAvancar);
    }
    delay(300);
    parar();
    obstaculo90('D');
    return;
  }

  parar();
  curvaEsq(velCurva);
  delay(900);
  parar();
  avancar(velAvancar);
  delay(200);
  leitura();
  while (leituraSf < 700) {
    leitura();
    avancar(velAvancar - 10);
  }
  delay(400);
  parar();
  leitura();
  while (leituraSf < 750) {
    leitura();
    curvaDir(velCurva - 10);
  }
  delay(100);
  parar();
}

void desvioE() {
  curvaEsq(velCurva);
  delay(1080);
  parar();
  delay(100);
  avancar(velAvancar);
  delay(1200);
  parar();
  delay(100);
  curvaDir(velCurva);
  delay(950);
  parar();
  while (true) {
    leitura();
    if (ultrassonico_cm('D') < 12 && ultrassonico_cm('D') > 0 || (leituraSf > 800 && temObstaculoEm90)) break;
    avancar(velAvancar);
    situacao('L');
  }
  avancar(velAvancar);
  if (!temObstaculoEm90) {
    delay(700);
  } else {
    while (leituraSf < 700) {
      avancar(velAvancar);
      leitura();
    }
    delay(200);
    parar();
    obstaculo90('E');
    return;
  }
  parar();
  curvaDir(velCurva);
  delay(800);
  parar();
  leitura();
  while (leituraSf < 800) {
    leitura();
    avancar(velAvancar);
  }
  delay(400);
  parar();
  leitura();
  while (leituraSf < 800) {
    leitura();
    curvaEsq(velCurva);
  }
  parar();
  situacao('L');
  delay(100);
  desligaLeds();
  delay(100);
}

void obstaculo90(char lado) {
  parar();
  delay(100);
  switch (lado) {
    case 'D':
      curvaDir(velCurva);
      delay(1100);
      parar();
      break;
    case 'E':
      curvaEsq(velCurva);
      delay(1000);
      parar();
      break;
  }
}