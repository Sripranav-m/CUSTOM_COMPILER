section	.text
	global _start       
_start:
    mov eax , [a]
    add eax , 15
    mov [a] , eax

    mov eax , 4
    mov ebx , 1
    mov ecx , a
    mov edx , 1
    int 0x80

    mov eax , 1
    mov ebx , 0
    int 0x80
; 	mov	edx, len    
; 	mov	ecx, msg    ;message to write
; 	mov	ebx, 1	    ;file descriptor (stdout)
; 	mov	eax, 4	    ;system call number (sys_write)
; 	int	0x80        ;call kernel
; 	mov	eax, 1	    ;system call number (sys_exit)
; 	int	0x80        ;call kernel

section	.data
a : db 0
b : db 0
c : db 0

; msg	db	'Hello, world!',0xa	;our dear string
; len	equ	$ - msg			;length of our dear string