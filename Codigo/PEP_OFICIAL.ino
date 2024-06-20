#include <ESP32Servo.h>

// Constantes para a direção
const int FRENTE = 1;
const int TRAS = -1;

//Definição da Variavel.
char num = 'O';

// Definição dos servos
Servo servoPeEsquerdo;
Servo servoPeDireito;
Servo servoPernaEsquerda;
Servo servoPernaDireita;
Servo servoBracoEsquerdo;
Servo servoBracoDireito;

// Definição das portas:
const int pinoPeEsquerdo = 2;
const int pinoPeDireito = 4;
const int pinoPernaEsquerda = 12;
const int pinoPernaDireita = 14;
const int pinoBracoEsquerdo = 16;
const int pinoBracoDireito = 17;
const int pinoBuzzer = 5;
const int trig = 12;
const int echo = 13;

  // Função para andar
void andar(int direcao, int passos) {
  for (int i = 0; i < passos; i++) {
    if (direcao == FRENTE) {
      // Movimento para frente
      passoFrente();
    } else {
      // Movimento para trás
      passoTras();
    }
  }
}

void passoFrente() {
  // Sequência de movimentos para andar para frente

  // Levanta a perna direita
  servoPernaDireita.write(60);
  delay(500);

  // Avança o pé direito
  servoPeDireito.write(120);
  delay(500);

  // Abaixa a perna direita
  servoPernaDireita.write(90);
  delay(500);

  // Levanta a perna esquerda
  servoPernaEsquerda.write(60);
  delay(500);

  // Avança o pé esquerdo
  servoPeEsquerdo.write(120);
  delay(500);

  // Abaixa a perna esquerda
  servoPernaEsquerda.write(90);
  delay(500);

  // Volta os pés para a posição neutra
  servoPeDireito.write(90);
  servoPeEsquerdo.write(90);
  delay(500);
}

void passoTras() {
  // Sequência de movimentos para andar para trás

  // Levanta a perna direita
  servoPernaDireita.write(60);
  delay(500);

  // Recuar o pé direito
  servoPeDireito.write(60);
  delay(500);

  // Abaixa a perna direita
  servoPernaDireita.write(90);
  delay(500);

  // Levanta a perna esquerda
  servoPernaEsquerda.write(60);
  delay(500);

  // Recuar o pé esquerdo
  servoPeEsquerdo.write(60);
  delay(500);

  // Abaixa a perna esquerda
  servoPernaEsquerda.write(90);
  delay(500);

  // Volta os pés para a posição neutra
  servoPeDireito.write(90);
  servoPeEsquerdo.write(90);
  delay(500);
}

//Função para mexer os braços.
void abrirBracos() {
  // Abrir os braços
  servoBracoEsquerdo.write(90);  // Ajuste conforme necessário para a posição aberta
  servoBracoDireito.write(90);   // Ajuste conforme necessário para a posição aberta
  delay(1000); // Tempo para os servos se moverem
}

void fecharBracos() {
  // Fechar os braços
  servoBracoEsquerdo.write(0);   // Ajuste conforme necessário para a posição fechada
  servoBracoDireito.write(180);  // Ajuste conforme necessário para a posição fechada
  delay(1000); // Tempo para os servos se moverem
}

void darOi() { // Levanta os braços para a posição de oi
  servoBracoEsquerdo.write(90);  // Ajuste conforme necessário para a posição de oi
  servoBracoDireito.write(90);   // Ajuste conforme necessário para a posição de oi
  delay(500);

  // Movimento de aceno
  for (int i = 0; i < 3; i++) {
    servoBracoEsquerdo.write(60);  // Ajuste conforme necessário para o movimento de aceno
    servoBracoDireito.write(120);  // Ajuste conforme necessário para o movimento de aceno
    delay(300);

    servoBracoEsquerdo.write(90);  // Volta para a posição de oi
    servoBracoDireito.write(90);   // Volta para a posição de oi
    delay(300);
  }

  // Abaixa os braços de volta para a posição inicial
  servoBracoEsquerdo.write(0);   // Ajuste conforme necessário para a posição inicial
  servoBracoDireito.write(180);  // Ajuste conforme necessário para a posição inicial
  delay(500);
}
// Função para apitar o buzzer rapidamente
void apitarBuzzer() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(pinoBuzzer, HIGH); // Liga o buzzer
    delay(100);                     // Espera 100 milissegundos
    digitalWrite(pinoBuzzer, LOW);  // Desliga o buzzer
    delay(100);                     // Espera 100 milissegundos
  }
}

void dancar() {
  // Movimento 1: Levantar os braços
  servoBracoEsquerdo.write(0);   
  servoBracoDireito.write(180); 
  delay(500);

  // Movimento 2: Mover os braços para o lado
  servoBracoEsquerdo.write(180);
  servoBracoDireito.write(0);
  delay(500);

  // Movimento 3: Pular para frente
  servoPernaEsquerda.write(60);
  servoPernaDireita.write(60);
  delay(500);

  servoPernaEsquerda.write(90);
  servoPernaDireita.write(90);
  delay(500);

  // Movimento 4: Pular para trás
  servoPernaEsquerda.write(120);
  servoPernaDireita.write(120);
  delay(500);

  servoPernaEsquerda.write(90);
  servoPernaDireita.write(90);
  delay(500);

  // Movimento 5: Girar os pés
  servoPeEsquerdo.write(0);
  servoPeDireito.write(180);
  delay(500);

  servoPeEsquerdo.write(180);
  servoPeDireito.write(0);
  delay(500);

  // Movimento 6: Movimentar os pés para dançar
  for (int i = 0; i < 3; i++) {
    servoPeEsquerdo.write(60);
    servoPeDireito.write(120);
    delay(300);

    servoPeEsquerdo.write(120);
    servoPeDireito.write(60);
    delay(300);
  }

  // Voltar para a posição inicial
  servoBracoEsquerdo.write(90);
  servoBracoDireito.write(90);
  servoPeEsquerdo.write(90);
  servoPeDireito.write(90);
  servoPernaEsquerda.write(90);
  servoPernaDireita.write(90);
  delay(500);
}

void setup() {
  Serial.begin(115200);

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
  servoPeDireito.write(90);
  servoPernaEsquerda.write(90);
  servoPernaDireita.write(180);
  servoBracoEsquerdo.write(0);   
  servoBracoDireito.write(180);

  delay(1000); // Pausa para estabilizar
}

void loop() {

  if (Serial.available() > 0){

    num = Serial.read();

    // Limpa o pino de trigger
    digitalWrite(trig, LOW);
    delayMicroseconds(2);

    // Gera um pulso de 10 microssegundos no pino de trigger
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    // Mede a duração do pulso recebido no pino echo
    long duracao = pulseIn(echo, HIGH);

    // Calcula a distância em centímetros
    int distancia = duracao * 0.034 / 2;

    if(distancia <= 20){
      darOi();
      delay(1000);
    }

    if(num == 'O'){//O = Quando o Pep inicializar

          // Andar para frente
      andar(FRENTE, 4); // (direção, número de passos)
      delay(1000);

      // Abrir os braços
      abrirBracos();
      delay(2000); // Manter os braços abertos por 2 segundos

      // Fechar os braços
      fecharBracos();
      delay(2000); // Manter os braços fechados por 2 segundos

      // Andar para trás
      andar(TRAS, 4); // (direção, número de passos)
      delay(1000);

      num = 'S';
    }

    if(num == 'A'){ //A = Quando o bluetooth conectar.
      apitarBuzzer();
    }

    if(num == 'B'){
      darOi();
    }

    if(num == 'C'){
      dancar();
    }
  }
}
