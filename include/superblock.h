
#ifndef __SUPERBLOCK_H__
#define __SUPERBLOCK_H__

#include "ext2_fs.h" // struct ext2_super_block

typedef unsigned int uint;

namespace filesystems
{

class SuperBlock
{
public:
	SuperBlock();
	~SuperBlock();
	
		
private:
	void read_super_block();
	
	int m_fd;
	struct ext2_super_block m_super_block;
};

} // filesystems

#endif // __SUPERBLOCK_H__
