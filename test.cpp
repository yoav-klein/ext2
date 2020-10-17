
#include <iostream>

#include "exception.h"

using namespace filesystems;

int main()
{
	try
	{
		throw CException("Ohh..");
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
	
}
