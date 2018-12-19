




#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
//#include "msp.h"

#ifndef GLOBAL_VARIABLES_H_
#define GLOBAL_VARIABLES_H_



//static  char transmission_header [] = {"TMSTART205100000000000000$"};
//static char pocket_header [] = {"NEUROTOUCH200100000000000000$"};
char resulr_storage[70];  // device data Pocket body
static char software_version[] = {"SW: V2.0"};
//static char pocket_footer [] = {"YOSTRA200100000000000000$"};
//static char transmission_footer [] = {"ENDOFTM205100000000000000$"};
static char device_ID[] = {"Y1001004180004"};
static char error_storage[] = {"102030405060$"};

void append_device_ID(void);
char blue_rce[10];
char cnti;
//static const char read_command_pocket[] = {0xAA,0x00,0x01,0x01,0xFE,'\0'};


// global variable and functions
#define hot_high_threshold 2.9   // hot plate turn off offset
#define hot_low_threshold  3.4    // hot plate turn on offset

// Battery max voltage
#define battery_actual_voltage   4.168

// Critical battery turn off
#define crital_battery_level  25   //

// cold temperature low threshold value
#define low_throshold_for_cold     10
// Hot temperature maz threshold value
#define high_throshold_for_hot     49

#define VPT_volts_limit           51 // as per VPT limit change the value
                                        // if vpt values are 50 then number should be 51

// VPT calibration data :
static const char VPT_calibration_values[]={

                                            5
                                            ,10
                                            ,15
                                            ,20
                                            ,25
                                            ,30
                                            ,35
                                            ,40
                                            ,45
                                            ,50
                                            ,55
                                            ,60
                                            ,65
                                            ,70
                                            ,75
                                            ,80
                                            ,85
                                            ,90
                                            ,95
                                            ,100
                                            ,105
                                            ,110
                                            ,115
                                            ,120
                                            ,125
                                            ,130
                                            ,135
                                            ,140
                                            ,145
                                            ,150
                                            ,155
                                            ,160
                                            ,165
                                            ,170
                                            ,175
                                            ,180
                                            ,185
                                            ,190
                                            ,195
                                            ,200
                                            ,205
                                            ,210
                                            ,215
                                            ,220
                                            ,225
                                            ,230
                                            ,235
                                            ,240
                                            ,245
                                            ,250
                                            ,253
,254


                                           };

char vpt_on_off;
void turn_on_vpt(void);
void turn_off_vpt(void);


char IR_temp_error;
void error_message_display(void);
char fuel_guage_error;
void battery_status_indicator(void);

#define PS_memory_addre            1
#define VPT_memory_addre           14
#define Hot_thermal_memory_addre   27
#define Cold_thermal_memory_addre  40
#define IR_temp_memory_addre       53

#define enable_vibrator            0x50  // enable LRA
#define disable_vibrator           0xAF

#define enable_hot_peltier         0X0005
#define disable_hot_cold_peltier   0XFFF8
#define enable_cold_peltier        0X0006


#define enable_peltier_fan         0X0001
#define disable_peltier_fan        0XFFFE


// Fuel gauge low threshold values
#define low_threshold_low_byte     0x00
#define low_threshold_high_byte    0x00
// Fuel gauge high threshold values
#define high_threshold_low_byte    0xff
#define high_threshold_high_byte   0xff

#define pwm_vpt_peroid       119// 119//  32000 //PWM period value 58
#define pwm_duty_cycle          1176// max Duty cycle
#define key_up_down_speed        3000 //100000 //
#define key_up_down_speed_vpt    50000 //
int key_count_VPT;
char extend_key_mul;
char vpt_key_speed_status;
char st_hot_cold;

float battery_full_voltage;

#define default_stored_mem_value    '_'

void reset_all_app(void);
int vibrator_pwm_cnt_cal_value;
uint8_t next_case ;
uint16_t IR_data[5];
uint8_t screen_rpt_flag;
char rcd_str[5];
char int_string_array[10];
char sign_1;
void intger_2_string(int zzz);
char string_length(char *rcd_array);
void float_to_string(float num_ber);
void int_string(int zzz);
char key_lock;
char test_counter;
int thermo_cnt;
char batter_level;
char stay_screen;

char result_track;
char data_saved ;
char to_save_tempe_data;
char to_save_hot_data;
char to_save_cold_data;
char to_save_vpt_data;
char old_data_status;
char  vpt_on ;
void print_PS_empty_bar(void);
float battery_read_value;
float battery_result;
char mains_available;
#define  battery_delay_read 500000//1000000
char status_low_battery;

int ix;


// ********************************************
// ADC variables


//#define   Num_of_Results   10
float Cold_pelt_temp;
float Hot_pelt_temp;
int PS_read_result;
int PS_previous_result;
int initial_loardcell_reading;
int status;
int cnt;


char equal_temp ;
char read_hot_temp_successfull;
char read_cold_temp_successfull;
// &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

// ********************************************
// Case applications variables

void read_key_pressed(void);
void main_menu(void);
void setup(void);
void enable_IRQ(void);
char read_key_pressed_API(void);
char read_key;
int vibrator_pwm_cnt ;
char volts_value;

void IR_Thermo_case_application(void);

void Hot_thermal_case_application(void);
void Cold_thermal_case_application(void);

