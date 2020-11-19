
#include <iostream> // std::cout
#include <exception> // Exception
#include <cstring> // strcmp
#include <memory> // std::shared_ptr

#include "device.h" // Device
#include "singleton.h" // Singleton
#include "logger.h" // Logger
#include "ext2.h" //Ext2


using namespace filesystems;
int main(int argc, char** argv)
{
	Logger* logger = Singleton<Logger>::get_instance();
	 
	if((2 == argc) && !strcmp(argv[1], "DEBUG"))
	{
		std::cout << "DEBUG MODE" << std::endl;
		logger->set_output_severity(Logger::DEBUG);
	}
	else
	{
		logger->set_output_severity(Logger::INFO);
	}
	
	try
	{
		Device* device = Singleton<Device>::get_instance();
		device->setup_device("/dev/ram0");
		Ext2 ext2;
		ext2.print_superblock();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	

	return 0;
}


