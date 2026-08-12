#include "stm32f10x.h"

int main(void)
{
    /* Enable clock for GPIOC */
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;

    /* Configure PC13 as push-pull output, max speed 10 MHz */
    GPIOC->CRH &= ~(GPIO_CRH_MODE13 | GPIO_CRH_CNF13);
    GPIOC->CRH |= GPIO_CRH_MODE13_0;

    while (1)
    {
        /* Toggle PC13 */
        GPIOC->ODR ^= GPIO_ODR_ODR13;

        /* Simple delay */
        for (volatile int i = 0; i < 500000; i++)
        {
            
        }
    }
}
