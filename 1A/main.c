#include <avr/io.h>

void delay(void) {
	unsigned long i;
	for (i = 0; i < 625000; i++);
}

int main(void)
{
	DDRD = 0xFF;
	while (1) {
		PORTD = 0x55;
		delay();
		PORTD = 0xAA;
		delay();
	}
}