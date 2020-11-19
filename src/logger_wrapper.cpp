
#include "logger_wrapper.h"

namespace filesystems
{
	
LoggerWrapper::LoggerWrapper(std::string module_)
	: m_logger(Singleton<Logger>::get_instance()), m_module(module_)
{
}

void LoggerWrapper::LOG(Logger::Severity severity, std::string msg, int line)
{
	m_logger->write(severity, m_module, msg, line);
}

} // filesystems
