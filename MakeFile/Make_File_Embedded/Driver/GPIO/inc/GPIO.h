
#ifndef _SUM_H
#define _SUM_H

#include <stdint.h>

/*!< Peripheral memory map */
/*!< Peripheral base address in the alias region */
#define PERIPH_BASE 	0x40000000UL
#define APB1PERIPH_BASE PERIPH_BASE
#define APB2PERIPH_BASE (PERIPH_BASE + 0x10000UL)
#define AHBPERIPH_BASE 	(PERIPH_BASE + 0x18000UL)

/*!< APB2 peripherals */
#define GPIOA_BASE		(APB2PERIPH_BASE + 0x0800UL)
#define GPIOB_BASE		(APB2PERIPH_BASE + 0x0C00UL)
#define GPIOC_BASE		(APB2PERIPH_BASE + 0x1000UL)
#define GPIOD_BASE		(APB2PERIPH_BASE + 0x1400UL)
#define GPIOE_BASE		(APB2PERIPH_BASE + 0x1800UL)
#define GPIOF_BASE		(APB2PERIPH_BASE + 0x1C00UL)
#define GPIOG_BASE		(APB2PERIPH_BASE + 0x2000UL)

/*!< AHB peripherals */
#define RCC_BASE 		(AHBPERIPH_BASE + 0x9000UL)

/* Clock register offset */
typedef struct
{
	volatile uint32_t CR;
	uint32_t RV1[4];
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	uint32_t RV2[2];
} RCC_OFF;

#define RCC ((RCC_OFF *) RCC_BASE)

/* GPIO */
typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
} GPIO_OFF;

void Clock_Init(void);
void myDelay(uint32_t time);
void GPIO_Init(void);

#define GPIOC ((GPIO_OFF *) GPIOC_BASE)

#endif
