#include <stdio.h>
#include "pico/stdlib.h"

/*Definicao de constantes */
#define PIN_RED_LED 12

#define TIME_BETWEEN_SIGNALS 125       //ms
#define TIME_BETWEEN_LETTERS 250       //ms
#define TIME_BETWEEN_TRANSMISSION 3000 //ms
#define DIT_DURATION 200               //ms
#define DAT_DURATION 800               //ms


/*Prototipo das funcoes */
void display_S_in_morse();
void display_O_in_morse();



void display_S_in_morse(){

  for(int i=0; i<3; ++i){
    gpio_put(PIN_RED_LED, true);
    sleep_ms(DIT_DURATION);
    gpio_put(PIN_RED_LED, false);
    if(i != 2) sleep_ms(TIME_BETWEEN_SIGNALS);
  }
}

void display_O_in_morse(){
  for(int i=0; i<3; ++i){
    gpio_put(PIN_RED_LED, true);
    sleep_ms(DAT_DURATION);
    gpio_put(PIN_RED_LED, false);
    if(i != 2) sleep_ms(TIME_BETWEEN_SIGNALS);
  }
}

int main() {
  /*Inicializacao dos pinos */
  gpio_init(PIN_RED_LED);
  gpio_set_dir(PIN_RED_LED, GPIO_OUT);
  stdio_init_all();

  while (true) {
    printf("Inicio da transmissão\n");
    display_S_in_morse();
    sleep_ms(TIME_BETWEEN_LETTERS);
    display_O_in_morse();
    sleep_ms(TIME_BETWEEN_LETTERS);
    display_S_in_morse();
    sleep_ms(TIME_BETWEEN_TRANSMISSION);
    printf("Reiniciando transmissão...\n");
  }
}