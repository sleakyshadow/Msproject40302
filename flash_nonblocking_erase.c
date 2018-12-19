/* DriverLib Includes */
#include <Config_GPIO_CLOCK_ADC.h>
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
//#include "msp.h"
#include <string.h>
#include "global_variables.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>


int main(void)
{
   int i=0;
   setup();
   while(1)
   {
       if(incr_pwn==1)
       {
        i2cOLEDClear();
        write_h_string(3,1," TEST",2);
        write_h_string(3,6,"SCRIPT",2);

        int j=0;
      for(j=0;j<4000000;j++)
      {
          int kx=0;
          kx+=101;
      }
      i=1;
        incr_pwn=0;

       }

       if(incr_pwn==0)
       {
           i2cOLEDClear();
           //int m=0;
//                  for(m=0;m<1000000;m++)
//                  {
//                     int kx=0;
//                     kx+=101;
//                  }

                  i=0;
       }





   }

}

// Setup function for initializing all GPIO, interrupt, protocols
void setup(void)
{


    // Stop WDT
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;

    // Configure all the required GPIO as per the requirement of product
    gpio_config();

    //set system clock
    clock_setting();

    //Setup for OLED using i2c
     i2c_init();
     i2cOLEDInitialize();
     i2cOLEDClear();
     i2cOLEDSetPos(0,0);


     timer_32_for_soft_count_config();
     enable_IRQ();

     //TIMER32_1->CONTROL |= TIMER32_CONTROL_ENABLE | TIMER32_CONTROL_IE;
     TIMER32_2->CONTROL |= TIMER32_CONTROL_ENABLE | TIMER32_CONTROL_IE;
//     turn_on_timer1();
//     turn_on_timer2();

     incr_pwn=0;
     incr_pwn1=0;
}


// Timer configuration for the vibrater
void timer_32_for_soft_count_config(void)
{

    // Timer32 set up in periodic mode, 32-bit, no pre-scale
       TIMER32_1->CONTROL = TIMER32_CONTROL_SIZE |TIMER32_CONTROL_MODE;

    // Load Timer32 counter with period = 0x20000
       TIMER32_1->LOAD=  pwm_vpt_peroid;//1200;

    // Enalbe the Timer32 interrupt in NVIC
//       __enable_irq();
//       NVIC->ISER[0] |= 1 << ((T32_INT1_IRQn) & 31);

}


void turn_off_timer1(void)
{
   TIMER32_1->CONTROL &= ~(TIMER32_CONTROL_ENABLE | TIMER32_CONTROL_IE);

}

void turn_on_timer1(void)
{
    TIMER32_1->CONTROL |= TIMER32_CONTROL_ENABLE | TIMER32_CONTROL_IE;

}

void turn_on_timer2(void)
{
   TIMER32_2->CONTROL |= TIMER32_CONTROL_ENABLE | TIMER32_CONTROL_IE;

}

void turn_off_timer2(void)
{
    TIMER32_2->CONTROL &= ~(TIMER32_CONTROL_ENABLE | TIMER32_CONTROL_IE);

}
