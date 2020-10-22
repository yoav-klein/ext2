
#include <string.h> // strerror
#include <unistd.h> // read
#include "utils.h"

namespace filesystems
{

void read_all(int fd, char* buffer, std::size_t len)
{
	
	while(len)
	{
		int read_bytes = read(fd, buffer, len);
		if(-1 == read_bytes)
		{
			throw CException(strerror(errno));
		}
		len -= read_bytes;
		buffer += read_bytes;
	}
}
	
} // filesystems
