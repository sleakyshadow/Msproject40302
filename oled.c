//#include "./oled.h"

/*
 * OLED Initialization
 */
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
//#include "msp.h"
#include "./global_variables.h"

void i2cOLEDInitialize()
{
    int init_length = sizeof(oled_init_sequence)/sizeof(oled_init_sequence[0]);
    int i;
    i2cOLEDStartCommand();
    for (i = 0; i < init_length; i++)
    {
        i2cOLEDSendByte(oled_init_sequence[i]);
    }
    i2cOLEDStopBit();
}

/*
 *  I2C OLED Clear
 */
void i2cOLEDClear()
{
    i2cOLEDFillScreen(0x00, 0x00);
    i2cOLEDSetPos(0, 0);
}


/*
 * I2C OLED Setting Cursor Position
 */
void i2cOLEDSetPos(uint8_t x, uint8_t y)
{
    i2cOLEDStartCommand();
    i2cOLEDSendByte(0xB0 + y);
    i2cOLEDSendByte(((x & 0xF0) >> 4) | 0x10);
    i2cOLEDSendByte((x & 0x0F) | 0x01);
    i2cOLEDStopBit();
}

/*
 * I2C OLED Setting Cursor Position
 */
void i2cOLEDSetPos_logo(uint8_t x, uint8_t y)
{
    i2cOLEDStartCommand();
    i2cOLEDSendByte(0xB0 + y);
    i2cOLEDSendByte(((x & 0xF0) >> 4) | 0x10);
    i2cOLEDSendByte(x & 0x0F);
    i2cOLEDStopBit();
}
/*
 * I2C OLED Send Char
 */
void i2cOLEDSendChar(char c)
{
    unsigned char cToPrint = c - 32;
    i2cOLEDStartData();
    int i;

    for (i=0; i < 6; i++)
    {
        i2cOLEDSendByte(font6x8[cToPrint*6 + i]);
    }
    i2cOLEDStopBit();
}

void any_text_display(const char* str)
{
    int n_i;
    i2cOLEDStartData();
       for (n_i=0; n_i<str[n_i]!='\0'; n_i++)
        {
            i2cOLEDSendByte(str[n_i]);
        }
        i2cOLEDStopBit();
}



/*
 * I2C OLED Start Data
 */
void i2cOLEDStartData()
{
    i2cOLEDStartBit(OLED_SLAVE_ADDR);
    i2cOLEDSendByte(0x40);
}

/*
 * i2cOLED Start Bit
 */
void i2cOLEDStartBit(uint8_t address)
{
    // set slave address
    UCB0I2CSA = address;
    while (UCB0CTLW0 & UCTXSTP);
    // put in transmitter mode and send start bit
    UCB0CTLW0 |= UCTR | UCTXSTT;

    while (UCB0CTLW0 & UCTXSTT);
    // wait for previous tx to complete
    while (!(UCB0IFG & UCTXIFG0));
}
/*
 * I2C Fill Screen
 */
void i2cOLEDFillScreen(uint8_t p1, uint8_t p2)
{


    unsigned char x,y;
    /*set lower column address*/
    i2cOLEDWriteCommand(0x02);
    /*set higher column address*/
    i2cOLEDWriteCommand(0x10);
    /*set page address*/
    i2cOLEDWriteCommand(0xB0);
    for(y=0;y<8;y++)
    {
        /*set page address*/
        i2cOLEDWriteCommand(0xB0+y);
        /*set lower column address*/
        i2cOLEDWriteCommand(0x02);
        /*set higher column address*/
        i2cOLEDWriteCommand(0x10);
        for(x=0;x<64;x++)
        {
            i2cOLEDWriteData(p2);
            i2cOLEDWriteData(p2);
        }
    }
}


/*
 * Send a string to OLED via I2C
 */
void i2cOLEDSendString(char* str)
{
    while(*str)
    {
        i2cOLEDSendChar(*str++);
    }
}

/*
 * I2C OLED Start Command
 */
void i2cOLEDStartCommand()
{
    i2cOLEDStartBit(OLED_SLAVE_ADDR);
    i2cOLEDSendByte(0x00);
}



/*
 * I2C OLED Send Byte
 */
void i2cOLEDSendByte(uint8_t byte)
{
    // setting TXBUF clears the TXIFG flag
    UCB0TXBUF = byte;
    // wait for previous tx to complete
    while (!(UCB0IFG & UCTXIFG0));

}




/*
 * i2cOLED Stop Bit
 */
void i2cOLEDStopBit()
{
    // I2C stop condition
    UCB0CTLW0 |= UCTXSTP;
    while (UCB0CTLW0 & UCTXSTP);
}

/*
 * OLED_commands
 */
void i2cOLEDWriteCommand(const uint8_t command)
{
    // set slave address
    UCB0I2CSA = OLED_SLAVE_ADDR;
    while (UCB0CTLW0 & UCTXSTP);
    // put in transmitter mode and send start bit
    UCB0CTLW0 |= UCTR | UCTXSTT;

    while(UCB0CTLW0 & UCTXSTT);
    // wait for previous tx to complete
    while (!(UCB0IFG & UCTXIFG0));
    // setting TXBUF clears the TXIFG flag
    UCB0TXBUF = 0x00;
    while (!(UCB0IFG & UCTXIFG0));
    // setting TXBUF clears the TXIFG flag
    UCB0TXBUF = command;
    // wait for previous tx to complete
    while (!(UCB0IFG & UCTXIFG0));
    // I2C stop condition
    UCB0CTLW0 |= UCTXSTP;
    while (UCB0CTLW0 & UCTXSTP);
}

