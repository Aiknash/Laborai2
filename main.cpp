#include "stm32f3xx.h"
//uint32_t i;
uint32_t SwitchState;                       //GPIOx_IDR register, how to read ?
uint32_t Mode = 0 ;                         //
int StepsPerRev = 200 ;                // Stepper motor steps per 1 revolution
//--Void--//
void StepperCw (int Steps);
void StepperCcw (int Steps);
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
//-------------------------Void Functions----------------------------------------//
//C:/Users/Airidas/eclipse-workspace/12
void StepperCw (int Steps) {
		for ( int i = 0 ;  i < Steps/4 ; i++ ){

		GPIOD->BRR |= 1 << 1 ;     //Step1
		GPIOD->BRR |= 1 << 2 ;
		GPIOD->BRR |= 1 << 3 ;
		GPIOD->BSRR |= 1 << 4 ;
		HAL_Delay(1/5000);

		GPIOD->BRR |= 1 << 4 ;
		GPIOD->BRR |= 1 << 1 ;     //Step2
		GPIOD->BSRR |= 1 << 2 ;
		GPIOD->BRR |= 1 << 3 ;

		HAL_Delay(1/5000);

		GPIOD->BRR |= 1 << 1 ;     //Step3
		GPIOD->BRR |= 1 << 2 ;
		GPIOD->BSRR |= 1 << 3 ;
		GPIOD->BRR |= 1 << 4 ;
		HAL_Delay(1/5000);


		GPIOD->BRR |= 1 << 2 ;
		GPIOD->BRR |= 1 << 3 ;
		GPIOD->BRR |= 1 << 4 ;
		GPIOD->BSRR |= 1 << 1 ;     //Step4
		HAL_Delay(1/5000);
		}
}
//------------------------------------------------------------------------------//
