
/**
 * @file    RTC_Project.c
 * @brief   Application entry point.
 */
#include "system.h"
#include <terminal.h>
#include "delay.h"

int main(void) {
	uint8_t mb_flag;
	uint8_t mb_mailbox;
	uint8_t min;
	system_init();

	RTC_set_min(06);
	RTC_set_sec(0);


	for(;;)
	{
		mb_flag = UART_get_mailbox_flag(UART_0);
		mb_mailbox = UART_get_mailbox(UART_0);
		if(mb_flag)
		{
			/**/
			if(ASCII_ONE == mb_mailbox)
			{
					term_get_time();
			}
			else if(ASCII_TWO == mb_mailbox)
			{
				term_set_time();
			}
			else if(ASCII_ESC == mb_mailbox)
			{
				term_menu();
			}
			/**/
			/*For debug*/
			/**Sends to the PCA the received data in the mailbox*/
			//UART_put_char (UART_0, g_mail_box_uart_0.mailBox);

			/**clear the reception flag*/
			UART_empty_mailbox(UART_0);
		}
	}

    return 0 ;
}
