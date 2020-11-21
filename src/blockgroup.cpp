
#include "blockgroup.h"

namespace filesystems
{

BlockGroup::BlockGroup(int index)
	: m_index(index), m_device(Singleton<Device>::get_instance()),
		m_logger(Singleton<Logger>::get_instance())
{
	LOG(Logger::DEBUG, "Ctor of block group: " + index, __LINE__);
	read_descriptor(); 
}
	
void BlockGroup::read_descriptor()
{
	
}	

void BlockGroup::LOG(Logger::Severity sever, std::string msg, int line)
{
	m_logger->write(sever, "BlockGroup", msg, line);
}

} // filesystems
