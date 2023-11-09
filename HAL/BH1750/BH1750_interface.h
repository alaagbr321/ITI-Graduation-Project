/**
 * @file  Intensity Sensor BH1750_interface.h
 * @author GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * @brief  Interface file for Functions Prototype and needed macros or enums
 * @version 0.1
 * @date 2023-10-10
 *
 * @copyright GP_4M_NC2_Intake3_Adaptive Light Control System_5
 *
*/

#ifndef COTS_HAL_BH1750_BH1750_INTERFACE_H_
#define COTS_HAL_BH1750_BH1750_INTERFACE_H_


#define BH1750_PowerOff     0x00
#define BH1750_PowerOn      0x01
#define BH1750_RESET        0x07
#define BH1750_CONT_HRES    0x10
#define BH1750_CONT_HRES2   0x11
#define BH1750_CONT_LRES    0x13
#define BH1750_ONE_HRES     0x20
#define BH1750_ONE_HRES2    0x21
#define BH1750_ONE_LRES     0x23

/**
 * @brief Function to initialize the intensity sensor
 * @details Function to initialize the I2C communication between Sensor and microcontroller
 * @param Address Address of the Sensor
*/
void BH1750_Init(u8 Address);

/**
 * @brief  Function to read the intenisty value from the sensor
 *
 * @param Address  Address of the sensor
 * @return u16 The light intensity value
*/

u16 BH1750_Read(u8 Address);


#endif /* COTS_HAL_BH1750_BH1750_INTERFACE_H_ */
