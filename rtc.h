/**
	\file 	  rtc.h
	\brief
			  This is the header file for the i2c device driver for Kinetis K64.
	\authors: César Villarreal Hernández, ie707560
	          José Luis Rodríguez Gutierrez,ie705694
	\date	  10/05/2019
 */

#ifndef RTC_H_
#define RTC_H_

#include "i2c.h"
#include "bits.h"
#include "gpio.h"

#define RTC_WRITE_CONTROL 0XDE
#define RTC_READ_CONTROL 0XDF

#define ENABLE_ADDR 0X00
#define ENABLE_COUNT 0x80

#define SEC_ADDR 0x00
#define MIN_ADDR 0x01
#define HOUR_ADDR 0x02

#define RTC_DELAY 1000

#define BIT0_MASK 0x01
#define BIT1_MASK 0x02
#define BIT2_MASK 0x04
#define BIT3_MASK 0x08
#define BIT4_MASK 0x10
#define BIT5_MASK 0x20
#define BIT6_MASK 0x40
#define BIT7_MASK 0x80

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Funct to set a value to a register
 	 \param[in] void
 	 \return void
 */
void RTC_enable(void);
/*!
 	 \brief	 Funct to delay the process so it can work properly.
 	 \param[in] delay
 	 \return void
 */
void RTC_delay(uint32_t delay);

uint8_t RTC_get_min(void);
uint8_t RTC_get_sec(void);
uint8_t RTC_get_hour(void);
void RTC_set_sec(uint8_t data);
void RTC_set_min(uint8_t data);
void RTC_set_hour(uint8_t data);
#endif /* RTC_H_ */
