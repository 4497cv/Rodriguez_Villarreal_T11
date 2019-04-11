/**
	\file 	  rtc.c
	\brief
			  This is the header file for the i2c device driver for Kinetis K64.
	\authors: César Villarreal Hernández, ie707560
	          José Luis Rodríguez Gutierrez,ie705694
	\date	  10/05/2019
 */

#include "rtc.h"


void RTC_enable()
{
	/*Start bit*/
	I2C_start();
	/*Send the RTC Address to the register*/
	I2C_write_byte(RTC_WRITE_CONTROL); /*1101/Direccion fisica(A2/A1/A0)*/
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);
	/*Register address*/
	I2C_write_byte(ENABLE_ADDR); /*Address = data*/
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);
	/*BCD code*/
	I2C_write_byte(ENABLE_COUNT); /*Dato que se envia*/
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);
	/*Send the stop signal*/
	I2C_stop();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);
}

void RTC_set_hour(uint8_t data)
{
	/*Start bit*/
	I2C_start();
	/*Send the RTC Address to the register*/
	I2C_write_byte(RTC_WRITE_CONTROL); /*1101/Direccion fisica(A2/A1/A0)*/
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);

	/*Register address*/
	I2C_write_byte(HOUR_ADDR); /*Address = data*/
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);

	/*BCD code*/
	I2C_write_byte(data); /*Dato que se envia*/
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);
	/*Send the stop signal*/
	I2C_stop();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);
}

void RTC_set_sec(uint8_t data)
{
	/*Start bit*/
	I2C_start();
	/*Send the RTC Address to the register*/
	I2C_write_byte(RTC_WRITE_CONTROL); /*1101/Direccion fisica(A2/A1/A0)*/
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);

	/*Register address*/
	I2C_write_byte(SEC_ADDR); /*Address = data*/
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);

	/*BCD code*/
	I2C_write_byte(data); /*Dato que se envia*/
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);
	/*Send the stop signal*/
	I2C_stop();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);
}

void RTC_set_min(uint8_t data)
{
	if(data > 59)
	{
		data = 1;
	}

	/*Start bit*/
	I2C_start();
	/*Send the RTC Address to the register*/
	I2C_write_byte(RTC_WRITE_CONTROL); /*1101/Direccion fisica(A2/A1/A0)*/
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);

	/*Register address*/
	I2C_write_byte(MIN_ADDR); /*Address = data*/
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);

	/*BCD code*/
	I2C_write_byte(data); /*Dato que se envia*/
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);
	/*Send the stop signal*/
	I2C_stop();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);
}

uint8_t RTC_get_hour(void)
{
	uint8_t data;
	/*Send the Tx mode
	 * Start bit*/
	I2C_start();
	/*Send the RTC Address to the register*/
	I2C_write_byte(RTC_WRITE_CONTROL);
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);

	/*Register address*/
	I2C_write_byte(HOUR_ADDR);
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);

	/*Send the start bit signal again so we can send now the data to read*/
	I2C_repeted_start();

	/*Writing to the slave to read the previous register*/
	I2C_write_byte(RTC_READ_CONTROL);
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);

	/*Chance I2C module to Rx mode*/
	I2C_tx_rx_mode(I2C_RX);

	/*Generate ~Acknowledge*/
	I2C_nack();
	/*data get the value that's in the I2C_D register*/
	data = I2C_read_byte();
	/*Check if I2C is busy*/
	I2C_wait();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);

	/*Send the stop signal*/
	I2C_stop();
	/*data get the value that's in the I2C_D register*/
	data = I2C_read_byte();

	return (data);
}

uint8_t RTC_get_min(void)
{
	uint8_t data;
	/*Send the Tx mode
	 * Start bit*/
	I2C_start();
	/*Send the RTC Address to the register*/
	I2C_write_byte(RTC_WRITE_CONTROL);
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);

	/*Register address*/
	I2C_write_byte(MIN_ADDR);
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);

	/*Send the start bit signal again so we can send now the data to read*/
	I2C_repeted_start();

	/*Writing to the slave to read the previous register*/
	I2C_write_byte(RTC_READ_CONTROL);
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);

	/*Chance I2C module to Rx mode*/
	I2C_tx_rx_mode(I2C_RX);

	/*Generate ~Acknowledge*/
	I2C_nack();
	/*data get the value that's in the I2C_D register*/
	data = I2C_read_byte();
	/*Check if I2C is busy*/
	I2C_wait();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);

	/*Send the stop signal*/
	I2C_stop();
	/*data get the value that's in the I2C_D register*/
	data = I2C_read_byte();

	return (data);
}

uint8_t RTC_get_sec(void)
{
	uint8_t data;
	/*Send the Tx mode
	 * Start bit*/
	I2C_start();
	/*Send the RTC Address to the register*/
	I2C_write_byte(RTC_WRITE_CONTROL);
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);

	/*Register address*/
	I2C_write_byte(SEC_ADDR);
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);

	/*Send the start bit signal again so we can send now the data to read*/
	I2C_repeted_start();

	/*Writing to the slave to read the previous register*/
	I2C_write_byte(RTC_READ_CONTROL);
	/*Check if I2C is busy*/
	I2C_wait();
	/*Recevie the Acknowledge*/
	I2C_get_ack();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);

	/*Chance I2C module to Rx mode*/
	I2C_tx_rx_mode(I2C_RX);

	/*Generate ~Acknowledge*/
	I2C_nack();
	/*data get the value that's in the I2C_D register*/
	data = I2C_read_byte();
	/*Check if I2C is busy*/
	I2C_wait();
	/*Delay to secure we get the signal*/
	RTC_delay(RTC_DELAY);

	/*Send the stop signal*/
	I2C_stop();
	/*data get the value that's in the I2C_D register*/
	data = I2C_read_byte();

	return (data);
}

/**/
void RTC_delay(uint32_t delay){
	uint32_t i=delay;
	while(i!=0)
	{
		i--;
	}
}
