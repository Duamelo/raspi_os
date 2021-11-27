#ifndef	_P_SYSTIMER_H
#define	_P_SYSTIMER_H

#include "peripherals/base.h"


#define  P_SYSTIMER_BASE       PERIPHERAL_BASE + 0x3000

#define TIMER_CS_M0	(1 << 0)
#define TIMER_CS_M1	(1 << 1)
#define TIMER_CS_M2	(1 << 2)
#define TIMER_CS_M3	(1 << 3)


typedef struct
{
    volatile uint32_t CONTROLE_STATUS;
    volatile uint32_t COUNTER_LOW;
    volatile uint32_t COUNTER_HIGH;
    volatile uint32_t COMPARE_0;
    volatile uint32_t COMPARE_1;
    volatile uint32_t COMPARE_2;
    volatile uint32_t COMPARE_3;
}
timer_t;


#endif  /*_P_SYSTIMER_H */
