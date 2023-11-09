/**
 * @file DotMatrix_Config.h
 * @author  GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * @brief Configuration file for ports connection and pin number
 * @version 0.1
 * @date 2023-9-18
 * 
 * @copyright GP_4M_NC2_Intake3_Adaptive Light Control System_5 (c) 2023
 * 
*/

#ifndef HAL_DOTMATRIX_DOTMATRIX_CONFIG_H_
#define HAL_DOTMATRIX_DOTMATRIX_CONFIG_H_

/**
 * @brief Choosing Ports For Rows and Coloumns
 *
*/

#define DotMatrix_ROW          GPIO_PORTA
#define DotMatrix_COl          GPIO_PORTB

/**
 * @brief Coosing Number of Rows and Coloumns
 *
*/

#define NumberOfCols    7
#define NumberOfRows    7


#endif /* HAL_DOTMATRIX_DOTMATRIX_CONFIG_H_ */
