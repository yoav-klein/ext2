
#ifndef __BLOCKGROUP_H__
#define __BLOCKGROUP_H__

#include "device.h" // Device
#include "logger.h" // Logger
#include "singleton.h" // Singleton

namespace filesystems
{

class BlockGroup
{
public:
	BlockGroup(int index);
	
private:
	void read_descriptor();	
	void LOG(Logger::Severity sever, std::string msg, int line);
	
	unsigned int m_start_block;
	unsigned int m_end_block;
	unsigned int m_index;
	Device* m_device;
	Logger* m_logger;
};

} // filesystems

#endif // __BLOCKGROUP_H__
