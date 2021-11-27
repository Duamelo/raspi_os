#ifndef	_IRQ_H
#define	_IRQ_H


#include "utils.h"
#include "printf.h"
#include "../timer/timer.h"
#include "entry.h"
#include "peripherals/interrupt.h"


void enable_interrupt_controller( void );

void irq_vector_init( void );
void enable_irq( void );
void disable_irq( void );

#endif  /*_IRQ_H */
