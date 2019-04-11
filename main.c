
/**
 * @file    RTC_Project.c
 * @brief   Application entry point.
 */
#include "system.h"

int main(void) {
	uint8_t mb_flag;
	uint8_t mb_mailbox;

	system_init();

	for(;;)
	{
		mb_flag = UART_get_mailbox_flag(UART_0);
		mb_mailbox = UART_get_mailbox(UART_0);
		if(mb_flag)
		{
			/**/
			if(ASCII_ONE == mb_mailbox)
			{
				tera_get_hora();
			}
			else if(ASCII_TWO == mb_mailbox)
			{
				tera_set_hora();
			}
			else if(ASCII_ESC == mb_mailbox)
			{
				tera_menu();
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
