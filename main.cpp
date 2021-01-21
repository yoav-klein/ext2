
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
	
	bool is_debug;
	if(argc < 2)
	{
		std::cout << "Usage: ext2.out <device_name> [DEBUG]" << std::endl;
		return 1;
	}
	if((2 < argc) && !strcmp(argv[2], "DEBUG"))
	{
		is_debug = true;
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
		device->setup_device(argv[1]);
		Ext2 ext2;
		ext2.print_superblock();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	

	return 0;
}


