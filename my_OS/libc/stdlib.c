#include "stdlib.h"

// our kernel starts at 0x1000 
unsigned int free_memory_address = 0x10000;

// pointer to free memory location that increases itself
unsigned int kernel_memory(u32 size_to_allocate, u32 *physical_address)
{
	if(free_memory_address + size_to_allocate > 0x50000)
	{
		return -1;
	}

	if(physical_address)
	{
		*physical_address = free_memory_address;
	}

	unsigned int ret_address = free_memory_address;
	free_memory_address += size;
	return ret_address;
}