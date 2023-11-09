/**
 * @file I2C_Private.h
 * @author GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * @brief The Private file that contains Driver Registers 
 * @version 0.1
 * @date 2023-10-03
 * 
 * @copyright GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * 
*/


#ifndef MCAL_I2C_I2C_PRIVATE_H_
#define MCAL_I2C_I2C_PRIVATE_H_



#define I2C1_BASE_ADDRESS               0x40005400
#define I2C2_BASE_ADDRESS               0x40005800
#define I2C3_BASE_ADDRESS               0x40005C00




/*CR1 Registers*/
#define PE             0
#define SMBUS          1
#define SMBTYPE        3
#define ENARP          4
#define ENPEC          5
#define ENGC           6
#define NOSTRETCH      7
#define START          8
#define STOP           9
#define ACK            10
#define POS            11
#define PEC            12
#define ALERT          13
#define SWRST          15

/*SR1 Registers*/
#define SR1_SB             0
#define SR1_ADDR           1
#define SR1_BTF            2
#define SR1_ADD10          3
#define SR1_STOPF          4
#define SR1_RxNE           6
#define SR1_TxE            7


/**
 * @brief Registers for I2C peripheral
 *
*/


typedef struct
{
	volatile u32     CR1           ;
	volatile u32     CR2           ;
	volatile u32     OAR1          ;
	volatile u32     OAR2          ;
	volatile u32     DR            ;
	volatile u32     SR1           ;
	volatile u32     SR2           ;
	volatile u32     CCR           ;
	volatile u32     TRISE         ;
	volatile u32     FLTR          ;
}I2C_MemMap_t;

#define I2C1        ( (volatile I2C_MemMap_t*) I2C1_BASE_ADDRESS)
#define I2C2        ( (volatile I2C_MemMap_t*) I2C2_BASE_ADDRESS)
#define I2C3        ( (volatile I2C_MemMap_t*) I2C3_BASE_ADDRESS)












#endif /* MCAL_I2C_I2C_PRIVATE_H_ */
