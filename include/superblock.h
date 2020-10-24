
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
	~SuperBlock() = default;
	
	
	void print();
	
private:
	void read_superblock();
	
	int m_fd;
	struct ext2_super_block m_superblock;
};

} // filesystems

#endif // __SUPERBLOCK_H__
