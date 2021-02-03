/**
 * \Task1
 *
 * \ Task1 of EE 326 -- Get an LED to turn on on butt0n down and off on button up through interrupts 
 *
 */

#include <asf.h>
#include "button.h"

int main (void)
{
	sysclk_init();
	board_init();
	configure_button();
	//ioport_set_pin_level(LED_PIN, true);
	while(1) {

		if (button_flag && !button_status) {
			ioport_set_pin_level(LED_PIN, true);
			delay_ms(10);
			button_flag = false;
		} 
		if (button_flag && button_status) {
			ioport_set_pin_level(LED_PIN, false);
			delay_ms(10);
			button_flag = false;
		}
	}
}
