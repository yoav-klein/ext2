
#ifndef __DEVICE_H__
#define __DEVICE_H__

#include <string> // std::string
#include "file_raii.h" // FileDescriptor
#include "exception.h" // CException

namespace filesystems
{

class Device
{
public:
	Device(std::string device_path);
	~Device();
	
	void read(std::size_t from, std::size_t length, char* buffer); 

private:
	void open_device();
	
	std::string m_device_path;
	FileDescriptor m_device_fd;	
};

} // filesystems

#endif // __DEVICE_H__
