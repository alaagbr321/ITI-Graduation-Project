/**
 * @file RCC_Config.h
 * @author GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * @brief Configuration File For RCC
 * @version 0.1
 * @date  2023-9-13
 * 
 * @copyright GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * 
*/

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/**
 * @brief Enabling or Disabling CLOCK
 * 
*/

#define ENABLE   1
#define DISABLE  0

/**
 * @brief Clock source options
 * 
*/

#define RCC_HSI 	1
#define RCC_HSE 	2
#define RCC_PLL		3


/**
 * @brief Clock source select
 * 
*/

#define RCC_ClockSource_Select   RCC_HSE


/**
 * @brief Clock enabling options
 * 1-ENABLE
 * 2-DISABLE
*/

#define RCC_HSI_ENABLE     DISABLE
#define RCC_HSE_ENABLE	   ENABLE
#define RCC_PLL_ENABLE     DISABLE


/**
 * @brief Selecting AHB prescaler
 * 1-CLK_Full
 * 2-CLK_2
 * 3-CLK_4
 * 4-CLK_8
 * 5-CLK_16
 * 6-CLK_64
 * 7-CLK_128
 * 8-CLK_256
 * 9-CLK_512
*/

#define AHB_Speed   CLK_Full





#endif /* RCC_CONFIG_H_ */