void load_cell_case_application(void);
void load_cell_first_bar(void);
void load_cell_second_bar(void);
void load_cell_third_bar(void);
void load_cell_fourth_bar(void);
void reset_stored_data(void);
void reset_data_send_case_application(void);
void left_right_arrow(void);

void battery_status(void);
void timer1_config(void);
int delay_cnt;
//void get_mem_addre_for_previous_point(void);

int set_peltier_temp;
int ambient_hot_peltier_temp;
int ambient_cold_peltier_temp;
int cold_previous_temp;
int hot_previous_temp;
int int_timer_cnt;
int int_timer_cnt_incr_pwn;
int sub_int_cnt;
int incr_pwn;
int down_cnt;
char one_time;
char stop_key_till_center;
uint8_t status_read;
// &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&


// ********************************************
// Fual gauge variables

void i2c_init_fual_gauge();
float i2c_read_fual_gauge_voltage(const uint8_t slaveAddr, int Voltage_read_addr);
void i2c_write_fual_gauge_ctrl_rg(const uint8_t slaveAddr, const uint8_t byteAddr, const uint8_t data);
void i2c_write_fual_gauge_acc_rg(const uint8_t slaveAddr, const uint8_t byteAddr, const uint8_t data1, const uint8_t data2);
float i2c_read_fual_gauge_acc_charge(uint8_t slaveAddr, char read_addr);
uint8_t i2c_read_fual_gauge_status(const uint8_t slaveAddr, const uint8_t status_read_addr);

#define Fual_gauge_SLAVE_ADDR   0x64


#define LTC2942_STATUS_REG                          0x00
#define LTC2942_CONTROL_REG                         0x01
#define LTC2942_ACCUM_CHARGE_MSB_REG                0x02
#define LTC2942_ACCUM_CHARGE_LSB_REG                0x03
#define LTC2942_CHARGE_THRESH_HIGH_MSB_REG          0x04
#define LTC2942_CHARGE_THRESH_HIGH_LSB_REG          0x05
#define LTC2942_CHARGE_THRESH_LOW_MSB_REG           0x06
#define LTC2942_CHARGE_THRESH_LOW_LSB_REG           0x07
#define LTC2942_VOLTAGE_MSB_REG                     0x08
#define LTC2942_VOLTAGE_LSB_REG                     0x09
#define LTC2942_VOLTAGE_THRESH_HIGH_REG             0x0A
#define LTC2942_VOLTAGE_THRESH_LOW_REG              0x0B
#define LTC2942_TEMPERATURE_MSB_REG                 0x0C
#define LTC2942_TEMPERATURE_LSB_REG                 0x0D
#define LTC2942_TEMPERATURE_THRESH_HIGH_REG         0x0E
#define LTC2942_TEMPERATURE_THRESH_LOW_REG          0x0F

#define LTC2942_AUTOMATIC_MODE                  0xF0
#define LTC2942_MANUAL_VOLTAGE                  0x80
#define LTC2942_MANUAL_TEMPERATURE              0x40
#define LTC2942_SLEEP_MODE                      0x00

#define LTC2942_PRESCALAR_M_1                   0x00
#define LTC2942_PRESCALAR_M_2                   0x08
#define LTC2942_PRESCALAR_M_4                   0x10
#define LTC2942_PRESCALAR_M_8                   0x18
#define LTC2942_PRESCALAR_M_16                  0x20
#define LTC2942_PRESCALAR_M_32                  0x28
#define LTC2942_PRESCALAR_M_64                  0x30
#define LTC2942_PRESCALAR_M_128                 0x38

#define LTC2942_ALERT_MODE                      0x04
#define LTC2942_CHARGE_COMPLETE_MODE            0x02
#define LTC2942_DISABLE_ALCC_PIN                0x00

#define LTC2942_SHUTDOWN_MODE                   0x01


// &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

// ********************************************
// ItC IR Temp variables
void i2c_init_IR_temp();
void i2c_write_reg_IR_temp(const uint8_t slaveAddr, const uint8_t byteAddr, const uint8_t data);
uint8_t i2c_read_reg_IR_temp(const uint8_t slaveAddr, const uint8_t byteAddr);
float i2c_read_mult_bytes_IR_temp(const uint8_t slaveAddr, const uint8_t byteAddr, const uint8_t n, uint16_t *arr);

#define IR_TEMP_SLAVE_ADDR   0x3C

// &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

// ********************************************
// I2C protocol variables

void i2c_init();
void i2c_write_reg(const uint8_t slaveAddr, const uint8_t byteAddr, const uint8_t data);
uint8_t i2c_read_reg(const uint8_t slaveAddr, const uint8_t byteAddr);
void i2c_read_mult_bytes(const uint8_t slaveAddr, const uint8_t byteAddr, const uint8_t n, uint8_t *arr);

// &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

// ********************************************
//  ISR variables
void ADC14_IRQHandler(void);
void TA0_0_IRQHandler(void);
void timer_32_for_soft_count_config(void);
void EUSCIA2_IRQHandler(void);
// &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

// ********************************************
// OLD  variables
// SLA (0x3C) + WRITE_MODE (0x00) =  0x78 (0b01111000)

#define OLED_SLAVE_ADDR   0x3C


