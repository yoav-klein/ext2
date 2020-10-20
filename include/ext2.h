
#ifndef __EXT2_H__
#define __EXT2_H__

namespace filesystems
{

class Ext2
{
public:
	Ext2();
	~Ext2();
	

private:
	SuperBlock m_superblock;
	std::vector<BlockGroup> m_blockgroups;
	
};

} // filesystems

#endif // __EXT2_H__
