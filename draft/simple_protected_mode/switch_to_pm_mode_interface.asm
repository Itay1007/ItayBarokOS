; Jump into 32-bit mode methadology:
; Disable interrupts
; Load our GDT
; Set a bit on the CPU control register cr0
; Flush the CPU pipeline by issuing a carefully crafted far jump
; Update all the segment registers
; Update the stack
; Call to a well-known label which contains the first useful code in 32 bits


[bits 16]
switch_to_pm:
    ; no interrupts
	cli 
    ; load the gdt descriptor
	lgdt [gdt_descriptor]
    
	; set 32 bit mode bit in cr0 
	; can not add directly a number to cr0
	mov eax, cr0
	or eax, 0x1 
	mov cr0, eax 
	
	; jump far in oreder to change the segment by using a different segment
	jmp CODE_SEG:init_pm 

[bits 32]
init_pm: ; in pm :-)
    ; update the regular segment registers
	mov ax, DATA_SEG
    mov ds, ax
    mov ss, ax
    mov es, ax
    ; update the pm segment registers
	mov fs, ax
    mov gs, ax

	; update the stack right at the top of the free space
    mov ebp, 0x90000
    mov esp, ebp

	; function call to the protected mode entry point
    call pm_entry_code 