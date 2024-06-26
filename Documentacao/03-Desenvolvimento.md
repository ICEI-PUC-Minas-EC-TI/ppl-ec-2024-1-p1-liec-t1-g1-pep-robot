
# Materiais

ESP32:
Descrição: Microcontrolador responsável pelo controle geral do robô e pela comunicação com o aplicativo móvel via Wi-Fi.

Cabo Mini USB:
Descrição: Utilizado para alimentar e programar o ESP32.

HC-06 Bluetooth:
Descrição: Módulo de comunicação Bluetooth para permitir a conexão sem fio entre o robô e o aplicativo móvel.

HC-SR04 Sensor Ultrassônico:
Descrição: Sensor utilizado para medir distâncias, ajudando o robô a detectar obstáculos e navegar autonomamente.

Mini Servo SG90 9g (x6):
Descrição: Seis pequenos motores servo utilizados para movimentar as partes do robô, permitindo que ele se mova e execute ações específicas.

Buzzer 5 Volts:
Descrição: Dispositivo de áudio utilizado para emitir sons ou alertas durante a operação do robô.

Cabos Fêmea-Fêmea:
Descrição: Utilizados para conectar os diversos componentes eletrônicos de forma prática e segura.

Caixa de Pilhas 4AA (6 Volts):
Descrição: Utilizada para abrigar as pilhas que alimentam o robô, fornecendo a energia necessária para os componentes eletrônicos.

4 Pilhas de 1.5 Volts AA:
Descrição: Pilhas utilizadas na caixa de pilhas para fornecer energia ao robô.

Mini Chave de Fenda Phillips (Cross Screw Driver):
Descrição: Ferramenta utilizada para montar e ajustar os componentes do robô.

# Desenvolvimento

Descreva aqui como foi o desenvolvimento do trabalho, destacando cada uma das etapas necessárias para chegar até a solução final.


## Desenvolvimento do Aplicativo

### Interface

Descreva o desenvolvimento das telas do aplicativo.
as telas do aplicativo foram feitas todas utilizando nossos conhecimentos adquiridos em nossas aulas de laboratorio pelo aplicativo do MIT app inventor.

### Código

O código foi desenvolvido em partes para cada componente do sistema. Foi dividido em duas partes principais: os códigos do App Inventor (utilizados para criar o aplicativo móvel) e os códigos do robô (programados para executar as funcionalidades controladas pelo aplicativo). As partes desenvolvidas separadamente foram então integradas em um único código para o robô.


## Desenvolvimento do Hardware

### Montagem

A montagem, foi feita iniciando pela carcaça do robo, com a impressora 3d. Finalizado isso prosseguimos, para encaixar os servo motores e a miniprotoboard dentro do robo, depois configuramos o buzzer e o sensor de distancia como os olhos do robo.

### Desenvolvimento do Código

Movimentação dos Servo Motores: Inicialmente, focamos na configuração e controle dos servo motores, garantindo que eles respondessem corretamente aos comandos.

Configuração do Sensor Ultrassônico: Após a movimentação dos servo motores estar funcionando adequadamente, configuramos o sensor ultrassônico. Este sensor foi essencial para medir a distância até objetos próximos e integrar essa informação ao comportamento do robô.

Integração do Buzzer: Em seguida, adicionamos o buzzer ao projeto, permitindo que o robô emitisse sons em resposta a eventos específicos, como a detecção de obstáculos pelo sensor ultrassônico.

Programação da Dança do Robô: Por fim, configuramos o robô para realizar uma dança. Para isso, utilizamos um código semipronto encontrado no GitHub, que foi modificado e ajustado conforme necessário para nosso projeto.

## Comunicação entre App e Hardware

Descreva como foi o processo de comunicação entre App e arduino/ESP.
