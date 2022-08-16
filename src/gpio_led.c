#include <zephyr/init.h>
#include <zephyr/kernel.h>
#include <string.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(dom0);

#define LED0_NODE DT_ALIAS(led0)
#if !DT_NODE_HAS_STATUS(LED0_NODE, okay)
#error "Unsupported board: led0 devicetree alias is not defined"
#endif
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

void configure_led(void) {
	int ret;

	if (!device_is_ready(led.port)) {
		LOG_ERR("GPIO device is not ready");
		return;
	}

	ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		LOG_ERR("gpio_pin_configure_dt failed");
		return;
	}
}

void toggle_led(void) {
	int ret;

	LOG_INF("GPIO toggle");
	ret = gpio_pin_toggle_dt(&led);
	if (ret < 0) {
		LOG_ERR("gpio_pin_toggle_dt failed");
		return;
	}
}
