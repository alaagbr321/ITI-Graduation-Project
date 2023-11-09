/**
 * @file GPIO_Program.c
 * @author GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * @brief The GPIO Program File
 * @version 0.1
 * @date 2023-9-15
 * 
 * @copyright GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * 
 */

#include"../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "GPIO_Interface.h"
#include "GPIO_Private.h"

/**
 * @brief Function to set pin mode
 * 1-GPIO_INPUT      
 * 2-GPIO_OUTPUT     
 * 3-GPIO_Alternate  
 * 4-GPIO_ANALOG 
 * @param Copy_u8PortID the Port ID 
 * @param Copy_u8Pin the Pin number
 * @param Copy_u8PinMode The pin mode    
 */

void GPIO_voidSetPinMode(u8 Copy_GPIOPortID  , u8 Copy_GPIOPinID ,u8 Copy_u8PinMode)
{
	switch(Copy_GPIOPortID)
	{
	case GPIO_PORTA:
	{
		GPIOA->MODER &= ~(0b11 << (Copy_GPIOPinID * 2));
		GPIOA->MODER |= (Copy_u8PinMode << (Copy_GPIOPinID * 2));
	}
	break;
	case GPIO_PORTB:
	{
		GPIOB->MODER &= ~(0b11 << (Copy_GPIOPinID * 2));
		GPIOB->MODER |= (Copy_u8PinMode << (Copy_GPIOPinID * 2));
	}
	break;
	case GPIO_PORTC:
	{
		GPIOC->MODER &= ~(0b11 << (Copy_GPIOPinID * 2));
		GPIOC->MODER |= (Copy_u8PinMode << (Copy_GPIOPinID * 2));
	}
	break;
	default:
		break;
	}
}

/**
 * @brief Function to set pin value 
 * 1- GPIO_HIGH  
 * 2- GPIO_LOW   
 * @param Copy_u8PortID the Port ID 
 * @param Copy_u8Pin the Pin number
 * @param Copy_u8PinMode The pin value
 */

void GPIO_voidSetPinValue(u8 Copy_u8PortID , u8 Copy_u8Pin ,u8 Copy_u8PinValue)
{
	switch(Copy_u8PinValue)
	{
	case GPIO_HIGH:
		switch(Copy_u8PortID)
		{
		case GPIO_PORTA:
			GPIOA->BSRR=1<<Copy_u8Pin;
			break;
		case GPIO_PORTB:
			GPIOB->BSRR=1<<Copy_u8Pin;
			break;
		case GPIO_PORTC:
			GPIOC->BSRR=1<<Copy_u8Pin;
			break;
		}
		break;
		case GPIO_LOW:
			switch(Copy_u8PortID)
			{
			case GPIO_PORTA:
				GPIOA->BSRR=1<<(Copy_u8Pin+16);
				break;
			case GPIO_PORTB:
				GPIOB->BSRR=1<<(Copy_u8Pin+16);
				break;
			case GPIO_PORTC:
				GPIOC->BSRR=1<<(Copy_u8Pin+16);
				break;
			}
			break;
	}

}

/**
 * @brief Function for Reading or Getting The Pin Value 
 * 1- GPIO_HIGH  
 * 2- GPIO_LOW   
 * @param Copy_u8PortID the Port ID 
 * @param Copy_u8Pin the Pin number
 * @return u8 the value of the Pin
 */

u8  GPIO_u8GetPinValue(u8 Copy_u8PortID , u8 Copy_u8Pin)
{
	u8 Local_u8Holder=255;
	switch(Copy_u8PortID)
	{
	case GPIO_PORTA:
		Local_u8Holder=GET_BIT(GPIOA->IDR,Copy_u8Pin);
		break;
	case GPIO_PORTB:
		Local_u8Holder=GET_BIT(GPIOB->IDR,Copy_u8Pin);
		break;
	case GPIO_PORTC:
		Local_u8Holder=GET_BIT(GPIOC->IDR,Copy_u8Pin);
		break;
	}
	return Local_u8Holder;

}

