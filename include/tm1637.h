#ifndef TM1637_h
#define TM1637_h

#include <inttypes.h>
#include <iostream>
#include <string>
#include "driver/gpio.h"
#include "string.h"
#include "math.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

using namespace std;
/*******************Definitions for TM1637*********************/
#define ADDR_AUTO 0x40
#define ADDR_FIXED 0x44

#define STARTADDR 0xc0
/*****Definitions for the clock point of the digit tube *******/
#define POINT_ON 1
#define POINT_OFF 0
/**************Definitions for brightness**********************/
#define BRIGHT_DARKEST 0
#define BRIGHT_TYPICAL 2
#define BRIGHTEST 7

#define DIO_PIN GPIO_NUM_17
#define CLK_PIN GPIO_NUM_18


class TM1637 {
  public:
    uint8_t cmd_set_data;
    uint8_t cmd_set_addr;
    uint8_t cmd_disp_ctrl;
    bool _PointFlag;            //_PointFlag=1:the clock point on
    TM1637(gpio_num_t, gpio_num_t);
    void init(void);               // To clear the display
    int writeByte(int8_t wr_data); // Write 8bit data to tm1637
    void start(void);              // Send start bits
    void stop(void);               // Send stop bits
    void display(int8_t DispData[]);
    void display(uint8_t BitAddr, int8_t DispData);
    void displayNum(float num, int decimal = 0, bool show_minus = true);
    void displayStr(char str[],  uint16_t loop_delay = 500);
    void clearDisplay(void);
    void set(uint8_t = BRIGHT_TYPICAL, uint8_t = 0x40, uint8_t = 0xc0); //To take effect the next time it displays.
    void point(bool
               PointFlag);                                      //whether to light the clock point ":".To take effect the next time it displays.
    void coding(int8_t DispData[]);
    int8_t coding(int8_t DispData);
    void bitDelay(void);

  private:
    const int DIGITS = 4; // Number of digits on display
    gpio_num_t clkpin;
    gpio_num_t datapin;
};
#endif
