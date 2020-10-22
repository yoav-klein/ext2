
#ifndef __UTILS_H__
#define __UTILS_H__

#include <iostream> // std::cout
#include "exception.h"

namespace filesystems 
{

void read_all(int fd, char* buffer, std::size_t len);
//void write_all(int fd, char* buffer, std::size_t len);
	

template<typename T>
void print_line(std::string field, T value)
{
	std::cout.width(30); std::cout << std::left << field;
	std::cout.width(30); std::cout << std::left << value << std::endl;
}

} // filesystems


#endif // __UTILS_H__
