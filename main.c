/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#define RCC_BASE 0x40021000
#define GPIOC_BASE 0x40011000
#define RCC_APB2ENR *(volatile uint32_t *)(RCC_BASE + 0x18)
#define GPIOC_CRH *(volatile uint32_t *)(GPIOC_BASE + 0x04)
#define GPIOC_ODR *(volatile uint32_t *)(GPIOC_BASE + 0x0C)

// bit fields
#define RCC_IOPCEN (1<<4)
#define GPIOC13 (1UL<<13)


int main(void)
{
    RCC_APB2ENR |= RCC_IOPCEN;       /* Clock configuration  */
    GPIOC_CRH &= 0xFF0FFFFF;         /* Port configuration   */
    GPIOC_CRH |= 0x00200000;

    while(1)
    {
        GPIOC_ODR |= GPIOC13;        /* GPIOC13 is ON        */
        for (int i = 0; i < 500000; i++); /* arbitrary delay */

        GPIOC_ODR &= ~GPIOC13;       /* GPIOC13 is OFF       */
        for (int i = 0; i < 500000; i++); /* arbitrary delay */
    }
}
