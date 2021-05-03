section	.text
global main 
main:
push rbp
mov rbp , rsp
sub rsp , 8
mov rcx , rbp
add rcx , -8
mov rax , 5
mov [rcx] , rax
sub rsp , 8
mov rcx , rbp
add rcx , -16
add rsp , -8
mov rdx , rbp
add rdx , -8
mov r8, [rdx]
mov [rsp],r8
mov rax , 1
call _fact
mov rcx , rbp
add rcx , -16
mov [rcx] , rax
add rsp ,8

mov rbx , rbp
add rbx , -16
mov rcx , [rbx]
mov rsi , rcx
mov rdi , intf
mov rax , 0
call printf

mov  rsp, rbp
pop  rbp
mov rax , 60
mov rdi , 0
syscall
_fact:
push rbp
mov rbp , rsp
add rsp , -8
mov rcx , rbp
add rcx , -8
mov rbx , rbp
add rbx , 16
mov rax, [rbx]
mov [rcx] , rax
add rcx , -8
add rbx , 8
LabelIf1:
mov rdx , rbp
add rdx , -8
mov r8, [rdx]
mov rax ,r8
mov rcx , 1
mov rbx , rcx
cmp rax , rbx
je NextSkip1
mov rax ,r8
mov rcx , 0
mov rbx , rcx
cmp rax , rbx
jne LabelElse1
NextSkip1:
mov rax , 1
jmp EndElse1
LabelElse1:
sub rsp , 8
sub rsp , 8
mov rax ,r8
mov rcx , 1
mov rbx , rcx
sub rax , rbx
mov rcx , rbp
add rcx , -24
mov [rcx] , rax
mov rdx , rbp
add rdx , -24
mov r9, [rdx]
mov rcx , rbp
add rcx , -16
add rsp , -8
mov [rsp],r9
mov rax , 1
call _fact
mov rcx , rbp
add rcx , -16
mov [rcx] , rax
add rsp ,8
mov rdx , rbp
add rdx , -16
mov r8, [rdx]
mov rax ,r8
mov rdx , rbp
add rdx , -8
mov r9, [rdx]
mov rbx ,r9
mul rbx
mov rcx , rbp
add rcx , -16
mov [rcx] , rax
mov rcx , rbp
add rcx , -16
mov r8, [rcx]
mov rbx , rbp
add rbx , -16
mov rax , [rbx]
EndElse1:
mov  rsp, rbp
pop  rbp
ret




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

