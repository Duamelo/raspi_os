#include "mini_uart.h"


static aux_t* AUX_BASE = (aux_t*)P_AUX_BASE; 



void uart_send ( char c )
{
	while(1) {
		if(mmio_read(AUX_BASE->AUX_MU_LSR_REG)&0x20) 
			break;
	}
	mmio_write(AUX_BASE->AUX_MU_IO_REG,c);
}

char uart_recv ( void )
{
	while(1) {
		if(mmio_read(AUX_BASE->AUX_MU_LSR_REG)&0x01) 
			break;
	}
	return(mmio_read(AUX_BASE->AUX_MU_IO_REG)&0xFF);
}

void uart_send_string(char* str)
{
	for (int i = 0; str[i] != '\0'; i ++) {
		uart_send((char)str[i]);
	}
}

void uart_init ( void )
{
	unsigned int selector;

	selector = mmio_read(get_gpio()->GPFSEL1);
	selector &= ~(7<<12);                   // clean gpio14
	selector |= 2<<12;                      // set alt5 for gpio14
	selector &= ~(7<<15);                   // clean gpio15
	selector |= 2<<15;                      // set alt5 for gpio15
	mmio_write(get_gpio()->GPFSEL1,selector);

	mmio_write(get_gpio()->GPPUD,0);
	delay(150);
	mmio_write(get_gpio()->GPPUDCLK0,(1<<14)|(1<<15));
	delay(150);
	mmio_write(get_gpio()->GPPUDCLK0,0);

	mmio_write(AUX_BASE->AUX_ENABLES,1);                   //Enable mini uart (this also enables access to it registers)
	mmio_write(AUX_BASE->AUX_MU_CNTL_REG,0);               //Disable auto flow control and disable receiver and transmitter (for now)
	mmio_write(AUX_BASE->AUX_MU_IER_REG,0);                //Disable receive and transmit interrupts
	mmio_write(AUX_BASE->AUX_MU_LCR_REG,3);                //Enable 8 bit mode
	mmio_write(AUX_BASE->AUX_MU_MCR_REG,0);                //Set RTS line to be always high
	mmio_write(AUX_BASE->AUX_MU_BAUD_REG,270);             //Set baud rate to 115200

	mmio_write(AUX_BASE->AUX_MU_CNTL_REG,3);               //Finally, enable transmitter and receiver
}


// This function is required by printf function
void putc ( void* p, char c)
{
	uart_send(c);
}
