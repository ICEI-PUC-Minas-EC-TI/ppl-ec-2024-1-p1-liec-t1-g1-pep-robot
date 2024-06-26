#include <ESP32Servo.h>
#include <BluetoothSerial.h>
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run make menuconfig to and enable it
#endif
BluetoothSerial SerialBT;



int num = 0;
int varDancar = 0;
int estaDancando = 0;
#define SOUND_SPEED 0.034
long duration;
float distanceCm;
float distanceInch;

// Definição dos servos
Servo servoPeEsquerdo;
Servo servoPeDireito;
Servo servoPernaEsquerda;
Servo servoPernaDireita;
Servo servoBracoEsquerdo;
Servo servoBracoDireito;

// Definição das portas:
const int pinoPeEsquerdo = 22;
const int pinoPeDireito = 33;
const int pinoPernaEsquerda = 21;
const int pinoPernaDireita = 32;
const int pinoBracoEsquerdo = 18;
const int pinoBracoDireito = 19;
const int pinoBuzzer = 15;
const int trig = 2;
const int echo = 4;

void darOi() {
  delay(100); // Levanta os braços para a posição de oi
  servoBracoDireito.write(130);
  delay(5000);  // Ajuste conforme necessário para a posição de oi
  servoBracoDireito.write(90);
  delay(200);
     // Ajuste conforme necessário para a posição de oi
}
void verificarSensor() {
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    duration = pulseIn(echo, HIGH);
    distanceCm = duration * SOUND_SPEED/2;
    if (distanceCm < 5){
      delay(50);
      pararDancar();
      delay(50);
      num == 0;
    //  varDancar = 0;
      delay(50);
      for (int i = 0; i < 3; i++) {
        tone(pinoBuzzer, 1000);
        delay(200);
        noTone(pinoBuzzer);  
        delay(200);                   // Espera 100 milissegundos
      }
    }
}
// Função para apitar o buzzer rapidamente
void apitarBuzzer() {
  for (int i = 0; i < 3; i++) {
    tone(pinoBuzzer, 1000);
    delay(1000);
    noTone(pinoBuzzer);  
    delay(1000);                   // Espera 100 milissegundos
  }
}
void pararDancar() {
  varDancar = 0;
}

void dancar() {
  if(estaDancando == 0){
    estaDancando = 1;
    delay(100);
    servoBracoEsquerdo.write(30);
    delay(200);
    servoBracoDireito.write(120);
    delay(200);
    servoPeDireito.write(150);
    delay(200);
    servoPernaDireita.write(70);
    delay(200);
    servoPeEsquerdo.write(30);
    delay(200);
    servoPernaEsquerda.write(110);
    delay(200);
    servoPeDireito.write(90);
    delay(200);
    servoPernaDireita.write(90);
    delay(200);
    servoPeEsquerdo.write(90);
    delay(200);
    servoPernaEsquerda.write(90);
    delay(200);
    servoBracoEsquerdo.write(90);
    delay(200);
    servoBracoDireito.write(90);
    delay(200);
    servoBracoEsquerdo.write(30);
    delay(200);
    servoBracoDireito.write(120);
    delay(200);
    servoPeDireito.write(150);
    delay(200);
    servoPernaDireita.write(110);
    delay(200);
    servoPeEsquerdo.write(30);
    delay(200);
    servoPernaEsquerda.write(70);
    delay(200);
    servoPeDireito.write(90);
    delay(200);
    servoPernaDireita.write(90);
    delay(200);
    servoPeEsquerdo.write(90);
    delay(200);
    servoPernaEsquerda.write(90);
    delay(200);
    servoBracoEsquerdo.write(90);
    delay(200);
    servoBracoDireito.write(90);
    delay(200);
    estaDancando = 0;
    delay(100);
  }
}

void setup() {
  Serial.begin(9600);
  SerialBT.begin("ROBO");

  pinMode(pinoBuzzer, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  servoPeEsquerdo.attach(pinoPeEsquerdo);
  servoPeDireito.attach(pinoPeDireito);
  servoPernaEsquerda.attach(pinoPernaEsquerda);
  servoPernaDireita.attach(pinoPernaDireita);
  servoBracoEsquerdo.attach(pinoBracoEsquerdo);
  servoBracoDireito.attach(pinoBracoDireito);

  // Posição inicial dos servos (posição neutra)
  servoPeEsquerdo.write(90);
  delay(100);
  servoPeDireito.write(90);
  delay(100);
  servoPernaEsquerda.write(90);
  delay(100);
  servoPernaDireita.write(90);
  delay(100);
  servoBracoEsquerdo.write(90);
  delay(100); 
  servoBracoDireito.write(90);
  delay(100); // Pausa para estabilizar
}

void loop() {
  verificarSensor();
  if(varDancar == 1){
    dancar();
  }
  if (SerialBT.available() > 0){

    num = (int)SerialBT.read();

    if(num == 1){ 
      varDancar = 0;
      delay(200);
      apitarBuzzer();
      delay(200);
      num == 0;
    }

    if(num == 2){
      varDancar = 0;
      delay(200);
      darOi();
      delay(200);
      num == 0;
    }

    if(num == 3){
      varDancar = 1;
      num == 0;
    }
    if(varDancar == 0){
      delay(50);
      pararDancar();
      num == 0;
    }
  }
}
