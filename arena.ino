void arena(bool subida) {
  if ((leituraS2 < 550 && leituraS2 > 280) && (leituraS3 < 550 && leituraS3 > 280) && (leituraS2 < 550 && leituraS2 > 280) && (leituraS4 < 650 && leituraS4 > 280) 
  && leituraSf < Preto || subida) { //Verifica se o robô está sobre a faixa prata
    if (ultrassonico_cm('E') > 15) return; //verifica se tem uma parede na esquerda, parede da arena;
    Serial.println("Arena");
    situacao('A');
    avancar(velAvancar); 
    delay(1200);
    velCurva = 210;
    velAvancar = velAvancar;

    if (ultrassonico_cm('E') > 11) { //Identifica se a parede está na esquerda, caso não, então a parede está na direita
      curvaDir(velCurva);
      delay(850);
      avancar(velAvancar); //Alinha o robô na parede
      delay(2000);
      voltar(velAvancar);
      delay(750);
      curvaEsq(velCurva);
      delay(955);
      parar();
      delay(100);
      arenaParedeD(); //Executa a arena seguindo a parede da direita
    } else { //Parede a esquerda
      curvaEsq(velCurva);
      delay(1000);
      avancar(velAvancar); //Alinha o robô na parede
      delay(2100);
      voltar(velAvancar);
      delay(1100);
      curvaDir(velCurva);
      delay(850);
      parar();
      delay(100);
      arenaParedeE(); //Executa a arena seguindo a parede da esquerda
    }
  }
}

void arenaParedeE() {
  for (int i = 0; i <= 4; i++) { //Executa a busca da saída 4 vezes
    while (true) { //Inicia um loop while até o sensor de toque encontrar o triangulo
      if (digitalRead(sensorToqueD) == 0 || digitalRead(sensorToqueE) == 0) break; //Verifica os sensores de toque
      if(i == 0 && ultrassonico_cm('F') <= 1) break; //Verifica se o sensor da frente está a uma distancia de 1 cm
      avancar(velAvancar - 15);
      leitura();
      int ultra = ultrassonico_cm('E');
      if (leituraS2 > Preto && leituraS3 > Preto || ultra >= 25) { //Verifica se tem saída
        parar();
        situacao('C');
        avancar(velAvancar);
        delay(500);
        if (ultra >= 25) { //Verifica se a saída foi identificada pelo ultra
          avancar(velAvancar);
          delay(210);
          curvaEsq(velCurva);
          delay(800);
          while (true) { //Avança até encontrar a linha preta
            avancar(velAvancar + 10);
            leitura();
            if (leituraS2 > Preto && leituraS3 > Preto) break;
          }
          delay(500);
        }
        parar();
        for(int i = 0; i < 5; i++) segue_linha(false);
        return;
      }
    }
    parar();
    delay(200);
    voltar(velAvancar);
    delay(510);
    curvaDir(velCurva);
    delay(440);
    parar();
    while (true) { //While responsavel por posicionar o robô depois do triângulo
      leitura();
      if (digitalRead(sensorToqueD) == 0 || digitalRead(sensorToqueE) == 0) break;
      if (leituraS2 > Preto || leituraS3 > Preto) { //Verifica se há saída no meio da arena
        situacao('V');
        avancar(velAvancar);
        delay(200);
        parar();
        return;
      }
      avancar(velAvancar - 15);
    }
    parar();
    delay(50);
    voltar(velAvancar);
    delay(300);
    curvaDir(velCurva);
    i == 1 ? delay(475) : delay(500);
    parar();
    delay(1000);
  }

  velAvancar = 118;
  velCurva = velCurvaI;
}

void arenaParedeD() {
  for (int i = 0; i <= 4; i++) { //Executa a busca da saída 4 vezes
    while (true) { //Inicia um loop while até o sensor de toque encontrar o triangulo
      if (digitalRead(sensorToqueD) == 0 || digitalRead(sensorToqueE) == 0) break; //Verifica os sensores de toque
      if(i == 0 && ultrassonico_cm('F') <= 1) break; //Verifica se o sensor da frente está a uma distancia de 1 cm
      avancar(velAvancar - 20);
      leitura();
      if (leituraS2 > Preto && leituraS3 > Preto || ultrassonico_cm('D') >= 25) { //Verifica se tem saída
        parar();
        desligaLeds();
        avancar(velAvancar);
        delay(400);
        if (ultrassonico_cm('D') >= 25) { //Verifica se a saída foi identificada pelo ultra
          avancar(velAvancar);
          delay(250);
          curvaDir(velCurva);
          delay(900);
          while (true) { //Avança até encontrar a linha preta
            avancar(velAvancar);
            leitura();
            if (leituraS2 > Preto && leituraS3 > Preto) break;
          }
          delay(100);
        }
        parar();
        int tempoEsperado = millis() + 1000;
        while (tempoEsperado > millis()) segue_linha(true);
        return;
      }
    }
    parar();
    delay(200);
    voltar(velAvancar);
    delay(500);
    curvaEsq(velCurva);
    delay(455);
    parar();
    while (true) { //While responsavel por posicionar o robô depois do triângulo
      leitura();
      if (digitalRead(sensorToqueD) == 0 || digitalRead(sensorToqueE) == 0) break;
      if (leituraS2 > Preto || leituraS3 > Preto) { //Verifica se há saída no meio da arena
        situacao('V');
        avancar(velAvancar);
        delay(200);
        parar();
        return;
      }
      avancar(velAvancar - 15);
    }
    parar();
    delay(50);
    voltar(velAvancar);
    delay(310);
    curvaEsq(velCurva);
    i == 1 ? delay(535) : delay(555);
    parar();
    delay(500);
  }
  velAvancar = 118;
  velCurva = velCurvaI;
}