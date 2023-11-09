/**
 * @file DotMatrix_Interface.h
 * @author GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * @brief Interface file for Functions Prototypes 
 * @version 0.1
 * @date 2023-9-18
 * 
 * @copyright GP_4M_NC2_Intake3_Adaptive Light Control System_5 (c) 2023
 * 
 */

#ifndef HAL_DOTMATRIX_DOTMATRIX_INTERFACE_H_
#define HAL_DOTMATRIX_DOTMATRIX_INTERFACE_H_


/**
 * @brief Function to initialize the DotMatrix
 * @details It initializes the columns and rows of DotMatrix's GPIO pins
*/

void DotMatrix_voidInit();

/**
 * @brief Function to draw a picture on the DotMatrix
 * 
 * @param Copy_u8Data DotMatrix's Rows values
*/

void DotMatrix_voidSendData(u8 *Copy_u8Data);

/**
 * @brief Function to disable all matrix's columns
 * @details It enables or disables the columns'pins according to control logic
*/

void DotMatrix_voidDisableCols();

/**
  * @brief Function to set matrix's row pins'value
  * 
  * @param Copy_u8Value row pins'value
*/

void DotMatrix_voidSetRowValue(u8 Copy_u8Value);



#endif /* HAL_DOTMATRIX_DOTMATRIX_INTERFACE_H_ */
