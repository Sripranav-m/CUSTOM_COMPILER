section	.text
global main 
main:
push rbp
mov rbp , rsp
sub rsp , 8
sub rsp , 56
mov rcx , rbp
add rcx , -64
mov rax , 5
mov [rcx] , rax
add rcx , 8
mov rax , 23
mov [rcx] , rax
add rcx , 8
mov rax , 46
mov [rcx] , rax
add rcx , 8
mov rax , 78
mov [rcx] , rax
add rcx , 8
mov rax , 4
mov [rcx] , rax
add rcx , 8
mov rax , 35
mov [rcx] , rax
add rcx , 8
mov rax , 19
mov [rcx] , rax
mov rax , 7
mov rcx , rbp
add rcx , -8
mov [rcx] , rax
sub rsp , 8
sub rsp , 8
sub rsp , 8
sub rsp , 8
sub rsp , 8
sub rsp , 8
mov rcx , rbp
add rcx , -8
mov rax , [rcx]
add rax , -1
mov [rcx] , rax
mov rcx , rbp
add rcx , -72
mov rax , 0
mov [rcx] , rax
LabelFor1:
mov rdx , rbp
add rdx , -72
mov r8, [rdx]
mov rax ,r8
mov rdx , rbp
add rdx , -8
mov r9, [rdx]
mov rbx ,r9
cmp rax , rbx
jge EndFor1
mov rax ,r9
mov rbx ,r8
sub rax , rbx
mov rcx , rbp
add rcx , -88
mov [rcx] , rax
mov rdx , rbp
add rdx , -88
mov r10, [rdx]
mov rcx , rbp
add rcx , -80
mov rax , 0
mov [rcx] , rax
LabelFor2:
mov rdx , rbp
add rdx , -80
mov r11, [rdx]
mov rax ,r11
mov rbx ,r10
cmp rax , rbx
jge EndFor2
mov rax , rbp
add rax , -80
mov rbx , 7
mov rcx , [rax]
sub rbx , rcx
sub  rbx , 1
mov rax , 8
mul rbx
mov rbx , rax
mov rcx , rbp
add rcx , -64
add rcx , rbx
mov rax , [rcx]
mov rcx , rbp
add rcx , -96
mov [rcx] , rax
mov rax ,r11
mov rcx , 1
mov rbx , rcx
add rax , rbx
mov rcx , rbp
add rcx , -112
mov [rcx] , rax
mov rdx , rbp
add rdx , -112
mov r12, [rdx]
mov rax , rbp
add rax , -112
mov rbx , 7
mov rcx , [rax]
sub rbx , rcx
sub  rbx , 1
mov rax , 8
mul rbx
mov rbx , rax
mov rcx , rbp
add rcx , -64
add rcx , rbx
mov rax , [rcx]
mov rcx , rbp
add rcx , -104
mov [rcx] , rax
LabelIf3:
mov rdx , rbp
add rdx , -96
mov r13, [rdx]
mov rax ,r13
mov rdx , rbp
add rdx , -104
mov r14, [rdx]
mov rbx ,r14
cmp rax , rbx
jle EndIf3
mov rax , rbp
add rax , -80
mov rbx , 7
mov rcx , [rax]
sub rbx , rcx
sub  rbx , 1
mov rax , 8
mul rbx
mov rbx , rax
mov rcx , rbp
add rcx , -64
add rcx , rbx
mov rax , [rcx]
mov rcx , rbp
add rcx , -96
mov [rcx] , rax
mov rax , rbp
add rax , -112
mov rbx , 7
mov rcx , [rax]
sub rbx , rcx
sub  rbx , 1
mov rax , 8
mul rbx
mov rbx , rax
mov rcx , rbp
add rcx , -64
add rcx , rbx
mov rax , [rcx]
mov rcx , rbp
add rcx , -104
mov [rcx] , rax
mov rax , rbp
add rax , -80
mov rbx , 7
mov rcx , [rax]
sub rbx , rcx
sub rbx , 1
mov rax , 8
mul rbx
mov rbx , rax
mov rcx , rbp
add rcx , -64
add rcx , rbx
mov rdx , rbp
add rdx , -104
mov rax , [rdx]
mov [rcx] , rax
mov rax , rbp
add rax , -112
mov rbx , 7
mov rcx , [rax]
sub rbx , rcx
sub rbx , 1
mov rax , 8
mul rbx
mov rbx , rax
mov rcx , rbp
add rcx , -64
add rcx , rbx
mov rdx , rbp
add rdx , -96
mov rax , [rdx]
mov [rcx] , rax
EndIf3:
mov rcx , rbp
add rcx , -80
mov rax , [rcx]
add rax , 1
mov [rcx] , rax
jmp LabelFor2
EndFor2:
mov rcx , rbp
add rcx , -72
mov rax , [rcx]
add rax , 1
mov [rcx] , rax
jmp LabelFor1
EndFor1:

mov rbx , rbp
add rbx , -16
mov rax , [rbx]
mov rsi , rax
mov rdi , lisfs
mov rax , 0
call printf
mov rbx , rbp
add rbx , -24
mov rax , [rbx]
mov rsi , rax
mov rdi , lisf
mov rax , 0
call printf
mov rbx , rbp
add rbx , -32
mov rax , [rbx]
mov rsi , rax
mov rdi , lisf
mov rax , 0
call printf
mov rbx , rbp
add rbx , -40
mov rax , [rbx]
mov rsi , rax
mov rdi , lisf
mov rax , 0
call printf
mov rbx , rbp
add rbx , -48
mov rax , [rbx]
mov rsi , rax
mov rdi , lisf
mov rax , 0
call printf
mov rbx , rbp
add rbx , -56
mov rax , [rbx]
mov rsi , rax
mov rdi , lisf
mov rax , 0
call printf
mov rbx , rbp
add rbx , -64
mov rax , [rbx]
mov rsi , rax
mov rdi , lisfe
mov rax , 0
call printf

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

