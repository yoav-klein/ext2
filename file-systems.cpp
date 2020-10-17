
#include <unistd.h> // read
#include <sys/types.h> //open
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream> // std::cout
#include "ext2_fs.h" // ext2_super_block

#define BLOCK_SIZE 1024
#define SUPERBLOCK_OFFSET 1024
#define BLOCK_OFFSET(block) (block * BLOCK_SIZE)

template<typename T>
void print_line(std::string field, T value)
{
	std::cout.width(20); std::cout << std::left << field;
	std::cout.width(20); std::cout << std::left << value << std::endl;
}

int open_device()
{
	int fd = open("/dev/ram0", O_RDWR);
	
	if(-1 == fd)
	{
		perror("Couldn't open /dev/ram0");
		throw std::exception("");
	}
	
	return fd;	
}

void read_super_block()
{
	struct ext2_super_block superblock;
	
	if(-1 == lseek(fd, SUPERBLOCK_OFFSET, SEEK_SET))
	{
		perror("lseek failed");
		
		return;
	}
	
	int read_bytes = read(fd, &superblock, sizeof(superblock));
	if(read_bytes < sizeof(superblock))
	{
		if(-1 == read_bytes)
		{
			perror("read error");
			
			return;
		}
		std::cout << "Not all bytes read! number of bytes read: " << read_bytes << std::endl; 
	}
	
	// print information
	print_line("inodes count", superblock.s_inodes_count);
	print_line("blocks count", superblock.s_blocks_count);
	print_line("reserved blocks", superblock.s_r_blocks_count);
	print_line("free blocks", superblock.s_free_blocks_count);
	print_line("block size", superblock.s_block_size);
	//print_line();
	//print_line();
	//print_line();
	//print_line();
	//print_line();
	//print_line();
	
	
	
	close(fd);
	
}



int main()
{

	int fd = 0;
	 = open_device();
	
	try
	{
		
	}
	if(-1 == fd)
	{	
		return 1;
	}
	
	struct ext2_group_desc group_desc = { 0 };
	
	read_super_block();
	
	read_group_descriptor();
	
	return 0;
}
