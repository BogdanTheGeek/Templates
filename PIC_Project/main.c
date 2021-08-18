/*
 * File    : main.c
 * Created : 01/01/1970
 * Modified: 01/01/1970
 * Authors : Bogdan Ionescu
 */

#include "pic16f877a.h"
#include <stdint.h>

#define DELAY 30000

__code uint16_t __at (_CONFIG) __configword = _FOSC_HS & _WDTE_OFF & _PWRTE_OFF & _BOREN_OFF & _LVP_OFF & _CPD_OFF & _WRT_OFF & _CP_OFF;


void delay(uint16_t iterations) {
  uint16_t i;
  for (i = 0; i < iterations; i++) {
    __asm__("nop");          // add a no-op to prevent removal by optimization
  }
}

void main(void) {

  TRISA = 0;
  while (1) {
    PORTA = 1<<4;
    delay(DELAY);
    PORTA = 0;
    delay(DELAY);
  }
}
