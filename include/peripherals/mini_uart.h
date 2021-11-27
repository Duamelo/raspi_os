#ifndef	_P_MINI_UART_H
#define	_P_MINI_UART_H

#include "peripherals/base.h"

#define P_AUX_BASE        PERIPHERAL_BASE + 0x215000



typedef struct 
{
    volatile unsigned int IRQ;
    volatile unsigned int AUX_ENABLES;

    volatile unsigned int reserved1[((0x40 - 0x04) / 4) - 1];

    volatile unsigned int AUX_MU_IO_REG;
    volatile unsigned int AUX_MU_IER_REG;
    volatile unsigned int AUX_MU_IIR_REG;
    volatile unsigned int AUX_MU_LCR_REG;
    volatile unsigned int AUX_MU_MCR_REG;
    volatile unsigned int AUX_MU_LSR_REG;
    volatile unsigned int AUX_MU_MSR_REG;
    volatile unsigned int AUX_MU_SCRATCH;
    volatile unsigned int AUX_MU_CNTL_REG;
    volatile unsigned int AUX_MU_STAT_REG;
    volatile unsigned int AUX_MU_BAUD_REG;

    volatile unsigned int reserved2[(0x80 - 0x68) / 4];

    volatile unsigned int SPI0_CNTL0;
    volatile unsigned int SPI0_CNTL1;
    volatile unsigned int SPI0_STAT;
    volatile unsigned int SPI0_IO;
    volatile unsigned int SPI0_PEEK;

    volatile unsigned int reserved3[(0xC0 - 0x94) / 4];

    volatile unsigned int SPI1_CNTL0;
    volatile unsigned int SPI1_CNTL1;
    volatile unsigned int SPI1_STAT;
    volatile unsigned int SPI1_IO;
    volatile unsigned int SPI1_PEEK;
} 
aux_t;


#endif  /*_P_MINI_UART_H */
