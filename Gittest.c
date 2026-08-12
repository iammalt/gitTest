#include "stm32f10x.h"

int main(void)
{
    unsigned char checkb=10;
    /* Enable clock for GPIOC */
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;

    /* Configure PC13 as push-pull output, max speed 10 MHz */
    GPIOC->CRH &= ~(GPIO_CRH_MODE13 | GPIO_CRH_CNF13);
    GPIOC->CRH |= GPIO_CRH_MODE13_0;

        /* Configure PA11 as push-pull output, max speed 10 MHz */
    GPIOA->CRH &= ~(GPIO_CRH_MODE11 | GPIO_CRH_CNF11);
    GPIOA->CRH |= GPIO_CRH_MODE11_0;

            /* Configure PB05 as push-pull output, max speed 10 MHz */
    GPIOB->CRH &= ~(GPIO_CRH_MODE05 | GPIO_CRH_CNF05);
    GPIOB->CRH |= GPIO_CRH_MODE05_0;

    while (1)
    {
        /* Toggle PC13 */
        GPIOC->ODR ^= GPIO_ODR_ODR13;

        /* Simple delay */
        for (volatile int i = 0; i < 500000; i++)
        {

        }
         /* Toggle PA11 */
        GPIOA->ODR ^= GPIO_ODR_ODR11;
         /* Toggle PB05 */
        GPIOB->ODR ^= GPIO_ODR_ODR05;
    }
}
