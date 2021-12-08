#include "stm32f3xx.h"
//uint32_t i;
uint32_t SwitchState;                       //GPIOx_IDR register, how to read ?
uint32_t Mode = 0 ;                         //
int StepsPerRev = 200 ;                // Stepper motor steps per 1 revolution
//--Void--//
//------------------------------------//
int main (void)
{
	//----------Clocks----------------//
	RCC->AHBENR |= RCC_AHBENR_GPIOEEN;
	RCC->AHBENR |= RCC_AHBENR_GPIODEN;
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

	//------------------I/O Setup-----------------------//
	//------------------   |= OR    ------------------------//
	GPIOA->MODER |= GPIO_MODER_MODER0_1;    //32bit MODER register PE8 Pin=Input

	GPIOE->MODER |= GPIO_MODER_MODER8_0;    //32bit MODER register Pin=Output
	GPIOE->MODER |= GPIO_MODER_MODER9_0;    //32bit MODER register Pin=Output
	GPIOE->MODER |= GPIO_MODER_MODER10_0;    //32bit MODER register Pin=Output
	GPIOE->MODER |= GPIO_MODER_MODER11_0;    //32bit MODER register Pin=Output
	GPIOE->MODER |= GPIO_MODER_MODER12_0;    //32bit MODER register Pin=Output
	GPIOE->MODER |= GPIO_MODER_MODER13_0;    //32bit MODER register Pin=Output
	GPIOE->MODER |= GPIO_MODER_MODER14_0;    //32bit MODER register Pin=Output
	GPIOE->MODER |= GPIO_MODER_MODER15_0;    //32bit MODER register Pin=Output

	while(1)
	{
		//--------------------------------------------------------------------------------//
		if ( GPIOA->IDR & GPIO_PIN_0 ) {
			GPIOE->BSRR = 1 << (8+16) ;
			GPIOE->BSRR = 1 << (12+16) ;
			GPIOE->BSRR = 1 << 11 ;
			GPIOE->BSRR = 1 << 15 ;
			HAL_Delay(100);
			GPIOE->BSRR = 1 << 11+16 ;
			GPIOE->BSRR = 1 << 15+16 ;
			GPIOE->BSRR = 1 << 10 ;
			GPIOE->BSRR = 1 << 14 ;
			HAL_Delay(100);
			GPIOE->BSRR = 1 << (10+16) ;
			GPIOE->BSRR = 1 << (14+16) ;
			GPIOE->BSRR = 1 << 9 ;
			GPIOE->BSRR = 1 << 13 ;
			HAL_Delay(100);
			GPIOE->BSRR = 1 << (9+16) ;
			GPIOE->BSRR = 1 << (13+16) ;
			GPIOE->BSRR = 1 << 8 ;
			GPIOE->BSRR = 1 << 12 ;
			HAL_Delay(100);
		}
		else {
			HAL_Delay(50);
			GPIOE->BSRR = 1 << 8 ;
			GPIOE->BSRR = 1 << 12 ;
			HAL_Delay(100);
			GPIOE->BSRR = 1 << (8+16) ;
			GPIOE->BSRR = 1 << (12+16) ;
			GPIOE->BSRR = 1 << 9 ;
			GPIOE->BSRR = 1 << 13 ;
			HAL_Delay(100);
			GPIOE->BSRR = 1 << (9+16) ;
			GPIOE->BSRR = 1 << (13+16) ;
			GPIOE->BSRR = 1 << 10 ;
			GPIOE->BSRR = 1 << 14 ;
			HAL_Delay(100);
			GPIOE->BSRR = 1 << (10+16) ;
			GPIOE->BSRR = 1 << (14+16) ;
			GPIOE->BSRR = 1 << 11 ;
			GPIOE->BSRR = 1 << 15 ;
			HAL_Delay(100);
			GPIOE->BSRR = 1 << (11+16) ;
			GPIOE->BSRR = 1 << (15+16) ;
		}

	}

	}
//------------------------------------------------------------------------------//
