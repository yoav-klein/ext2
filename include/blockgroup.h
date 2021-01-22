
#ifndef __BLOCKGROUP_H__
#define __BLOCKGROUP_H__

#include "device.h" // Device
#include "logger.h" // Logger
#include "singleton.h" // Singleton
#include "info.h" // Info

namespace filesystems
{

class BlockGroup
{
public:
	BlockGroup(int index);
	void print_descriptor();
	
private:
	void read_descriptor();
	void LOG(Logger::Severity sever, std::string msg, int line);
	
	struct ext2_group_desc m_gd;
	unsigned int m_index;
	unsigned int m_start_block;
	unsigned int m_end_block;
	Device* m_device;
	Logger* m_logger;
	Info* m_info;
};

} // filesystems

#endif // __BLOCKGROUP_H__
