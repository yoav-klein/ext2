

#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__


#include <exception>

class CException : public std::exception
{

	CException(std::string msg);
	
	const char* what() override;
}


#endif // __EXCEPTION_H__