void any_text_display(const char* str);

void clear_battery_area(void);
void display_actual_battery(char bat_cn);



static const char battery_symbol[] = {0xff,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0xff,0x3c,0x3c,'\0'};//{0xff,0x81,0xbd,0xbd,0xbd,0xbd,0xbd,0xbd,0xbd,0xbd,0xbd,0xbd,0xbd,0xbd,0x81,0xff,0x3c,0x3c,0x00};

static  char Neuro_touch1[] = {    0X00    ,0X00    ,0X00    ,0X00    ,0X00    ,0X00    ,0X00    ,0X00,
                                   0X00    ,0X00    ,0X00    ,0X00    ,0X00    ,0X00    ,0X00    ,0X00,
                                   0X00    ,0X00    ,0X00    ,0X00    ,0X00    ,0X00    ,0X00    ,0X00,
                                   0X00    ,0X00    ,0X00    ,0X00    ,0X00    ,0X00    ,0X00    ,0X00,
                                   0X08    ,0X08    ,0X08    ,0X08    ,0X08    ,0X08    ,0X08    ,0X08,
                                   0X0C    ,0X0C    ,0X0C    ,0X0C    ,0X0C    ,0X0C    ,0X0C    ,0X0C,
                                   0X0E    ,0X0E    ,0X0E    ,0X0E    ,0X0E    ,0X0E    ,0X0E    ,0X0E,
                                   0X0F    ,0X0F    ,0X0F    ,0X0F    ,0X0F    ,0X0F    ,0X0F    ,0X0F,'\0'

                              };
static char Neuro_touch2[] = {
                                   0X80   ,0X80   ,0X80   ,0X80   ,0X80   ,0X80   ,0X80   ,0X80,
                                   0XC0   ,0XC0   ,0XC0   ,0XC0   ,0XC0   ,0XC0   ,0XC0   ,0XC0,
                                   0XE0   ,0XE0   ,0XE0   ,0XE0   ,0XE0   ,0XE0   ,0XE0   ,0XE0,
                                   0XF0   ,0XF0   ,0XF0   ,0XF0   ,0XF0   ,0XF0   ,0XF0   ,0XF0,
                                   0XF8   ,0XF8   ,0XF8   ,0XF8   ,0XF8   ,0XF8   ,0XF8   ,0XF8,
                                   0XFC   ,0XFC   ,0XFC   ,0XFC   ,0XFC   ,0XFC   ,0XFC   ,0XFC,
                                   0XFE   ,0XFE   ,0XFE   ,0XFE   ,0XFE   ,0XFE   ,0XFE   ,0XFE,
                                   0XFF   ,0XFF   ,0XFF   ,0XFF   ,0XFF   ,0XFF   ,0XFF   ,0XFF,'\0'

                           };

static char Neuro_touch3[] = {
                              0X80   ,0X80   ,0X80   ,0X80   ,0X80   ,0X80   ,0X80   ,0X80,
                              0XC0   ,0XC0   ,0XC0   ,0XC0   ,0XC0   ,0XC0   ,0XC0   ,0XC0,
                              0XE0   ,0XE0   ,0XE0   ,0XE0   ,0XE0   ,0XE0   ,0XE0   ,0XE0,
                              0XF0   ,0XF0   ,0XF0   ,0XF0   ,0XF0   ,0XF0   ,0XF0   ,0XF0, '\0'

                            };
static char Neuro_touch4[] = {
                              0x00,   0x00,   0x1f,   0xf0,
                              0x00,   0x00,   0x3f,   0xe0,
                              0x00,   0x00,   0x7f,   0xc0,
                              0x00,   0x00,   0xff,   0x80,
                              0x00,   0x01,   0xff,   0x00,
                              0x00,   0x03,   0xfe,   0x00,
                              0x00,   0x07,   0xfc,   0x00,
                              0x00,   0x0f,   0xf8,   0x00,
                              0x00,   0x1f,   0xf0,   0x00,
                              0x00,   0x3f,   0xe0,   0x00,
                              0x00,   0x7f,   0xc0,   0x00,
                              0x00,   0xff,   0x80,   0x00,
                              0x01,   0xff,   0x00,   0x00,
                              0x03,   0xfe,   0x00,   0x00,
                              0x07,   0xfc,   0x00,   0x00,
                              0x0f,   0xf8,   0x00,   0x00, '\0'
                            };
static char Neuro_touch5[] = {0x0f,0x1f,0x3f,0x7f,0xff,0xff,0x01,0x03,0x07,0x0f,0x1f,0x3f,0x7f,0xff,'\0' };


// Control byte
#define OLED_CONTROL_BYTE_CMD_SINGLE    0x80
#define OLED_CONTROL_BYTE_CMD_STREAM    0x00
#define OLED_CONTROL_BYTE_DATA_STREAM   0x40

// Fundamental commands (pg.28)
#define OLED_CMD_SET_CONTRAST           0x81    // follow with 0x7F
#define OLED_CMD_DISPLAY_RAM            0xA4
#define OLED_CMD_DISPLAY_ALLON          0xA5
#define OLED_CMD_DISPLAY_NORMAL         0xA6
#define OLED_CMD_DISPLAY_INVERTED       0xA7
#define OLED_CMD_DISPLAY_OFF            0xAE
#define OLED_CMD_DISPLAY_ON             0xAF

