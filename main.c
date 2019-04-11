
/**
 * @file    RTC_Project.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "system.h"

int main(void) {
	uint8_t mb_flag;
	system_init();

	for(;;)
	{
		mb_flag = UART_get_mailbox_flag(UART_0);
		mb_mailbox = UART_get_mailbox(UART_0);
		if(mb_flag)
		{

		}
		UART_empty_mailbox(UART_0);
	}

    return 0 ;
}
