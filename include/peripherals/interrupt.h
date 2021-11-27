#ifndef	_P_IRQ_H
#define	_P_IRQ_H

#include "peripherals/base.h"

#define P_INTERRUPT_BASE        PERIPHERAL_BASE + 0xB200

#define SYSTEM_TIMER_IRQ_0	(1 << 0)
#define SYSTEM_TIMER_IRQ_1	(1 << 1)
#define SYSTEM_TIMER_IRQ_2	(1 << 2)
#define SYSTEM_TIMER_IRQ_3	(1 << 3)

// See BCM2836 ARM-local peripherals at
// https://www.raspberrypi.org/documentation/hardware/raspberrypi/bcm2836/QA7_rev3.4.pdf

#define TIMER_INT_CTRL_0    (0x40000040)
#define INT_SOURCE_0        (LPBASE+0x60)

#define TIMER_INT_CTRL_0_VALUE  (1 << 1)
#define GENERIC_TIMER_INTERRUPT (1 << 1)

typedef struct 
{
    volatile uint32_t IRQ_BASIC_PENDING;
    volatile uint32_t IRQ_PENDING_1;
    volatile uint32_t IRQ_PENDING_2;
    volatile uint32_t FIQ_CONTROL;
    volatile uint32_t ENABLE_IRQS_1;
    volatile uint32_t ENABLE_IRQS_2;
    volatile uint32_t ENABLE_BASIC_IRQS;
    volatile uint32_t DISABLE_IRQS_1;
    volatile uint32_t DISABLE_IRQS_2;
    volatile uint32_t DISABLE_BASIC_IRQS;
} 
interrupt_t;



void enable_interrupt_controller( void );
void irq_vector_init( void );
void enable_irq( void );
void disable_irq( void );



#endif  /*_P_IRQ_H */
