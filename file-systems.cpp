

#include <sys/types.h> //open
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream> // std::cout
#include "ext2_fs.h" // ext2_super_block
#include "exception.h" // CException

#define SUPERBLOCK_OFFSET (1024)
#define BLOCK_OFFSET(block) (1024 + (BLOCK_LEN * block))
#define GROUP_DESC_BASE_OFFSET(gd) (BLOCK_LEN + (gd * (sizeof(struct ext2_group_desc))))
#define GROUP_DESC_OFFSET(gd) ((BLOCK_LEN >= 2048) ? GROUP_DESC_BASE_OFFSET(gd) : (GROUP_DESC_BASE_OFFSET(gd) + SUPERBLOCK_OFFSET))


unsigned int BLOCK_LEN = 0;

namespace filesystems
{



int open_device(std::string device)
{
	int fd = open(device.c_str(), O_RDWR);
	
	if(-1 == fd)
	{
		throw CException(strerror(errno));
	}
	
	return fd;	
}

void print_super_block(struct ext2_super_block superblock)
{
	// print information
	
	print_line("inodes count", superblock.s_inodes_count);
	print_line("blocks count", superblock.s_blocks_count);
	print_line("reserved blocks", superblock.s_r_blocks_count);
	print_line("free blocks", superblock.s_free_blocks_count);
	print_line("free inodes", superblock.s_free_inodes_count);
	print_line("first data block", superblock.s_first_data_block);
	print_line("log block size", superblock.s_log_block_size);
	print_line("log frag size", superblock.s_log_frag_size);
	print_line("blocks per group", superblock.s_blocks_per_group);
	print_line("frags per group" , superblock.s_frags_per_group);
	print_line("inodes_per_group", superblock.s_inodes_per_group);
	print_line("first inode", superblock.s_first_ino);
	print_line("mounted on", (char*)&superblock.s_last_mounted);
	
	std::cout << "=== Diagnostics ===" << std::endl;
	print_line("num of block groups", (superblock.s_blocks_count / superblock.s_blocks_per_group) +
				((superblock.s_blocks_count % superblock.s_blocks_per_group) != 0));
	
	unsigned int inodes_per_block = BLOCK_LEN / sizeof(struct ext2_inode);
	print_line("inodes per block", inodes_per_block);
	unsigned int inode_blocks_per_group = superblock.s_inodes_per_group / inodes_per_block;
	print_line("num of blocks for inodes", inode_blocks_per_group);
	
	//print_line();
	//print_line();
	//print_line();
	//print_line();
}

void read_super_block(int fd, struct ext2_super_block* superblock)
{
	
	if(-1 == lseek(fd, SUPERBLOCK_OFFSET, SEEK_SET))
	{
		throw CException(strerror(errno));
	}
	
	int read_bytes = read(fd, superblock, sizeof(*superblock));
	if(read_bytes < (int)sizeof(*superblock))
	{
		if(-1 == read_bytes)
		{
			throw CException(strerror(errno));
		}
		
		std::cout << "Not all bytes read! number of bytes read: " << read_bytes << std::endl; 
	}
	
	BLOCK_LEN = 1024 << superblock->s_log_block_size;
}

void read_group_descriptor(int fd, int gd_num, struct ext2_group_desc* gd)
{
	if(-1 == lseek(fd, GROUP_DESC_OFFSET(gd_num), SEEK_SET))
	{
		throw CException(strerror(errno));
	}
	
	int read_bytes = read(fd, gd, sizeof(struct ext2_group_desc));
	std::cout << "read bytes: " << read_bytes << std::endl;
	if(-1 == read_bytes)
	{
		throw CException(strerror(errno));
	}
}

void print_group_descriptor(struct ext2_group_desc gd)
{
	print_line("bg_block_bitmap", gd.bg_block_bitmap);
	print_line("bg_inode_bitmap", gd.bg_inode_bitmap);
	print_line("bg_inode_table", gd.bg_inode_table);
	print_line("bg_free_blocks_count", gd.bg_free_blocks_count);
	print_line("bg_free_inodes_count", gd.bg_free_inodes_count);
	print_line("bg_used_dirs_count", gd.bg_used_dirs_count);
}

} // filesystems

using namespace filesystems;


int main(int argc, char** argv)
{
	(void)argc;
	int fd = 0;
	if(0 == argv[1])
	{
		std::cout << "Enter device path" << std::endl;
		
		return 1;
	}
	std::string device = argv[1];
	
	std::cout << "Opening: " << device << std::endl;
	struct ext2_super_block superblock = { 0 };	
	struct ext2_group_desc group_desc = { 0 };
	
	try
	{
		fd = open_device(device);	
		read_super_block(fd, &superblock);
		print_super_block(superblock);
		
		
		std::cout << "===========Block Group 0==========================" << std::endl;
		read_group_descriptor(fd, 0, &group_desc);
		print_group_descriptor(group_desc);
		
		std::cout << "===========Block Group 1==========================" << std::endl;
		group_desc = { 0 };
		
		read_group_descriptor(fd, 1, &group_desc);
		print_group_descriptor(group_desc);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
		
		return 1;
	}
	
	close(fd);
	
	return 0;
}
