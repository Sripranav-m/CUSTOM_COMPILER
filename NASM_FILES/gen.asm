section .bss
digitSpace resb 100
digitSpacePos resb 8
section	.text
global _start 
_start:
push rbp
mov rbp , rsp
sub rsp , 8
mov rcx , 23
mov rax , rcx
mov rcx , 120
mov rbx , rcx
isub rax , rbx
mov rcx , rbp
add rcx , -8
mov [rcx] , rax
mov rbx , rbp
add rbx , -8
mov rax , [rbx]
call _printRAX
mov rax , 60
mov rdi , 0
syscall
_printRAX:
mov rcx, digitSpace
mov rbx, 10
mov [rcx], rbx
inc rcx
mov [digitSpacePos], rcx
_printRAXLoop:
mov rdx, 0
mov rbx, 10
div rbx
push rax
add rdx, 48
mov rcx, [digitSpacePos]
mov [rcx], dl
inc rcx
mov [digitSpacePos], rcx
pop rax
cmp rax, 0
jne _printRAXLoop
_printRAXLoop2:
mov rcx, [digitSpacePos]
mov rax, 1
mov rdi, 1
mov rsi, rcx
mov rdx, 1
syscall
mov rcx, [digitSpacePos]
dec rcx
mov [digitSpacePos], rcx
cmp rcx, digitSpace
jge _printRAXLoop2
ret