/**
 * @brief Function for Setting the Pull Mode
 * 1- GPIO_NoPullUp_NoPullDown   
 * 2- GPIO_PullUp				  
 * 3- GPIO_PullDown			  
 * @param Copy_u8PortID the Port ID 
 * @param Copy_u8Pin the Pin number
 * @param Copy_u8PinMode The Pull Mode
 */

void GPIO_voidPUPDMode(u8 Copy_u8PortID  , u8 Copy_u8Pin ,u8 Copy_u8PinMode)
{
	u8 Local_u8Location=(Copy_u8Pin*2);
	switch(Copy_u8PinMode)
	{
	case GPIO_NoPullUp_NoPullDown:
		switch(Copy_u8PortID)
		{
		case GPIO_PORTA:
			CLR_BIT(GPIOA->PUPDR,Local_u8Location);
			CLR_BIT(GPIOA->PUPDR,(Local_u8Location+1));
			break;
		case GPIO_PORTB:
			CLR_BIT(GPIOB->PUPDR,Local_u8Location);
			CLR_BIT(GPIOB->PUPDR,(Local_u8Location+1));
			break;
		case GPIO_PORTC:
			CLR_BIT(GPIOC->PUPDR,Local_u8Location);
			CLR_BIT(GPIOC->PUPDR,(Local_u8Location+1));
			break;
		}

		break;
		case GPIO_PullUp:
			switch(Copy_u8PortID)
			{
			case GPIO_PORTA:
				SET_BIT(GPIOA->PUPDR,Local_u8Location);
				CLR_BIT(GPIOA->PUPDR,(Local_u8Location+1));
				break;
			case GPIO_PORTB:
				SET_BIT(GPIOB->PUPDR,Local_u8Location);
				CLR_BIT(GPIOB->PUPDR,(Local_u8Location+1));
				break;
			case GPIO_PORTC:
				SET_BIT(GPIOC->PUPDR,Local_u8Location);
				CLR_BIT(GPIOC->PUPDR,(Local_u8Location+1));
				break;
			}
			break;
			case GPIO_PullDown:
				switch(Copy_u8PortID)
				{
				case GPIO_PORTA:
					CLR_BIT(GPIOA->PUPDR,Local_u8Location);
					SET_BIT(GPIOA->PUPDR,(Local_u8Location+1));
					break;
				case GPIO_PORTB:
					CLR_BIT(GPIOB->PUPDR,Local_u8Location);
					SET_BIT(GPIOB->PUPDR,(Local_u8Location+1));
					break;
				case GPIO_PORTC:
					CLR_BIT(GPIOC->PUPDR,Local_u8Location);
					SET_BIT(GPIOC->PUPDR,(Local_u8Location+1));
					break;
				}
				break;
	}

}

/**
 * @brief Function to Set the output Type 
 * 1- GPIO_OUTPUT_PUSH_PULL 
 * 2- GPIO_OUTPUT_OPEN_DRAIN
 * @param Copy_u8PortID the Port ID 
 * @param Copy_u8Pin the Pin number
 * @param Copy_u8OutPutPinType The Output Type
 */

void GPIO_voidSetPinOutputType(u8 Copy_u8PortID  , u8 Copy_u8Pin ,u8 Copy_u8OutPutPinType)
{
	switch(Copy_u8OutPutPinType)
	{
	case GPIO_OUTPUT_PUSH_PULL:
		switch(Copy_u8PortID)
		{
		case GPIO_PORTA:
			CLR_BIT(GPIOA->OTYPER,Copy_u8Pin);
			break;

		case GPIO_PORTB:
			CLR_BIT(GPIOB->OTYPER,Copy_u8Pin);
			break;

		case GPIO_PORTC:
			CLR_BIT(GPIOC->OTYPER,Copy_u8Pin);
			break;
		}
		break;

		case GPIO_OUTPUT_OPEN_DRAIN:

			switch(Copy_u8PortID)
			{
			case GPIO_PORTA:
				SET_BIT(GPIOA->OTYPER,Copy_u8Pin);
				break;

			case GPIO_PORTB:
				SET_BIT(GPIOB->OTYPER,Copy_u8Pin);
				break;

			case GPIO_PORTC:
				SET_BIT(GPIOC->OTYPER,Copy_u8Pin);
				break;
			}
			break;
	}

}

