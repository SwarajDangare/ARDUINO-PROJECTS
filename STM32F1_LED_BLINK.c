#include "stm32f10x.h"


int main()
{
    RCC ->APB2ENR |=(1<<4);                // initialise the clock for GPIO C

    GPIOC ->CRH |= ( (1<<20)| (1<<21));    //SET MODE TO 1:1 i.e OUTPUT AT 50MHZ
    GPIOC ->CRH &= ~( (1<<22)|(1<<23));    //SET THE BIT TO GENARAL PURPOSE OUTPUT
	
    while (1)
    {
    	
    	GPIOC->BSRR = (1<<13);               //LED OFF
			for(int i=0 ; i<=1000000000 ; i++);
    	
    	GPIOC->BSRR = (1<<(13+16));          //LED ON   //AS PIN 13 IS ACTIVE LOW WE NEED TO PUT THE PIN TO LOW
			for(int i=0 ; i<=1000000000 ; i++);
			
    }


}


