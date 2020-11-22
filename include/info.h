
#ifndef __INFO_H__
#define __INFO_H__

#include <iostream>

namespace filesystems
{

struct Info
{
	Info()
		: num_groups(0), block_size(0), first_data_block(0) 
	{}

	const std::size_t BASE_OFFSET = 1024;
	unsigned int num_groups;
	unsigned int block_size;
	unsigned int first_data_block;
	
	inline unsigned int block_offset(unsigned int block_num)
	{
		return (block_size * block_num);
	}
};

} // filesystems

#endif // __INFO_H__
