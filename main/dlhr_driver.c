#include "driver/i2c_master.h"
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
}
