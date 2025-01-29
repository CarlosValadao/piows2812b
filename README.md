Neste projeto foi realizado a integração da matriz 5x5 de LEDs RGB ws2812b, do teclado matricial 5x5 e um buzzer com a RaspBerry Pi PICO W incluída na plataforma de desenvolvimento BitDogLab.

## FUNCIONALIDADES

**Matriz 5x5 LED RGB ws2812b**

  - Pressione `0`: Os LEDs serão acesos formando o número 0.
  - Pressione `1`: Os LEDs serão acesos formando o número 1.
  - Pressione `2`: Os LEDs serão acesos formando o número 2.
  - Pressione `3`: Os LEDs serão acesos formando o número 3.
  - Pressione `4`: Os LEDs serão acesos formando o número 4.
  - Pressione `5`: Os LEDs serão acesos formando o número 5.
  - Pressione `6`: Os LEDs serão acesos formando o número 6.
  - Pressione `7`: Os LEDs serão acesos formando o número 7.
  - Pressione `8`: Os LEDs serão acesos formando o número 8.
  - Pressione `9`: Os LEDs serão acesos formando o número 9.
  - Pressione `A`: Todos os LEDs serão desligados.
  - Pressione `B`: Todos os LEDs serão ligados na cor azul com 100% de intensidade.
  - Pressione `C`: Todos os LEDs serão ligados na cor vermelha com 80% de intensidade.
  - Pressione `D`: Todos os LEDs serão ligados na cor verde com 50% de intensidade.
  - Pressione `#`: Todos os LEDs serão ligados na cor branca com 20% de intensidade.
  - Pressione `*`: O Raspberry Pi PICO W entra no modo de gravação (BOOTSEL).

## Tecnologias Utilizadas

- **Linguagem:** C
- **Hardware:** Raspberry Pi PICO W
- **Simulação:** [Wokwi](https://wokwi.com)
- **SDK:** Pico SDK versão 2.1.0  

## Requisitos para Execução

Antes de rodar o código, você precisa ter instalado:

1. **GNU Arm Embedded Toolchain**
   - [Instalar GNU Arm Embedded Toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm)

2. **Pico SDK 2.1.0**
   - Siga a [documentação oficial do Pico SDK](https://github.com/raspberrypi/pico-sdk) para configurá-lo.

3. **Extensões para VS Code:**
   - Raspberry Pi Pico
   - Wokwi
   - CMake

## Como Rodar

1. **Clone o repositório:**
   ```bash
   git clone https://github.com/CarlosValadao/piows2812b.git
   cd piows2812b
   ```

2. **Importe o projeto:**
   - Abra o VS Code.
   - No menu da extensão da Raspberry Pi Pico, escolha **"Importar Projeto"** e selecione o diretório do repositório.

3. **Compile o código:**
   - Use a opção de **"compile"** na extensão do Pico no VS Code.

4. **Simule no Wokwi:**
   - **Abra o arquivo do circuito configurado** e execute a simulação no Wokwi.

## Simulação no Wokwi

O circuito foi projetado e simulado no Wokwi. Certifique-se de usar o arquivo `diagram.json` para replicar a simulação.

## Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou pull requests para melhorias no projeto.

## Licença

Este projeto está sob a licença MIT. Consulte o arquivo `LICENSE` para mais detalhes.

## Contato

Para mais informações, entre em contato com [Carlos Valadão](https://github.com/CarlosValadao).