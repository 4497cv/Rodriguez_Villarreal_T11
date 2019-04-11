/*
 * uart_tera.h
 *
 *  Created on: Apr 10, 2019
 *      Author: LuisFernando
 */

#ifndef TERMINAL_H_
#define TERMINAL_H_

#include <time.h>
#include "bits.h"
#include "uart.h"
#include "delay.h"
#include <time.h>
#include "stdint.h"
#include "rtc.h"


typedef enum
{
	ASCII_ENTER = 13,
	ASCII_ESC = 27,
	/**/
	ASCII_LETTER_A = 65,
	ASCII_LETTER_B = 66,
	ASCII_LETTER_C = 67,
	ASCII_LETTER_D = 68,
	ASCII_LETTER_E = 69,
	ASCII_LETTER_F = 70,
	ASCII_LETTER_a = 97,
	ASCII_LETTER_b = 98,
	ASCII_LETTER_c = 99,
	ASCII_LETTER_d = 100,
	ASCII_LETTER_e = 101,
	ASCII_LETTER_f = 102,
	/**/
	ASCII_ONE = 49,
	ASCII_TWO = 50,
	ASCII_THREE = 51,
	ASCII_FOUR = 52,
	ASCII_FIVE = 53,
	ASCII_SIX = 54,
	ASCII_SEVEN = 55,
	ASCII_EIGHT = 56,
	ASCII_NINE = 57,
	ASCII_ZERO = 48
}ASCII_type;

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Funct to show the default menu
 	 \param[in] void
 	 \return void
 */
void term_menu(void);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Funct to show the default menu
 	 \param[in] void
 	 \return void
 */
void term_get_time(void);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Funct to show the default menu
 	 \param[in] void
 	 \return void
 */
void term_set_time(void);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/

#endif