// Addressing Command Table (pg.30)
#define OLED_CMD_SET_MEMORY_ADDR_MODE   0x20    // follow with 0x00 = HORZ mode = Behave like a KS108 graphic LCD
#define OLED_CMD_SET_COLUMN_RANGE       0x21    // can be used only in HORZ/VERT mode - follow with 0x00 and 0x7F = COL127
#define OLED_CMD_SET_PAGE_RANGE         0x22    // can be used only in HORZ/VERT mode - follow with 0x00 and 0x07 = PAGE7

// Hardware Config (pg.31)
#define OLED_CMD_SET_DISPLAY_START_LINE 0x40
#define OLED_CMD_SET_SEGMENT_REMAP      0xA1
#define OLED_CMD_SET_MUX_RATIO          0xA8    // follow with 0x3F = 64 MUX
#define OLED_CMD_SET_COM_SCAN_MODE      0xC8
#define OLED_CMD_SET_DISPLAY_OFFSET     0xD3    // follow with 0x00
#define OLED_CMD_SET_COM_PIN_MAP        0xDA    // follow with 0x12
#define OLED_CMD_NOP                    0xE3    // NOP

// Timing and Driving Scheme (pg.32)
#define OLED_CMD_SET_DISPLAY_CLK_DIV    0xD5    // follow with 0x80
#define OLED_CMD_SET_PRECHARGE          0xD9    // follow with 0xF1
#define OLED_CMD_SET_VCOMH_DESELCT      0xDB    // follow with 0x30

// Charge Pump (pg.62)
#define OLED_CMD_SET_CHARGE_PUMP        0x8D    // follow with 0x14

// Function Prototypes
void i2cOLEDStartBit(uint8_t address);
void i2cOLEDStopBit();
void i2cOLEDSendByte(uint8_t byte);
void i2cOLEDStartCommand();
void i2cOLEDStartData();
void i2cOLEDSendChar(char c);
void i2cOLEDSendString(char* str);
void i2cOLEDInitialize();
void i2cOLEDWriteCommand(const uint8_t command);
void i2cOLEDWriteData(const uint8_t data);
void i2cOLEDSetPos(uint8_t x, uint8_t y);
void i2cOLEDFillScreen(uint8_t p1, uint8_t p2);
void i2cOLEDClear();

// OLED_INIT_SEQUENCE
static const uint8_t oled_init_sequence[] = {
        0xAE,           // Display OFF (sleep mode)
        0x20, 0x00,     // Set Memory Addressing Mode
                        // 00=Horizontal Addressing Mode; 01=Vertical Addressing Mode;
                        // 10=Page Addressing Mode (RESET); 11=Invalid
        0xB0,           // Set Page Start Address for Page Addressing Mode, 0-7
        0xC8,           // Set COM Output Scan Direction
        0x00,           // ---set low column address
        0x10,           // ---set high column address
        0x40,           // --set start line address
        0x81, 0x3F,     // Set contrast control register
        0xA1,           // Set Segment Re-map. A0=address mapped; A1=address 127 mapped.
        0xA6,           // Set display mode. A6=Normal; A7=Inverse
        0xA8, 0x3F,     // Set multiplex ratio(1 to 64)
        0xA4,           // Output RAM to Display
                        // 0xA4=Output follows RAM content; 0xA5,Output ignores RAM content
        0xD3, 0x00,     // Set display offset. 00 = no offset
        0xD5,           // --set display clock divide ratio/oscillator frequency
        0xF0,           // --set divide ratio
        0xD9, 0x22,     // Set pre-charge period
        0xDA, 0x12,     // Set com pins hardware configuration
        0xDB,           // --set vcomh
        0x20,           // 0x20,0.77xVcc
        0x8D, 0x14,     // Set DC-DC enable
        0xAF            // Display ON in normal mode
};

