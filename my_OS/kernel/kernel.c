#include "../drivers/screen.h"
// kernel entry is really useful
// when there are more function other than main here
// because I concantrate into an image the boot_loader and afterwords the kernel
// and I jump to the start position of the kernel from the boot loader
// so it is important that the first command will be to jump to main
// whetever it might be with all the functions after


// void example_for_prevoius_note()
// {	
//		char y = 'a';
//		int x = y + 1;
// }
//
//


void main_entry_in_c()
{
	print("hello world from the kernel of Itay Barok");
}