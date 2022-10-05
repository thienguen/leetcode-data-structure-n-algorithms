;   Grant Mercer
;   assignmnet 3
;   section 1002

; -----
;  Write a simple assembly language program to compute the
;  the provided formulas.

;  Focus on learning basic arithmetic operations
;  (add, subtract, multiply, and divide).
;  Ensure understanding of sign and unsigned operations.

; *****************************************************************
;  Data Declarations (provided).

section .data
; -----
;  Define constants.

NULL        equ 0           ; end of string

TRUE        equ 1
FALSE       equ 0

EXIT_SUCCESS    equ 0           ; Successful operation
SYS_exit    equ 60          ; call code for terminate

; -----
;  Assignment #3 data declarations

; byte data
bNum1       db  35
bNum2       db  17
bNum3       db  15
bNum4       db  11
bNum5       db  -39
bNum6       db  -19
bAns1       db  0
bAns2       db  0
bAns3       db  0
bAns4       db  0
bAns5       db  0
bAns6       db  0
bAns7       db  0
bAns8       db  0
bAns9       db  0
bAns10      db  0
wAns11      dw  0
wAns12      dw  0
wAns13      dw  0
wAns14      dw  0
wAns15      dw  0
bAns16      db  0
bAns17      db  0
bAns18      db  0
bRem18      db  0
bAns19      db  0
bAns20      db  0
bAns21      db  0
bRem21      db  0

; word data
wNum1       dw  315
wNum2       dw  145
wNum3       dw  5183
wNum4       dw  2198
wNum5       dw  -576
wNum6       dw  -168
wAns1       dw  0
wAns2       dw  0
wAns3       dw  0
wAns4       dw  0
wAns5       dw  0
wAns6       dw  0
wAns7       dw  0
wAns8       dw  0
wAns9       dw  0
wAns10      dw  0
dAns11      dd  0
dAns12      dd  0
dAns13      dd  0
dAns14      dd  0
dAns15      dd  0
wAns16      dw  0
wAns17      dw  0
wAns18      dw  0
wRem18      dw  0
wAns19      dw  0
wAns20      dw  0
wAns21      dw  0
wRem21      dw  0

; double-word data
dNum1       dd  13456789
dNum2       dd  31342
dNum3       dd  219815
dNum4       dd  61569
dNum5       dd  -703
dNum6       dd  -5249
dAns1       dd  0
dAns2       dd  0
dAns3       dd  0
dAns4       dd  0
dAns5       dd  0
dAns6       dd  0
dAns7       dd  0
dAns8       dd  0
dAns9       dd  0
dAns10      dd  0
qAns11      dq  0
qAns12      dq  0
qAns13      dq  0
qAns14      dq  0
qAns15      dq  0
dAns16      dd  0
dAns17      dd  0
dAns18      dd  0
dRem18      dd  0
dAns19      dd  0
dAns20      dd  0
dAns21      dd  0
dRem21      dd  0

; quadword data
qNum1       dq  24656793
qNum2       dq  115732
qNum3       dq  1526241
qNum4       dq  254879
qNum5       dq  -27517
qNum6       dq  -312759
qAns1       dq  0
qAns2       dq  0
qAns3       dq  0
qAns4       dq  0
qAns5       dq  0
qAns6       dq  0
qAns7       dq  0
qAns8       dq  0
qAns9       dq  0
qAns10      dq  0
dqAns11     ddq 0
dqAns12     ddq 0
dqAns13     ddq 0
dqAns14     ddq 0
dqAns15     ddq 0
qAns16      dq  0
qAns17      dq  0
qAns18      dq  0
qRem18      dq  0
qAns19      dq  0
qAns20      dq  0
qAns21      dq  0
qRem21      dq  0

; *****************************************************************

section .text
global _start
_start:

; ----------------------------------------------
; Byte Operations

; unsigned byte additions
;   bAns1  = bNum1 + bNum2
;   bAns2  = bNum1 + bNum3
;   bAns3  = bNum3 + bNum4

mov al, byte[bNum1]
add al, byte[bNum2]
mov byte[bAns1], al

mov al, byte[bNum1]
add al, byte[bNum3]
mov byte[bAns2], al

mov al, byte[bNum3]
add al, byte[bNum4]
mov byte[bAns3], al

; -----
; signed byte additions
;   bAns4  = bNum5 + bNum6
;   bAns5  = bNum1 + bNum6

mov al, byte[bNum5]
add al, byte[bNum6]
mov byte[bAns4], al

mov al, byte[bNum1]
add al, byte[bNum6]
mov byte[bAns5], al

; -----
; unsigned byte subtractions
;   bAns6  = bNum1 - bNum2
;   bAns7  = bNum1 - bNum3
;   bAns8  = bNum2 - bNum4

