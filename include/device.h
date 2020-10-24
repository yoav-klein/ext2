
#ifndef __DEVICE_H__
#define __DEVICE_H__

#include <string> // std::string
#include "file_raii.h" // FileDescriptor
#include "singleton.h" // Singleton<Device>
#include "exception.h" // CException

namespace filesystems
{

class Device
{
public:
	Device() = default;
	~Device() = default;
	Device(const Device&) = delete;
	Device& operator=(const Device&) = delete;
	Device& operator=(Device&&) = delete;
	
	void setup_device(const std::string device_name);
	void read(std::size_t from, std::size_t length, char* buffer); 

private:
	Device(Device&&) = delete;
	friend class Singleton<Device>;
		
	void open_device();
	std::string m_device_path;
	FileDescriptor m_device_fd;	
};

} // filesystems

#endif // __DEVICE_H__
