#include <stdint.h>
#include <Headers.h>

int main(void)
{
	configRegister();
	int send_one = 0;
	int send_zero = 0;
	uint32_t *usart1SrADDRESS = (uint32_t*)(USART1BASE);
	uint32_t *usart1DrADDRESS = (uint32_t*)(USART1BASE + DR);
	uint32_t *gpiocCrhADDRESS = (uint32_t*)(GPIOC_BASE_ADDRESS + CRH);
	uint32_t TXEFLAG = *usart1SrADDRESS & 0x80; //Indicates if the data has finished to transmit(TXE)
	uint32_t RXNEFLAG = *usart1SrADDRESS & 0x20;
	uint32_t DataRecieved;
	
	while(1)
	{
		/*Transmission Area*/
		if (send_one == 1)
		{
			/*Write 1 to TX register*/
			*usart1DrADDRESS = 0x31;
			while(TXEFLAG == 0) TXEFLAG = *usart1SrADDRESS & 0x80; //wait untill data transmission complete
		}
		if (send_zero == 1)
		{
			/*Write 0 to TX register*/
			*usart1DrADDRESS = 0x30;
			while(TXEFLAG == 0) TXEFLAG = *usart1SrADDRESS & 0x80; //wait untill data transmission complete
		}
		
		/*Recieve Area*/ 
		if(*usart1DrADDRESS != 0)
		{
			DataRecieved = *usart1DrADDRESS;
			if(DataRecieved == 0x30) // this means that we recieved '0' and we need to turn OFF the LED
			{
				*gpiocCrhADDRESS = 0x44444444; //Turns OFF LED
				*usart1DrADDRESS = 0x0;
			}
			else // this means that we recieved '1' and we need to turn ON the LED
			{
				*gpiocCrhADDRESS = 0x44544444; //Turns ON LED
				*usart1DrADDRESS = 0x0;
			}
		}
	}
}
 

void configRegister(){
	/*RCC_ENABLES*/
	 uint32_t *rccAPB2ADDRESS = (uint32_t*)(RCC_BASE_ADDRESS + APB2ENR);
	*rccAPB2ADDRESS = 0x00004014;
	
	/*GPIOA Enable(TX+RX USART1)*/
	uint32_t *gpioaCrhADDRESS = (uint32_t*)(GPIOA_BASE_ADDRESS + CRH);
	*gpioaCrhADDRESS = 0x88844494;
	
	/*USART1 Enable*/
	uint32_t *usart1Cr1ADDRESS = (uint32_t*)(USART1BASE + CR1);
 *usart1Cr1ADDRESS = 0x0000200C;
	uint32_t *usart1BrrADDRESS = (uint32_t*) (USART1BASE + BRR); //Baud Configuration
 *usart1BrrADDRESS = 0x683;
	
	
	
	
	
	
	
}
