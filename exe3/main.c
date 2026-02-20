#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

//Inicializando pinos como variáveis globais
const int LED_PIN_R = 4;
const int LED_PIN_G = 6;
const int BTN_PIN_R = 28;
const int BTN_PIN_G = 26;


int main() {
  stdio_init_all();

  //Inicializando leitura dos botões pela GPIO (mecanismo que faz a leitura de inputs e escrita de outputs)
  gpio_init(BTN_PIN_R);
  gpio_set_dir(BTN_PIN_R, GPIO_IN);
  gpio_pull_up(BTN_PIN_R);

  gpio_init(BTN_PIN_G);
  gpio_set_dir(BTN_PIN_G, GPIO_IN);
  gpio_pull_up(BTN_PIN_G);

  //Inicializando a escrita dos leds
  gpio_init(LED_PIN_R);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);
  gpio_init(LED_PIN_G);
  gpio_set_dir(LED_PIN_G, GPIO_OUT);

  while (true) {
    if (!gpio_get(BTN_PIN_R)) {
      printf("Botao R\n");
      if (gpio_get(LED_PIN_R) == 1){
        gpio_put(LED_PIN_R, 0);
      }
      else{
        gpio_put(LED_PIN_R, 1);
      }
      while (!gpio_get(BTN_PIN_R)) {
      };
    }

    if (!gpio_get(BTN_PIN_G)) {
      printf("Botao G\n");
      if (gpio_get(LED_PIN_G) == 1){
        gpio_put(LED_PIN_G, 0);
      }
      else{
        gpio_put(LED_PIN_G, 1);
      }
      while (!gpio_get(BTN_PIN_G)) {
      };
    }
  }
}
