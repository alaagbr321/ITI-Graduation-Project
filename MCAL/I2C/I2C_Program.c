/**
 * @file I2C_Program.c
 * @author GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * @brief The I2C Program File
 * @version 0.1
 * @date 2023-10-03
 *
 * @copyright GP_4M_NC2_Intake3_Adaptive Light Control System_5
 *
*/

#include"../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "I2C_Interface.h"
#include "I2C_Private.h"


/**
 * @brief Configuration and Initialization For I2C
 *
*/

void I2C_Init (void)
{
	// Reset the I2C
	SET_BIT(I2C1->CR1,SWRST);
	CLR_BIT(I2C1->CR1,SWRST);

	// Program the peripheral input clock in I2C_CR2 Register in order to generate correct timings
	I2C1->CR2 = I2C_CLK;   //CLK FREQUENCY in MHz

	// Configure the clock control registers
	I2C1->CCR = CCR_Time;

	// Configure the rise time register
	I2C1->TRISE = Rise_Time;

	// Program the I2C_CR1 register to enable the peripheral
	SET_BIT(I2C1->CR1,PE); 	 // Enable I2C
}

/**
 * @brief A function for Generating A start condition to start the data transformation
 *
*/

void I2C_Start (void)
{

	SET_BIT(I2C1->CR1,ACK);  	// Enable the ACK
	SET_BIT(I2C1->CR1,START);	 // Generate START

	while (GET_BIT(I2C1->SR1,SR1_SB)!=1);  // Wait for SB bit to set

}

/**
 * @brief A function for writing Data to be transfered from master to slave
 *
 * @param data the data the master transfer to slave
 */

void I2C_Write (u8 data)
{
	while (GET_BIT(I2C1->SR1,SR1_TxE)!=1);  // wait for TXE bit to set
	I2C1->DR = data;

	while (GET_BIT(I2C1->SR1,SR1_BTF)!=1);  // wait for BTF bit to set
}

/**
 * @brief A function tp Send Slave address
 *
 * @param Address Slave address
*/

void I2C_Address (u8 Address)
{

	I2C1->DR = Address;  //  send the address
	while (GET_BIT(I2C1->SR1,SR1_ADDR)!=1);  // wait for ADDR bit to set
	u32 temp = I2C1->SR1 | I2C1->SR2;  // read SR1 and SR2 to clear the ADDR bit
}

/**
 * @brief A function to generate a stop condition to end data transmission
 *
*/

void I2C_Stop (void)
{
	SET_BIT(I2C1->CR1,STOP);  // Stop I2C
}

/**
 * @brief  A function to transmit multiple data to slave
 *
 * @param data data array or buffer
 * @param size size of data to be sent to slave
*/

void I2C_WriteMulti (u8 *data, u8 size)
{

	while (GET_BIT(I2C1->SR1,SR1_TxE)!=1);  // wait for TXE bit to set
	while (size)
	{
		while (GET_BIT(I2C1->SR1,SR1_TxE)!=1);  // wait for TXE bit to set
		I2C1->DR = (u32 )*data++;  // send data
		size--;
	}

	while (GET_BIT(I2C1->SR1,SR1_BTF)!=1);  // wait for BTF to set
}

/**
 * @brief A function to read data from slave
 *
 * @param Address slave Address
 * @param buffer buffer to store data from slave
 * @param size the size of buffer that stores data
*/

void I2C_Read (u8 Address, u8 *buffer, u8 size)
{


	int remaining = size;

	if (size == 1)
	{
		I2C1->DR = Address;  //  send the address
		while (GET_BIT(I2C1->SR1,SR1_ADDR)!=1);  // wait for ADDR bit to set

		CLR_BIT(I2C1->CR1,ACK); // clear the ACK bit
		u32 temp = I2C1->SR1 | I2C1->SR2;  // read SR1 and SR2 to clear the ADDR bit.... EV6 condition
		I2C1->CR1 |= (1<<STOP);  // Stop I2C

		while (GET_BIT(I2C1->SR1,SR1_RxNE)!=1);  // wait for RxNE to set

		buffer[size-remaining] = I2C1->DR;  // Read the data from the DATA REGISTER

	}

	else 
	{
		I2C1->DR = Address;  //  send the address
		while (GET_BIT(I2C1->SR1,SR1_ADDR)!=1);  // wait for ADDR bit to set

		u32 temp = I2C1->SR1 | I2C1->SR2;  // read SR1 and SR2 to clear the ADDR bit

		while (remaining>2)
		{
			while (GET_BIT(I2C1->SR1,SR1_RxNE)!=1);  // wait for RxNE to set

			buffer[size-remaining] = I2C1->DR;  // copy the data into the buffer

			SET_BIT(I2C1->CR1,ACK);  // Set the ACK bit to Acknowledge the data received

			remaining--;
		}

		while (!(I2C1->SR1 & (1<<6)));  // wait for RxNE to set
		buffer[size-remaining] = I2C1->DR;

		CLR_BIT(I2C1->CR1,ACK);  // clear the ACK bit

		SET_BIT(I2C1->CR1,STOP);  // Stop I2C

		remaining--;

		while (GET_BIT(I2C1->SR1,SR1_RxNE)!=1);  // wait for RxNE to set
		buffer[size-remaining] = I2C1->DR;  // copy the data into the buffer
	}	

}
