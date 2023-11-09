/**
 * @file DotMatrix_Program.c
 * @author GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * @brief DotMatrix Program File
 * @version 0.1
 * @date 2023-9-18
 * 
 * @copyright GP_4M_NC2_Intake3_Adaptive Light Control System_5
*/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_Interface.h"

#include "DotMatrix_Interface.h"
#include "DotMatrix_Private.h"
#include "DotMatrix_Config.h"

#include "cmsis_os.h"

/**
 * @brief Function to initialize the DotMatrix
 * @details It initializes the columns and rows of DotMatrix's GPIO pins
*/

void DotMatrix_voidInit()
{
	for(u8 i=0;i<NumberOfRows;i++)
	{
		GPIO_voidSetPinMode(GPIO_PORTA,i,GPIO_OUTPUT);
		GPIO_voidSetPinOutputType(GPIO_PORTA,i,GPIO_OUTPUT_OPEN_DRAIN);
		GPIO_voidPUPDMode(GPIO_PORTA,i,GPIO_PullUp);
	}
	for(u8 i=0;i<NumberOfCols;i++)
	{
		if(i==6 ||i==7)
		{
			GPIO_voidSetPinMode(GPIO_PORTB,i+4,GPIO_OUTPUT);
			GPIO_voidSetPinOutputType(GPIO_PORTB,i+4,GPIO_OUTPUT_OPEN_DRAIN);
			GPIO_voidPUPDMode(GPIO_PORTB,i+4,GPIO_PullUp);

		}else
		{
			GPIO_voidSetPinMode(GPIO_PORTB,i,GPIO_OUTPUT);
			GPIO_voidSetPinOutputType(GPIO_PORTB,i,GPIO_OUTPUT_OPEN_DRAIN);
			GPIO_voidPUPDMode(GPIO_PORTB,i,GPIO_PullUp);
		}
	}
}

/**
 * @brief Function to disable all matrix's columns
 * @details It enables or disables the columns'pins according to control logic
*/

void DotMatrix_voidDisableCols()
{

	for(u8 i=0;i<NumberOfCols;i++)
	{

		if(i==6 ||i==7)
		{
			GPIO_voidSetPinValue(GPIO_PORTB,i+4,GPIO_LOW);
		}else
		{
			GPIO_voidSetPinValue(GPIO_PORTB,i,GPIO_LOW);
		}
	}
}

/**
  * @brief Function to set matrix's row pins'value
  * 
  * @param Copy_u8Value row pins'value
*/

void DotMatrix_voidSetRowValue(u8 Copy_u8Value)
{
	GPIO_voidSetPortValue(GPIO_PORTA,Copy_u8Value);
}

/**
 * @brief Function to draw a picture on the DotMatrix
 * 
 * @param Copy_u8Data DotMatrix's Rows values
*/

void DotMatrix_voidSendData(u8 *Copy_u8Data)
{

	for(u8 i=0; i<NumberOfRows ;i++)
	{
		DotMatrix_voidDisableCols();
		DotMatrix_voidSetRowValue(Copy_u8Data[i]);
		if(i==6 ||i==7)
		{
			GPIO_voidSetPinValue(GPIO_PORTB,i+4,GPIO_HIGH);
		}else
		{
			GPIO_voidSetPinValue(GPIO_PORTB,i,GPIO_HIGH);
		}
		osDelay(3);
	}
}




