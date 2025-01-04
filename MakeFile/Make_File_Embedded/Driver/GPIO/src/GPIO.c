#include "GPIO.h"


void Clock_Init(void)
{
	/* HSI ON */
	RCC->CR |= (1 << 0);
	/* Clock for GPIOC */
	RCC->APB2ENR |= (1<<4);
}

void myDelay(uint32_t time)
{
	uint32_t i;
	while(time--)
	{
		for(i=0;i<1000;i++);
	}
}

void GPIO_Init(void)
{
	/* Reset port C pin 13 */
	GPIOC->CRH &= ~(0xF<<20);
	/* 11: output mode, max speed 50hz */
	GPIOC->CRH |= (3<<20);
}


