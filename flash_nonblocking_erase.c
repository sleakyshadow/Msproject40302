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
       if(i==0)
       {
        i2cOLEDClear();
        write_h_string(3,1," TEST",0);
        write_h_string(3,6,"SCRIPT",0);
        i=1;
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




}