// ASCII Library
static const uint8_t font6x8 [] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0xfe, 0x02, 0x02, 0x02, 0x02, 0xfe, // ! //  down U
    0xff, 0x80, 0x80, 0x80, 0x80, 0xff, // " //
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, // # //  Full ON
    0x3f, 0x20, 0x20, 0x20, 0x20, 0x3f, // $  // UP U
    0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,  // %
    0xFF, 0x00, 0x00, 0x00, 0x00, 0xff, // & // parrellel line
    0x7e, 0x81, 0xbd, 0xb9, 0xb1, 0xa1, // '//    - 1
    0x81, 0x81, 0x81, 0x81, 0x81, 0x81,  // (//   - 2
    0x81, 0x81, 0x81, 0xff, 0x3c, 0x3c,  // )//   - 3
    0X08, 0x04, 0xfe, 0x67, 0x20, 0x10, //0xff, 0x81, 0xbd, 0xbd, 0xbd, 0xbd, // *//  -4
    0xbd, 0xbd, 0xbd, 0xbd, 0xb9, 0xb1,  // +//  -5
    0xa1, 0x81, 0x81, 0xff, 0x3c, 0x3c,  // , // -6
    0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd,  // - //  -7
    0x00, 0x00, 0x60, 0x60, 0x00, 0x00, // .
    0xbd, 0xbd, 0x81, 0xff, 0x3c, 0x3c, // /  // -8
    0x00, 0x3E, 0x51, 0x49, 0x45, 0x3E, // 0
    0x00, 0x00, 0x42, 0x7F, 0x40, 0x00, // 1
    0x00, 0x42, 0x61, 0x51, 0x49, 0x46, // 2
    0x00, 0x21, 0x41, 0x45, 0x4B, 0x31, // 3
    0x00, 0x18, 0x14, 0x12, 0x7F, 0x10, // 4
    0x00, 0x27, 0x45, 0x45, 0x45, 0x39, // 5
    0x00, 0x3C, 0x4A, 0x49, 0x49, 0x30, // 6
    0x00, 0x01, 0x71, 0x09, 0x05, 0x03, // 7
    0x00, 0x36, 0x49, 0x49, 0x49, 0x36, // 8
    0x00, 0x06, 0x49, 0x49, 0x29, 0x1E, // 9
    0x00, 0x00, 0x36, 0x36, 0x00, 0x00, // :
    0x00, 0x00, 0x56, 0x36, 0x00, 0x00, // ;
    0x00, 0x08, 0x14, 0x22, 0x41, 0x00, // <
    0x00, 0x14, 0x14, 0x14, 0x14, 0x14, // =
    0x00, 0x00, 0x41, 0x22, 0x14, 0x08, // >
    0x00, 0x02, 0x01, 0x51, 0x09, 0x06, // ?
    0x00, 0x32, 0x49, 0x59, 0x51, 0x3E, // @   // degree symbol
    0x00, 0x7C, 0x12, 0x11, 0x12, 0x7C, // A
    0x00, 0x7F, 0x49, 0x49, 0x49, 0x36, // B
    0x00, 0x3E, 0x41, 0x41, 0x41, 0x22, // C
    0x00, 0x7F, 0x41, 0x41, 0x22, 0x1C, // D
    0x00, 0x7F, 0x49, 0x49, 0x49, 0x41, // E
    0x00, 0x7F, 0x09, 0x09, 0x09, 0x01, // F
    0x00, 0x3E, 0x41, 0x49, 0x49, 0x7A, // G
    0x00, 0x7F, 0x08, 0x08, 0x08, 0x7F, // H
    0x00, 0x00, 0x41, 0x7F, 0x41, 0x00, // I
    0x00, 0x20, 0x40, 0x41, 0x3F, 0x01, // J
    0x00, 0x7F, 0x08, 0x14, 0x22, 0x41, // K
    0x00, 0x7F, 0x40, 0x40, 0x40, 0x40, // L
    0x00, 0x7F, 0x02, 0x0C, 0x02, 0x7F, // M
    0x00, 0x7F, 0x04, 0x08, 0x10, 0x7F, // N
    0x00, 0x3E, 0x41, 0x41, 0x41, 0x3E, // O
    0x00, 0x7F, 0x09, 0x09, 0x09, 0x06, // P
    0x00, 0x3E, 0x41, 0x51, 0x21, 0x5E, // Q
    0x00, 0x7F, 0x09, 0x19, 0x29, 0x46, // R
    0x00, 0x46, 0x49, 0x49, 0x49, 0x31, // S
    0x00, 0x01, 0x01, 0x7F, 0x01, 0x01, // T
    0x00, 0x3F, 0x40, 0x40, 0x40, 0x3F, // U
    0x00, 0x1F, 0x20, 0x40, 0x20, 0x1F, // V
    0x00, 0x3F, 0x40, 0x38, 0x40, 0x3F, // W
    0x00, 0x63, 0x14, 0x08, 0x14, 0x63, // X
    0x00, 0x07, 0x08, 0x70, 0x08, 0x07, // Y
    0x00, 0x61, 0x51, 0x49, 0x45, 0x43, // Z
    0x00, 0x20, 0x10, 0x08, 0x04, 0x02,//0x00, 0x00, 0x7F, 0x41, 0x41, 0x00, // [  replaced with '/'
    0x00, 0x55, 0x2A, 0x55, 0x2A, 0x55, // 55
    0x00, 0x00, 0x41, 0x41, 0x7F, 0x00, // ]
    0x00, 0x04, 0x02, 0x01, 0x02, 0x04, // ^
    0x00, 0x40, 0x40, 0x40, 0x40, 0x40, // _
    0x00, 0x00, 0x01, 0x02, 0x04, 0x00, // '
    0x00, 0x20, 0x54, 0x54, 0x54, 0x78, // a
    0x00, 0x7F, 0x48, 0x44, 0x44, 0x38, // b
    0x00, 0x38, 0x44, 0x44, 0x44, 0x20, // c
    0x00, 0x38, 0x44, 0x44, 0x48, 0x7F, // d
    0x00, 0x38, 0x54, 0x54, 0x54, 0x18, // e
    0x00, 0x08, 0x7E, 0x09, 0x01, 0x02, // f
    0x00, 0x18, 0xA4, 0xA4, 0xA4, 0x7C, // g
    0x00, 0x7F, 0x08, 0x04, 0x04, 0x78, // h
    0x00, 0x00, 0x44, 0x7D, 0x40, 0x00, // i
    0x00, 0x40, 0x80, 0x84, 0x7D, 0x00, // j
    0x00, 0x7F, 0x10, 0x28, 0x44, 0x00, // k
    0x00, 0x00, 0x41, 0x7F, 0x40, 0x00, // l
    0x00, 0x7C, 0x04, 0x18, 0x04, 0x78, // m
    0x00, 0x7C, 0x08, 0x04, 0x04, 0x78, // n
    0x00, 0x38, 0x44, 0x44, 0x44, 0x38, // o
    0x00, 0xFC, 0x24, 0x24, 0x24, 0x18, // p
    0x00, 0x18, 0x24, 0x24, 0x18, 0xFC, // q
    0x00, 0x7C, 0x08, 0x04, 0x04, 0x08, // r
    0x00, 0x48, 0x54, 0x54, 0x54, 0x20, // s
    0x00, 0x04, 0x3F, 0x44, 0x40, 0x20, // t
    0x00, 0x3C, 0x40, 0x40, 0x20, 0x7C, // u
    0x00, 0x1C, 0x20, 0x40, 0x20, 0x1C, // v
    0x00, 0x3C, 0x40, 0x30, 0x40, 0x3C, // w
    0x18, 0x3c, 0x7e, 0x7e, 0x3c, 0x18, //0x00, 0x44, 0x28, 0x10, 0x28, 0x44, // x
    0x3c, 0x3c, 0xff, 0x7e, 0x3c, 0x18,//0x00, 0x1C, 0xA0, 0xA0, 0xA0, 0x7C, // y
    0x18, 0x3c, 0x7e, 0xff, 0x3c, 0x3c,  // z  0x00, 0x44, 0x64, 0x54, 0x4C, 0x44, // z
    0x14, 0x14, 0x14, 0x14, 0x14, 0x14 // horiz lines
};


