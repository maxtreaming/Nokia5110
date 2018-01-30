/*
 * main.cpp
 *
 *  Created on: Jan 30, 2018
 *      Author: maxime
 */

#include <iostream>
#include <ctime>
#include "Nokia5110.h"

int main()
{
	Nokia5110 display("spidev0.0", "PA01", "PA00", "PA03");
	display.light_off();
	while(1)
	{
		time_t t = time(nullptr);
		char current_date[100];
		char current_time[100];
		strftime(current_date, sizeof(current_date), "%d.%m.%Y", std::localtime(&t));
		strftime(current_time, sizeof(current_time), "%H:%M:%S", std::localtime(&t));

		display.clear_display(false);
		display.put_text(current_date, 2, 12, false);
		display.put_text(current_time, 3, 18, true);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}

	return 0;
}


