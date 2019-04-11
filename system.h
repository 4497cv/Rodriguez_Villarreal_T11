
#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <uart.h>/**UART device driver*/
#include "MK64F12.h" /* include peripheral declarations */
#include "nvic.h"/**NVIC device driver*/
#include "gpio.h"
#include "i2c.h"
#include "uart.h"

#define MAL_SIZE 0
#define HAL_SIZE 2
#define APP_SIZE 0
#define SYSTEM_CLOCK 21000000

/*!
 	 \brief		 It configures the main system.
 	 \param[in]  void
 	 \return     static void
 */
void system_init(void);

/*!
 	 \brief		 It contains the configuration for the UART module.
 	 \param[in]  void
 	 \return     static void
 */
void UART_config(void);
/*!
 	 \brief		 It contains the configuration for the i2c module.
 	 \param[in]  void
 	 \return     static void
 */
void I2C_config(void);

#endif