mov al, byte[bNum1]
sub al, byte[bNum2]
mov byte[bAns6], al

mov al, byte[bNum1]
sub al, byte[bNum3]
mov byte[bAns7], al

mov al, byte[bNum2]
sub al, byte[bNum4]
mov byte[bAns8], al

; -----
; signed byte subtraction
;   bAns9  = bNum6 - bNum5
;   bAns10 = bNum5 - bNum2

mov al, byte[bNum6]
sub al, byte[bNum5]
mov byte[bAns9], al

mov al, byte[bNum5]
sub al, byte[bNum2]
mov byte[bAns10], al

; -----
; unsigned byte multiplication
;   wAns11  = bNum1 * bNum3
;   wAns12  = bNum2 * bNum2
;   wAns13  = bNum2 * bNum4
    
mov al, byte[bNum1]
mul byte[bNum3]
mov word[wAns11], ax

mov al, byte[bNum2]
mul byte[bNum2]
mov word[wAns12], ax

mov al, byte[bNum2]
mul byte[bNum4]
mov word[wAns12], ax

; -----
; signed byte multiplication
;   wAns14  = bNum5 * bNum5
;   wAns15  = bNum1 * bNum5

mov al, byte[bNum5]
imul byte[bNum5]
mov word[wAns14], ax

mov al, byte[bNum1]
imul byte[bNum5]
mov word[wAns15], ax

; -----
; unsigned byte division
;   bAns16 = bNum1 / bNum2
;   bAns17 = bNum3 / bNum4
;   bAns18 = wNum1 / bNum4
;   bRem18 = wNum1 % bNum4

mov al, byte[bNum1]
cbw
div byte[bNum2]
mov byte[bAns16], al

mov al, byte[bNum3]
cbw
div byte[bNum4]
mov byte[bAns17], al

mov ax, word[wNum1]
div byte[bNum4]
mov byte[bAns18], al
mov byte[bRem18], ah

; -----
; signed byte division
;   bAns19 = bNum5 / bNum6
;   bAns20 = bNum6 / bNum3
;   bAns21 = wNum6 / bNum4
;   bRem21 = wNum6 % bNum4

mov al, byte[bNum5]
cbw
idiv byte[bNum6]
mov byte[bAns19], al

mov al, byte[bNum6]
cbw
idiv byte[bNum3]
mov byte[bAns20], al

mov ax, word[wNum6]
idiv byte[bNum4]
mov byte[bAns21], al
mov byte[bRem21], ah

; *****************************************
; Word Operations

; -----
; unsigned word additions
;   wAns1  = wNum1 + wNum3
;   wAns2  = wNum2 + wNum4
;   wAns3  = wNum3 + wNum2

mov ax, word[wNum1]
add ax, word[wNum3]
mov word[wAns1], ax

mov ax, word[wNum2]
add ax, word[wNum4]
mov word[wAns2], ax

mov ax, word[wNum3]
add ax, word[wNum2]
mov word[wAns3], ax

; -----
; signed word additions
;   wAns4  = wNum5 + wNum6
;   wAns5  = wNum1 + wNum6

mov ax, word[wNum5]
add ax, word[wNum6]
mov word[wAns4], ax

mov ax, word[wNum1]
add ax, word[wNum6]
mov word[wAns5], ax

; -----
; unsigned word subtractions
;   wAns6  = wNum1 - wNum2
;   wAns7  = wNum3 - wNum4
;   wAns8  = wNum2 - wNum4

mov ax, word[wNum1]
sub ax, word[wNum2]
mov word[wAns6], ax

mov ax, word[wNum3]
sub ax, word[wNum4]
mov word[wAns7], ax

mov ax, word[wNum2]
sub ax, word[wNum4]
mov word[wAns8], ax

; -----
; signed word subtraction
;   wAns9  = wNum5 - wNum6
;   wAns10  = wNum2 - wNum6

mov ax, word[wNum5]
sub ax, word[wNum6]
mov word[wAns9], ax

mov ax, word[wNum2]
sub ax, word[wNum6]
mov word[wAns10], ax

; -----
; unsigned word multiplication
;   dAns11 = wNum1 * wNum2
;   dAns12  = wNum2 * wNum4
;   dAns13  = wNum3 * wNum3

mov ax, word[wNum1]
mul word[wNum2]
mov word[dAns11], ax
mov word[dAns11+2], dx

mov ax, word[wNum2]
mul word[wNum4]
mov word[dAns12], ax
mov word[dAns12+2], dx

mov ax, word[wNum3]
mul word[wNum3] 
mov word[dAns13], ax
mov word[dAns13+2], dx

; -----
; signed word multiplication
;   dAns14  = wNum5 * wNum6
;   dAns15  = wNum5 * wNum2

