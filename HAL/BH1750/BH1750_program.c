/**
 * @file Intensity Sensor BH1750_program.c
 * @author GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * @brief Intensity Sensor BH1750 Program File
 * @version 0.1
 * @date 2023-10-10
 *
 * @copyright GP_4M_NC2_Intake3_Adaptive Light Control System_5
 *
*/


#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"

#include "../../MCAL/I2C/I2C_Interface.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"

#include"BH1750_interface.h"

u8 buff[2];

/**
 * @brief Function to initialize the intensity sensor
 * @details Function to initialize the I2C communication between Sensor and microcontroller
 * @param Address Address of the Sensor
*/

void BH1750_Init(u8 Address)
{
	GPIO_Config I2C_SCL =
	{
			.Port = GPIO_PORTB,
			.Pin = GPIO_PIN6,
			.Mode = GPIO_Alternate,
			.OutputSpeed = VeryHighSpeed,
			.OutputType = GPIO_OUTPUT_OPEN_DRAIN,
			.PullState = GPIO_PullUp
	};
	GPIO_Config I2C_SDA =
	{
			.Port = GPIO_PORTB,
			.Pin = GPIO_PIN7,
			.Mode = GPIO_Alternate,
			.OutputSpeed = VeryHighSpeed,
			.OutputType = GPIO_OUTPUT_OPEN_DRAIN,
			.PullState = GPIO_PullUp
	};
	GPIO_voidInit(&I2C_SCL);
	GPIO_voidInit(&I2C_SDA);
	GPIO_voidSetPinAF(I2C_SCL.Port,I2C_SCL.Pin,I2C1_I2C3);
	GPIO_voidSetPinAF(I2C_SDA.Port,I2C_SDA.Pin,I2C1_I2C3);

	/*
	 * 1-Set Power On
	 * 2-Set Measurement Mode
	 */

	I2C_Start();
	I2C_Address(Address << 1);
	I2C_Write(BH1750_PowerOn);
	I2C_Stop();
	I2C_Start();
	I2C_Address(Address << 1);
	I2C_Write(BH1750_CONT_HRES);
	I2C_Stop();

}

/**
 * @brief  Function to read the intenisty value from the sensor
 *
 * @param Address  Address of the sensor
 * @return u16 The light intensity value
*/

u16 BH1750_Read(u8 Address)
{
	u16 Local_u16Value = 0;
	I2C_Start();
	I2C_Read(((Address << 1)|0x01),buff,2);
	I2C_Stop();
	Local_u16Value=((buff[0]<<8)|buff[1])/1.2;
	return Local_u16Value;

}

