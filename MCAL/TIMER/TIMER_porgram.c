/**
 * @file TIMER_porgram.c
 * @author GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * @brief Program file for the Timer Peripheral
 * @version 0.1
 * @date 2023-10-04
 * 
 * @copyright GP_4M_NC2_Intake3_Adaptive Light Control System_5
 * 
*/

#include"../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_private.h"


/**
 * @brief Initializing function with certain configuration
 * 
*/

void TIMER4_voidInit(void)
{
	// Working on Timer 4    C4

	u32 local_CR1REG = 0 ;
	u32 local_CCMR2REG = 0 ;
	u32 local_CCERREG = 0 ;

	/*pwm1 */   // outputcompare 4
	SET_BIT( local_CCMR2REG , 14 ) ;
	SET_BIT( local_CCMR2REG , 13 ) ;
	CLR_BIT( local_CCMR2REG , 12 ) ;


	/* select c4 */ // output
	CLR_BIT( local_CCMR2REG , 9 ) ;
	CLR_BIT( local_CCMR2REG , 8 ) ;


	/*  output compare 4 preload enable */
	SET_BIT( local_CCMR2REG , 11 );

	TIMER4->TIMER_CCMR2 = local_CCMR2REG;

/* ********************************************************* */


		CLR_BIT( local_CCERREG , 1 ) ;  // COMAPRE1 OUTPUT POLARITY Active high
		TIMER4->TIMER_CCER = local_CCERREG ;


/* ********************************************************* */

	TIMER4->TIMER_PSC = (25 - 1 ); // prescaler to make 1 Mhz
	TIMER4->TIMER_ARR = (20000 - 1 );  //  making frequnecy 1 MHZ / 20000 = 50hz

/* ******************************************************** */

	SET_BIT( local_CR1REG , 7 ) ;     // ARR auto reload preload

	/*Edge alinged mode    depend on DIR BIT*/
	CLR_BIT( local_CR1REG , 6 ) ;
	CLR_BIT( local_CR1REG , 5 ) ;

	CLR_BIT( local_CR1REG , 4 ) ;     // upcounter

	TIMER4->TIMER_CR1 = local_CR1REG;

/*************************************************/
	TIMER4->TIMER_CCER |= (1 << 12 ); // enable compare c4
    TIMER4->TIMER_CR1  |= (1 << 0 )  ; // enable the counter

}

/**
 * @brief Function for Setting compare value for the timer
 * 
 * @param CopyCompareValue the compare value to be set
*/

void TIMER4_u16SetCompareValue(u16 CopyCompareValue )
{

	TIMER4->TIMER_CCR4 = CopyCompareValue ;
}
