
//define examples.


#define PERIPH_BASE           ((uint32_t)0x40000000) /*!< Peripheral base address in the alias region */

#define APB1PERIPH_BASE       PERIPH_BASE

#define TIM2_BASE             (APB1PERIPH_BASE + 0x0000)
#define TIM3_BASE             (APB1PERIPH_BASE + 0x0400)
#define TIM4_BASE             (APB1PERIPH_BASE + 0x0800)

//configuration offset
#define TIM_CR1_CEN			  (0x00000001)   // enable bit in CR1 register of all timers

#define TIM_ENABLE(__TIM__)   ((__TIM__)->CR1|=(TIM_CR1_CEN)) // enable timer __TIM__.


#define __IO volatile

typedef struct
{
  __IO uint32_t CR1;             /*!< TIM control register 1,                      Address offset: 0x00 */
  __IO uint32_t CR2;             /*!< TIM control register 2,                      Address offset: 0x04 */
  __IO uint32_t SMCR;            /*!< TIM slave Mode Control register,             Address offset: 0x08 */
  __IO uint32_t DIER;            /*!< TIM DMA/interrupt enable register,           Address offset: 0x0C */
  __IO uint32_t SR;              /*!< TIM status register,                         Address offset: 0x10 */
  __IO uint32_t EGR;             /*!< TIM event generation register,               Address offset: 0x14 */
  __IO uint32_t CCMR1;           /*!< TIM  capture/compare mode register 1,        Address offset: 0x18 */
  __IO uint32_t CCMR2;           /*!< TIM  capture/compare mode register 2,        Address offset: 0x1C */
  __IO uint32_t CCER;            /*!< TIM capture/compare enable register,         Address offset: 0x20 */
  __IO uint32_t CNT;             /*!< TIM counter register,                        Address offset: 0x24 */
  __IO uint32_t PSC;             /*!< TIM prescaler register,                      Address offset: 0x28 */
  __IO uint32_t ARR;             /*!< TIM auto-reload register,                    Address offset: 0x2C */
  __IO uint32_t RCR;             /*!< TIM  repetition counter register,            Address offset: 0x30 */
  __IO uint32_t CCR1;            /*!< TIM capture/compare register 1,              Address offset: 0x34 */
  __IO uint32_t CCR2;            /*!< TIM capture/compare register 2,              Address offset: 0x38 */
  __IO uint32_t CCR3;            /*!< TIM capture/compare register 3,              Address offset: 0x3C */
  __IO uint32_t CCR4;            /*!< TIM capture/compare register 4,              Address offset: 0x40 */
  __IO uint32_t BDTR;            /*!< TIM break and dead-time register,            Address offset: 0x44 */
  __IO uint32_t DCR;             /*!< TIM DMA control register,                    Address offset: 0x48 */
  __IO uint32_t DMAR;            /*!< TIM DMA address for full transfer register,  Address offset: 0x4C */
  __IO uint32_t OR;              /*!< TIM option register,                         Address offset: 0x50 */
} TIM_TypeDef;

// then you can do: TIM_TypeDef* tim2 = ((TIM_TypeDef*)TIM2_BASE);
// tim2->CR1 &= SOME_CONFIGURATION;
// or use TIM_ENABLE(tim2); // to enable it.