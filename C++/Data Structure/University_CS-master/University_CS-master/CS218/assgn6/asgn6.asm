;  Provided Main

;  Write a simple assembly language program to calculate
;  calculate the area of each rhmbus in a series of
;  rhmobus's.

;  The lengths are provided as senary (base 6) values
;  represented as ASCII characters and must be converted
;  into integer in order to perform the calculations.

; --------------------------------------------------------------
;  Macro to convert senary value in ASCII format into an integer.
;  Assumes valid data, no error checking is performed.

;  Call:  senary2int  <string>, <integer>, <stringLength>
;   Arguments:
;       %1 -> <string>, string address
;       %2 -> <integer>, address (for result)
;       %3 -> <stringLength>, immediate value

;  Reads <string>, converts to integer and places in <integer>
;  Note, should preserve any registers that the macro alters.

; -----
; Algorithm:
;   runningSum = 0
;   startLoop
;   get character from string
;   convert character to integer (integerDigit)
;   runningSum = runningSum * 6
;   runningSum = runningSum + integerDigit
;   next loop
;   return final result (from running sum)

%macro  senary2int  3
    push    rcx
    push    rsi
    push    rdi
    push    rax
    push    r8  
 
    mov r8, %1
    mov rsi, 0 
    mov eax, 0      ; running sum
    mov ecx, 6      ; constant 6 for running sum
    %%loop:
        cmp byte[r8], NULL     ; compare character to NULL
        je %%loopdone           ; if NULL end loop
        mov sil, byte[r8]      ; move character to registry
        sub sil, 0x30           ; convert to integer
        mul ecx                 ; running sum *= 6
        add eax, esi             ; running sum += integerDigit
        inc r8                 ; increment rdi
        jmp %%loop              ; loop up
    %%loopdone:
    mov dword[%2], eax                 ; move answer to integer address
    
    pop r8
    pop rax
    pop rdi             ; restore original register contents
    pop rsi
    pop rcx
%endmacro

; --------------------------------------------------------------
;  Macro to convert integer to senary value in ASCII format.

;  Call:  int2senary    <integer>, <string-addr>
;   Arguments:
;       %1 -> <integer>, value
;       %2 -> <string>, string address

;  Reads <string>, place count including NULL into <count>
;  Note, should preserve any registers that the macro alters.


;   YOUR CODE GOES HERE


%macro int2senary 2
    push rdx
    push rax
    push rcx
    push rsi
    push rdi
    push r9
    push r10

    mov eax, dword[%1]  ; move int value into eax
    mov rsi, 6          ; senary radix
    mov r10, 0x30       ; constant for conversion to ascii
    mov rcx, 0          ; string length
    mov r9, %2          ; set string address to r9
    %%cnt:
        mov edx, 0      ; extend positive sign bit  
        div esi         ; divide by radix
        inc rcx         ; increment length
        cmp eax, 0
        jne %%cnt
    mov eax, dword[%1]  ; reset eax to value of integer
    add r9, rcx         ; set string to last digit
    mov byte[r9], NULL  ; set last as NULL
    dec r9              ; decrement
    %%cloop:
        mov edx, 0      ; extend positive sign bit
        div esi         ; divide by radix
        add edx, r10d   ; convert to ascii
        mov byte[r9], dl    ; add converted ascii number to string
        dec r9          ; move one down string
        cmp eax, 0
        jne %%cloop
    pop r10
    pop r9
    pop rdi
    pop rsi
    pop rcx
    pop rax
    pop rdx
%endmacro


; --------------------------------------------------------------
;  Simple macro to display a string.
;   Call:   printString  <stringAddress>

;   Arguments:
;       %1 -> <string>, string address

;  Count characters (excluding NULL).
;  Display string starting at address <string>

%macro  printString 1
    push    rax         ; save altered registers
    push    rdi
    push    rsi
    push    rdx
    push    rcx

    mov rdx, 0
    mov rdi, %1
%%countLoop:
    cmp byte [rdi], NULL
    je  %%countLoopDone
    inc rdi
    inc rdx
    jmp %%countLoop
%%countLoopDone:

    mov rax, SYS_write      ; system call for write (SYS_write)
    mov rdi, STDOUT     ; standard output
    mov rsi, %1         ; address of the string
    syscall             ; call the kernel

    pop rcx         ; restore registers to original values
    pop rdx
    pop rsi
    pop rdi
    pop rax
%endmacro

; --------------------------------------------------------------

section .data

; -----
;  Define constants.

TRUE        equ 1
FALSE       equ 0

EXIT_SUCCESS    equ 0           ; Successful operation

STDIN       equ 0           ; standard input
STDOUT      equ 1           ; standard output
STDERR      equ 2           ; standard error

SYS_read    equ 0           ; system call code for read
SYS_write   equ 1           ; system call code for write
SYS_open    equ 2           ; system call code for file open
SYS_close   equ 3           ; system call code for file close
SYS_fork    equ 57          ; system call code for fork
SYS_exit    equ 60          ; system call code for terminate
SYS_creat   equ 85          ; system call code for file open/create
SYS_time    equ 201         ; system call code for get time

LF      equ 10
SPACE       equ " "
NULL        equ 0
ESC     equ 27

NUMS_PER_LINE   equ 6

; -----
;  Assignment #6 Provided Data

STR_LENGTH  equ 9

