/**
 * @file SERVO_interface.h
 * @author GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * @brief Interface file for functions prototypes
 * @version 0.1
 * @date 2023-10-04
 *
 * @copyright GP_4M_NC2_Intake3_Adaptive Light Control System_5
 *
*/

#ifndef HAL_SERVO_SERVO_INTERFACE_H_
#define HAL_SERVO_SERVO_INTERFACE_H_

/**
 * @brief Function to initialize the serve GPIO pins
 *
*/

void SERVO_voidInit(void);

/**
 * @brief Function to Send the desired angle to servo motor
 *
 * @param Copy_u8Angle
*/

void SERVO_u8SendAngle (u8 Copy_u8Angle );

#endif /* HAL_SERVO_SERVO_INTERFACE_H_ */
