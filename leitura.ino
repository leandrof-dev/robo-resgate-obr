//Função responsável por realizar as leituras dos sensores de cor e luz
void leitura() {
  leituraSf = analogRead(sf);
  leituraS1 = analogRead(s1);
  leituraS2 = analogRead(s2);
  leituraS3 = analogRead(s3);
  leituraS4 = analogRead(s4);

  leituraCD = analogRead(scd);
  leituraCE = analogRead(sce);
}

//Função usada para mostrar as leituras de todos os sensores
void mostraLeituras() {
  Serial.print("Leitura refletancia: ");
  Serial.println(String(leituraS1) + " " + String(leituraS2) + " " + String(leituraSf) + " " + String(leituraS3) + " " + String(leituraS4));
  Serial.print("Leitura cor: ");
  mediaVerde();
  Serial.println(String(mediaVerdeE) + " " + String(mediaVerdeE));
  Serial.println("-----------------------------\n");
  delay(1000);
}