#define f_width     5
unsigned char byte,bit_num;     // will be used for different functions
unsigned int h_index,w_index;
#define max_f_size      8
#define meta_w_size     64
#define space_char  1       // space between chars
// 128 chars = 640 bytes (128*5bytes)
static const uint8_t ascii_table[][f_width]={0xFF,0xFF,0xFF,0xFF,0xFF,  // ASCII 00: all pixel
                                             0x00,0x00,0x00,0x00,0x00,          // ASCII 01: reserved
                                             0x00,0x00,0x00,0x00,0x00,          // ASCII 02: reserved
                                             0x00,0x00,0x00,0x00,0x00,          // ASCII 03: reserved
                                             0x00,0x00,0x00,0x00,0x00,          // ASCII 04: reserved
                                             0x00,0x00,0x00,0x00,0x00,          // ASCII 05: reserved
                                             0x00,0x00,0x00,0x00,0x00,          // ASCII 06: reserved
                                             0x00,0x00,0x00,0x00,0x00,          // ASCII 07: reserved
                                             0x00,0x00,0x00,0x00,0x00,          // ASCII 08: reserved
                                             0x00,0x00,0x00,0x00,0x00,          // ASCII 09: reserved
                                             0x00,0x00,0x00,0x00,0x00,          // ASCII 0a: reserved
                                             0x00,0x00,0x00,0x00,0x00,          // ASCII 0b: reserved
                                             0x00,0x00,0x00,0x00,0x00,          // ASCII 0c: reserved
                                             0x00,0x00,0x00,0x00,0x00,          // ASCII 0d: reserved
                                             0x00,0x00,0x00,0x00,0x00,          // ASCII 0e: reserved
                                             0x00,0x00,0x00,0x00,0x00,          // ASCII 0f: reserved
                                             0x00,0x00,0x00,0x00,0x00,          // ASCII 10: reserved
                                             0x00,0x00,0x00,0x00,0x00,          // ASCII 11: reserved
                                             0x00,0x00,0x00,0x00,0x00,          // ASCII 12: reserved
                                             0x00,0x00,0x00,0x00,0x00,          // ASCII 13: reserved
                                             0x00,0x00,0x00,0x00,0x00,          // ASCII 14: reserved
                                             0x00,0x00,0x00,0x00,0x00,          // ASCII 15: reserved
                                             0x00,0x00,0x00,0x00,0x00,          // ASCII 16: reserved
                                             0x00,0x00,0x00,0x00,0x00,          // ASCII 17: reserved
                                             0x00,0x00,0x00,0x00,0x00,          // ASCII 18: reserved
                                             0x00,0x00,0x00,0x00,0x00,          // ASCII 19: reserved
                                             0x00,0x00,0x00,0x00,0x00,          // ASCII 1a: reserved
                                             0x00,0x00,0x00,0x00,0x00,          // ASCII 1b: reserved
                                             0x00,0x00,0x00,0x00,0x00,          // ASCII 1c: reserved
                                             0x00,0x00,0x00,0x00,0x00,          // ASCII 1d: reserved
                                             0x00,0x00,0x00,0x00,0x00,          // ASCII 1e: reserved
                                             0x00,0x00,0x00,0x00,0x00,          // ASCII 1f: reserved
                                             0x00,0x00,0x00,0x00,0x00,          // ASCII 20: SP (Space)
                                             0x00,0x00,0x5f,0x00,0x00,          // ASCII 21: !
                                             0x00,0x07,0x00,0x07,0x00,          // ASCII 22: "
                                             0x14,0x7f,0x14,0x7f,0x14,          // ASCII 23: #
                                             0x24,0x2a,0x7f,0x2a,0x12,          // ASCII 24: $
                                             0x23,0x13,0x08,0x64,0x62,          // ASCII 25: %
                                             0x36,0x49,0x55,0x22,0x50,          // ASCII 26: &
                                             0x00,0x05,0x03,0x00,0x00,          // ASCII 27: '
                                             0x00,0x1c,0x22,0x41,0x00,          // ASCII 28: (
                                             0x00,0x41,0x22,0x1c,0x00,          // ASCII 29: )
                                             0x14,0x08,0x3e,0x08,0x14,          // ASCII 2a: *
                                             0x08,0x08,0x3e,0x08,0x08,          // ASCII 2b: +
                                             0x00,0x50,0x30,0x00,0x00,          // ASCII 2c: ,
                                             0x08,0x08,0x08,0x08,0x08,          // ASCII 2d: -
                                             0x00,0x60,0x60,0x00,0x00,          // ASCII 2e: .
                                             0x20,0x10,0x08,0x04,0x02,          // ASCII 2f: /
                                             0x3e,0x51,0x49,0x45,0x3e,          // ASCII 30: 0
                                             0x00,0x42,0x7f,0x40,0x00,          // ASCII 31: 1
                                             0x42,0x61,0x51,0x49,0x46,          // ASCII 32: 2
                                             0x21,0x41,0x45,0x4b,0x31,          // ASCII 33: 3
                                             0x18,0x14,0x12,0x7f,0x10,          // ASCII 34: 4
                                             0x27,0x45,0x45,0x45,0x39,          // ASCII 35: 5
                                             0x3c,0x4a,0x49,0x49,0x30,          // ASCII 36: 6
                                             0x01,0x71,0x09,0x05,0x03,          // ASCII 37: 7
                                             0x36,0x49,0x49,0x49,0x36,          // ASCII 38: 8
                                             0x06,0x49,0x49,0x29,0x1e,          // ASCII 39: 9
                                             0x00,0x36,0x36,0x00,0x00,          // ASCII 3a: :
                                             0x00,0x56,0x36,0x00,0x00,          // ASCII 3b: ;
                                             0x08,0x14,0x22,0x41,0x00,          // ASCII 3c: <
                                             0x14,0x14,0x14,0x14,0x14,          // ASCII 3d: =
                                             0x00,0x41,0x22,0x14,0x08,          // ASCII 3e: >
                                             0x02,0x01,0x51,0x09,0x06,          // ASCII 3f: ?
                                             0x00,0x06,0x09,0x09,0x06,         // 0x32,0x49,0x79,0x41,0x3e,          // ASCII 40: @
                                             0x7e,0x11,0x11,0x11,0x7e,          // ASCII 41: A
                                             0x7f,0x49,0x49,0x49,0x36,          // ASCII 42: B
                                             0x3e,0x41,0x41,0x41,0x22,          // ASCII 43: C
                                             0x7f,0x41,0x41,0x22,0x1c,          // ASCII 44: D
                                             0x7f,0x49,0x49,0x49,0x41,          // ASCII 45: E
                                             0x7f,0x09,0x09,0x09,0x01,          // ASCII 46: F
                                             0x3e,0x41,0x49,0x49,0x7a,          // ASCII 47: G
                                             0x7f,0x08,0x08,0x08,0x7f,          // ASCII 48: H
                                             0x00,0x41,0x7f,0x41,0x00,          // ASCII 49: I
                                             0x20,0x40,0x41,0x3f,0x01,          // ASCII 4a: J
                                             0x7f,0x08,0x14,0x22,0x41,          // ASCII 4b: K
                                             0x7f,0x40,0x40,0x40,0x40,          // ASCII 4c: L
                                             0x7f,0x02,0x0c,0x02,0x7f,          // ASCII 4d: M
                                             0x7f,0x04,0x08,0x10,0x7f,          // ASCII 4e: N
                                             0x3e,0x41,0x41,0x41,0x3e,          // ASCII 4f: O
                                             0x7f,0x09,0x09,0x09,0x06,          // ASCII 50: P
                                             0x3e,0x41,0x51,0x21,0x5e,          // ASCII 51: Q
                                             0x7f,0x09,0x19,0x29,0x46,          // ASCII 52: R
                                             0x46,0x49,0x49,0x49,0x31,          // ASCII 53: S
                                             0x01,0x01,0x7f,0x01,0x01,          // ASCII 54: T
                                             0x3f,0x40,0x40,0x40,0x3f,          // ASCII 55: U
                                             0x1f,0x20,0x40,0x20,0x1f,          // ASCII 56: V
                                             0x3f,0x40,0x38,0x40,0x3f,          // ASCII 57: W
                                             0x63,0x14,0x08,0x14,0x63,          // ASCII 58: X
                                             0x07,0x08,0x70,0x08,0x07,          // ASCII 59: Y
                                             0x61,0x51,0x49,0x45,0x43,          // ASCII 5a: Z
                                             0x00,0x7f,0x41,0x41,0x00,          // ASCII 5b: [
                                             0x02,0x04,0x08,0x10,0x20,          // ASCII 5c: ¥
                                             0x00,0x41,0x41,0x7f,0x00,          // ASCII 5d: ]
                                             0x04,0x02,0x01,0x02,0x04,          // ASCII 5e: ^
                                             0x40,0x40,0x40,0x40,0x40,          // ASCII 5f: _
                                             0x00,0x01,0x02,0x04,0x00,          // ASCII 60: `
                                             0x20,0x54,0x54,0x54,0x78,          // ASCII 61: a
                                             0x7f,0x48,0x44,0x44,0x38,          // ASCII 62: b
                                             0x38,0x44,0x44,0x44,0x20,          // ASCII 63: c
                                             0x38,0x44,0x44,0x48,0x7f,          // ASCII 64: d
                                             0x38,0x54,0x54,0x54,0x18,          // ASCII 65: e
                                             0x08,0x7e,0x09,0x01,0x02,          // ASCII 66: f
                                             0x0c,0x52,0x52,0x52,0x3e,          // ASCII 67: g
                                             0x7f,0x08,0x04,0x04,0x78,          // ASCII 68: h
                                             0x00,0x44,0x7d,0x40,0x00,          // ASCII 69: i
                                             0x20,0x40,0x44,0x3d,0x00,          // ASCII 6a: j
                                             0x7f,0x10,0x28,0x44,0x00,          // ASCII 6b: k
                                             0x00,0x41,0x7f,0x40,0x00,          // ASCII 6c: l
                                             0x7c,0x04,0x18,0x04,0x78,          // ASCII 6d: m
                                             0x7c,0x08,0x04,0x04,0x78,          // ASCII 6e: n
                                             0x38,0x44,0x44,0x44,0x38,          // ASCII 6f: o
                                             0x7c,0x14,0x14,0x14,0x08,          // ASCII 70: p
                                             0x08,0x14,0x14,0x18,0x7c,          // ASCII 71: q
                                             0x7c,0x08,0x04,0x04,0x08,          // ASCII 72: r
                                             0x48,0x54,0x54,0x54,0x20,          // ASCII 73: s
                                             0x04,0x3f,0x44,0x40,0x20,          // ASCII 74: t
                                             0x3c,0x40,0x40,0x20,0x7c,          // ASCII 75: u
                                             0x1c,0x20,0x40,0x20,0x1c,          // ASCII 76: v
                                             0x3c,0x40,0x30,0x40,0x3c,          // ASCII 77: w
                                             0x44,0x28,0x10,0x28,0x44,          // ASCII 78: x
                                             0x0c,0x50,0x50,0x50,0x3c,          // ASCII 79: y
                                             0x44,0x64,0x54,0x4c,0x44,          // ASCII 7a: z
                                             0x00,0x08,0x36,0x41,0x00,          // ASCII 7b: {
                                             //0x00,0x00,0x7f,0x00,0x00,        // ASCII 7c: |
                                             0xff,0xff,0xff,0xff,0xff,
                                             0x00,0x41,0x36,0x08,0x00,          // ASCII 7d: }
                                             0x10,0x08,0x08,0x10,0x08,          // ASCII 7e: ->
                                             0x78,0x46,0x41,0x46,0x78           // ASCII 7f: <-
                                             };

