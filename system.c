
#include "system.h"

void (*fptr_HAL[HAL_SIZE])(void) =
{
	GPIO_config,
	UART_config,
	I2C_config,
	NVIC_config
};


void (*fptr_MAL[MAL_SIZE])(void) =
{
	RTC_config
};

void (*fptr_APP[APP_SIZE])(void) =
{
	term_menu
};

void system_init(void)
{
	uint8_t i;

	for(i = 0; i < HAL_SIZE; i++)
	{
		fptr_HAL[i]();
	}


	fptr_MAL[0]();

	fptr_APP[0]();

}

void UART_config(void)
{
	/**Configures UART 0 to transmit/receive at 11520 bauds with a 21 MHz of clock core*/
	UART_init (UART_0, SYSTEM_CLOCK, BD_115200);
	/**Enables the UART 0 interrupt*/
	UART_interrupt_enable(UART_0);


	UART_empty_mailbox(UART_0);
}

void I2C_config(void)
{
	I2C_init(I2C_0,SYSTEM_CLOCK,BD_9600);
}

void GPIO_config(void)
{
	/*PCR config*/
	static const gpio_pin_control_register_t uart_config = GPIO_MUX3;
	/** Activate PORT B clock gating **/
	SIM->SCGC5 = SIM_SCGC5_PORTB_MASK;
	/**Configures the pin control register of pin16 in PortB as UART RX*/
	GPIO_pin_control_register(GPIO_B,bit_16,&uart_config);
	/**Configures the pin control register of pin16 in PortB as UART TX*/
	GPIO_pin_control_register(GPIO_B,bit_17,&uart_config);
}

void NVIC_config(void)
{
	/**Enables the UART 0 interrupt in the NVIC*/
	NVIC_enable_interrupt_and_priotity(UART0_IRQ, PRIORITY_10);
	/**Enables interrupts*/
	NVIC_global_enable_interrupts;
}

void RTC_config(void)
{
	RTC_enable();
}
