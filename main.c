#include <stdint.h>
#include <Headers.h>

int main(void)
{
	configRegister();
	int send_one = 0;
	int send_zero = 0;
	while(1)
	{
		/*Transmission Area*/
		if (send_one == 1)
		{
			/*Write 1 to TX register*/
		}
		if (send_zero == 1)
		{
			/*Write 0 to TX register*/
		}
		
		
		/*Recieve Area*/
		
		
		
	}
}
 

void configRegister(){
	/*RCC_ENABLES*/
	 uint32_t *rccAPB2ADDRESS = (uint32_t*)(RCC_BASE_ADDRESS + APB2ENR);
	*rccAPB2ADDRESS = 0x00004014;
	
	/*GPIOA Enable(TX+RX USART1)*/
	uint32_t *gpioaCrhADDRESS = (uint32_t*)(GPIOA_BASE_ADDRESS + CRH);
	*gpioaCrhADDRESS = 0x888444d4;
	
	/*GPIOC PC13 Enable*/
	uint32_t *gpiocCrhADDRESS = (uint32_t*)(GPIOC_BASE_ADDRESS + CRH);
	*gpiocCrhADDRESS = 0x44544444;
	
	/*USART1 Enable*/
	uint32_t *usart1Cr1ADDRESS = (uint32_t*)(USART1BASE + CR1);
	*usart1Cr1ADDRESS = 0x0000300C;
	
	
	
	
}