void send_data_array( const uint8_t *d_array, unsigned char size);
void convert_font_size(unsigned char x, unsigned char y, unsigned char character, unsigned char f_size);
void write_char(unsigned char x, unsigned char y, const char character, unsigned char f_size);
void write_h_string(unsigned char x, unsigned char y, const char *string, unsigned char f_size);


// &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

// ********************************************
// VPT - Vibrator  variables

void Port_Mapping(void);
void config_timerA0_for_PWM(void);
void VPT_case_application(void);

// &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

#endif /* GLOBAL_VARIABLES_H_ */


// Flash programming for patient information
#define addr_flash 0x0003F000    // Primary
#define addre_flash_secondary 0x0003E000  // Secondary data storage
int backup_current_mem_addr;
#define  write 1
#define  read  2
#define  erase 3
#define  offset_patient_mem_addr 66
#define speed_logo 10000


char  offset_test_mem_addr,local_test_mem_addr ;

int flash_mem_address;
void flash_read_write_earse(char option,int addr);
void flash_read_operations(void);
void relaocate_flash_data(void);
void display_patient_counts(void);


char  read_back_data[10];
uint8_t flash_data_storage[4096];
uint8_t patient_count;
char inc;
char IR_flash_data_flag;
char cold_temp_flash_data_flag;
char hot_temp_flash_data_flag;
char VPT_flash_data_flag;
char load_cell_flash_data_flag;

char where_i_am;
char read_key_pressed_API_VPT(void);
//char key_read_at_ISR;
char its_tim_int_key_raed;
char temp_read_key;
char bat_cnt;
char hot_cold_guage_error;
char present_patient_data_on_flash;
void wait_ms(int ext_delay);
void blue_tooth_device_ID_read(void);
void data_earse_from_flash(void);
char wait_for_ack;
void print_logo(uint8_t x_ad,uint8_t y_ad,   char* str);
void i2cOLEDSetPos_logo(uint8_t x, uint8_t y);
#define x_ad_off 16
char read_key_pressed_cold_Hot(void);
int key_count_hot;
char rpt_vpt_flag ;
//char PWN_cnt;
//char PWM_volts;
//int toff_period;

int extend_key_time;

