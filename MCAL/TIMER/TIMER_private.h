/**
 * @file TIMER_private.h
 * @author GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * @brief The Private file that contains Driver Registers 
 * @version 0.1
 * @date 2023-10-04
 * 
 * @copyright GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * 
*/

#ifndef MCAL_TIMER_TIMER_PRIVATE_H_
#define MCAL_TIMER_TIMER_PRIVATE_H_

#define TIMER5_BASE_ADDRESS             0x40000C00
#define TIMER4_BASE_ADDRESS             0x40000800
#define TIMER3_BASE_ADDRESS             0x40000400
#define TIMER2_BASE_ADDRESS             0x40000000


/**
 * @brief Registers for Timer peripheral
 * 
*/

typedef struct
{
	volatile u32 TIMER_CR1;
	volatile u32 TIMER_CR2;
	volatile u32 TIMER_SMCR;
	volatile u32 TIMER_DIER;
	volatile u32 TIMER_SR;
	volatile u32 TIMER_EGR;
	volatile u32 TIMER_CCMR1;
	volatile u32 TIMER_CCMR2;
	volatile u32 TIMER_CCER;
	volatile u32 TIMER_CNT;
	volatile u32 TIMER_PSC;
	volatile u32 TIMER_ARR;
	volatile u32 TIMER_NOTUSED;
	volatile u32 TIMER_CCR1;
	volatile u32 TIMER_CCR2;
	volatile u32 TIMER_CCR3;
	volatile u32 TIMER_CCR4;
	volatile u32 TIMER_NOTUSED2;
	volatile u32 TIMER_DCR;
	volatile u32 TIMER_DMAR;
	volatile u32 TIMER_OR;
}TIMER_MemMap_t;

#define TIMER5         ((volatile TIMER_MemMap_t*)  TIMER5_BASE_ADDRESS)
#define TIMER4         ((volatile TIMER_MemMap_t*)  TIMER4_BASE_ADDRESS)
#define TIMER3         ((volatile TIMER_MemMap_t*)  TIMER3_BASE_ADDRESS)
#define TIMER2         ((volatile TIMER_MemMap_t*)  TIMER2_BASE_ADDRESS)


#endif /* MCAL_TIMER_TIMER_PRIVATE_H_ */
