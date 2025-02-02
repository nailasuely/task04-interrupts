#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "features/matriz.c"
#include "features/matrix_led_control.c"
#include "pico/bootrom.h"


#define QTD_LEDS 25
#define PINO_MATRIZ 7

const uint pinoLEDVermelho = 13;  // LED Vermelho
const uint pinoLEDVerde = 11;     // LED Verde
const uint pinoLEDAzul = 12;      // LED Azul

const uint pinoBotaoA = 5;        // Botão A
const uint pinoBotaoB = 6;        // Botão B
const uint pinoReset = 22;        // Botão Reset


static void tratarInterrupcao(uint gpio, uint32_t eventos);


uint numeroExibido = 0;
bool modoReset = false;
static volatile uint32_t ultimoTempo = 0;
bool estadoLED = false;

void tratarInterrupcao(uint gpio, uint32_t eventos) {
    uint32_t tempoAtual = to_ms_since_boot(get_absolute_time());

    if (gpio == pinoBotaoB && numeroExibido < 9 && tempoAtual - ultimoTempo > 200) {  // Troquei Botão B para aumentar
        ultimoTempo = tempoAtual;
        numeroExibido++;
    }

    else if (gpio == pinoBotaoA && numeroExibido > 0 && tempoAtual - ultimoTempo > 200) {  // Troquei Botão A para diminuir
        ultimoTempo = tempoAtual;
        numeroExibido--;
    }
    
    else if (gpio == pinoReset) {
        modoReset = true;
    }
}


int main() {
    stdio_init_all();

    // Configuração dos botões e LEDs
    configurarBotao(pinoBotaoA);
    configurarBotao(pinoBotaoB);
    configurarBotao(pinoReset);
    configurarLED(pinoLEDVermelho);  

    inicializarPIO(PINO_MATRIZ);
    exibirMatriz(matrizDesligada, 0, 0.8); // Inicializa com a matriz apagada

    // Exibe o número inicial
    exibirMatriz(numerosFormatados[numeroExibido], 0, 1);

    // Configuração de interrupções nos botões
    gpio_set_irq_enabled_with_callback(pinoBotaoA, GPIO_IRQ_EDGE_FALL, true, &tratarInterrupcao);
    gpio_set_irq_enabled_with_callback(pinoBotaoB, GPIO_IRQ_EDGE_FALL, true, &tratarInterrupcao);
    gpio_set_irq_enabled_with_callback(pinoReset, GPIO_IRQ_EDGE_FALL, true, &tratarInterrupcao);

    uint ultimoValor = numeroExibido;

    while (true) {
        // Pisca o LED vermelho
        gpio_put(pinoLEDVermelho, estadoLED);
        estadoLED = !estadoLED; // Alterna o estado do LED
        sleep_ms(100);

        if (numeroExibido != ultimoValor && numeroExibido < 10) {
            exibirMatriz(numerosFormatados[numeroExibido], 0, 1);
            ultimoValor = numeroExibido;
        }
        
        if (modoReset) {
            printf("Iniciando modo de gravação...");
            reset_usb_boot(0, 0);
        }
        
        
        if (numeroExibido == 10) {
            exibirMatriz(matrizDesligada, 0, 0.8);
            ultimoValor = numeroExibido;
        }
    }
}

