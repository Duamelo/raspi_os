#ifndef	_P_BASE_H
#define	_P_BASE_H

#include<stdint.h>



typedef volatile uint32_t rpi_reg_rw_t;
typedef volatile const uint32_t rpi_reg_ro_t;
typedef volatile uint32_t rpi_reg_wo_t;

typedef volatile uint64_t rpi_wreg_rw_t;
typedef volatile const uint64_t rpi_wreg_ro_t;


#define PERIPHERAL_BASE     0x3F000000
#define LPBASE              0x40000000

#endif  /*_P_BASE_H */
