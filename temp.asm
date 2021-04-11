section	.text
global main 
main:
push rbp
mov rbp , rsp
sub rsp , 8
mov rcx , rbp
add rcx , -8
mov qword[rcx] , __float32__(1.234)
sub rsp , 8

mov rbx , rbp
add rbx , -8
add rsp , -8
fld dword[rbx]
fstp qword[temp]
mov rdi , fmtf
movq xmm0 , qword[temp]
mov rax , 1
call printf
add rsp , 8

mov  rsp, rbp
pop  rbp
mov rax , 60
mov rdi , 0
syscall


extern printf , scanf
section .data
intf: db "%ld",10,0 
lisfs: dq "[%ld ",32,0 
lisf: dq "%ld ",32,0 
lisfe: db "%ld]",10,0 
fmtf: db "%lf",10,0 
intin: db "%ld",0
floatin: db "%lf",0
integer:times 4 db 0


section .bss
scanned resb 16
temp : resq 1
temq : resq 1

section	.text
global main 
main:
push rbp
mov rbp , rsp
sub rsp , 8
mov rcx , rbp
add rcx , -8
mov qword[rcx] , __float32__(1.234)
sub rsp , 8

mov rbx , rbp
add rbx , -8
add rsp , -8
fld dword[rbx]
fstp qword[temp]
mov rdi , fmtf
movq xmm0 , qword[temp]
mov rax , 1
call printf
add rsp , 8

mov  rsp, rbp
pop  rbp
mov rax , 60
mov rdi , 0
syscall


extern printf , scanf
section .data
intf: db "%ld",10,0 
lisfs: dq "[%ld ",32,0 
lisf: dq "%ld ",32,0 
lisfe: db "%ld]",10,0 
fmtf: db "%lf",10,0 
intin: db "%ld",0
floatin: db "%lf",0
integer:times 4 db 0


section .bss
scanned resb 16
temp : resq 1
temq : resq 1

