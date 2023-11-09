/**
 * @file RCC_Program.c
 * @author GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * @brief The RCC Program File
 * @version 0.1
 * @date 2023-9-13
 * 
 * @copyright GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * 
*/

#include"../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include  "RCC_Interface.h"
#include "RCC_Config.h"
#include "RCC_Private.h"

/**
 * @brief Configuring and initializing RCC
 * 
*/

void RCC_voidInit   (void)
{
	/*Enable Clock Security*/
	SET_BIT(RCC->CR , CSSON);
	/* BYPASS Select    */
	/*Not Bypass*/
	CLR_BIT(RCC->CR , HSEBYP);
	/*Select Clock Source*/
#if RCC_ClockSource_Select ==RCC_HSI
	CLR_BIT(RCC->CFGR ,SW0);
	CLR_BIT(RCC->CFGR ,SW1);

#elif RCC_ClockSource_Select ==RCC_HSE
	SET_BIT(RCC->CFGR,SW0);
	CLR_BIT(RCC->CFGR,SW1);

#elif RCC_ClockSource_Select ==RCC_PLL
	CLR_BIT(RCC->CFGR,SW0);
	SET_BIT(RCC->CFGR,SW1);

#endif
	/*Enable Clock Source*/
#if RCC_HSI_ENABLE   == ENABLE
	SET_BIT(RCC->CR,HSION);

#elif RCC_HSI_ENABLE == DISABLE
	CLR_BIT(RCC->CR,HSION);
#endif
#if RCC_HSE_ENABLE   == ENABLE
	SET_BIT(RCC->CR,HSEON);
#elif RCC_HSE_ENABLE == DISABLE
	CLR_BIT(RCC->CR,HSEON);
#endif
#if RCC_PLL_ENABLE   == ENABLE
	SET_BIT(RCC->CR,PLLON);
#elif RCC_PLL_ENABLE == DISABLE
	CLR_BIT(RCC->CR,PLLON);
#endif

}

/**
 * @brief Enabling Peripheral Clock
 * 
 * @param Copy_u8BusId the BUS ID
 * @param Copy_u8PerId The peripheral ID
*/

void RCC_voidEnablePeripheralClock      (   u8 Copy_u8BusId    , u8 Copy_u8PerId    )
{
	if((Copy_u8BusId<=RCC_AHB2) && (Copy_u8PerId <32))
	{
		switch(Copy_u8BusId)
		{
		case RCC_APB1:
			SET_BIT(RCC->APB1ENR,Copy_u8PerId);

			break;

		case RCC_APB2:
			SET_BIT(RCC->APB2ENR,Copy_u8PerId);
			break;

		case RCC_AHB1:
			SET_BIT(RCC->AHB1ENR,Copy_u8PerId);
			break;

		case RCC_AHB2:
			SET_BIT(RCC->AHB2ENR,Copy_u8PerId);
			break;
		}
	}

}

/**
 * @brief Disabling Peripheral Clock
 * 
 * @param Copy_u8BusId the BUS ID
 * @param Copy_u8PerId The peripheral ID
*/

void RCC_voidDisablePeripheralClock     (   u8 Copy_u8BusId    , u8 Copy_u8PerId    )
{

	if((Copy_u8BusId<=RCC_AHB2) && (Copy_u8PerId <32))
	{
		switch(Copy_u8BusId)
		{
		case RCC_APB1:
			CLR_BIT(RCC->APB1ENR,Copy_u8PerId);


			break;

		case RCC_APB2:
			CLR_BIT(RCC->APB2ENR,Copy_u8PerId);
			break;

		case RCC_AHB1:
			CLR_BIT(RCC->AHB1ENR,Copy_u8PerId);
			break;

		case RCC_AHB2:
			CLR_BIT(RCC->AHB2ENR,Copy_u8PerId);
			break;

		}
	}
}

/**
 * @brief Change AHB speed
 * 
*/

void RCC_voidChangeAHB_Speed()
{
	RCC->CFGR&=~(0b1111<<4);
	RCC->CFGR|=(AHB_Speed<<4);
}
