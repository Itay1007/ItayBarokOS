;
; A simple boot sector program that loops forever.
;

loop :

jmp loop



times 510 -( $ - $$ ) db 0 ; When compiled , our program must fit into 512 bytes

; with the last two bytes being the magic number ,
; so here , tell our assembly compiler to pad out our
; program with enough zero bytes (db 0) to bring us to the
; 510 th byte.

dw 0xaa55 