section .bss
digitSpace resb 100
digitSpacePos resb 8
scanned resb 16
section	.text
global _start 
_start:
push rbp
mov rbp , rsp
sub rsp , 8
mov rax, 15
mov [rsp] , rax
sub rsp , 120
sub rsp , 8
mov rcx , rbp
add rcx , -136
mov rax , 12
mov [rcx] , rax
mov rax , 0
mov rdi , 0
mov rsi , scanned
mov rdx , 16
syscall
xor rax, rax
mov rdx , scanned
top:
movzx rcx , byte [rdx]
add rdx , 1
cmp rcx , '0' 
jl done
cmp rcx , '9' 
jg done
sub rcx , '0'
imul rax , 10
add rax , rcx
jmp top
done:
mov rcx , rbp
add rcx , -136
mov [rcx] , rax
mov rbx , rbp
add rbx , -136
mov rax , [rbx]
call _printRAX
sub rsp , 8
mov rcx , rbp
add rcx , -144
mov rax , 15
mov [rcx] , rax
mov rbx , rbp
add rbx , -144
mov rax , [rbx]
call _printRAX
sub rsp , 8
mov rcx , rbp
add rcx , -152
mov rax , 14
mov [rcx] , rax
mov rbx , rbp
add rbx , -152
mov rax , [rbx]
call _printRAX
mov rbx , rbp
add rbx , -144
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
