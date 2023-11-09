/**
 * @file RCC_Private.h
 * @author GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * @brief The Private file that contains Driver Registers 
 * @version 0.1
 * @date 2023-9-13
 * 
 * @copyright GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * 
*/

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

#define RCC_BASE_ADDRESS        0x40023800

/* CR BITS  */
#define HSION  0
#define HSEON  16
#define PLLON  24
#define CSSON  19
#define HSEBYP 18

/*CFGR BITS*/
#define SW0		0
#define SW1     1


/**
 * @brief Registers for RCC peripheral
 * 
*/

typedef struct
{
    volatile u32     CR             ;
    volatile u32     PLLCFGR        ;
    volatile u32     CFGR           ;
    volatile u32     CIR            ;
    volatile u32     AHB1RSTR       ;
    volatile u32     AHB2RSTR       ;
    volatile u32     RESERVED1      ;
    volatile u32     RESERVED2      ;
    volatile u32     APB1RSTR       ;
    volatile u32     APB2RSTR       ;
    volatile u32     RESERVED3      ;
    volatile u32     RESERVED4      ;
    volatile u32     AHB1ENR        ;
    volatile u32     AHB2ENR        ;
    volatile u32     RESERVED5      ;
    volatile u32     RESERVED6      ;
    volatile u32     APB1ENR        ;
    volatile u32     APB2ENR        ;
    volatile u32     RESERVED7      ;
    volatile u32     RESERVED8      ;
    volatile u32     AHB1LPENR      ;
    volatile u32     AHB2LPENR      ;
}RCC_MemMap_t;

#define RCC         ((volatile RCC_MemMap_t  *)RCC_BASE_ADDRESS)



#endif /* RCC_PRIVATE_H_ */
