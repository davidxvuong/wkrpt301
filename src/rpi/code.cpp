#include <iostream>
#include <errno.h>
#include <wiringPiI2C.h>
	
int main(void) {
	int fd, result;

	fd = wiringPiI2CSetup(0x08);
	result = wiringPiI2CRead(fd);

	std::cout << result <<std::endl;
}