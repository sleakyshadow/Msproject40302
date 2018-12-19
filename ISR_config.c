
//#include "./ISR_config.h"
//#include "./ADC-config.h"
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
//#include "msp.h"
#include "./global_variables.h"
#include <math.h>




// interrupt for every 5usec
void T32_INT1_IRQHandler(void)
{
    TIMER32_1->INTCLR |= BIT0;              // Clear Timer32 interrupt flag

    int_timer_cnt_incr_pwn1++;
                if(int_timer_cnt_incr_pwn1 >= 700000)
                {
                    incr_pwn1 = 1;
                    int_timer_cnt_incr_pwn1 = 0;
                }


}

void T32_INT2_IRQHandler(void)
{


        TIMER32_2->INTCLR |= BIT0;              // Clear Timer32 interrupt flag
        int_timer_cnt_incr_pwn++;
            if(int_timer_cnt_incr_pwn >= 7000)
            {
                incr_pwn = 1;
                int_timer_cnt_incr_pwn = 0;
            }

}




