# Projeto de Animações em Matriz de LEDs 5x5

Este repositório contém os códigos necessários para controlar um teclado matricial 4x4, um buzzer passivo MLT8530 e uma matriz de LEDs WS2812b (dispostos em série). Os arquivos de código estão organizados em diferentes módulos, com funções específicas para a manipulação de cada componente do sistema.

## Estrutura do Repositório

### 1. **keyboard.h** e **keyboard.c**
Contêm funções para inicializar e capturar as teclas pressionadas do teclado matricial 4x4.

### 2. **mlt8530.h e mlt8530.c**
Funções para operar o buzzer passivo MLT8530, incluindo a inicialização e a emissão de frequências com durações específicas.

### 3. **ws2812b.h, ws2812b_motion.h e ws2812b_definitions.h**
Contêm funções para inicializar a máquina de estados responsável por enviar informações ao pino onde o WS2812b está conectado, enviar dados aos LEDs em série e desenhar padrões com base em uma matriz de 5x5 de 0s e 1s. Além disso, o `ws2812b_definitions.h` define cores como `RED`, `GREEN`, `BLUE`, `PURPLE`, `YELLOW` e `BLUE_MARINE`, e permite manipular a intensidade dos LEDs em porcentagem.

### 4. **Animações e Controle**
As animações da matriz de LEDs são baseadas em teclas pressionadas no teclado matricial. Cada tecla acionada corresponde a uma animação específica, e os efeitos gerados podem ser ajustados de acordo com as especificações do projeto.

## Requisitos do Projeto

### Atividade Obrigatória: Geração de Animações em uma Matriz de LEDs 5x5

O objetivo deste projeto é gerar animações em uma matriz de LEDs 5x5, controlada por um teclado matricial 4x4 e um buzzer passivo MLT8530, utilizando o Raspberry Pi Pico W. A animação e o controle dos LEDs são acionados pelas teclas do teclado.

**Componentes utilizados:**
- Teclado Matricial 4x4.
- Raspberry Pi Pico W.
- Matriz de LEDs 5x5 WS2812 (RGB).
- Buzzer Passivo MLT-8530 (opcional).

### Especificações e Requisitos:

1. **Teclado Matricial 4x4**:
   - As teclas de 0 a 9 acionam animações diferentes na matriz de LEDs 5x5, com cores, tipos de desenho e luminosidade definidas pela equipe de desenvolvimento.
   - Cada animação deve ter no mínimo 4 frames, com FPS (quadros por segundo) ajustável.

2. **Ações das Teclas**:
   - **Tecla A**: Desliga todos os LEDs.
   - **Tecla B**: Liga todos os LEDs na cor azul com intensidade de 100%.
   - **Tecla C**: Liga todos os LEDs na cor vermelha com intensidade de 80%.
   - **Tecla D**: Liga todos os LEDs na cor verde com intensidade de 50%.
   - **Tecla #**: Liga todos os LEDs na cor branca com intensidade de 20%.
   - **Tecla * (opcional)**: Habilita o modo de gravação via software no Raspberry Pi Pico W.

3. **Animações**:
   - São geradas animações baseadas nos desenhos de 5x5 LEDs, e cada animação é composta por no mínimo 5 frames. As animações podem ter sons associados, utilizando o buzzer passivo.

4. **Especificações Opcionais**:
   - **Buzzer**: Um sinal sonoro opcional é gerado durante uma das animações (ao pressionar 6).
   - **Modo de Gravação**: Caso a tecla * seja pressionada, o Raspberry Pi Pico W entra no modo de gravação, reiniciando o sistema.

### Requisitos Técnicos:

- **Ambiente de Desenvolvimento**:
  - O código foi desenvolvido utilizando **linguagem C**, com o uso do **Pico SDK** e **GNU ARM GCC (gcc-arm-eabi)**.
  - O ambiente de desenvolvimento utilizado é o **Visual Studio Code (VS Code)**, juntamente com as extensões **Raspberry Pi Pico** e **CMake**.

- **Simulação e Controle**:
  - O simulador Wokwi foi integrado ao ambiente de desenvolvimento para testar a comunicação entre os componentes (teclado, LEDs e buzzer).

- **GitHub**:
  - O repositório foi versionado e registrado no GitHub para facilitar a colaboração e o controle de versões.
  - Cada membro da equipe criou um branch para trabalhar nas suas respectivas tarefas e realizou commits regulares.

### Funcionalidades Implementadas:

- **Controle do Teclado Matricial**: Leitura das teclas e execução de animações nos LEDs.
- **Controle dos LEDs WS2812b**: Envio de dados para os LEDs, manipulação de cores e intensidade.
- **Geração de Animações**: Várias animações de 5x5 LEDs, com diferentes cores e intensidades.
- **Buzzer Passivo**: Emissão de sinais sonoros durante as animações.

## Instruções de Uso

1. **Clone o repositório**:
    ```bash
    git clone https://github.com/CarlosValadao/piows2812b.git
    ```
2. **Instale as dependências**:
    - Certifique-se de que o **Pico SDK** e **GNU ARM GCC** estão configurados corretamente no seu ambiente.
    - Instale o **VS Code** e as extensões **Raspberry Pi Pico** e **CMake**.

3. **Compile o código**:
    - Abra o VS Code e execute o CMake para compilar o projeto:
    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ```

4. **Envie o código para o Raspberry Pi Pico**:
    - Faça o upload do código compilado para o Raspberry Pi Pico W utilizando o ambiente de desenvolvimento.

5. **Teste no simulador Wokwi** (opcional):
    - Utilize o simulador Wokwi para testar a integração dos componentes sem a necessidade de hardware físico.

## Vídeo de Demonstração

[Assista à demonstração do projeto aqui](https://youtu.be/fCvgXIrpLeQ)

## Contribuições

Se você deseja contribuir para o projeto, siga estas etapas:

1. Faça um fork deste repositório.
2. Crie um novo branch.
3. Implemente suas modificações.
4. Submeta um pull request com uma descrição clara das mudanças realizadas.

## Licença

Este projeto está licenciado sob a [Licença MIT](LICENSE).
