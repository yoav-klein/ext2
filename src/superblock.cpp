
#include "superblock.h" // Superblock
#include "device.h" // Device
#include "singleton.h" // Singleton
#include "utils.h" // print_line

namespace filesystems
{

SuperBlock::SuperBlock()
{

}
void SuperBlock::read_superblock()
{
	Device* device = Singleton<Device>::get_instance();
}


void SuperBlock::print()
{
	// print information
	
	print_line("inodes count", m_superblock.s_inodes_count);
	print_line("blocks count", m_superblock.s_blocks_count);
	print_line("reserved blocks", m_superblock.s_r_blocks_count);
	print_line("free blocks", m_superblock.s_free_blocks_count);
	print_line("free inodes", m_superblock.s_free_inodes_count);
	print_line("first data block", m_superblock.s_first_data_block);
	print_line("log block size", m_superblock.s_log_block_size);
	print_line("log frag size", m_superblock.s_log_frag_size);
	print_line("blocks per group", m_superblock.s_blocks_per_group);
	print_line("frags per group" , m_superblock.s_frags_per_group);
	print_line("inodes_per_group", m_superblock.s_inodes_per_group);
	print_line("first inode", m_superblock.s_first_ino);
	print_line("mounted on", (char*)&m_superblock.s_last_mounted);
	/*
	std::cout << "=== Diagnostics ===" << std::endl;
	std::size_t num_block_groups = (m_superblock.s_blocks_count / m_superblock.s_blocks_per_group);
	num_block_groups += (m_superblock.s_blocks_count % m_superblock.s_blocks_per_group != 0);
	print_line("num of block groups", num_block_groups);
	
	unsigned int inodes_per_block = BLOCK_LEN / sizeof(struct ext2_inode);
	print_line("inodes per block", inodes_per_block);
	unsigned int inode_blocks_per_group = m_superblock.s_inodes_per_group / inodes_per_block;
	print_line("num of blocks for inodes", inode_blocks_per_group);
	*/
	//print_line();
	//print_line();
	//print_line();
	//print_line();
}

} // filesystems
