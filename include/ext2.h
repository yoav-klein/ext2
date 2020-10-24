
#ifndef __EXT2_H__
#define __EXT2_H__

#include <vector> // std::vector
#include <string> // std::string

#include "superblock.h" // SuperBlock
#include "blockgroup.h" // BlockGroup
#include "file_raii.h" // FileDescriptor
#include "device.h" // Device

namespace filesystems
{

class Ext2
{
public:
	Ext2(std::string device_path);
	~Ext2() = default;
	Ext2(const Ext2&) = delete;
	Ext2& operator=(const Ext2&) = delete;
	
private:
	std::string m_device_path;
	SuperBlock m_superblock;
	std::vector<BlockGroup> m_blockgroups;
	Device* m_device;
};

} // filesystems

#endif // __EXT2_H__
