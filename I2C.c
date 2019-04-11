/**
	\file 	  i2c.c
	\brief    This is the source file for the i^2 C device driver for Kinetis K64.
	\authors: César Villarreal Hernández,   ie707560
	          José Luis Rodríguez Gutierrez,ie705694
	\date	    09/04/2019
 */

#include "I2C.h"

void I2C_init(i2c_channel_t channel, uint32_t system_clock, uint16_t baud_rate)
{
  /*PCR config*/
  static const gpio_pin_control_register_t i2c_config = GPIO_MUX2 | GPIO_PS;
  uint32_t valueSCL;

  /** Activating PORT_B clock gating **/
  GPIO_clock_gating(GPIO_B);

  /** Configuring a pin for transmission (Tx)*/
  GPIO_pin_control_register(GPIO_B, bit_2, &i2c_config);
  /** Configuring a pin for Reception (Rx)*/
  GPIO_pin_control_register(GPIO_B, bit_3, &i2c_config);
  /** Configuring the logic for the pin that will transmit data*/
  GPIO_data_direction_pin(GPIO_B, GPIO_OUTPUT,bit_2);
  /** Configuring the logic for the pin that will receive data*/
  GPIO_data_direction_pin(GPIO_B, GPIO_INPUT,bit_3);
  /*I2C baud rate = I2C module clock speed (Hz)/(mul × SCL divider)*/
  valueSCL = system_clock/(baud_rate*MULT);

  switch(channel)
  {
  	case I2C_0:
  		SIM->SCGC4 |= SIM_SCGC4_I2C0_MASK;
  		/** Set the clock rate **/
  		I2C0->F = I2C_F_ICR(valueSCL);
  		I2C0->F = I2C_F_MULT(2);
  		/** Enable the i2c module **/
  		I2C0->C1 = I2C_C1_IICEN_MASK;
  	break;
  	case I2C_1:
  		SIM->SCGC4 |= SIM_SCGC4_I2C1_MASK;
  		/** Set the clock rate **/
  		I2C1->F = I2C_F_ICR(valueSCL);
  		I2C1->F = I2C_F_MULT(2);
  		/*Enable I2C mo0dule*/
  		I2C1->C1 = I2C_C1_IICEN_MASK;
  	break;
  	case I2C_2:
  		SIM->SCGC1 |= SIM_SCGC1_I2C2_MASK;
  		/** Set the clock rate **/
  		I2C2->F = I2C_F_ICR(valueSCL);
  		/** Set multiplier factor by 4 **/
  		I2C2->F = I2C_F_MULT(2);
  		/** Enable the i2c module **/
  		I2C2->C1 = I2C_C1_IICEN_MASK;
  	break;
  	default:
  	break;
  	}
}

uint8_t I2C_busy(void)
{

}

void I2C_mst_or_slv_mode(uint8_t mst_or_slv)
{

}

void I2C_tx_rx_mode(uint8_t tx_or_rx)
{

}

void I2C_nack(void)
{

}

void I2C_repeted_start(void)
{

}

void I2C_write_byte(uint8_t data)
{

}

uint8_t I2C_read_byte(void)
{

}

void I2C_wait(void)
{

}

uint8_t I2C_get_ack(void)
{

}

void I2C_start(void)
{

}

void I2C_stop(void)
{

}

#endif /* I2C_H_ */
