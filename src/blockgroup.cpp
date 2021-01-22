
#include <sstream> // ostringstream
#include "ext2_fs.h" // ext2 structs
#include "utils.h" // print_line
#include "blockgroup.h"

namespace filesystems
{

BlockGroup::BlockGroup(int index)
	: m_index(index), m_device(Singleton<Device>::get_instance()),
		m_logger(Singleton<Logger>::get_instance()), 
		m_info(Singleton<Info>::get_instance())
{
	std::ostringstream log_msg;
	log_msg << "Ctor of block group: " << index;
	LOG(Logger::DEBUG, log_msg.str(), __LINE__);
	read_descriptor();
	print_descriptor();
}

void BlockGroup::read_descriptor()
{
	std::ostringstream log_msg;
	
	m_start_block = m_info->first_data_block + (m_index * m_info->blocks_per_group);
	m_end_block = m_start_block + m_info->blocks_per_group - 1;

	std::size_t gd_first_block = m_info->first_data_block + 1;
	std::size_t descriptor_offset = m_info->block_offset(gd_first_block) + 
		sizeof(ext2_group_desc) * m_index;
	
	log_msg << "Reading from offset: " << descriptor_offset;
	LOG(Logger::DEBUG, log_msg.str(), __LINE__);
	
	m_device->read(descriptor_offset, sizeof(ext2_group_desc), &m_gd);
}

void BlockGroup::print_descriptor()
{
	std::cout << "--------- Block number : " << m_index << "-----------" << std::endl;
	print_line("Block Group Start", m_start_block);
	print_line("Block Group End", m_end_block);
	print_line("Block bitmap", m_gd.bg_block_bitmap);
	print_line("Inode bitmap", m_gd.bg_inode_bitmap);
	print_line("Inode table", m_gd.bg_inode_table);
	print_line("Free blocks", m_gd.bg_free_blocks_count);
	print_line("Free inodes", m_gd.bg_free_inodes_count);

}	

void BlockGroup::LOG(Logger::Severity sever, std::string msg, int line)
{
	m_logger->write(sever, "BlockGroup", msg, line);
}

} // filesystems
