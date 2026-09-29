// Definições dos pinos dos sensores de luz e de cor (Luz: Fita vermelha)
#define s1 A0   //Fio verde
#define s2 A1   //Fio amarelo
#define s3 A2   //Fio branco
#define s4 A3   //Fio roxo
#define sf A4   //Sensor de luz na ponta da placa, Fio Azul
#define sce A8  //Senor de cor da esquerda
#define scd A9  //Sensor de cor da direita

//Definição dos Ultrassônicos, o sufixo indica a qual se refere (F: Frente, D: Direita e E: Esquerda)
#define echoF 5   //cinza
#define trigF 26  // azul

#define echoD 6   //verde
#define trigD 24  //amarelo

#define echoE 4   //azul
#define trigE 28  //cinza

//Definição dos leds que fazem o feedback da programação de forma visual
#define ledVermelho1 A13  //Fio verde
#define ledVerde1 A14     //Fio azul
#define ledAzul1 A15      //Fio branco

#define ledVermelho2 A10  //Fio verde
#define ledVerde2 A11     //Fio azul
#define ledAzul2 A12      //Fio branco

#define sensorSubida 32
#define sensorDescida 34

#define Preto 750

#define sensorToqueE 50
#define sensorToqueD 52

//Definição dos pinos dos motores
int MET = 11;  // MOTOR ESQUERDO TRAS -- IN 1 -- verde
int MEF = 10;  // MOTOR Esquerdo FRENTE -- IN 2 -- amarelo

int velE = 8;  // Velocidade do motor da esquerda

int MDT = 12;  // MOTOR DIREITO TRAS -- IN 3 -- marrom
int MDF = 13;  // MOTOR Direito FRENTE --IN 4 -- azul

int velD = 9;  // Velocidade do motor da direita

//Definição das variaveis que armazenam os valores das leituras dos sensores de luz e cor
int leituraSf = 0;
int leituraS1 = 0;
int leituraS2 = 0;
int leituraS3 = 0;
int leituraS4 = 0;

int leituraCD = 0;
int leituraCE = 0;

//Variaveis que são usadas para verificar a media da luz verde no sensor de cor
int mediaVerdeD = 0;
int mediaVerdeE = 0;

//Variaveis que armazenam os valores das leituras dos ultrassônicos
int ultraEValor = 0;
int ultraDValor = 0;
int ultraFValor;

int velCurvaI = 178;
//Variaveis que definem as velocidades padrões do código todo
int velAvancar = 118;
int velCurva = velCurvaI;

int contador = 0;

void setup() {
  Serial.begin(9600);

  //Definindo os tipos de pinos (INPUT, OUTPUT ou INPUT_PULLUP)
  pinMode(MDT, OUTPUT);
  pinMode(MDF, OUTPUT);
  pinMode(MET, OUTPUT);
  pinMode(MEF, OUTPUT);

  pinMode(ledVerde1, OUTPUT);
  pinMode(ledAzul1, OUTPUT);
  pinMode(ledVermelho1, OUTPUT);
  pinMode(ledVerde2, OUTPUT);
  pinMode(ledAzul2, OUTPUT);
  pinMode(ledVermelho2, OUTPUT);

  pinMode(trigF, OUTPUT);
  digitalWrite(trigF, LOW);
  delayMicroseconds(10);
  pinMode(echoF, INPUT);

  pinMode(trigD, OUTPUT);
  digitalWrite(trigD, LOW);
  delayMicroseconds(10);
  pinMode(echoD, INPUT);

  pinMode(trigE, OUTPUT);
  digitalWrite(trigE, LOW);
  delayMicroseconds(10);
  pinMode(echoE, INPUT);

  pinMode(sensorSubida, INPUT);
  pinMode(sensorDescida, INPUT);

  pinMode(sensorToqueE, INPUT_PULLUP);
  pinMode(sensorToqueD, INPUT_PULLUP);

}

void loop() {
  //Nesta parte verificamos os ultrassônicos e caso não haja obstáculos e o robô não estar em uma rampa ele irá seguir linnha
  leitura();
  if (ultrassonico_cm('F') < 4 && ultrassonico_cm('F') > 0 && 0) {
    obstaculo('E', false);  //D para direita e E para a esquerda
  } else {
    if (digitalRead(sensorSubida) == 0 && 0) {  //Verfifica o sensor de inclinação, caso esteja ativo, executa rampa(true)(subida);
      rampa(true);
    } else if (digitalRead(sensorDescida) == 0 && 0) {  //Verfifica o sensor de declinação, caso esteja ativo, executa rampa(false) (descida);
      rampa(false);
    } else {  //Caso não tenha inclinação ou declinação, o robô segirá linha de forma normal
      segue_linha(false);
      //fim();  //Verifica se esta na faixa vermelha

    }
  }
}

void fim() {
  if (leituraS1 > 50 && leituraS1 < 200 && leituraS2 > 20 && leituraS2 < 200 && leituraS3 > 40 && leituraS3 < 200 && leituraS4 > 200 && leituraS4 < 330) {
    //Verifica se é a faixa e vermelha;
    Serial.println("Fim");
    voltar(velAvancar);  //Avança para posicionar os sensores de cor sobre a faixa
    delay(300);
    parar();
    delay(100);
    mediaVerde();
    if (mediaVerdeD > 170 && mediaVerdeE > 170) {  //Verifica se está entre as leituras que represetam o vermelho;
      desligaLeds();
      parar();
      situacao('F');
    }
    situacao('V');
    avancar(velAvancar);
    delay(500);
  }
}