
#include <iostream>

#include "exception.h"

using namespace filesystems;

#define ENDIAN std::cout << *(int*)"\0\0\0f" << std::endl;

int main()
{
	//std::cout << (void*)((char*)&1)  << std::endl;
	int a = 6;
	int b = *(char*)&a;
	
	ENDIAN
	
	std::cout << b;
	return 0;
	
}
