#include <avr/io.h>

void delay(void) {
	unsigned long i;
	for (i = 0; i < 100000; i++);
}

int main(void)
{
	DDRB = 0x00;
	
	DDRD = 0xFF;
	PORTD = 0x00;
	
	unsigned char last_state = 0;
	unsigned char current_pb = 0;
	unsigned char previous_pb = 0;
	
	while (1) {
		current_pb = PINB;
		
		if (((current_pb & 0x10) == 0x10) && ((previous_pb & 0x10) == 0x00) ) {
			//delay();
			if (last_state == 0) {
				last_state = 1;
				PORTD = 0xFF;
			} else if (last_state == 1) {
				last_state = 0;
				PORTD = 0x00;
			}
		}
		previous_pb = current_pb;
	}
}