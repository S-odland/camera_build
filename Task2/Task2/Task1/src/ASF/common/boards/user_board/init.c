#include <asf.h>
#include <board.h>
#include <conf_board.h>

void board_init(void)
{
	ioport_init();
	ioport_set_pin_dir(LED_PIN, IOPORT_DIR_OUTPUT);
	
	ioport_set_pin_dir(BUTTON_PIN, IOPORT_DIR_INPUT);
	ioport_set_pin_mode(BUTTON_PIN, IOPORT_MODE_PULLDOWN);
}
