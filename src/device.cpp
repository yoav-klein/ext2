
#include <sys/types.h> //open
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h> // lseek
#include <string.h> // strerror

#include "singleton.h" // Singleton<Logger>
#include "logger.h" // Logger
#include "device.h"

namespace filesystems
{

Device::Device()
	: m_logger(Singleton<Logger>::get_instance())
{
	LOG(Logger::DEBUG, "Ctor", __LINE__); 
}

Device::~Device()
{
	LOG(Logger::DEBUG, "Dtor", __LINE__);
}

void Device::setup_device(std::string device_path)
{
	LOG(Logger::DEBUG, "Setup device", __LINE__);
	m_device_path = device_path;
	open_device();
}

void Device::open_device()
{
	int fd = open(m_device_path.c_str(), O_RDONLY);
	if(-1 == fd)
	{
		throw CException(strerror(errno));
	}
	
	m_device_fd = fd;	
}

void Device::read(std::size_t from, std::size_t length, void* buffera)
{
	char* buffer = static_cast<char*>(buffera);
	if(-1 == lseek(m_device_fd, from, SEEK_SET))
	{
		throw CException(strerror(errno));
	}
	
	while(length)
	{
		int read_bytes = ::read(m_device_fd, buffer, length);
		if(-1 == read_bytes)
		{
			throw CException(strerror(errno));
		}
		length -= read_bytes;
		buffer += read_bytes;
	}
}

void Device::LOG(Logger::Severity sever, std::string msg, int line)
{
	m_logger->write(sever, "Device", msg, line);
}


} // filesystems
