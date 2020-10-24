
#include "ext2.h"
#include "singleton.h"

namespace filesystems
{

Ext2::Ext2(std::string device_path)
	: m_device_path(device_path)
{
	m_device = Singleton<Device>::get_instance();
	m_device->setup_device(device_path);
}


} // filesystems
