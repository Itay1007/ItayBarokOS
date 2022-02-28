C_SOURCES = $( wildcard kernel/*.c drivers/*.c libc/*.c)
HEADERS = $( wildcard kernel/*.h drivers/*.h libc/*.h)

OBJ = $ { C_SOURCES :.c =.o}

all : os-image

run : all
bochs

os-image : boot/boot_loader.bin kernel.bin
cat $^ > os - image

kernel.bin : boot/kernel_entry.o ${ OBJ }
ld -o $@ - Ttext 0 x1000 $^ -- oformat binary

%.o : %. c $ { HEADERS }
gcc - ffreestanding -c $ < -o $@

%.o : %.asm
nasm $ < -f elf -o $@

%.bin : %.asm
nasm $ < -f bin -I ’../../16 bit /’ -o $@

clean :
rm -fr *.bin *.dis *. o os-image
rm -fr kernel/*.o boot/*.bin drivers/*.o libc/*.o
