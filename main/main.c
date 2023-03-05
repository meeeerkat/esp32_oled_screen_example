#include "esp_system.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "oled_screen.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/timers.h"
#include "driver/gpio.h"


#define SDA_GPIO 33
#define SCL_GPIO 32


oled_screen_t os;
uint8_t buff[OLED_SCREEN_128x32_BUFF_SIZE] = {
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111
};


void app_main(void) {
  oled_screen__init(&os, SDA_GPIO, SCL_GPIO, I2C_NUM_0, RES_128x32);

  oled_screen__write(&os, buff);

  vTaskDelay(pdMS_TO_TICKS(100000));
}
