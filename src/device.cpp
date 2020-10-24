
#include <sys/types.h> //open
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h> // lseek
#include <string.h> // strerror

#include "device.h"

namespace filesystems
{

void Device::open_device()
{
	int fd = open(m_device_path.c_str(), O_RDONLY);
	if(-1 == fd)
	{
		throw CException(strerror(errno));
	}
	
	m_device_fd = fd;	
}

void Device::read(std::size_t from, std::size_t length, char* buffer)
{
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


} // filesystems
