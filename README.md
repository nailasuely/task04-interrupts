<h1 align="center">
  <br>
    <img width="300px" src="https://github.com/nailasuely/task04-interrupts/blob/main/src/logo.png">
  <br>
  Capítulo 4 - Interrupções
  <br>
</h1>
<div align="center">

</div>

<div align="center"> 
  
Este projeto tem como objetivo utilizar o Raspberry Pi Pico para controlar uma matriz de LEDs 5x5, 
LEDs RGB, e realizar manipulações interativas com botões, utilizando interrupções e debouncing via software.
</div>

<details open="open">
<summary>Sumário</summary>
  
- [Requisitos](#requisitos)
- [Componentes Utilizados](#componentes-utilizados)
- [Estrutura do Projeto](#estrutura-do-projeto)
- [Funcionalidades](#funcionalidades)
- [Como Executar](#como-executar)
  - [Pré-requisitos](#pré-requisitos)
  - [Passos para Execução](#passos-para-execução)
- [Testes Realizados](#testes-realizados)
- [Vídeo Demonstração](#vídeo-demonstração)
- [Autora](#autora)

</details>


## Requisitos

- **Raspberry Pi Pico** com o microcontrolador RP2040.
- **Matriz de LEDs 5x5 WS2812**.
- **LED RGB** (pinos GPIO 11, 12 e 13).
- **Botões A e B** conectados aos pinos GPIO 5 e GPIO 6.
- Utilização do **SDK do Raspberry Pi Pico** e programação em **C**.
- **Tratamento de debouncing** de botões via software.

![-----------------------------------------------------](https://github.com/nailasuely/breakout-problem3/blob/main/assets/img/prancheta.png)


## Componentes Utilizados

- **Raspberry Pi Pico** (RP2040).
- **Matriz de LEDs 5x5 WS2812** (conectada à GPIO 7).
- **LED RGB** (com pinos conectados às GPIOs 11, 12 e 13).
- **Botões A e B** (conectados aos pinos GPIO 5 e GPIO 6).
  
![-----------------------------------------------------](https://github.com/nailasuely/breakout-problem3/blob/main/assets/img/prancheta.png)


## Estrutura do Projeto
- **task04-interrupts.c**: Arquivo principal que integra o controle da matriz de LEDs e o teclado matricial.
- **matriz.c**: Controla a matriz de LEDs, configurando botões e LEDs, e exibindo animações.
- **features/matrix_led_control.c**: Contém padrões de animação e números formatados para exibição na matriz de LEDs.
  
![-----------------------------------------------------](https://github.com/nailasuely/breakout-problem3/blob/main/assets/img/prancheta.png)


## Funcionalidades

- **Piscar LED Vermelho**: O LED vermelho (RGB) pisca 5 vezes por segundo.
- **Incremento e Decremento com Botões**: 
  - O **Botão A** (GPIO 5) incrementa o número exibido na matriz de LEDs (de 0 a 9).
  - O **Botão B** (GPIO 6) decrementa o número exibido na matriz de LEDs (de 0 a 9).
- **Exibição de Números**: 
  - A matriz de LEDs WS2812 é usada para criar efeitos visuais que representam números de 0 a 9.
  - Debouncing via software para garantir que o botão seja lido corretamente.

![-----------------------------------------------------](https://github.com/nailasuely/breakout-problem3/blob/main/assets/img/prancheta.png)


## Como Executar

### Pré-requisitos

1. **Instalar o SDK do Raspberry Pi Pico**.
2. **Compilar o código** usando o compilador adequado para o Raspberry Pi Pico.
3. **Carregar o código** no Raspberry Pi Pico.

### Passos para Execução

1. **Conectar o hardware**
   
3. **Compilar o código** utilizando o **Pico SDK**:
   - Utilize o CMake para compilar o código e gerar o arquivo .uf2 para o Raspberry Pi Pico.

4. **Carregar o código no Raspberry Pi Pico**:
   - Após compilar, arraste o arquivo .uf2 para a unidade de armazenamento do Raspberry Pi Pico para carregá-lo.

5. **Interação**:
   - **Botão A**: Pressione para incrementar o número exibido na matriz.
   - **Botão B**: Pressione para decrementar o número exibido na matriz.
   - O LED vermelho piscará a cada 100ms.
     
![-----------------------------------------------------](https://github.com/nailasuely/breakout-problem3/blob/main/assets/img/prancheta.png)


## Testes Realizados

![-----------------------------------------------------](https://github.com/nailasuely/breakout-problem3/blob/main/assets/img/prancheta.png)

   
## Vídeo Demonstração
[Link](https://youtu.be/5P4eKq4PS4c)
## Autora

<table>
  <tr>
    <td align="center">
      <a href="https://github.com/nailasuely" target="_blank">
        <img src="https://avatars.githubusercontent.com/u/98486996?v=4" width="100px;" alt=""/>
      </a>
      <br /><sub><b> Naila Suele </b></sub>
    </td>

</table>


