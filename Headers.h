#define GPIOA_BASE_ADDRESS    0x40010800
#define GPIOC_BASE_ADDRESS    0x40011000
#define CRH                   0x04
#define RCC_BASE_ADDRESS      0x40021000
#define APB2ENR               0x18
#define USART1BASE            0x40013800
#define CR1                   0x0C
#define CR2                   0x10
#define CR3                   0x14
#define USART1BASE_CR1        (USART1BASE + CR1)


void configRegister();
