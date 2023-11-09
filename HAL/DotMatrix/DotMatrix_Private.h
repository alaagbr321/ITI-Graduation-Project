/**
 * @file DotMatrix_Private.h
 * @author GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * @brief File includes private Functions prototype
 * @version 0.1
 * @date 2023-9-18
 * 
 * @copyright GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * 
*/

#ifndef HAL_DOTMATRIX_DOTMATRIX_PRIVATE_H_
#define HAL_DOTMATRIX_DOTMATRIX_PRIVATE_H_

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


#endif /* HAL_DOTMATRIX_DOTMATRIX_PRIVATE_H_ */
