
#include <iostream> // std::cout
#include <exception> // Exception
#include <cstring> // strcmp

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
		Ext2 ext2("/dev/ram0");
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	

	return 0;
}
