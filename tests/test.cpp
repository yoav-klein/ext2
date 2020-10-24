
#include <iostream>

#include "exception.h"
#include "logger.h"
#include "device.h"
#include "singleton.h"

using namespace filesystems;


int main()
{
	Device* device = Singleton<Device>::get_instance();
	
	return 0;
}
