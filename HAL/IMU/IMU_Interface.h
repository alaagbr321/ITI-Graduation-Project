/**
 * @file IMU_Interface.h
 * @author GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * @brief IMU Interface file for Functions Prototypes
 * @version 0.1
 * @date 2023-10-05
 *
 * @copyright GP_4M_NC2_Intake3_Adaptive Light Control System_5
 *
*/


#ifndef HAL_IMU_IMU_INTERFACE_H_
#define HAL_IMU_IMU_INTERFACE_H_

/**
 * @brief Function to write data to IMU sensor
 *
 * @param Address The IMU address
 * @param Reg The IMU Register
 * @param Data Data will be written
*/

void MPU_Write (u8 Address, u8 Reg, u8 Data);

/**
 * @brief Function to read Data from IMU
 *
 * @param Address The IMU address
 * @param Reg The IMU Register
 * @param buffer Variable to store the data
 * @param size Data size
*/

void MPU_Read (u8 Address, u8 Reg, u8 *buffer, u8 size);

/**
 * @brief Function to Initialize the IMU sensor
 * @details it initializes the communication between the micro and IMU
*/

void MPU6050_Init (void);

/**
 * @brief Function to convert IMU data to readable acceleration values
 *
*/

void MPU6050_Read_Accel (void);

/**
 * @brief Kalman filter to filter the IMU data from any noise
 *
 * @param KalmanState Kalman State
 * @param KalmanUncertainty Kalman Uncertainty
 * @param KalmanInput  Kalman Input
 * @param KalmanMeasurement  Kalman Measurement
*/

void kalman_1d(float KalmanState, float KalmanUncertainty, float KalmanInput, float KalmanMeasurement) ;




#endif /* HAL_IMU_IMU_INTERFACE_H_ */
