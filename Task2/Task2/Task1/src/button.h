#ifndef BUTTON_H_
#define BUTTON_H_

#include <asf.h>

#define BUTTON_PIN_1_MASK   PIO_PA22
#define BUTTON_PIN_1_PIO    PIOA
#define BUTTON_PIN_1_ID     ID_PIOA
#define BUTTON_PIN_1_TYPE   PIO_INPUT
#define BUTTON_PIN_DOWN_ATTR   PIO_PULLUP | PIO_DEBOUNCE | PIO_IT_RISE_EDGE
#define BUTTON_PIN_UP_ATTR   PIO_PULLUP | PIO_DEBOUNCE | PIO_IT_FALL_EDGE

volatile uint32_t button_flag;
volatile uint32_t button_status;
void configure_button(void);


#endif /* BUTTON_H_ */