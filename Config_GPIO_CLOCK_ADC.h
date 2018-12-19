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



void ADC_config_ch9_ch11_ch13(void)
{

     // Turn on ADC14, extend sampling time to avoid overflow of results
       ADC14->CTL0 = ADC14_CTL0_ON |ADC14_CTL0_MSC|ADC14_CTL0_SHT1__192 |ADC14_CTL0_SHP |ADC14_CTL0_CONSEQ_1;

       ADC14->MCTL[9]  = ADC14_MCTLN_INCH_9;                    // ref+=AVcc, channel = A9
       ADC14->MCTL[11] = ADC14_MCTLN_INCH_11;                   // ref+=AVcc, channel = A11
       ADC14->MCTL[13] = ADC14_MCTLN_INCH_13|ADC14_MCTLN_EOS;   // ref+=AVcc, channel = A13, end seq.
       // Enable ADC14IFG.3
       ADC14->IER0 |= ADC14_IER0_IE9;
       ADC14->IER0 |= ADC14_IER0_IE11;
       ADC14->IER0 |= ADC14_IER0_IE13;
       // Enable global interrupt
     /////  __enable_irq();
      // Enable ADC interrupt in NVIC module
   /////    NVIC->ISER[0] |= 1 << ((ADC14_IRQn) & 31);

}




void enable_IRQ(void)
{
    // Enable global interrupt
        __enable_irq();

        // Enable eUSCIA2 interrupt in NVIC module
        NVIC->ISER[0] |= 1 << ((EUSCIA2_IRQn) & 31);

        NVIC->ISER[0] |= 1 << ((ADC14_IRQn) & 31);// ADC


        NVIC->ISER[0] |= 1 << ((T32_INT1_IRQn) & 31); //timer

        NVIC->ISER[0] |= 1 << ((T32_INT2_IRQn) & 31); //timer
}
