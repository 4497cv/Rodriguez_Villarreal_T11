/*
 * UART_DECO.c
 *
 *  Created on: Nov 5, 2018
 *      Author: LuisFernando
 */

#include <time.h>

static uint8_t temp0 = FALSE;	/*Unidad*/
static uint8_t temp1 = FALSE;	/*Decena*/
static uint8_t temp2 = FALSE;	/*Centena*/
static uint8_t temp3 = FALSE;	/*Millar*/
static uint8_t temp4 = FALSE; /*Decena Millar*/


void value_capture(uint32_t value)
{
	uint8_t tempValue4 = value / DECENA_MILLAR;
	uint8_t tempValue3 = value / MILLAR;
	uint8_t tempValue2 = value / CENTENA;
	uint8_t tempValue1 = value / DECENA;

	/*Decena del Millar*/
	if (FALSE != tempValue4)
	{
		temp4 = tempValue4;
	}
	else
	{
		temp4 = 0;
	}

	/*Millar*/
	if (FALSE != tempValue3)
	{
		value = value - (DECENA_MILLAR * temp4);
		temp3 = value / MILLAR;
	} else
		temp3 = 0;
	/*Centena*/
	if (FALSE != tempValue2)
	{
		value = value - (MILLAR * temp3);
		temp2 = value / CENTENA;
	} else
		temp2 = 0;
	/*Decena*/
	if (FALSE != tempValue1)
	{
		value = value - (CENTENA * temp2);
		temp1 = value / DECENA;
	} else
		temp1 = 0;
	/*Unidad*/
	if (FALSE != value)
		temp0 = value - (DECENA * temp1);
	else
		temp0 = 0;

}

uint8_t get_unit()
{
	return (temp0 + ASCII_CONV);
}
uint8_t get_deci()
{
	return (temp1 + ASCII_CONV);
}
