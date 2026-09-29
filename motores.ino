//Avançar
void avancar(byte forca) {
  digitalWrite(MDF,HIGH);
  digitalWrite(MDT,LOW);
  analogWrite(velD, forca);
  digitalWrite(MEF,HIGH);
  digitalWrite(MET,LOW);
  analogWrite(velE, forca+60); 
  //Serial.print("avancar");
}

//Voltar
void voltar(byte forca) {
  digitalWrite(MDF,LOW);
  digitalWrite(MDT,HIGH);
  analogWrite(velD, forca-20); // robo grande usar 20
  digitalWrite(MEF,LOW);
  digitalWrite(MET, HIGH);
  analogWrite(velE, forca+15);
}

//Parar
void parar() {
  digitalWrite(MDF, LOW);
  digitalWrite(MEF,LOW);
  digitalWrite(MDT, LOW);
  digitalWrite(MET, LOW);
}

//Curva  Esquerda
void curvaEsq(byte forca) {
  digitalWrite(MDF,HIGH);
  digitalWrite(MDT, LOW);
  analogWrite(velE, forca);
  digitalWrite(MEF, LOW);
  digitalWrite(MET, HIGH);
  analogWrite(velD, forca-15); // robo grande usar 20
  //Serial.println("Curva Esq");
}

//Curva  Direita
void curvaDir(byte forca) {
  digitalWrite(MDF,LOW);
  digitalWrite(MDT, HIGH);
  analogWrite(velE, forca-5); // robo grande usar 20
  digitalWrite(MEF, HIGH);
  digitalWrite(MET, LOW);
  analogWrite(velD, forca);
  //Serial.println("Curva Dir");
}

//Curva para o 180 graus
void curva180(byte forca){
  digitalWrite(MDF,HIGH);
  digitalWrite(MDT,LOW);
  analogWrite(velD, forca);
  digitalWrite(MEF,LOW);
  digitalWrite(MET,HIGH);
  analogWrite(velE, forca+10); 
}