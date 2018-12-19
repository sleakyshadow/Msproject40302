//#include "./i2c_protocol.h"



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
/*
 * I2C Initialization  for OLD
 */
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
//#include "msp.h"
#include "./global_variables.h"

void i2c_init()
{
    // Enable SW reset (reset state machine)
    UCB0CTLW0 |= UCSWRST;
    // I2C Master, synchronous mode
    UCB0CTLW0 |= (UCMST | UCMODE_3 | UCSYNC);
    // Use SMCLK, keep SW reset
    UCB0CTLW0 |= (UCSSEL__SMCLK| UCTR);//

    // fSCL = SMCLK/60, for example
    UCB0BRW = 0x000f;
    // Clear SW reset, resume operation
    UCB0CTLW0 &= ~UCSWRST;
}

/*
 * I2C Writing Process
 */
void i2c_write_reg(const uint8_t slaveAddr, const uint8_t byteAddr, const uint8_t data)
{
    // set slave address
    UCB0I2CSA = slaveAddr;

    while (UCB0CTLW0 & UCTXSTP);
    // put in transmitter mode and send start bit
    UCB0CTLW0 |= UCTR | UCTXSTT;
    while(UCB0CTLW0 & UCTXSTT);
    // wait for previous tx to complete
    while (!(UCB0IFG & UCTXIFG0));
    // setting TXBUF clears the TXIFG flag
    UCB0TXBUF = byteAddr;
    while (!(UCB0IFG & UCTXIFG0));
    // setting TXBUF clears the TXIFG flag
    UCB0TXBUF = data;
    // wait for previous tx to complete
    while (!(UCB0IFG & UCTXIFG0));
    // I2C stop condition
    UCB0CTLW0 |= UCTXSTP;
    while (UCB0CTLW0 & UCTXSTP);
}

/*
* I2C Reading Process
*/
uint8_t i2c_read_reg(const uint8_t slaveAddr, const uint8_t byteAddr)
{
    int dataToReturn;

    /** ACCESSING DATA **/
    // set slave address
    UCB0I2CSA = slaveAddr;
    // put in transmitter mode and send start bit
    UCB0CTLW0 |= UCTR | UCTXSTT;
    // wait for previous tx to complete
    while (UCB0CTLW0 & UCTXSTT);
    while (!(UCB0IFG & UCTXIFG0));
    // setting TXBUF clears the TXIFG flag
    UCB0TXBUF = byteAddr;
    // wait for previous tx to complete
    while(UCB0CTLW0 & UCTXSTT);
    while (!(UCB0IFG & UCTXIFG0));

    /*** SEND BACK DATA **/
    // change to receiver mode
    UCB0CTLW0 &= ~UCTR;
    // send start bit
    UCB0CTLW0 |= UCTXSTT;

    while(UCB0CTLW0 & UCTXSTT);
    // wait for an rx character
    while (!(UCB0IFG & UCRXIFG0));
    // I2C stop condition
    UCB0CTLW0 |= UCTXSTP;

    dataToReturn = UCB0RXBUF;
    // reading clears RXIFG flag
    while (UCB0CTLW0 & UCTXSTP);

    return dataToReturn;
}

/*
* I2C Reading Multiple Bytes Consecutively
*/
void i2c_read_mult_bytes(const uint8_t slaveAddr, const uint8_t byteAddr, const uint8_t n, uint8_t *arr)
{

    int i;
    // set slave address
    UCB0I2CSA = slaveAddr;

    /** ACCESSING DATA **/
    // put in transmitter mode and send start bit
    UCB0CTLW0 |= UCTR + UCTXSTT;
    // wait for previous tx to complete
    while (!(UCB0IFG & UCTXIFG0) | (UCB0CTLW0 & UCTXSTT));
    // setting TXBUF clears the TXIFG flag
    UCB0TXBUF = byteAddr;
    // wait for previous tx to complete
    while (!(UCB0IFG & UCTXIFG0) | (UCB0CTLW0 & UCTXSTT));

    /** SEND DATA BACK IN STREAM **/
    //change to receiver mode
    UCB0CTLW0 &= ~UCTR;
    UCB0CTLW0 |= UCTXSTT;

    // send start bit
    while(UCB0CTLW0 & UCTXSTT);
    for (i = 0; i < n; i++)
    {
        // wait for rx buffer
        while (!(UCB0IFG & UCRXIFG0));
        if(i == n - 1)
        {
            // I2C stop condition
            UCB0CTLW0 |= UCTXSTP;
        }
        arr[i] = UCB0RXBUF;
    }


    while (UCB0CTLW0 & UCTXSTP);

}



//#####################################################################################
