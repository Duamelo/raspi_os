#ifndef	_TIMER_H
#define	_TIMER_H


#include "utils.h"
#include "printf.h"
#include "../boot/boot.h" 
#include "../led/led.h"


void timer_init ( void );
void handle_timer_irq ( void );

void generic_timer_init ( void );
void handle_generic_timer_irq ( void );

extern void gen_timer_init();
extern void gen_timer_reset(unsigned int interval);

#endif  /*_TIMER_H */
