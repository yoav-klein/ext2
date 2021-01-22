
#include "singleton.h" // Singleton<Logger>
#include "utils.h" // print_line

#include "ext2.h"

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
	
	print_line("num groups", m_info->num_groups);
	print_line("Block size", m_info->block_size);
	print_line("First block", m_info->first_data_block);

	
}

void Ext2::print_root()
{
	struct ext2_group_desc first_group_desc;
	
}

void Ext2::LOG(Logger::Severity sever, std::string msg, int line)
{
	m_logger->write(sever, "Ext2", msg, line);
}

} // filesystems
