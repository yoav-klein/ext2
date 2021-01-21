
#ifndef __EXT2_H__
#define __EXT2_H__

#include <vector> // std::vector
#include <string> // std::string
#include <memory> // std::shared_ptr

#include "info.h" // Info
#include "superblock.h" // SuperBlock
#include "blockgroup.h" // BlockGroup
#include "file_raii.h" // FileDescriptor
#include "device.h" // Device

namespace filesystems
{

class Ext2
{
public:
	Ext2();
	~Ext2();
	Ext2(const Ext2&) = delete;
	Ext2& operator=(const Ext2&) = delete;
	
	void print_superblock();
	void print_root();
	
private:
	void LOG(Logger::Severity sever, std::string msg, int line);
	void init_blockgroups();
	
	Logger* m_logger;
	Info* m_info;
	SuperBlock m_superblock;
	std::vector<BlockGroup> m_blockgroups;
	Device* m_device;
};

} // filesystems

#endif // __EXT2_H__
