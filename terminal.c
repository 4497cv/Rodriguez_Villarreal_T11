
#include <terminal.h>

void term_menu(void)
{
	UART_put_string(UART_0,"\033[2J");
	/**The following sentences send strings to PC using the UART_put_string function. Also, the string
	 * is coded with terminal code*/
	/*VT100 command for clearing the screen*/
	UART_put_string(UART_0,"\033[2J");
	/** VT100 command for text in black and background in black*/
	UART_put_string(UART_0,"\033[0;30;40m");
	/*VT100 command for clearing the screen*/
	UART_put_string(UART_0,"\033[2J");
	/** VT100 command for text in red and background in green*/
	UART_put_string(UART_0, "\033[0;47;40m");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_put_string(UART_0, "\033[10;10H");
	/** Set the text in a string*/
	UART_put_string(UART_0, "1) Leer hora\r");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_put_string(UART_0, "\033[11;10H");
	/** Set the text in a string*/
	UART_put_string(UART_0, "2) Configurar hora\r");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_put_string(UART_0, "\033[12;10H");
}

void term_get_time(void)
{
	uint8_t mb_flag;
	uint8_t mb_mailbox;
	UART_put_string(UART_0,"\033[2J");
	/**The following sentences send strings to PC using the UART_put_string function. Also, the string
	 * is coded with terminal code*/
	/*VT100 command for clearing the screen*/
	UART_put_string(UART_0,"\033[2J");
	/** VT100 command for text in black and background in black*/
	UART_put_string(UART_0,"\033[0;30;40m");
	/*VT100 command for clearing the screen*/
	UART_put_string(UART_0,"\033[2J");
	/** VT100 command for text in red and background in green*/
	UART_put_string(UART_0, "\033[0;47;40m");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_put_string(UART_0, "\033[10;10H");
	/** Set the text in a string*/
	UART_put_string(UART_0, "La hora actual es:\r");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_put_string(UART_0, "\033[11;10H");

	do
	{
		mb_flag = UART_get_mailbox_flag(UART_0);
		refresh_hour();
		if(mb_flag)
		{
		mb_mailbox = UART_get_mailbox(UART_0);
		}
	}while(ASCII_ESC != mb_mailbox);
}

void term_set_time(void)
{
	UART_put_string(UART_0,"\033[2J");
	/**The following sentences send strings to PC using the UART_put_string function. Also, the string
	 * is coded with terminal code*/
	/*VT100 command for clearing the screen*/
	/** VT100 command for text in black and background in black*/
	UART_put_string(UART_0,"\033[0;30;40m");
	/** VT100 command for text in red and background in green*/
	UART_put_string(UART_0, "\033[0;47;40m");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_put_string(UART_0, "\033[10;10H");
	/** Set the text in a string*/
	UART_put_string(UART_0, "Introducir la hora actual en formato HH:MM:SS\r");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_put_string(UART_0, "\033[11;10H");
}

void refresh_hour()
{
	static uint8_t reg_min;
	static uint8_t reg_sec;
	uint8_t min;
	uint8_t sec;
	min = RTC_get_min();
	value_capture(min);
	sec = RTC_get_sec();
	value_capture(sec);

	if(reg_min == min && reg_sec == sec)
	{
	UART_put_string(UART_0,"\033[2J");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_put_string(UART_0, "\033[11;10H");
	/** Gets the value in the register of time, corresponding to Hrs*/
	/** Print the value of the register once it got deco*/
	UART_put_char(UART_0, get_deci());
	UART_put_char(UART_0, get_unit());
	/*Prints : for the format*/
	UART_put_string(UART_0, ":");
	/** Gets the value in the register of time, corresponding to Hrs*/
	/** Print the value of the register once it got deco*/
	UART_put_char(UART_0, get_deci());
	UART_put_char(UART_0, get_unit());
	}
	reg_min = min;
	reg_min = sec;
}

