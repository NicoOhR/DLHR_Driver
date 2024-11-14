#include "driver/i2c_master.h"
#include "driver/i2c_types.h"
#include "esp_err.h"
#include "sdkconfig.h"
#include <stdio.h>

// stupid IDF
#define CONFIG_I2C_MASTER_SCL 4
#define CONFIG_I2C_MASTER_SDA 5

void app_main(void) {

  i2c_master_bus_config_t i2c_mst_config = {
      .clk_source = I2C_CLK_SRC_DEFAULT,
      .i2c_port = -1,
      .scl_io_num = CONFIG_I2C_MASTER_SCL,
      .sda_io_num = CONFIG_I2C_MASTER_SDA,
      .glitch_ignore_cnt = 7,
      .flags.enable_internal_pullup = true,
  };

  i2c_master_bus_handle_t bus_handle;

  ESP_ERROR_CHECK(i2c_new_master_bus(&i2c_mst_config, &bus_handle));

  i2c_device_config_t dev_cfg = {
      .dev_addr_length = I2C_ADDR_BIT_LEN_7,
      .device_address = 0x58,
      .scl_speed_hz = 100000,
  };

  i2c_master_dev_handle_t dev_handle;
  ESP_ERROR_CHECK(i2c_master_bus_add_device(bus_handle, &dev_cfg, &dev_handle));

  const uint8_t command_buffer[1] = {0xAA};
  uint8_t recieve_buffer[8] = {0};

  ESP_ERROR_CHECK(i2c_master_transmit_receive(dev_handle, command_buffer, 1,
                                              recieve_buffer, 8, -1));
}
