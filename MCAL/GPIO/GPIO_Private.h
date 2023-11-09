/**
 * @file GPIO_Private.h
 * @author GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * @brief The Private file that contains Driver Registers 
 * @version 0.1
 * @date 2023-9-15
 * 
 * @copyright GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * 
*/

#ifndef MCAL_GPIO_GPIO_PRIVATE_H_
#define MCAL_GPIO_GPIO_PRIVATE_H_


#define GPIOA_BASE_ADDRESS	0x40020000
#define GPIOB_BASE_ADDRESS  0x40020400
#define GPIOC_BASE_ADDRESS  0x40020800


/**
 * @brief Registers for GPIO peripheral
 * 
*/

typedef struct
{
	volatile u32     MODER              ;
	volatile u32     OTYPER             ;
	volatile u32     OSPEEDR            ;
	volatile u32     PUPDR              ;
	volatile u32     IDR       	        ;
	volatile u32     ODR                ;
	volatile u32     BSRR       	    ;
	volatile u32     LCKR               ;
	volatile u32     AFRL               ;
	volatile u32     AFRH               ;

}GPIO_MemMap_t;

#define GPIOA         ((volatile GPIO_MemMap_t  *)GPIOA_BASE_ADDRESS)
#define GPIOB		  ((volatile GPIO_MemMap_t  *)GPIOB_BASE_ADDRESS)
#define GPIOC		  ((volatile GPIO_MemMap_t  *)GPIOC_BASE_ADDRESS)

#endif /* MCAL_GPIO_GPIO_PRIVATE_H_ */