/*
 * OLED Write Data
 */
void i2cOLEDWriteData(const uint8_t data)
{
    // set slave address
    UCB0I2CSA = OLED_SLAVE_ADDR;
    while (UCB0CTLW0 & UCTXSTP);
    // put in transmitter mode and send start bit
    UCB0CTLW0 |= UCTR | UCTXSTT;
    // wait for previous tx to complete
    while(UCB0CTLW0 & UCTXSTT);
    while (!(UCB0IFG & UCTXIFG0));
    // setting TXBUF clears the TXIFG flag
    UCB0TXBUF = 0x40;
    while (!(UCB0IFG & UCTXIFG0));
    // setting TXBUF clears the TXIFG flag
    UCB0TXBUF = data;
    // wait for previous tx to complete
    while (!(UCB0IFG & UCTXIFG0));
    // I2C stop condition
    UCB0CTLW0 |= UCTXSTP;
    while (UCB0CTLW0 & UCTXSTP);
}




// ////////////////*******************************************



void write_h_string(unsigned char x, unsigned char y, const char *string, unsigned char f_size)
{
    while(*string!=0)
    {
        write_char(x,y,*string++,f_size);
        if(f_size==1)
             x+=(char)f_size;
        else if(f_size>1)
             x+=(char)f_size;
         else x++;
    }
}

void write_char(unsigned char x, unsigned char y, const char character, unsigned char f_size)
{

    x*=(f_width+space_char);

    i2cOLEDSetPos(x,y);

    if(f_size)
        convert_font_size(x,y,character,f_size);
    else
      {   i2cOLEDStartData();
          send_data_array(ascii_table[character],f_width);
          i2cOLEDStopBit();
      }

}

// horizontal resize with cache (every bit in one byte will be resized to f_size, for example:
// f_size=2, every pixel will have a new size of 2*2 pixel, f_size=3, pixel-size: 3*3 pixel etc.
// f_size=1, double height font, only horizontal duplication of pixels (bits), pixel-size: 1*2 pixel
// the vertical duplication is running over a cache (every horizontal row (resized byte to f_size),
// will be write "f_size"-times to the display)
void convert_font_size(unsigned char x, unsigned char y, unsigned char character, unsigned char f_size)
{
    unsigned char x_char=0,bit_num_b=0,size=0,px_size=0,y_pos_new=0,x_pos_new=0;
    unsigned char cache[max_f_size],i=0;
    byte=0;
    bit_num=0;

    if (f_size==1) size=2;
    else size=f_size;

    while(x_char<f_width)                                                   // test byte, starting at 0 to f_width (font width)
    {
        while(bit_num<8)                                                    // test bit 0..7 of current byte
        {
            if(ascii_table[character][x_char]&(1<<bit_num))  // ascii_table               // if bit=1 in byte...
            {
                while(px_size<size)                                         // duplicate bits (f_size*f_size)
                {
                    if(bit_num_b>7&&px_size>0)                              // byte overflow, new byte
                    {
                        i2cOLEDSetPos(x+x_pos_new,y+y_pos_new++);               // set cursor (increment y-new position)
                        i2cOLEDStartData();
                        i2cOLEDSendByte(byte);                          // send byte
                        i2cOLEDStopBit();
                        bit_num_b=0;                                        // reset bit counter (buffer)
                        cache[i++]=byte;                                    // save byte in cache
                        byte=0;                                             // reset byte
                    }
                    byte|=(1<<bit_num_b);                                   // set bit in byte
                    px_size++;                                              // increment pixel duplicate counter
                    bit_num_b++;                                            // increment bit position for buffer
                }
                px_size=0;                                                  // reset pixel duplicate counter
            }
            else bit_num_b+=size;                                           // bit=0, calculate new bit position in byte
                                                                            // if bit=0, remaining bits are 0, too

            if(bit_num_b>7)                                                 // byte overflow, new byte
            {
                i2cOLEDSetPos(x+x_pos_new,y+y_pos_new++);
                i2cOLEDStartData();
                i2cOLEDSendByte(byte);
                i2cOLEDStopBit();
                bit_num_b-=8;
                cache[i++]=byte;
                byte=0;
            }
            bit_num++;                                                      // test next byte in array
        }
        y_pos_new=0;                                                        // reset y-offset
        x_pos_new++;                                                        // increment x-position
        i=0;                                                                // reset cache counter
        if(f_size==1) size=0;                                               // double height font (only for f_size=1)
        else size--;                                                        // first row is ready, only size-1
        while(size--)
        {
            while(i<f_size)
            {
                i2cOLEDSetPos(x+x_pos_new,y+y_pos_new++);
                i2cOLEDStartData();
                i2cOLEDSendByte(cache[i++]);                                // horizontal cache write
                i2cOLEDStopBit();
            }
            i=0;
            y_pos_new=0;
            x_pos_new++;
        }
        x_char++;                    // increment byte position
        if(f_size==1) size=2;        // size correction
        else size=f_size;
        i=0;                        // reset cache counter
        bit_num=0;
    }
}


void send_data_array( const uint8_t *d_array, unsigned char size)
{

    while(size--)
        i2cOLEDSendByte(*d_array++);

}
