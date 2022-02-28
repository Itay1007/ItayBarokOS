[bits 32]

VIDEO_MEMORY equ 0xb800
WHITE_ON_BLACK equ 0x0f

print_string_pm:
	pusha
	
	mov edx, VIDEO_MEMORY
	
	repeat:
		mov al, [ebx]
		mov ah, WHITE_ON_BLACK
		
		cmp al, 0
		je end
		
		mov [edx], ax
		add ebx, 1
		add edx, 2
		
		jmp repeat
		
	end:
		popa
		ret