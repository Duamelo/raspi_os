#ifndef	_P_GPIO_H
#define	_P_GPIO_H

#include "base.h"


#define P_GPIO_BASE       (PERIPHERAL_BASE + 0x200000)


typedef struct 
{
    rpi_reg_rw_t    GPFSEL0;
    rpi_reg_rw_t    GPFSEL1;
    rpi_reg_rw_t    GPFSEL2;
    rpi_reg_rw_t    GPFSEL3;
    rpi_reg_rw_t    GPFSEL4;
    rpi_reg_rw_t    GPFSEL5;
    rpi_reg_ro_t    Reserved0;
    rpi_reg_wo_t    GPSET0;
    rpi_reg_wo_t    GPSET1;
    rpi_reg_ro_t    Reserved1;
    rpi_reg_wo_t    GPCLR0;
    rpi_reg_wo_t    GPCLR1;
    rpi_reg_ro_t    Reserved2;
    rpi_reg_wo_t    GPLEV0;
    rpi_reg_wo_t    GPLEV1;
    rpi_reg_ro_t    Reserved3;
    rpi_reg_wo_t    GPEDS0;
    rpi_reg_wo_t    GPEDS1;
    rpi_reg_ro_t    Reserved4;
    rpi_reg_wo_t    GPREN0;
    rpi_reg_wo_t    GPREN1;
    rpi_reg_ro_t    Reserved5;
    rpi_reg_wo_t    GPFEN0;
    rpi_reg_wo_t    GPFEN1;
    rpi_reg_ro_t    Reserved6;
    rpi_reg_wo_t    GPHEN0;
    rpi_reg_wo_t    GPHEN1;
    rpi_reg_ro_t    Reserved7;
    rpi_reg_wo_t    GPLEN0;
    rpi_reg_wo_t    GPLEN1;
    rpi_reg_ro_t    Reserved8;
    rpi_reg_wo_t    GPAREN0;
    rpi_reg_wo_t    GPAREN1;
    rpi_reg_ro_t    Reserved9;
    rpi_reg_wo_t    GPAFEN0;
    rpi_reg_wo_t    GPAFEN1;
    rpi_reg_ro_t    Reserved10;
    rpi_reg_wo_t    GPPUD;
    rpi_reg_wo_t    GPPUDCLK0;
    rpi_reg_wo_t    GPPUDCLK1;
    rpi_reg_ro_t    Reserved11;
} 
gpio_t;

extern void mmio_write(long reg, unsigned int val);
extern unsigned int mmio_read(long reg);

#endif  /*_P_GPIO_H */
