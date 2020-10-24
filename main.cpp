
#include <iostream> // std::cout
#include <exception> // Exception
#include "ext2.h" //Ext2

using namespace filesystems;
int main()
{

	try
	{
		Ext2 ext2("/dev/ram0");
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	

	return 0;
}
