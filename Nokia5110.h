/*
 * Nokia5110.h
 *
 *  Created on: Jan 30, 2018
 *      Author: maxime
 */

#ifndef NOKIA5110_H_
#define NOKIA5110_H_

#include <memory>
#include <thread>
#include <chrono>
#include <string.h>

#include "SPI.h"
#include "GPIO.h"

const int display_cols = 84;
const int display_rows = 6;

class Nokia5110 {
private:
	std::string rst_pin, dc_pin, light_pin;
	std::unique_ptr<SPI> spi_dev;
	__u8 matrix[display_rows*display_cols];


	void reset_module();
	void send_cmd(__u8 value);
	void send_data(__u8 value);
	void send_data_buffer();

public:
	Nokia5110(std::string spidev, std::string rst_pin, std::string dc_pin, std::string light_pin);
	void light_on();
	void light_off();
	void clear_display(bool send_to_device);
	void copy_buffer(__u8* in_buffer, int len_buffer, bool send_to_device);
	void put_text(const char* text,int row, int col, bool send_to_device);
	virtual ~Nokia5110();
};

#endif /* NOKIA5110_H_ */
