/**
 * @file TIMER_interface.h
 * @author GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * @brief interface File that contains functions prototypes
 * @version 0.1
 * @date 2023-10-04
 * 
 * @copyright GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * 
*/

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_



/**
 * @brief Initializing function with certain configuration
 * 
*/

void TIMER4_voidInit(void);

/**
 * @brief Function for Setting compare value for the timer
 * 
 * @param CopyCompareValue the compare value to be set
*/

void TIMER4_u16SetCompareValue(u16 CopyCompareValue );

#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
