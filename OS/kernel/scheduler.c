#include "scheduler.h"


void kernel_main(void)
{
	uart_init();
	init_printf(0, putc);
	int el = get_el();
	printf("Exception level: %d \r\n", el);
	printf("kernel boots...\n");

	irq_vector_init();
	generic_timer_init();
	enable_interrupt_controller();
	enable_irq();


	while (1) 
	{
		uart_send(uart_recv());
	}
}