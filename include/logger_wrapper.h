
#ifndef __LOGGER_WRAPPER_H__
#define __LOGGER_WRAPPER_H__

#include "logger.h" // Logger
#include "singleton.h" // Singleton<Logger>

namespace filesystems
{

class LoggerWrapper
{
public:
	LoggerWrapper(std::string module_);
	
	void LOG(Logger::Severity severity, std::string msg, int line);
	
private:
	Logger* m_logger;
	std::string m_module;
};

} // filesystems

#endif // __LOGGER_WRAPPER_H__
