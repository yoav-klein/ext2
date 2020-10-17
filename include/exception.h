


#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <string>
#include <exception>
#include <stdexcept>


namespace filesystems 
{

class CException : public std::runtime_error
{
public:

	CException(const std::string msg);
	
};



} // namespace filesystems
#endif // __EXCEPTION_H__