mov ax, word[wNum5]
imul word[wNum6]
mov word[dAns14], ax
mov word[dAns14+2], dx

mov ax, word[wNum5]
imul word[wNum2]
mov word[dAns15], ax
mov word[dAns15+2], dx

; -----
; unsigned word division
;   wAns16 = wNum1 / wNum2
;   wAns17 = wNum3 / wNum4
;   wAns18 = dNum4 / wNum1
;   wRem18 = dNum4 % wNum1

mov ax, word[wNum1]
mov dx, 0
div word[wNum2]
mov word[wAns16], ax

mov ax, word[wNum3]
mov dx, 0
div word[wNum4]
mov word[wAns17], ax

mov ax, word[dNum4]
mov dx, word[dNum4+2]
div word[wNum1]
mov word[wAns18], ax
mov word[wRem18], dx 

; -----
; signed word division
;   wAns19 = wNum5 / wNum6
;   wAns20 = wNum1 / wNum5
;   wAns21 = dNum6 / wNum2
;   wRem21 = dNum6 % wNum2

mov ax, word[wNum5]
cwd
idiv word[wNum6]
mov word[wAns19], ax

mov ax, word[wNum1]
cwd
idiv word[wNum5]
mov word[wAns20], ax

mov ax, word[dNum6]
mov dx, word[dNum6+2]
idiv word[wNum2]
mov word[wAns21], ax
mov word[wRem21], dx

; *****************************************
; Double-Word Operations

; -----
; unsigned double-word additions
;   dAns1  = dNum1 + dNum2
;   dAns2  = dNum2 + dNum3
;   dAns3  = dNum4 + dNum2

mov eax, dword[dNum1]
add eax, dword[dNum2]
mov dword[dAns1], eax

mov eax, dword[dNum2]
add eax, dword[dNum3]
mov dword[dAns2], eax

mov eax, dword[dNum4]
add eax, dword[dNum2]
mov dword[dAns3], eax

; -----
; signed double-word additions
;   dAns4  = dNum6 + dNum5 
;   dAns5  = dNum6 + dNum1

mov eax, dword[dNum6]
add eax, dword[dNum5]
mov dword[dAns4], eax

mov eax, dword[dNum6]
add eax, dword[dNum1]
mov dword[dAns5], eax

; -----
; unsigned double-word subtractions
;   dAns6  = dNum1 - dNum3
;   dAns7  = dNum3 - dNum4
;   dAns8  = dNum2 - dNum3

mov eax, dword[dNum1]
sub eax, dword[dNum3]
mov dword[dAns6], eax

mov eax, dword[dNum3]
sub eax, dword[dNum4]
mov dword[dAns7], eax

mov eax, dword[dNum2]
sub eax, dword[dNum3]
mov dword[dAns8], eax

; -----
; signed double-word subtraction
;   dAns9  = dNum6 - dNum5
;   dAns10 = dNum2 – dNum5

mov eax, dword[dNum6]
sub eax, dword[dNum5]
mov dword[dAns9], eax

mov eax, dword[dNum2]
sub eax, dword[dNum5]
mov dword[dAns10], eax

; -----
; unsigned double-word multiplication
;   qAns11  = dNum1 * dNum3
;   qAns12  = dNum2 * dNum3
;   qAns13  = dNum3 * dNum4

mov eax, dword[dNum1]
mul dword[dNum3]
mov dword[qAns11], eax
mov dword[qAns11+4], edx

mov eax, dword[dNum2]
mul dword[dNum3]
mov dword[qAns12], eax
mov dword[qAns12+4], edx

mov eax, dword[dNum3]
mul dword[dNum4]
mov dword[qAns13], eax
mov dword[qAns13+4], edx

; -----
; signed double-word multiplication
;   qAns14  = dNum5 * dNum2
;   qAns15  = dNum5 * dNum5

mov eax, dword[dNum5]
imul dword[dNum2]
mov dword[qAns14], eax
mov dword[qAns14+4], edx

mov eax, dword[dNum5]
imul dword[dNum5]
mov dword[qAns15], eax
mov dword[qAns15+4], edx

; -----
; unsigned double-word division
;   dAns16 = dNum1 / dNum2
;   dAns17 = dNum3 / dNum4
;   dAns18 = qAns11 / dNum4
;   dRem18 = qAns11 % dNum4

mov eax, dword[dNum1]
mov edx, 0
div dword[dNum2]
mov dword[wAns16], eax

mov eax, dword[dNum3]
mov edx, 0
div dword[dNum4]
mov dword[wAns17], eax

mov eax, dword[qAns11]
mov edx, dword[qAns11+4]
div dword[dNum4]
mov dword[dAns18], eax
mov dword[dRem18], edx

