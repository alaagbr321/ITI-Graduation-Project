/**
 * @file IMU_Private.h
 * @author GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * @brief IMU private file for needed private macros
 * @version 0.1
 * @date 2023-10-05
 *
 * @copyright GP_4M_NC2_Intake3_Adaptive Light Control System_5
 *
*/

#ifndef HAL_IMU_IMU_PRIVATE_H_
#define HAL_IMU_IMU_PRIVATE_H_

#define MPU6050_ADDR 0xD0


#define SMPLRT_DIV_REG 0x19
#define GYRO_CONFIG_REG 0x1B
#define ACCEL_CONFIG_REG 0x1C
#define ACCEL_XOUT_H_REG 0x3B
#define TEMP_OUT_H_REG 0x41
#define GYRO_XOUT_H_REG 0x43
#define PWR_MGMT_1_REG 0x6B
#define WHO_AM_I_REG 0x75



#endif /* HAL_IMU_IMU_PRIVATE_H_ */
