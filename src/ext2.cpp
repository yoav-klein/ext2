
#include "ext2.h"
#include "singleton.h"

namespace filesystems
{

Ext2::Ext2(std::string device_path)
	: m_device_path(device_path), m_info(new Info()), m_superblock(m_info)
{
	LOG(Logger::DEBUG, "Ctor", __LINE__);
	m_device = Singleton<Device>::get_instance();
	m_device->setup_device(device_path);
}

Ext2::~Ext2()
{
	LOG(Logger::DEBUG, "Dtor", __LINE__);
}

void Ext2::LOG(Logger::Severity sever, std::string msg, int line)
{
	m_logger->write(sever, "Ext2", msg, line);
}

} // filesystems
