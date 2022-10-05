; CS 218
; Assignment #7

; Sort a list of number using the shell sort algorithm.
; Also finds the minimum, median, maximum, and average of the list.

; -----
; Shell Sort

;   h = 1;
;       while ( (h*3+1) < a.length) {
;       h = 3 * h + 1;
;   }

;       while( h > 0 ) {
;           for (i = h-1; i < a.length; i++) {
;               tmp = a[i];
;               j = i;
;               for( j = i; (j >= h) && (a[j-h] > B); j -= h) {
;                   a[j] = a[j-h];
;               }
;               a[j] = tmp;
;           }
;           h = h / 3;
;       }

; --------------------------------------------------------------
;  Macro to convert integer to senary value in ASCII format.

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
    dec r9
    %%cloop:
        mov edx, 0      ; extend positive sign bit
        div esi         ; divide by radix 
        add edx, r10d   ; convert to ascii
        mov byte[r9], dl; add converted ascii number to string
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

; ---------------------------------------------

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
NULL        equ 0
ESC     equ 27

LIMIT       equ 10000
STR_LENGTH  equ 10

; -----
;  Provided data

lst dd  1113, 1232, 2146, 1376, 5120, 2356, 3164, 4565, 3155, 3157
    dd  6759, 6326,  171,  147, 5628, 7527, 7569, 1177, 6785, 3514
    dd  1001,  128, 1133, 1105, 3327,  101,  115, 1108,    1, 2115
    dd  1227, 1226, 5129,  117,  107,  105,  109, 9999, 1150, 3414
    dd  1107, 6103, 1245, 6440, 1465, 2311,  254, 4528, 1913, 6722
    dd  1149, 2126, 5671, 4647, 4628,  327, 2390, 1177, 8275, 5614
    dd  3121,  415,  615,  122, 7217,    1,  410, 1129, 812,  2134
    dd  1221, 2234, 6151,  432,  114, 1629,  114,  522, 2413,  131
    dd  5639,  126, 1162,  441,  127,  877,  199, 5679, 1101, 3414
    dd  2101,  133, 1133, 2450, 4532, 8619,  115, 1618, 9999,  115
    dd  1219, 3116,  612,  217,  127, 6787, 4569,  679, 5675, 4314
    dd  1104, 6825, 1184, 2143, 1176,  134, 4626,  100, 4566, 2346
    dd  1214, 6786, 1617,  183, 3512, 7881, 8320, 3467, 4559, 1190
    dd   103,  112,    1, 2186,  191,  186,  134, 1125, 5675, 3476
    dd   100,    1, 1146,  100,  101,    1, 5616, 5662, 6328, 2342
    dd  2137, 2113, 1647,  114,  115, 6571, 7624,  128,  113, 3112
    dd  1724, 6316, 1217, 2183, 4352,  121,  320, 4540, 5679, 1190
    dd  9125,  116, 1122,  117,  127, 5677,  101, 3727, 6512, 3184
    dd  1897, 6374, 1190, 1667, 1224, 7123,  116, 8126, 6784, 2329
    dd  1104,  124, 1112,  143,  176, 7534, 2126, 6112,  156, 1103
    dd  1153,  172, 1146, 2176,  170,  156,  164,  165,  155, 5156
    dd   894, 6325,  100,  143,  276, 5634, 7526, 3413, 7686, 7563
    dd   511, 6383, 1133, 2150,  825, 5721, 5615, 4568, 7813, 1231
    dd  9999,  146, 1162,  147,  157,  167,  169,  177,  175, 2144
    dd  5527, 1344, 1130, 2172,  224, 7525,  100,    1,  100, 1134   
    dd   181,  155, 1145,  132,  167,  185,  150,  149,  182, 1434
    dd  6581, 3625, 6315,    1,  617, 7855, 6737,  129, 4512,    1
    dd   177,  164, 1160, 1172,  184,  175,  166, 6762,  158, 4572
    dd  6561, 1283, 1133, 1150,  135, 5631, 8185,  178, 1197, 1185
    dd  5649, 6366, 1162, 1167,  167, 1177,  169, 1177,  175, 1169

len dd  300

min dd  0
med dd  0
max dd  0
sum dd  0
avg dd  0

; -----
;  Misc. data definitions (if any).

h       dd  0
i       dd  0
j       dd  0
tmp     dd  0
dSix        dd  6
dTwo        dd  2
dThree      dd  3

; -----
;  Provided string definitions.

newLine     db  LF, NULL

hdr     db  LF, "---------------------------"
        db  "---------------------------"
        db  LF, ESC, "[1m", "CS 218 - Assignment #7", ESC, "[0m"
        db  LF, "Shell Sort", LF, LF, NULL

hdrMin      db  "Minimum:  ", NULL
hdrMax      db  "Maximum:  ", NULL
hdrMed      db  "Median:   ", NULL
hdrSum      db  "Sum:      ", NULL
hdrAve      db  "Average:  ", NULL