; -----
; signed double-word division
;   dAns19 = dNum6 / dNum5
;   dAns20 = dNum1 / dNum5
;   dAns21 = qAns12 / dNum6
;   dRem21 = qAns12 % dNum6

mov eax, dword[dNum6]
cdq
idiv dword[dNum5]
mov dword[dAns19], eax

mov eax, dword[dNum1]
cdq
idiv dword[dNum5]
mov dword[dAns20], eax

mov eax, dword[qAns12]
mov edx, dword[qAns12+4]
idiv dword[dNum6]
mov dword[dAns21], eax
mov dword[dRem21], edx

; *****************************************
; QuadWord Operations

; -----
; unsigned quadword additions
;   qAns1  = qNum2 + qNum3
;   qAns2  = qNum1 + qNum4
;   qAns3  = qNum4 + qNum2

mov rax, qword[qNum2]
add rax, qword[qNum3]
mov qword[qAns1], rax

mov rax, qword[qNum1]
add rax, qword[qNum4]
mov qword[qAns2], rax

mov rax, qword[qNum4]
add rax, qword[qNum2]
mov qword[qAns3], rax

; -----
; signed quadword additions
;   qAns4  = qNum6 + qNum5
;   qAns5  = qNum1 + qNum5

mov rax, qword[qNum6]
add rax, qword[qNum5]
mov qword[qAns4], rax

mov rax, qword[qNum1]
add rax, qword[qNum5]
mov qword[qAns5], rax

; -----
; unsigned quadword subtractions
;   qAns6  = qNum2 - qNum3
;   qAns7  = qNum1 - qNum4
;   qAns8  = qNum2 - qNum3

mov rax, qword[qNum2]
sub rax, qword[qNum3]
mov qword[qAns6], rax

mov rax, qword[qNum1]
sub rax, qword[qNum4]
mov qword[qAns7], rax

mov rax, qword[qNum2]
sub rax, qword[qNum3]
mov qword[qAns8], rax

; -----
; signed quadword subtraction
;   qAns9  = qNum6 - qNum5
;   qAns10 = qNum6 - qNum2

mov rax, qword[qNum6]
sub rax, qword[qNum5]
mov qword[qAns9], rax

mov rax, qword[qNum6]
sub rax, qword[qNum2]
mov qword[qAns10], rax

; -----
; unsigned quadword multiplication
;   dqAns11  = qNum3 * qNum2
;   dqAns12  = qNum3 * qNum3
;   dqAns13  = qNum4 * qNum1

mov rax, qword[qNum3]
mul qword[qNum2]
mov qword[dqAns11], rax
mov qword[dqAns11+8], rdx

mov rax, qword[qNum3]
mul qword[qNum3]
mov qword[dqAns12], rax
mov qword[dqAns12+8], rdx

mov rax, qword[qNum4]
mul qword[qNum1]
mov qword[dqAns13], rax
mov qword[dqAns13+8], rdx

; -----
; signed quadword multiplication
;   dqAns14  = qNum1 * qNum6
;   dqAns15  = qNum5 * qNum6

mov rax, qword[qNum1]
imul qword[qNum6]
mov qword[dqAns14], rax
mov qword[dqAns14+8], rdx

mov rax, qword[qNum5]
imul qword[qNum6]
mov qword[dqAns15], rax
mov qword[dqAns15+8], rdx

; -----
; unsigned quadword division
;   qAns16 = qNum1 / qNum2
;   qAns17 = qNum3 / qNum4
;   qAns18 = dqAns11 / qNum4
;   qRem18 = dqAns11 % qNum4

mov rax, qword[qNum1]
mov rdx, 0
div qword[qNum2]
mov qword[qAns16], rax

mov rax, qword[qNum3]
mov rdx, 0
div qword[qNum4]
mov qword[qAns17], rax

mov rax, qword[dqAns11]
mov rdx, qword[dqAns11+8]
div qword[qNum4]
mov qword[qAns18], rax
mov qword[qRem18], rdx

; -----
; signed quadword division
;   qAns19 = qNum6 / qNum5
;   qAns20 = qNum2 / qNum5
;   qAns21 = dqAns12 / qNum6
;   qRem21 = dqAns12 % qNum6

mov rax, qword[qNum6]
cqo
idiv qword[qNum5]
mov qword[qAns19], rax

mov rax, qword[qNum2]
cqo
idiv qword[qNum5]
mov qword[qAns20], rax

mov rax, qword[dqAns12]
mov rdx, qword[dqAns12+8]
idiv qword[qNum6]
mov qword[qAns21], rax
mov qword[qRem21], rdx


; *****************************************************************
;   Done, terminate program.

last:
    mov eax, SYS_exit       ; call call for exit (SYS_exit)
    mov ebx, EXIT_SUCCESS   ; return code of 0 (no error)
    syscall


