
#include <iostream>
#include "ext2_fs.h"
/*
#include "tools.h"
#include "exception.h"
#include "logger.h"
#include "device.h"
#include "singleton.h"
*/
//using namespace filesystems;


int main(int argc, char** argv)
{
	#ifdef DEBUG
	std::cout << "DEBUG" << std::endl;
	#endif	
	std::cout << sizeof(struct ext2_inode) << std::endl;
	
	/*Logger* logger = Singleton<Logger>::get_instance();
	logger->set_output_severity(Logger::Severity::DEBUG);
	
	Device* device = Singleton<Device>::get_instance();
	std::cout << "HERE" << std::endl;
	logger->write(Logger::Severity::ERROR, BOLDON REDL "Main" RESET, "Testttt", __LINE__);
	*/
	return 0;
}
