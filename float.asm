       extern printf , scanf


	
	section	.data  		
	
str : db 

fmt:    db "c=%lf",10,0	
	
	section .bss 		
c:	resq	1		

	section .text		
	global	main		
main:			

	push	rbp		

    mov rbp , rsp



    mov dword[rsp] , __float32__(6.234)

    finit
    fld dword[rsp]
	fstp qword [c]	
    mov rdi , fmt
    mov rsi , str
    movq xmm0 , qword[c] 
    call printf
	
	
mov rax , 60
mov rdi , 0
syscall