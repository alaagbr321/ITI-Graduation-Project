/**
 * @file I2C_Interface.h
 * @author GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * @brief Interface file for Functions Prototypes and needed Macros or enums
 * @version 0.1
 * @date 2023-10-03
 * 
 * @copyright GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * 
*/

#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

/**
 * @brief Configuring:
 * 1- Clock frequancy for the peripheral
 * 2- CCR Time 
 * 3- Rise Time 
 * 
*/

#define I2C_CLK         25
#define CCR_Time        125
#define Rise_Time       26 


/**
 * @brief Configuration and Initialization For I2C 
 * 
*/

void I2C_Init (void);

/**
 * @brief A function for Generating A start condition to start the data transformation
 * 
*/

void I2C_Start (void);

/**
 * @brief A function for writing Data to be transfered from master to slave 
 * 
 * @param data the data the master transfer to slave
*/

void I2C_Write (u8 data);

/**
 * @brief A function tp Send Slave address 
 * 
 * @param Address Slave address
*/

void I2C_Address (u8 Address);

/**
 * @brief A function to generate a stop condition to end data transmission
 * 
*/

void I2C_Stop (void);

/**
 * @brief  A function to transmit multiple data to slave
 * 
 * @param data data array or buffer
 * @param size size of data to be sent to slave
*/

void I2C_WriteMulti (u8 *data, u8 size);

/**
 * @brief A function to read data from slave
 * 
 * @param Address slave Address
 * @param buffer buffer to store data from slave
 * @param size the size of buffer that stores data
*/

void I2C_Read (u8 Address, u8 *buffer, u8 size);

#endif
