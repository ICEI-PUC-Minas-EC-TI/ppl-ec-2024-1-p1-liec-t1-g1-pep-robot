
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


O desenvolvimento das telas do aplicativo foi realizado utilizando o MIT App Inventor, aplicando os conhecimentos adquiridos em nossas aulas de laboratório
Tela de Conexão Bluetooth:

Descrição: Esta tela é a primeira vista ao abrir o aplicativo. Ela permite que o usuário inicie a conexão Bluetooth com o robô.
Componentes:
Botão "Conectar": Inicia a busca por dispositivos Bluetooth disponíveis para conexão.
Lista de Dispositivos: Mostra os dispositivos encontrados para que o usuário selecione o robô.
Menu Principal:

Descrição: Após a conexão bem-sucedida, o usuário é direcionado para o menu principal, onde pode escolher entre diversas funcionalidades disponíveis.
Componentes:
Botões de Opções: Cada botão representa uma funcionalidade do robô, como Saudação, Tradutor, Dancinha, Calculadora, Previsão do Tempo e Horário.
Ícones e Nomes: Cada funcionalidade é representada por um ícone e um nome para fácil identificação.
Tela de Saudação:

Descrição: Ao selecionar "Saudação" no menu principal, esta tela permite que o usuário veja o robô executar uma saudação visual ou auditiva.
Componentes:
Botão "Executar Saudação": Inicia a sequência de saudação no robô.
Vídeo ao Vivo: Mostra o robô em tempo real executando a saudação.
Tela de Tradutor:

Descrição: Nesta tela, o usuário pode inserir uma palavra para ser traduzida pelo robô.
Componentes:
Campo de Texto: Permite ao usuário digitar a palavra a ser traduzida.
Botão "Traduzir": Inicia o processo de tradução, exibindo o resultado na tela e o robô pronunciando a tradução.
Tela de Dancinha:

Descrição: Ao escolher "Dancinha" no menu, esta tela exibe opções para iniciar uma coreografia no robô.
Componentes:
Lista de Coreografias: Mostra diferentes opções de danças disponíveis.
Botão "Executar Dança": Inicia a dança selecionada no robô.
Tela de Calculadora:

Descrição: Permite ao usuário realizar cálculos simples utilizando o robô como assistente.
Componentes:
Campo de Entrada: Onde o usuário digita a expressão matemática.
Botão "Calcular": Inicia o cálculo e exibe o resultado na tela, além do robô falar o resultado.
Tela de Previsão do Tempo:

Descrição: Mostra a previsão do tempo atual para uma localização específica.
Componentes:
Campo de Localização: O usuário insere a cidade ou código postal para verificar a previsão.
Botão "Obter Previsão": Inicia a busca pela previsão do tempo, exibindo as informações na tela e no robô.
Tela de Horário:

Descrição: Informa as horas atuais, utilizando o robô para falar a hora.
Componentes:
Botão "Ver Horário": Inicia a exibição do horário atual pelo robô.

### Código

O código foi desenvolvido em partes para cada componente do sistema. Foi dividido em duas partes principais: os códigos do App Inventor (utilizados para criar o aplicativo móvel) e os códigos do robô (programados para executar as funcionalidades controladas pelo aplicativo). As partes desenvolvidas separadamente foram então integradas em um único código para o robô.


## Desenvolvimento do Hardware

### Montagem

 A primeira etapa do projeto envolveu a criação da carcaça do robô utilizando uma impressora 3D. Com a carcaça impressa e pronta, a próxima etapa foi encaixar os servo motores SG90 9g. Utilizando parafusos e a mini chave de fenda Phillips, fixamos os seis servo motores nos locais designados dentro da carcaça. Conectamos os cabos dos servos à mini protoboard, garantindo que todos os motores estivessem corretamente ligados ao ESP32 para controle. A mini protoboard foi colocada dentro da carcaça do robô para facilitar as conexões elétricas entre os componentes.  A mini protoboard foi fixada em uma posição central dentro da carcaça para otimizar o espaço e facilitar as conexões. Utilizando cabos fêmea-fêmea, conectamos os servos, o buzzer, o sensor ultrassônico e o módulo Bluetooth à protoboard, que por sua vez estava conectada ao ESP32. O buzzer de 5 volts foi configurado para emitir sons e alertas durante a operação do robô. O buzzer foi fixado na parte superior da carcaça, em um local onde o som pudesse ser claramente ouvido. Conectamos o buzzer à mini protoboard e ao ESP32, configurando o pino de controle no código para permitir a emissão de sons. O sensor ultrassônico HC-SR04 foi instalado como os "olhos" do robô, permitindo a detecção de obstáculos.


### Desenvolvimento do Código

Movimentação dos Servo Motores: Inicialmente, focamos na configuração e controle dos servo motores, garantindo que eles respondessem corretamente aos comandos.

Configuração do Sensor Ultrassônico: Após a movimentação dos servo motores estar funcionando adequadamente, configuramos o sensor ultrassônico. Este sensor foi essencial para medir a distância até objetos próximos e integrar essa informação ao comportamento do robô.

Integração do Buzzer: Em seguida, adicionamos o buzzer ao projeto, permitindo que o robô emitisse sons em resposta a eventos específicos, como a detecção de obstáculos pelo sensor ultrassônico.

Programação da Dança do Robô: Por fim, configuramos o robô para realizar uma dança. Para isso, utilizamos um código semipronto encontrado no GitHub, que foi modificado e ajustado conforme necessário para nosso projeto.

## Comunicação entre App e Hardware

Descreva como foi o processo de comunicação entre App e arduino/ESP.
