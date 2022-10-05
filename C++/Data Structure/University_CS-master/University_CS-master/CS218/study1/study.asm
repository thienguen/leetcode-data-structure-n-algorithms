
%macro doMath 7
    push rax
    push rdx
    push rbx
    push rsi

    ; ANSWER 1
    mov rbx, 3
    mov eax, 0
    mov ax, word[%1]
    add eax, dword[%2]
    add eax, dword[%3]
    mov edx, 0
    imul rbx
    mov rbx, 9
    idiv rbx
    mov dword[%4], eax

    ; ANSWER 2
    mov rbx, 3
    mov ax, word[%1]
    cwd
    cdq
    idiv ebx
    mov r8d, eax
    mov eax, -42
    cdq
    idiv dword[%2]
    add eax, r8d
    mov r8d, eax
    mov eax, -13
    cdq
    idiv dword[%3]
    add eax, r8d
    mov edx, 0
    mov rbx, 2
    imul ebx
    mov r8d, 0
    mov r8w, word[%1]
    add r8d, dword[%2]
    cdq
    idiv r8d
    mov dword[%5], eax

    ; ANSWER 3
    mov rbx, 2
    mov eax, 0
    mov ax, word[%1]
    cdw
    cdq
    idiv dword[%2]
    mov r8d, eax
    mov eax, dword[%3]
    mov edx, 0
    imul ebx
    sub r8d, eax
    mov eax, r8d
    mov r8d, 0
    mov r8w, word[%1]
    cmp r8d, 0
    jg %%isPos
    neg r8d
    %%isPos:
    cdq
    idiv r8d
    mov dword[%6], eax
    mov dword[%7], edx

    pop rsi
    pop rbx
    pop rdx
    pop rax
%endmacro

section .data

; ----
; Define constants

TRUE            equ 1
FALSE           equ 0

EXIT_SUCCESS    equ 0
SYS_exit        equ 60

    x   dw  2
    y   dd  12
    z   dd  1
    ans1    dd  0
    ans2    dd  0
    ans3    dd  0
    ans4    dd  0

section .text
global _start
_start:

    doMath x, y, z, ans1, ans2, ans3, ans4

last:
    mov eax, SYS_exit
    mov ebx, EXIT_SUCCESS
    syscall
