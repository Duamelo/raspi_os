#include "timer.h"



static unsigned int interval = 2 * 1000 * 1000; // around 2 sec
static unsigned int lit = 0;


void generic_timer_init ( void )
{
	printf("interval is set to: %u\n", interval);
	gen_timer_init();
	gen_timer_reset(interval);
}

void handle_generic_timer_irq( void ) 
{

	printf("Timer interrupt received. next in %u ticks\n\r", interval);
    
    if (lit)
    {
        led_white_off();
        lit = 0;
    }
    else
    {
    
        led_white_on();
        lit = 1;
    }
	
    gen_timer_reset(interval);
}
