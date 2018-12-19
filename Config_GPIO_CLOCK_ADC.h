//         ---------------
//     /|\|               |
//      | |               |
//      --|RST            |
//        |               |
//        |               |
//        |           P4.2|---> ACLK = ~32kHz
//        |           P4.3|---> MCLK = SMCLK = default DCO = ~12MHz
//        |_______________|

//#include "msp.h"
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

#include"global_variables.h"
void clock_setting(void);
void gpio_config(void);
void ADC_config_ch9_ch11_ch13(void);
void UART_config_bluetoorh(void);

void clock_setting(void)
{
       // Unlock CS module for register access
       CS->KEY  = CS_KEY_VAL;
       // Reset tuning parameters
       CS->CTL0 = 0;
       // Set DCO to 12MHz (nominal, center of 8-16MHz range)
       CS->CTL0 = CS_CTL0_DCORSEL_4;  //CS_CTL0_DCORSEL_3;
       // Select ACLK = REFO, SMCLK = MCLK = DCO
       CS->CTL1 = CS_CTL1_SELA_2 | CS_CTL1_SELS_3| CS_CTL1_SELM_3;// CS_CTL1_SELS_3
       // Lock CS module from unintended accesses
       CS->KEY = 0;
}


void gpio_config(void)
{

       // turn off battery charging as mains available
        P3->DIR |= BIT6;           //
        P3->OUT |= 0X40;


       // 1.7 SCL, 1.6 SDA  for OLED interfacing
       // Assign I2C pins to SCL/SDA
       P1SEL0 |=   BIT6 | BIT7;
       // Selection mode P1SEL1=0 and P1SEL0=1 for UCS_B0_I2C
       P1SEL1 &= ~(BIT6 | BIT7);


}








void enable_IRQ(void)
{
    // Enable global interrupt
        __enable_irq();




        NVIC->ISER[0] |= 1 << ((T32_INT1_IRQn) & 31); //timer

        NVIC->ISER[0] |= 1 << ((T32_INT2_IRQn) & 31); //timer
}
