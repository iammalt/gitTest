#include "stm32f10x.h"
#include "GitBranch.h"

int main(void)
{
    unsigned int mclock=0;
    unsigned int mtime=0;

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

    /* Enable clock for GPIOD */
    RCC->APB2ENR |= RCC_APB2ENR_IOPDEN;

    /* Configure PD5 as input pull-up */
    GPIOD->CRL &= ~(GPIO_CRL_MODE5 | GPIO_CRL_CNF5);
    GPIOD->CRL |= GPIO_CRL_CNF5_1;
    GPIOD->ODR |= GPIO_ODR_ODR5;

    while (1)
    {
        /* Toggle PC13 */
        GPIOC->ODR ^= GPIO_ODR_ODR13;

        /* Simple delay */
        for (volatile int i = 0; i < 500000; i++)
        {
            mclock++;
            if (mclock >= 100)
            {
                mtime ++;
                if(mtime >= 1000)
                {
                    mtime = 0;
                }
            }
        }

        /* Toggle PA11 and PB05 when PD5 key is pressed */
        if (!(GPIOD->IDR & GPIO_IDR_IDR5))
        {
            GPIOA->ODR ^= GPIO_ODR_ODR11;
            GPIOB->ODR ^= GPIO_ODR_ODR05;
        }
    }
}