/**
 * @brief Function to set he output speed on the GPIO Pin
 * 1- LowSpeed       
 * 2- MediumSpeed    
 * 3- HighSpeed      
 * 4- VeryHighSpeed  
 * @param Copy_u8PortID the Port ID 
 * @param Copy_u8Pin the Pin number
 * @param Copy_u8OutPutPinSpeed The Output speed
 */

void GPIO_voidSetPinOutputSpeed(u8 Copy_u8PortID  , u8 Copy_u8Pin ,u8 Copy_u8OutPutPinSpeed)
{
	u8 Local_u8Location=(Copy_u8Pin*2);

	switch(Copy_u8OutPutPinSpeed)
	{
	case LowSpeed:
		switch(Copy_u8PortID)
		{
		case GPIO_PORTA:

			CLR_BIT(GPIOA->OSPEEDR,Local_u8Location);
			CLR_BIT(GPIOA->OSPEEDR,(Local_u8Location+1));
			break;
		case GPIO_PORTB:
			CLR_BIT(GPIOB->OSPEEDR,Local_u8Location);
			CLR_BIT(GPIOB->OSPEEDR,(Local_u8Location+1));
			break;
		case GPIO_PORTC:
			CLR_BIT(GPIOC->OSPEEDR,Local_u8Location);
			CLR_BIT(GPIOC->OSPEEDR,(Local_u8Location+1));
			break;
		}
		break;


		case MediumSpeed:
			switch(Copy_u8PortID)
			{
			case GPIO_PORTA:

				SET_BIT(GPIOA->OSPEEDR,Local_u8Location);
				CLR_BIT(GPIOA->OSPEEDR,(Local_u8Location+1));
				break;
			case GPIO_PORTB:
				SET_BIT(GPIOB->OSPEEDR,Local_u8Location);
				CLR_BIT(GPIOB->OSPEEDR,(Local_u8Location+1));
				break;
			case GPIO_PORTC:
				SET_BIT(GPIOC->OSPEEDR,Local_u8Location);
				CLR_BIT(GPIOC->OSPEEDR,(Local_u8Location+1));
				break;
			}
			break;


			case HighSpeed:
				switch(Copy_u8PortID)
				{
				case GPIO_PORTA:

					CLR_BIT(GPIOA->OSPEEDR,Local_u8Location);
					SET_BIT(GPIOA->OSPEEDR,(Local_u8Location+1));
					break;
				case GPIO_PORTB:
					CLR_BIT(GPIOB->OSPEEDR,Local_u8Location);
					SET_BIT(GPIOB->OSPEEDR,(Local_u8Location+1));
					break;
				case GPIO_PORTC:
					CLR_BIT(GPIOC->OSPEEDR,Local_u8Location);
					SET_BIT(GPIOC->OSPEEDR,(Local_u8Location+1));
					break;
				}
				break;

				case VeryHighSpeed:
					switch(Copy_u8PortID)
					{
					case GPIO_PORTA:

						SET_BIT(GPIOA->OSPEEDR,Local_u8Location);
						SET_BIT(GPIOA->OSPEEDR,(Local_u8Location+1));
						break;
					case GPIO_PORTB:
						SET_BIT(GPIOB->OSPEEDR,Local_u8Location);
						SET_BIT(GPIOB->OSPEEDR,(Local_u8Location+1));
						break;
					case GPIO_PORTC:
						SET_BIT(GPIOC->OSPEEDR,Local_u8Location);
						SET_BIT(GPIOC->OSPEEDR,(Local_u8Location+1));
						break;
					}
					break;
	}
}

