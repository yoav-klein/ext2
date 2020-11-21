
#include "ext2.h"
#include "singleton.h"

namespace filesystems
{

Ext2::Ext2()
	: m_logger(Singleton<Logger>::get_instance()), 
		m_info(Singleton<Info>::get_instance()), m_superblock(), 
		m_device(Singleton<Device>::get_instance())
{
	LOG(Logger::DEBUG, "Ctor", __LINE__);
	init_blockgroups();
	
}

void Ext2::init_blockgroups()
{
	for(unsigned int i = 0; i < m_info->num_groups; ++i)
	{
		m_blockgroups.push_back(BlockGroup(i));
	}
}

Ext2::~Ext2()
{
	LOG(Logger::DEBUG, "Dtor", __LINE__);
}

void Ext2::print_superblock()
{
	m_superblock.print();
	std::cout << "---------------" << std::endl;
	std::cout << "stats:" << std::endl;
	std::cout << "num groups: " << m_info->num_groups << std::endl;
	std::cout << "Block size: " << m_info->block_size << std::endl;
}

void Ext2::LOG(Logger::Severity sever, std::string msg, int line)
{
	m_logger->write(sever, "Ext2", msg, line);
}

} // filesystems