; ---------------------------------------------

section .bss

count       resd    LIMIT
tmpString   resb    STR_LENGTH

; ---------------------------------------------

section .text
global  _start
_start:

; ******************************
;  Shell Sort.
    mov eax, 1
    mov dword[h], eax
    whileLoop1:                     ; while( (h*3+1) < length ) 
        mov eax, dword[dThree]      
        mul dword[h]                ; h * 3
        inc eax                     ; h * 3 + 1
        cmp eax, dword[len]
        jge exitWhileLoop1           ; h * 3 + 1 >= length ? if yes break
        mov dword[h], eax           ; h = h * 3 + 1
        jmp whileLoop1
    exitWhileLoop1:
        
    whileLoop2:                     ; while( h > 0)
        mov ecx, dword[h]           ; move h to ecx
        cmp ecx, 0                  ; compare h to 0    
        jle exitWhileLoop2          ; h > 0 ? exit 
        dec ecx                     ; h - 1
        mov dword[i], ecx           ; i = h - 1
        forLoop1:                   ; for( i = h - 1; i < length; i++)
            cmp ecx, dword[len]         ; compare h - 1 to len
            jge exitForLoop1            ; i >= length ? exit
            mov eax, dword[lst+ecx*4]   ; lst[i]
            mov dword[tmp], eax         ; tmp = lst[i]
            mov dword[j], ecx           ; j = i
            forLoop2:                   ; for( j = i; j >= h && lst[j-h] > tmp; j = j-h)
                mov edi, dword[j]           ; move j to edi
                cmp edi, dword[h]           ; compare j to h
                jl exitForLoop2             ; j < h ? exit
                mov esi, edi                ; move j to esi
                sub esi, dword[h]           ; j - h
                mov esi, dword[lst+esi*4]   ; lst[j - h]
                cmp esi, dword[tmp]         ; compare lst[j-h] to tmp
                jle exitForLoop2            ; lst[j-h]j <= tmp ? exit
                mov r9d, dword[j]           ; move j to r9d
                mov dword[lst+r9d*4], esi   ; lst[j] = lst[j - h]
                sub r9d, dword[h]           ; j - h
                mov dword[j], r9d           ; j = j - h
                jmp forLoop2
            exitForLoop2:
            mov esi, dword[j]          ; move j to esi
            mov r9d, dword[tmp]        ; move tmp to r9d
            mov dword[lst+esi*4], r9d  ; lst[j] = tmp
            inc ecx                    ; i++
            jmp forLoop1
        exitForLoop1: 
        mov eax, dword[h]           ; move h to eax
        cdq                         ; extend sign bit
        idiv dword[dThree]          ; h / 3
        mov dword[h], eax           ; h = h / 3
        jmp whileLoop2
    exitWhileLoop2

    mov rax, 0
    mov rcx, 0
    mov ecx, dword[len]
    mov rsi, 0 
    sumLoop:
        add eax, dword[lst+rsi*4]   ; add to running sum
        inc rsi                     ; increment index
        loop sumLoop
    mov dword[sum], eax             ; move sum to dsum
    cdq                             ; extend sign bit
    idiv dword[len]                 ; sum / len
    mov dword[avg], eax             ; avg = sum / len
    mov eax, dword[len]             ; len
    dec eax                         ; len--
    mov eax, dword[lst+eax*4]       ; lst[len--]
    mov dword[max], eax             ; max = lst[len--]
    mov eax, dword[lst]             ; lst[0]
    mov dword[min], eax             ; min = lst[0]
    mov eax, dword[len]             ; len
    mov edx, 0                      ; extend sign bit
    idiv dword[dTwo]                ; len / 2
    dec eax                         ; len / 2 - 1
    mov edx, eax                    ; len / 2 - 1
    dec edx                         ; len / 2 - 2
    mov eax, dword[lst+eax*4]       ; lst[len/2-1]
    add eax, dword[lst+edx*4]       ; lst[len/2-1] + lst[len/2-2]
    cdq                             ; extend sign bit
    idiv dword[dTwo]                ; (lst[len/2-1]+lst[len/2-2]) / 2
    mov dword[med], eax
        
        
; ******************************
;  Display results to screen in hex.

    printString hdr

    printString hdrMin
    int2senary  min, tmpString
    printString tmpString
    printString newLine

    printString hdrMax
    int2senary  max, tmpString
    printString tmpString
    printString newLine

    printString hdrMed
    int2senary  med, tmpString
    printString tmpString
    printString newLine

    printString hdrSum
    int2senary  sum, tmpString
    printString tmpString
    printString newLine

    printString hdrAve
    int2senary  avg, tmpString
    printString tmpString
    printString newLine
    printString newLine

; ******************************
;  Done, terminate program.

last:
    mov rax, SYS_exit
    mov rbx, EXIT_SUCCESS
    syscall


