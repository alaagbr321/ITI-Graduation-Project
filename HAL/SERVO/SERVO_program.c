/**
 * @file SERVO_program.c
 * @author GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * @brief Servo Program File
 * @version 0.1
 * @date  2023-10-04
 *
 * @copyright GP_4M_NC2_Intake3_Adaptive Light Control System_5 (c) 2023
 *
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/TIMER/TIMER_interface.h"

#include "SERVO_interface.h"



/**
 * @brief Function to initialize the serve GPIO pins
 *
*/

void SERVO_voidInit(void)
{
	GPIO_voidSetPinMode(GPIO_PORTB,GPIO_PIN8,GPIO_Alternate);
	GPIO_voidSetPinAF(GPIO_PORTB, GPIO_PIN8, TIM3_TIM5);

	TIMER4_voidInit();
	SERVO_u8SendAngle(0);
}

/**
 * @brief Function to Send the desired angle to servo motor
 *
 * @param Copy_u8Angle Angle of the servo motor
 */

void SERVO_u8SendAngle(u8 Copy_u8Angle)
{
	Copy_u8Angle+=90;
	if( Copy_u8Angle >0 && Copy_u8Angle <=180)
	{
		u16 Local_CCRValue =( ( 45+Copy_u8Angle) * 100 ) / 9 ;
		TIMER4_u16SetCompareValue(Local_CCRValue);
	}
	else if(Copy_u8Angle>180)
	{
		TIMER4_u16SetCompareValue(2500);
	}else
	{
		TIMER4_u16SetCompareValue(500);
	}
}
