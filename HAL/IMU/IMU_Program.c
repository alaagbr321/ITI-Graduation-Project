/**
 * @file IMU_Program.c
 * @author GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * @brief IMU program File
 * @version 0.1
 * @date 2023-10-05
 *
 * @copyright GP_4M_NC2_Intake3_Adaptive Light Control System_5
 *
*/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "../../MCAL/I2C/I2C_Interface.h"

#include "IMU_Interface.h"
#include "IMU_Private.h"
#include "math.h"


u32 LoopTimer;
extern f32 Kalman1DOutput[2];
extern f32 AngleRoll, AnglePitch;


float Ax, Ay, Az, Gx, Gy, Gz;


s16 Accel_X_RAW = 0;
s16 Accel_Y_RAW = 0;
s16 Accel_Z_RAW = 0;

s16 Gyro_X_RAW = 0;
s16 Gyro_Y_RAW = 0;
s16 Gyro_Z_RAW = 0;

/**
 * @brief Function to write data to IMU sensor
 *
 * @param Address The IMU address
 * @param Reg The IMU Register
 * @param Data Data will be written
*/

void MPU_Write (u8 Address, u8 Reg, u8 Data)
{
	I2C_Start ();
	I2C_Address (Address);
	I2C_Write (Reg);
	I2C_Write (Data);
	I2C_Stop ();

}

/**
 * @brief Function to read Data from IMU
 *
 * @param Address The IMU address
 * @param Reg The IMU Register
 * @param buffer Variable to store the data
 * @param size Data size
*/

void MPU_Read (u8 Address, u8 Reg, u8 *buffer, u8 size)
{

	I2C_Start ();
	I2C_Address (Address);
	I2C_Write (Reg);
	I2C_Start ();  // repeated start
	I2C_Read (Address+0x01, buffer, size);

	I2C_Stop ();
}

/**
 * @brief Function to Initialize the IMU sensor
 * @details it initializes the communication between the micro and IMU
*/

void MPU6050_Init (void)
{
	GPIO_Config I2C_SCL =
		{
				.Port = GPIO_PORTB,
				.Pin = GPIO_PIN6,
				.Mode = GPIO_Alternate,
				.OutputSpeed = VeryHighSpeed,
				.OutputType = GPIO_OUTPUT_OPEN_DRAIN,
				.PullState = GPIO_PullUp
		};
		GPIO_Config I2C_SDA =
		{
				.Port = GPIO_PORTB,
				.Pin = GPIO_PIN7,
				.Mode = GPIO_Alternate,
				.OutputSpeed = VeryHighSpeed,
				.OutputType = GPIO_OUTPUT_OPEN_DRAIN,
				.PullState = GPIO_PullUp
		};
		GPIO_voidInit(&I2C_SCL);
		GPIO_voidInit(&I2C_SDA);
		GPIO_voidSetPinAF(I2C_SCL.Port,I2C_SCL.Pin,I2C1_I2C3);
		GPIO_voidSetPinAF(I2C_SDA.Port,I2C_SDA.Pin,I2C1_I2C3);

	u8 check;
	u8 Data;

	// check device ID WHO_AM_I

	MPU_Read (MPU6050_ADDR,WHO_AM_I_REG, &check, 1);

	if (check == 104)  // 0x68 will be returned by the sensor if everything goes well
	{
		// power management register 0X6B we should write all 0's to wake the sensor up
		Data = 0;
		MPU_Write (MPU6050_ADDR, PWR_MGMT_1_REG, Data);

		// Set DATA RATE of 1KHz by writing SMPLRT_DIV register
		Data = 0x07;
		MPU_Write(MPU6050_ADDR, SMPLRT_DIV_REG, Data);

		// Set accelerometer configuration in ACCEL_CONFIG Register
		// XA_ST=0,YA_ST=0,ZA_ST=0, FS_SEL=0 -> ? 2g
		Data = 0x00;
		MPU_Write(MPU6050_ADDR, ACCEL_CONFIG_REG, Data);

		// Set Gyroscopic configuration in GYRO_CONFIG Register
		// XG_ST=0,YG_ST=0,ZG_ST=0, FS_SEL=0 -> ? 250 ?/s
		Data = 0x00;
		MPU_Write(MPU6050_ADDR, GYRO_CONFIG_REG, Data);


	}

}

/**
 * @brief Function to convert IMU data to readable acceleration values
 *
*/

void MPU6050_Read_Accel (void)
{
	u8 Rx_data[6];

	// Read 6 BYTES of data starting from ACCEL_XOUT_H register

	MPU_Read (MPU6050_ADDR, ACCEL_XOUT_H_REG, Rx_data, 6);

	Accel_X_RAW = (s16)(Rx_data[0] << 8 | Rx_data [1]);
	Accel_Y_RAW = (s16)(Rx_data[2] << 8 | Rx_data [3]);
	Accel_Z_RAW = (s16)(Rx_data[4] << 8 | Rx_data [5]);

	/*** convert the RAW values into acceleration in 'g'
	     we have to divide according to the Full scale value set in FS_SEL
	     I have configured FS_SEL = 0. So I am dividing by 16384.0
	     for more details check ACCEL_CONFIG Register              ****/

	Ax = Accel_X_RAW/16384.0;
	Ay = Accel_Y_RAW/16384.0;
	Az = Accel_Z_RAW/16384.0;

	AngleRoll=atan(Ay/sqrt(Ax*Ax+Az*Az))*1/(3.142/180);
	AnglePitch=-atan(Ax/sqrt(Ay*Ay+Az*Az))*1/(3.142/180);
}

/**
 * @brief Kalman filter to filterize tha IMU data from any noise
 *
 * @param KalmanState Kalman State
 * @param KalmanUncertainty Kalman Uncertainty
 * @param KalmanInput  Kalman Input
 * @param KalmanMeasurement  Kalman Measurement
*/

void kalman_1d(float KalmanState, float KalmanUncertainty, float KalmanInput, float KalmanMeasurement)
{
	KalmanState=KalmanState+0.004*KalmanInput;
	KalmanUncertainty=KalmanUncertainty + 0.004 * 0.004 * 4 * 4;
	f32 KalmanGain=KalmanUncertainty * 1/(1*KalmanUncertainty + 3 * 3);
	KalmanState=KalmanState+KalmanGain * (KalmanMeasurement-KalmanState);
	KalmanUncertainty=(1-KalmanGain) * KalmanUncertainty;
	Kalman1DOutput[0]=KalmanState;
	Kalman1DOutput[1]=KalmanUncertainty;
}
