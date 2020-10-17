
#include <string>
#include "exception.h"

namespace filesystems
{
	CException::CException(const std::string msg)
		: std::runtime_error(msg)
	{
	}

} // filesystems

