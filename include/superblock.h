
#ifndef __SUPERBLOCK_H__
#define __SUPERBLOCK_H__

#include <memory> // std::shared_ptr
#include "ext2_fs.h" // struct ext2_super_block
#include "logger.h" // Logger
#include "info.h" // Info
#include "device.h" // Device

#define SUPERBLOCK_SIZE (1024)

typedef unsigned int uint;

namespace filesystems
{

class SuperBlock
{
public:
	SuperBlock(std::shared_ptr<Info> info);
	~SuperBlock();
	
	void print();
	
private:
	std::shared_ptr<Info> m_info;
	Device* m_device;
	void LOG(Logger::Severity sever, std::string msg, int line);
	Logger* m_logger;
	void read_superblock();
	
	int m_fd;
	struct ext2_super_block m_superblock;
};

} // filesystems

#endif // __SUPERBLOCK_H__
