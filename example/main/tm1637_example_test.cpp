#include "tm1637.h"

#define CLK_PIN GPIO_NUM_17
#define DIO_PIN GPIO_NUM_16

extern "C" void app_main(void)
{
    TM1637 tm1637(CLK_PIN, DIO_PIN);

    tm1637.init();
    tm1637.set(BRIGHTEST);
    tm1637.point(POINT_ON);

    // display tm1637 four digit, from left to right, 0000 - 9999
    for (int i = 0; i < 10; i++)
    {
        tm1637.display(0, i);
        tm1637.display(1, i);
        tm1637.display(2, i);
        tm1637.display(3, i);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}