pDiags      db  "00000123", NULL, "00000213", NULL, "00011030", NULL
        db  "00125214", NULL, "00002152", NULL, "00101035", NULL
        db  "00000212", NULL, "00000343", NULL, "00000254", NULL
        db  "00000154", NULL, "00000521", NULL, "00021453", NULL
        db  "00000151", NULL, "00000523", NULL, "00011345", NULL
        db  "00000143", NULL, "00003543", NULL, "00000425", NULL
        db  "00000122", NULL, "00000235", NULL, "00001212", NULL
        db  "00011323", NULL, "00000055", NULL, "00015214", NULL
        db  "00021153", NULL, "00000004", NULL, "00011214", NULL
        db  "00121251", NULL, "00123451", NULL, "00000321", NULL
        db  "00000543", NULL, "00000032", NULL, "00000255", NULL
        db  "00001005", NULL, "00002153", NULL, "00002143", NULL
        db  "00000143", NULL, "00000103", NULL, "00000043", NULL
        db  "00000012", NULL, "00003000", NULL, "00000212", NULL

qDiags      db  "00024134", NULL, "00003244", NULL, "00021435", NULL
        db  "00002212", NULL, "00002235", NULL, "00001341", NULL
        db  "00002345", NULL, "00001524", NULL, "00000451", NULL
        db  "00001245", NULL, "00000333", NULL, "00002325", NULL
        db  "00000513", NULL, "00000214", NULL, "00003123", NULL
        db  "00000251", NULL, "00002415", NULL, "00001321", NULL
        db  "00002134", NULL, "00000152", NULL, "00002121", NULL
        db  "00001552", NULL, "00000231", NULL, "00004352", NULL
        db  "00005432", NULL, "00000151", NULL, "00004451", NULL
        db  "00001132", NULL, "00000511", NULL, "00011512", NULL
        db  "00004344", NULL, "00034332", NULL, "00001245", NULL
        db  "00002415", NULL, "00001143", NULL, "00001251", NULL
        db  "00001003", NULL, "00000234", NULL, "00001043", NULL
        db  "00000212", NULL, "00000125", NULL, "00000543", NULL

length      dd  42

areasSum    dd  0
areasAve    dd  0
areasMax    dd  0
; -----
;  Misc. variables for main.

hdr     db  LF, "-----------------------------------------------------"
        db  LF, ESC, "[1m", "CS 218 - Assignment #6", ESC, "[0m", LF
        db  "Rhombus Areas", LF, LF
        db  "Area's:", LF, NULL

sHdr        db  LF, "Area's Sum:  ", NULL
avHdr       db  LF, "Area's Ave:  ", NULL
maxHdr      db  LF, "Area's Max:  ", NULL

numCount    dd  0
tempNum     dd  0

newLine     db  LF, NULL
dSix        dd  6
dTwo        dd  2
spaces      db  "   ", NULL

; --------------------------------------------------------------
;  Uninitialized (empty) variables

section .bss

tmpString   resb    20
intPdiags   resd    42
intQdiags   resd    42
rhombusAreas    resd    42

; --------------------------------------------------------------

section .text
global  _start
_start:

; -----
;  Display assignment initial headers.

    printString hdr

; -----
;  Display each of the rhombus areas.
;  For every 6th line, print a newLine (for formatting).

    mov ecx, dword [length]
    add ecx, ecx
    mov rsi, pDiags
    mov dword [numCount], 0

printLoop:
    printString rsi
    printString spaces

    inc dword [numCount]
    cmp dword [numCount], NUMS_PER_LINE
    jl  skipNewline
    printString newLine
    mov dword [numCount], 0
skipNewline:

    add rsi, STR_LENGTH

    dec ecx
    cmp ecx, 0
    jne printLoop

; -----
;  Convert senary data, in ASCII format, to integer.

    mov ecx, dword [length]
    mov rsi, pDiags
    mov rdi, intPdiags

cvtPloop:
    senary2int  rsi, rdi, STR_LENGTH
    add rsi, STR_LENGTH
    add rdi, 4

    dec ecx
    cmp ecx, 0
    jne cvtPloop

    mov ecx, dword [length]
    mov rsi, qDiags
    mov rdi, intQdiags

cvtQloop:
    senary2int  rsi, rdi, STR_LENGTH

    add rsi, STR_LENGTH
    add rdi, 4

    dec ecx
    cmp ecx, 0
    jne cvtQloop

; -----
;  Calculate the Rhombus areas
;  Also find areas sum, average, and max.
mov rcx, 0
mov ecx, dword[length] 
mov rsi, 0
mov ebx, 2
mov r8, 0
calcLoop:
    mov eax, dword[intQdiags+rsi*4]
    mul dword[intPdiags+rsi*4]
    mov edx, 0
    div ebx
    mov dword[rhombusAreas+rsi*4], eax
    ; Add Area sum
    add r8d, eax
    ; Check Max Area
    cmp eax, dword[areasMax]
    jbe AreaNotMore
    mov dword[areasMax], eax
AreaNotMore:
    inc rsi
    dec rcx
    cmp rcx, 0
    je calcLoopDone
    jmp calcLoop
calcLoopDone:

; Move Area Sum and find Area Average
mov edx, 0
mov dword[areasSum], r8d
mov eax, r8d
div dword[length]
mov dword[areasAve], eax

; -----
;  Convert sum, average, and maximum to senary (in ASCII format)
;  for printing.

    printString sHdr
    int2senary  areasSum, tmpString
    printString tmpString

    printString avHdr
    int2senary  areasAve, tmpString
    printString tmpString

    printString maxHdr
    int2senary  areasMax, tmpString
    printString tmpString

    printString newLine
    printString newLine

; -----
; Done, terminate program.

last:
    mov rax, SYS_exit
    mov rbx, EXIT_SUCCESS
    syscall


