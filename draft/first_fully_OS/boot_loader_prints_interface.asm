
segment .text:
	.global print_string

print_string:
	pusha
	
	repeat:
		mov si, bx
		mov byte al, [si]
		mov ah, 0x0e
		cmp al, 0
		je print_string_end
		int 0x10
		inc si
		jne repeat

print_string_end:
	popa
	ret
	
print_new_line:
	pusha ; save do not break the registers values
	
	mov ah, 0x0e
	; new line
	mov al, 0xa
	int 0x10
	; carriage return
	mov al, 0x0d
	int 0x10
	
	popa ; pop back do not break the registers values
	ret
	
print_hex:
	pusha
	
	mov cx, 0
	
	repeat:
		cmp cx, 0x04
		je print_hex_end
		
		mov ax, bx
		and ax, 0x000F
		add ax, 0x30
		cmp al, 0x39 ; check if char or digit
		jle placing_character
		add ax, 0x07
	
		placing_character:
			push bx
			mov bx, output + 5
			sub bx, cx
			mov [bx], al
			pop bx
			ror bx, 4
	
			inc cx
			jmp repeat
	
	print_hex_end:
	
	mov bx, output
	call print_string

	popa
	ret
	
	
	output:
		db "0x0000", 0 ; keep memory for the building string output