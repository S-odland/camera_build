#include "button.h"

volatile uint32_t button_flag = false;
volatile uint32_t button_status = true; // true = up and false = down

static void button_handler(uint32_t ul_id, uint32_t ul_mask) {
	
	unused(ul_id);
	unused(ul_mask);
	
	if (button_status) {
		button_flag = true;
		pio_handler_set(BUTTON_PIN_1_PIO, BUTTON_PIN_1_ID, BUTTON_PIN_1_MASK, BUTTON_PIN_UP_ATTR, button_handler); // Initialize pio interrupt handler, see pio definition in conf_board.h
		button_status = false;
	} else {
		button_flag = true;
		pio_handler_set(BUTTON_PIN_1_PIO, BUTTON_PIN_1_ID, BUTTON_PIN_1_MASK, BUTTON_PIN_DOWN_ATTR, button_handler); // Initialize pio interrupt handler, see pio definition in conf_board.h
		button_status = true;
	}
}

void configure_button(void) {
	
	pmc_enable_periph_clk(BUTTON_PIN_1_ID); // configure pio clock
	pio_set_debounce_filter(BUTTON_PIN_1_PIO, BUTTON_PIN_1_MASK, 10); // adust pio debounce filter using a 10 Hz filter
	pio_handler_set(BUTTON_PIN_1_PIO, BUTTON_PIN_1_ID, BUTTON_PIN_1_MASK, BUTTON_PIN_DOWN_ATTR, button_handler); // Initialize pio interrupt handler, see pio definition in conf_board.h
	NVIC_EnableIRQ((IRQn_Type)BUTTON_PIN_1_ID); //Enable pio controller irqs
	pio_enable_interrupt(BUTTON_PIN_1_PIO, BUTTON_PIN_1_MASK); //Enable pio interrupt lines

}