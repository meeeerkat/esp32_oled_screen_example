#include "esp_system.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "oled_screen.h"
#include <string.h>


#define SDA_GPIO 33
#define SCL_GPIO 32


oled_screen_t os;
uint8_t buff[OLED_SCREEN_128x32_BUFF_SIZE];


void app_main(void) {


  oled_screen__init(&os, SDA_GPIO, SCL_GPIO, I2C_NUM_0, RES_128x32);
  vTaskDelay(pdMS_TO_TICKS(100)); // Init duration


  memset(buff, 0x7F, OLED_SCREEN_128x32_BUFF_SIZE);
  buff[4] = 0;
  buff[30] = 0;
  oled_screen__write(&os, buff);


  vTaskDelay(pdMS_TO_TICKS(3000));


  oled_screen__off(&os);


  vTaskDelay(pdMS_TO_TICKS(100000));
}
