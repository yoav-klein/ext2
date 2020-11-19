
#include "ext2.h"
#include "singleton.h"

namespace filesystems
{

Ext2::Ext2()
	: m_logger(Singleton<Logger>::get_instance()), m_info(new Info()), m_superblock(m_info), m_device(Singleton<Device>::get_instance())
{
	LOG(Logger::DEBUG, "Ctor", __LINE__);
}

Ext2::~Ext2()
{
	LOG(Logger::DEBUG, "Dtor", __LINE__);
}

void Ext2::print_superblock()
{
	m_superblock.print();
}

void Ext2::LOG(Logger::Severity sever, std::string msg, int line)
{
	m_logger->write(sever, "Ext2", msg, line);
}

} // filesystems
