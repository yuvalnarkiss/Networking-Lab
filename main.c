#include <stdint.h>

void configRegister(){
	/*RCC_ENABLES*/
	rccAHBADDRESS = (uint32_t*)(RCC_BASE_ADDRESS + AHBENR)
	*rccAHBADDRESS = *rccAHBADDRESS | 0x11
		
	rccAPB2ADDRESS = (uint32_t*)(RCC_BASE_ADDRESS + APB2ENR)
	*rccAPB2ADDRESS = (rccAPB2ADDRESS | (0x4010))
	
	/*GPIOC PC13 Enable*/
	gpiocCrhADDRESS = (uinut32_t*)(GPIOC_BASE_ADDRESS + CRH)
	*gpiocCrhADDRESS = 0x100000
	
	
	
	
}



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
 



