/**
 * @file RCC_Interface.h
 * @author GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * @brief Interface file for Functions Prototypes and needed Macros or enums
 * @version 0.1
 * @date 2023-9-13
 * 
 * @copyright GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * 
*/

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_


/**
 * @brief RCC Buses
 * 
*/

#define RCC_APB1    1
#define RCC_APB2    2
#define RCC_AHB1    3
#define RCC_AHB2    4

/**
 * @brief AHB1 Peripherals
 * 
*/

#define RCC_AHB1_GPIOA          0
#define RCC_AHB1_GPIOB          1
#define RCC_AHB1_GPIOC          2
#define RCC_AHB1_GPIOD          3
#define RCC_AHB1_GPIOE          4
#define RCC_AHB1_GPIOH          7
#define RCC_AHB1_CRC            12
#define RCC_AHB1_FLITF          15
#define RCC_AHB1_SRAM1          16
#define RCC_AHB1_DMA1           21
#define RCC_AHB1_DMA2           22

/**
 * @brief AHB2 Peripherals
 * 
*/

#define RCC_AHB2_OTGFS          7

/**
 * @brief APB1 Peripherals
 * 
*/

#define RCC_APB1_TIMER2          0
#define RCC_APB1_TIMER3          1
#define RCC_APB1_TIMER4          2
#define RCC_APB1_TIMER5          3
#define RCC_APB1_WWDG           11
#define RCC_APB1_SPI2			14
#define RCC_APB1_SPI3			15
#define RCC_APB1_USART2			17
#define RCC_APB1_I2C1			21
#define RCC_APB1_I2C2			22
#define RCC_APB1_I2C3			23
#define RCC_APB1_PWR			28


/**
 * @brief APB2 Peripherals
 * 
*/

#define RCC_APB2_TIMER1          0
#define RCC_APB2_USART1          4
#define RCC_APB2_USART6          5
#define RCC_APB2_ADC1	         8
#define RCC_APB2_SDIO	         11
#define RCC_APB2_SPI1	         12
#define RCC_APB2_SPI4	         13
#define RCC_APB2_SYSCFG	         14
#define RCC_APB2_TIMER9          16
#define RCC_APB2_TIMER10         17
#define RCC_APB2_TIMER11         18

/**
 * @brief AHB Speed Options
 * 
*/

typedef enum
{
	CLK_Full,
	CLK_2=8,
	CLK_4,
	CLK_8,
	CLK_16,
	CLK_128,
	CLK_256,
	CLK_512,

}AHB_ClK_t;


/**
 * @brief Configuring and initializing RCC
 * 
*/

void RCC_voidInit   (void);

/**
 * @brief Enabling Peripheral Clock
 * 
 * @param Copy_u8BusId the BUS ID
 * @param Copy_u8PerId The peripheral ID
*/

void RCC_voidEnablePeripheralClock      (   u8 Copy_u8BusId    , u8 Copy_u8PerId    );

/**
 * @brief Disabling Peripheral Clock
 * 
 * @param Copy_u8BusId the BUS ID
 * @param Copy_u8PerId The peripheral ID
*/

void RCC_voidDisablePeripheralClock     (   u8 Copy_u8BusId    , u8 Copy_u8PerId    );

/**
 * @brief Change AHB speed
 * 
*/

void RCC_voidChangeAHB_Speed();



#endif /* RCC_INTERFACE_H_ */
