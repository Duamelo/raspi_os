ARMGNU ?= aarch64-linux-gnu

COPS = -Wall -nostdlib -nostartfiles -ffreestanding -Iinclude -mgeneral-regs-only -g -O0
ASMOPS = -Iinclude  -g


all: clean kernel8.img

start.o: OS/kernel/start.S
	$(ARMGNU)-gcc $(COPS) -MMD -c OS/kernel/start.S -o start.o


entry.o: OS/modules/irq/entry.S
	$(ARMGNU)-gcc $(COPS) -MMD -c OS/modules/irq/entry.S -o entry.o


irq.o: OS/modules/irq/irq.S
	$(ARMGNU)-gcc $(COPS) -MMD -c OS/modules/irq/irq.S -o irq.o

utils.o: OS/utils.S
	$(ARMGNU)-gcc $(COPS) -MMD -c OS/utils.S -o utils.o


tim.o: OS/modules/timer/timer.S
	$(ARMGNU)-gcc $(COPS) -MMD -c OS/modules/timer/timer.S -o tim.o


timer.o: OS/modules/timer/timer.c
	$(ARMGNU)-gcc $(COPS) -MMD -c OS/modules/timer/timer.c -o timer.o


mm.o: OS/mm.S
	$(ARMGNU)-gcc $(COPS) -MMD -c OS/mm.S -o mm.o


scheduler.o: OS/kernel/scheduler.c
	$(ARMGNU)-gcc $(COPS) -MMD -c OS/kernel/scheduler.c -o scheduler.o


gpio.o: OS/modules/gpio/gpio.c
	$(ARMGNU)-gcc $(COPS) -MMD -c OS/modules/gpio/gpio.c -o gpio.o


led.o: OS/modules/led/led.c
	$(ARMGNU)-gcc $(COPS) -MMD -c OS/modules/led/led.c -o led.o

mini_uart.o: OS/modules/mini_uart/mini_uart.c
	$(ARMGNU)-gcc $(COPS) -MMD -c OS/modules/mini_uart/mini_uart.c -o mini_uart.o

irq_c.o: OS/modules/irq/irq.c
	$(ARMGNU)-gcc $(COPS) -MMD -c OS/modules/irq/irq.c -o irq_c.o

printf.o: OS/printf.c
	$(ARMGNU)-gcc $(COPS) -MMD -c OS/printf.c -o printf.o

app.o: OS/app/app.c
	$(ARMGNU)-gcc $(COPS) -MMD -c OS/app/app.c -o app.o


kernel8.img: start.o entry.o irq.o tim.o utils.o mm.o timer.o gpio.o led.o mini_uart.o app.o irq_c.o printf.o scheduler.o 
	$(ARMGNU)-ld -nostdlib -nostartfiles start.o entry.o irq.o tim.o utils.o mm.o  timer.o gpio.o led.o mini_uart.o app.o irq_c.o printf.o scheduler.o -T OS/linker.ld -o kernel8.elf
	$(ARMGNU)-objcopy -O binary kernel8.elf kernel8.img

clean:
	/bin/rm kernel8.elf *.o *.img > /dev/null 2> /dev/null || true

