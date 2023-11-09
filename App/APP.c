/**
 * @file APP.c
 * @author GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * @brief Application Program File
 * @version 0.1
 * @date 2023-11-05
 *
 * @copyright GP_4M_NC2_Intake3_Adaptive Light Control System_5
 *
*/

#include "cmsis_os.h"

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"


#include "../MCAL/RCC/RCC_Interface.h"
#include "../MCAL/GPIO/GPIO_Interface.h"
#include "../MCAL/I2C/I2C_Interface.h"

#include "../HAL/IMU/IMU_Interface.h"
#include "../HAL/SERVO/SERVO_interface.h"
#include "../HAL/BH1750/BH1750_interface.h"
#include "../HAL/DotMatrix/DotMatrix_Interface.h"

#include "APP.h"


u8 Day[]={0, 0, 0, 0, 0, 0, 0, 0};
u8 Night[]={255, 255, 255, 255, 255, 255, 255, 255};
u8 Right_close[]={31, 31, 31, 31, 31, 31, 31, 31};
u8 Right_far[]={63, 63, 63, 63, 63, 63, 63, 63};
u8 Left_close[] ={248, 248, 248, 248, 248, 248, 248, 248};
u8 Left_far[] ={252, 252, 252, 252, 252, 252, 252, 252};



f32 RateRoll, RatePitch, RateYaw;
f32 RateCalibrationRoll, RateCalibrationPitch, RateCalibrationYaw;
u32 RateCalibrationNumber;
f32 AngleRoll, AnglePitch;
f32 Kalman1DOutput[2]={0,0};
f32 KalmanAngleRoll=0, KalmanUncertaintyAngleRoll=2*2;
f32 KalmanAnglePitch=0, KalmanUncertaintyAnglePitch=2*2;
u32 ElapsedTime;

u16 Light_SensorL;
u16 Light_SensorR;


/* Private variables ---------------------------------------------------------*/
osThreadId Read_IMU_TaskHandle;
osThreadId Read_LightSensoHandle;
osThreadId LedMatrix_TaskHandle;
osThreadId MoveServo_TaskHandle;



/* Private function prototypes -----------------------------------------------*/
void IMU_Read_Task(void const * argument);
void Read_Light_Task(void const * argument);
void LedMatrix_Display_Task(void const * argument);

/**
 * @brief Function to initialize the system.
 *
 */

void App_voidInit(void)
{

	/* Create the thread(s) */
	/* definition and creation of Read_IMU_Task */

	osThreadDef(Read_IMU_Task, IMU_Read_Task, osPriorityHigh, 0, 128);
	Read_IMU_TaskHandle = osThreadCreate(osThread(Read_IMU_Task), NULL);

	/* definition and creation of Read_LightSenso */
	osThreadDef(Read_LightSenso, Read_Light_Task, osPriorityAboveNormal, 0, 128);
	Read_LightSensoHandle = osThreadCreate(osThread(Read_LightSenso), NULL);

	/* definition and creation of LedMatrix_Task */
	osThreadDef(LedMatrix_Task, LedMatrix_Display_Task, osPriorityRealtime, 0, 128);
	LedMatrix_TaskHandle = osThreadCreate(osThread(LedMatrix_Task), NULL);


	RCC_voidInit ();

	RCC_voidEnablePeripheralClock(RCC_AHB1,RCC_AHB1_GPIOA);
	RCC_voidEnablePeripheralClock(RCC_AHB1,RCC_AHB1_GPIOB);
	RCC_voidEnablePeripheralClock(RCC_APB1,RCC_APB1_I2C1);
	RCC_voidEnablePeripheralClock(RCC_APB1, RCC_APB1_TIMER4);

	I2C_Init();
	MPU6050_Init ();
	BH1750_Init(0x23);
	BH1750_Init(0x5C);
	SERVO_voidInit();
	DotMatrix_voidInit();

	for (RateCalibrationNumber=0; RateCalibrationNumber<2000; RateCalibrationNumber ++)
	{
		MPU6050_Read_Accel ();
		RateCalibrationRoll+=RateRoll;
		RateCalibrationPitch+=RatePitch;
		RateCalibrationYaw+=RateYaw;
	}
	RateCalibrationRoll/=2000;
	RateCalibrationPitch/=2000;
	RateCalibrationYaw/=2000;
}

/**
 * @brief Function to start the scheduler.
 *
 */

void App_voidStart(void)
{

	/* Start scheduler */
	osKernelStart();
}


/**
 * @brief Function implementing the IMU_Read_Task thread.
 * @param argument: Not used
 * @retval None
 */

void IMU_Read_Task(void const * argument)
{
	for(;;)
	{
		s16 reading=KalmanAnglePitch;

		MPU6050_Read_Accel ();
		RateRoll-=RateCalibrationRoll;
		RatePitch-=RateCalibrationPitch;
		RateYaw-=RateCalibrationYaw;
		kalman_1d(KalmanAngleRoll, KalmanUncertaintyAngleRoll, RateRoll, AngleRoll);
		KalmanAngleRoll=Kalman1DOutput[0];
		KalmanUncertaintyAngleRoll=Kalman1DOutput[1];
		kalman_1d(KalmanAnglePitch, KalmanUncertaintyAnglePitch, RatePitch, AnglePitch);
		KalmanAnglePitch=Kalman1DOutput[0];
		KalmanUncertaintyAnglePitch=Kalman1DOutput[1];
		if(reading<-30)
		{
			reading=-30;
		}
		else if(reading >30)
		{
			reading=30;
		}
		SERVO_u8SendAngle(reading);
		osDelay(10);
	}
}

/**
 * @brief Function implementing the Read_LightSenso thread.
 * @param argument: Not used
 * @retval None
 */


void Read_Light_Task(void const * argument)
{
	/* USER CODE BEGIN Read_Light_Task */
	/* Infinite loop */
	for(;;)
	{
		Light_SensorR = BH1750_Read(0x23);
		osDelay(10);

		Light_SensorL= BH1750_Read(0x5C);
		osDelay(50);
	}
}


/**
 * @brief Function implementing the LedMatrix_Task thread.
 * @param argument: Not used
 * @retval None
*/

void LedMatrix_Display_Task(void const * argument)
{
	for(;;)
	{
		if(Light_SensorR <= 100 && Light_SensorL <= 100 )
		{
			DotMatrix_voidSendData(Night);
		}
		else if( Light_SensorR >= 3000 && Light_SensorL >= 3000)
		{
			DotMatrix_voidSendData(Day);
		}
		else if ((Light_SensorR > Light_SensorL) && (Light_SensorR>100 && Light_SensorR < 1000) )
		{
			DotMatrix_voidSendData(Right_far);
		}
		else if ((Light_SensorL > Light_SensorR) && ( Light_SensorL > 100 && Light_SensorL < 1000) )
		{
			DotMatrix_voidSendData(Left_far);
		}
		else if ((Light_SensorR > Light_SensorL) && ( Light_SensorR >= 1000 && Light_SensorR < 65000) )
		{
			DotMatrix_voidSendData(Right_close);
		}
		else if ((Light_SensorL > Light_SensorR) && ( Light_SensorL >= 1000 && Light_SensorL < 65000) )
		{
			DotMatrix_voidSendData(Left_close);
		}
		else
		{
			DotMatrix_voidSendData(Day);
		}

		osDelay(3);
	}
}


