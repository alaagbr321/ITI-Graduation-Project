#ifndef BIT_MATH_h
#define BIT_MATH_h


#define SET_BIT(VAR,BIT_NO)     ( VAR |=(1<<BIT_NO))
#define CLR_BIT(VAR,BIT_NO)     ( VAR &=~(1<<BIT_NO))
#define GET_BIT(VAR,BIT_NO)      ((VAR>>BIT_NO)&1)
#define TOGGLE_BIT(VAR,BIT_NO)    (VAR ^=(1<<BIT_NO))



#endif
