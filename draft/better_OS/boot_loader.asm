[org 0x7c00]

KERNEL_OFFSET_FROM_BOOT_LOADER equ 0x1000

	mov [BOOT_DRIVE], dl

	mov bp, 0x9000
	mov sp, bp

	mov bx, MSG_REAL_MODE
	call print_string

	call print_new_line

	call load_kernel

	call switch_to_pm

	jmp $

%include "boot_loader_pm_print_interface.asm"
%include "boot_loader_prints_interface.asm"
%include "gdt_pm.asm"
%include "boot_loader_disks_interface.asm"
%include "switch_to_pm_mode_interface.asm"

[bits 16]

load_kernel:
	mov bx, MSG_LOAD_KERNEL
	call print_string
	call print_new_line
	mov bx, KERNEL_OFFSET_FROM_BOOT_LOADER
	mov dh, 15
	mov dl, [BOOT_DRIVE]
	call disk_load

; here we get after reaching to protected mode

[bits 32]

pm_entry_code:
	mov ebx, MSG_PROT_MODE
	call print_string_pm
	
	call KERNEL_OFFSET_FROM_BOOT_LOADER ; get into the loaded kernel code in mainly the high level C
	
	jmp $
	
BOOT_DRIVE db 0
MSG_REAL_MODE db "Started in 16-bit Real Mode", 0
MSG_PROT_MODE db "Successfuly landed in 32-bit Protected Mode", 0
MSG_LOAD_KERNEL db "Loading kernel into memory.", 0


times 510 - ($ - $$) db 0
dw 0xaa55