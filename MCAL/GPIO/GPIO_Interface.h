/**
 * @file GPIO_Interface.h
 * @author GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * @brief Interface file for Functions Prototypes and needed Macros or enums
 * @version 0.1
 * @date 2023-9-15
 * 
 * @copyright GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * 
*/

#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_


/**
 * @brief GPIO Ports
 * 
*/

#define GPIO_PORTA			 0
#define GPIO_PORTB           1
#define GPIO_PORTC           2

/**
 * @brief GPIO Modes
 * 
*/

#define GPIO_INPUT      0
#define GPIO_OUTPUT     1
#define GPIO_Alternate  2
#define GPIO_ANALOG     3

/**
 * @brief GPIO Pull Modes
 * 
*/

#define GPIO_NoPullUp_NoPullDown   0
#define GPIO_PullUp				   1
#define GPIO_PullDown			   2

/**
 * @brief GPIO Alternative Modes
 * 
*/

#define AF_System					0
#define TIM1_TIM2					1
#define TIM3_TIM5					2
#define TIM9_TIM11					3
#define I2C1_I2C3					4
#define SPI1_4                      5
#define USART1_2                    7
#define USART6                      8
#define I2C2_3                      9
#define OTG_FS                      10
#define SDIO                        12
#define EVENOUT                     15

/**
 * @brief GPIO OUTPUT Types
 * 
*/

#define GPIO_OUTPUT_PUSH_PULL   0
#define GPIO_OUTPUT_OPEN_DRAIN   1

/**
 * @brief GPIO OUTPUT SPEED
 * 
*/

#define LowSpeed       0
#define MediumSpeed    1
#define HighSpeed      2
#define VeryHighSpeed  3

/**
 * @brief GPIO Pin Value
 * 
*/

#define GPIO_HIGH       1
#define GPIO_LOW        0

/**
 * @brief GPIO Port Direction
 * 
*/

#define GPIO_PORT_INPUT  0x00000000
#define GPIO_PORT_OUTPUT 0xFFFFFFFF

/**
 * @brief GPIO Port Value
 * 
*/

#define GPIO_PORT_LOW  0x00000000
#define GPIO_PORT_HIGH 0xFFFFFFFF

/**
 * @brief GPIO PINS
 * 
*/

#define GPIO_PIN0     0
#define GPIO_PIN1     1
#define GPIO_PIN2     2
#define GPIO_PIN3     3
#define GPIO_PIN4     4
#define GPIO_PIN5     5
#define GPIO_PIN6     6
#define GPIO_PIN7     7
#define GPIO_PIN8     8
#define GPIO_PIN9     9
#define GPIO_PIN10    10
#define GPIO_PIN11    11
#define GPIO_PIN12    12
#define GPIO_PIN13    13
#define GPIO_PIN14    14
#define GPIO_PIN15    15

typedef struct
{
	u8 						 Port 		;
	u8  					 Pin  		;
	u8		        		 Mode 		;
	u8 						 OutputType	;
	u8 	       				 OutputSpeed;
	u8 						 PullState 	;

}GPIO_Config;

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

void GPIO_voidSetPinMode(u8 Copy_u8PortID  , u8 Copy_u8Pin ,u8 Copy_u8PinMode);

/**
 * @brief Function to set pin value 
 * 1- GPIO_HIGH  
 * 2- GPIO_LOW   
 * @param Copy_u8PortID the Port ID 
 * @param Copy_u8Pin the Pin number
 * @param Copy_u8PinMode The pin value
*/

void GPIO_voidSetPinValue(u8 Copy_u8PortID , u8 Copy_u8Pin ,u8 Copy_u8PinValue);



void GPIO_voidSetPortValue(u8 Copy_u8PortID,u8 Copy_u8PortValue);

/**
 * @brief Function for Reading or Getting The Pin Value 
 * 1- GPIO_HIGH  
 * 2- GPIO_LOW   
 * @param Copy_u8PortID the Port ID 
 * @param Copy_u8Pin the Pin number
 * @return u8 the value of the Pin
*/

u8  GPIO_u8GetPinValue(u8 Copy_u8PortID , u8 Copy_u8Pin);

/**
 * @brief Function for Setting the Pull Mode
 * 1- GPIO_NoPullUp_NoPullDown   
 * 2- GPIO_PullUp				  
 * 3- GPIO_PullDown			  
 * @param Copy_u8PortID the Port ID 
 * @param Copy_u8Pin the Pin number
 * @param Copy_u8PinMode The Pull Mode
*/

void GPIO_voidPUPDMode(u8 Copy_u8PortID  , u8 Copy_u8Pin ,u8 Copy_u8PinMode);

/**
 * @brief Function to Set the output Type 
 * 1- GPIO_OUTPUT_PUSH_PULL 
 * 2- GPIO_OUTPUT_OPEN_DRAIN
 * @param Copy_u8PortID the Port ID 
 * @param Copy_u8Pin the Pin number
 * @param Copy_u8OutPutPinType The Output Type
*/

void GPIO_voidSetPinOutputType(u8 Copy_u8PortID  , u8 Copy_u8Pin ,u8 Copy_u8OutPutPinType);

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

void GPIO_voidSetPinOutputSpeed(u8 Copy_u8PortID  , u8 Copy_u8Pin ,u8 Copy_u8OutPutPinSpeed);


/**
 * @brief Function To choose the Alternative Function for The GPIO Pin
 * 
 * @param Copy_GPIOPortID the Port ID
 * @param Copy_GPIOPinID the Pin number
 * @param Copy_Alternative The Alternative Function To Be Choosen
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

void GPIO_voidSetPinAF(u8 Copy_GPIOPortID  , u8 Copy_GPIOPinID ,u8 Copy_Alternative);

/**
 * @brief A function to configure GPIO pins
 *
 * @param config pointer to struct that initialize to Configure GPIO PIN
*/

void GPIO_voidInit(GPIO_Config	*config);
#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