/**
 * @brief Function To Set Port Value
 * 
 * @param Copy_u8PortID the Port ID 
 * @param Copy_u8PortValue the Port Value
 */

void GPIO_voidSetPortValue(u8 Copy_u8PortID,u8 Copy_u8PortValue)
{
	switch(Copy_u8PortID)
	{
	case GPIO_PORTA:
		GPIOA->ODR=Copy_u8PortValue;
		break;

	case GPIO_PORTB:
		GPIOB->ODR=Copy_u8PortValue;
		break;
	case GPIO_PORTC:
		GPIOC->ODR=Copy_u8PortValue;
		break;
	}
}

/**
 * @brief Function To choose the Alternative Function for The GPIO Pin
 * 
 * @param Copy_u8PortID the Port ID 
 * @param Copy_u8Pin the Pin number
 * @param Copy_u8AFPinMode The Alternative Function To Be Choosen
 * 1-AF_System	
 * 2-TIM1_TIM2	
 * 3-TIM3_TIM5	
 * 4-TIM9_TIM11	
 * 5-I2C1_I2C3	
 * 6-SPI1_4      
 * 7-SPI3        
 * 8-USART1_2    
 * 9-USART6      
 * 10-I2C2_3      
 * 11-OTG_FS      
 * 12-SDIO        
 * 13-EVENOUT     
 */

void GPIO_voidSetPinAF(u8 Copy_GPIOPortID  , u8 Copy_GPIOPinID ,u8 Copy_Alternative)
{
	if(Copy_GPIOPinID < 8)
	{
		switch(Copy_GPIOPortID)
		{
		case GPIO_PORTA:
		{
			GPIOA->AFRL &= ~((0b1111)<<(Copy_GPIOPinID*4));
			GPIOA->AFRL |= ((Copy_Alternative)<<(Copy_GPIOPinID*4));
		}
		break;
		case GPIO_PORTB:
		{
			GPIOB->AFRL &= ~((0b1111)<<(Copy_GPIOPinID*4));
			GPIOB->AFRL |= ((Copy_Alternative)<<(Copy_GPIOPinID*4));
		}
		break;
		case GPIO_PORTC:
		{
			GPIOC->AFRL &= ~((0b1111)<<(Copy_GPIOPinID*4));
			GPIOC->AFRL |= ((Copy_Alternative)<<(Copy_GPIOPinID*4));
		}
		break;
		default:
			break;
		}
	}
	else if(Copy_GPIOPinID < 16)
	{
		switch(Copy_GPIOPortID)
		{
		case GPIO_PORTA:
		{
			GPIOA->AFRH &= ~((0b1111)<< (Copy_GPIOPinID-8) * 4 );
			GPIOA->AFRH |= ((Copy_Alternative)<<(Copy_GPIOPinID-8) * 4);
		}
		break;
		case GPIO_PORTB:
		{
			GPIOB->AFRH &= ~((0b1111)<<(Copy_GPIOPinID-8) * 4);
			GPIOB->AFRH |= ((Copy_Alternative)<<(Copy_GPIOPinID-8) * 4);
		}
		break;
		case GPIO_PORTC:
		{
			GPIOC->AFRH &= ~((0b1111)<<(Copy_GPIOPinID-8) * 4);
			GPIOC->AFRH |= ((Copy_Alternative)<<(Copy_GPIOPinID-8) * 4);
		}
		break;
		default:
			break;
		}
	}
}
/**
 * @brief A function to configure GPIO pins
 *
 * @param config pointer to struct that initialize to Configure GPIO PIN
 */

void GPIO_voidInit(GPIO_Config	*config)
{
	GPIO_voidSetPinMode(config->Port , config->Pin , config->Mode);
	GPIO_voidSetPinOutputType(config->Port , config->Pin , config->OutputType);
	GPIO_voidSetPinOutputSpeed(config->Port , config->Pin , config->OutputSpeed);
	GPIO_voidPUPDMode(config->Port , config->Pin , config->PullState);
}


