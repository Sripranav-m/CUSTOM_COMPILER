section	.text
global main 
main:
push rbp
mov rbp , rsp
sub rsp , 8
sub rsp , 8
mov rcx , rbp
add rcx , -8
mov rax , 35
mov [rcx] , rax
mov rcx , rbp
add rcx , -16
mov rax , 45
mov [rcx] , rax
sub rsp , 8
mov rdx , rbp
add rdx , -8
mov r8, [rdx]
mov rax ,r8
mov rdx , rbp
add rdx , -16
mov r9, [rdx]
mov rbx ,r9
add rax , rbx
mov rcx , rbp
add rcx , -24
mov [rcx] , rax
mov rdx , rbp
add rdx , -24
mov r10, [rdx]
mov rax ,r8
mov rbx ,r9
sub rax , rbx
mov rcx , rbp
add rcx , -24
mov [rcx] , rax
mov rcx , rbp
add rcx , -24
mov r10, [rcx]
mov rax ,r8
mov rbx ,r9
mul rbx
mov rcx , rbp
add rcx , -24
mov [rcx] , rax
mov rcx , rbp
add rcx , -24
mov r10, [rcx]
mov  rsp, rbp
pop  rbp
mov rax , 60
mov rdi , 0
syscall




extern printf , scanf
section .data
intf: db "%ld",10,0 
chrf: db "%s",10,0 
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
digitSpace resb 100
digitSpacePos resb 8

