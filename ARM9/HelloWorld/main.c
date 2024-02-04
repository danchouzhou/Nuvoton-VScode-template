/**************************************************************************//**
 * @file     main.c
 * @brief    Software Development Template.
 *
 * @copyright (C) 2018 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#include "nuc980.h"
#include "sys.h"
#include <stdio.h>
#include "gpio.h"

void UART_Init()
{
    /* enable UART0 clock */
    outpw(REG_CLK_PCLKEN0, inpw(REG_CLK_PCLKEN0) | 0x10000);

    /* GPF11, GPF12 */
    outpw(REG_SYS_GPF_MFPH, (inpw(REG_SYS_GPF_MFPH) & 0xfff00fff) | 0x11000);   // UART0 multi-function

    /* UART0 line configuration for (115200,n,8,1) */
    outpw(REG_UART0_LCR, inpw(REG_UART0_LCR) | 0x07);
    outpw(REG_UART0_BAUD, 0x30000066); /* 12MHz reference clock input, 115200 */
}

/*---------------------------------------------------------------------------------------------------------*/
/*  Main Function                                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
int32_t main(void)
{
    int8_t ch;

    outpw(REG_CLK_HCLKEN, inpw(REG_CLK_HCLKEN)|(1<<11)); //Enable GPIO engine
    sysDisableCache();
    sysFlushCache(I_D_CACHE);
    sysEnableCache(CACHE_WRITE_BACK);
    UART_Init();

    printf("Simple Demo Code\n\n");

    /* Get address of the PG7 PDIO register */
    volatile uint32_t *u32PG7Ptr = (volatile uint32_t *)((GPIO_PIN_DATA_BASE+(0x40*(6))) + ((7)<<2));

    GPIO_SetMode(PG, BIT7, GPIO_MODE_OUTPUT);

    while(1)
    {
        *u32PG7Ptr=1;
        *u32PG7Ptr=0;
    }


    // printf("Please Input Any Key\n\n");

    // do
    // {
    //     printf("Input: ");
    //     ch = getchar();
    //     printf("%c\n", ch);
    // }
    // while(1);

}
