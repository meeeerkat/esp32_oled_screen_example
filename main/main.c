#include "esp_system.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "oled_screen.h"
#include "img_buffer/img_buffer.h"
#include <string.h>


#define SDA_GPIO 33
#define SCL_GPIO 32


oled_screen_t os;
img_buffer_t ib;


void app_main(void) {
  img_buffer_size_t buff_size = {128, 32};
  img_buffer__init(&ib, buff_size);
  img_buffer__clear(&ib);

  oled_screen__init(&os, SDA_GPIO, SCL_GPIO, I2C_NUM_0, RES_128x32);
  vTaskDelay(pdMS_TO_TICKS(100)); // Init duration

  oled_screen__write(&os, img_buffer__get_buff(&ib));
  oled_screen__on(&os);

  vTaskDelay(pdMS_TO_TICKS(2000));

  img_buffer__set_pixel(&ib, (img_buffer_point_t){10, 1}, 1);
  oled_screen__write(&os, img_buffer__get_buff(&ib));
  
  vTaskDelay(pdMS_TO_TICKS(3000));

  oled_screen__off(&os);


  vTaskDelay(pdMS_TO_TICKS(100000));
}
