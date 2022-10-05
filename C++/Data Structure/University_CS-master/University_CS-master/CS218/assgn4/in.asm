;   Grant Mercer
;   assignmnet 4
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

NULL            equ 0           ; end of string

TRUE            equ 1
FALSE           equ 0

EXIT_SUCCESS    equ 0           ; Successful operation
SYS_exit        equ 60          ; call code for terminate

; -----
;  Assignment #4 data declarations         
            
lst         dd   4224, -1116,  1542,  1240,  1677
            dd  -1635,  2420,  1820,  1246,  -333
            dd   2315,  -215,  2726,  1140,  2565
            dd   2871,  1614,  2418,  2513,  1422
            dd   -119,  1215, -1525,  -712,  1441
            dd  -3622,  -731, -1729,  1615,  2724
            dd   1217,  -224,  1580,  1147,  2324
            dd   1425,  1816,  1262, -2718,  1192
            dd  -1435,   235,  2764, -1615,  1310
            dd   1765,  1954,  -967,  1515,  1556
            dd   1342,  7321,  1556,  2727,  1227
            dd  -1927,  1382,  1465,  3955,  1435
            dd   -225, -2419, -2534, -1345,  2467
            dd   1615,  1959,  1335,  2856,  2553
            dd  -1035,  1833,  1464,  1915, -1810
            dd   1465,  1554,  -267,  1615,  1656
            dd   2192,  -825,  1925,  2312,  1725
            dd  -2517,  1498,  -677,  1475,  2034
            dd   1223,  1883, -1173,  1350,  2415
            dd   -335,  1125,  1118,  1713,  3025
length      dd  100

lstMin      dd  0
lstMid      dd  0
lstMax      dd  0
lstSum      dd  0
lstAve      dd  0

negCnt      dd  0
negSum      dd  0
negAve      dd  0

threeCnt    dd  0
threeSum    dd  0
threeAve    dd  0

; ******************************************************

section .text
global _start
_start:

; get midpoint (with respect that we might not know length)
mov ebx, 2
mov eax, dword[length]
cdq
idiv ebx
mov ebx, dword[lst+eax*4]
dec eax
add ebx, dword[lst+eax*4]
mov eax, ebx
mov ebx, 2
cdq
idiv ebx
mov dword[lstMid], eax


mov ecx, dword[length]
mov rsi, 0
mov eax, 0
calcLoop:
    ; Check Min
    mov ebx, dword[lst+rsi*4]
    cmp ebx, dword[lstMin]
    jl isLess
    jmp nLess
    isLess:
        mov dword[lstMin], ebx
    nLess:
    ; Check Max
    mov ebx, dword[lst+rsi*4]
    cmp ebx, dword[lstMax]
    jg isMore
    jmp nMore
    isMore:
        mov dword[lstMax], ebx
    nMore:
    ; Check Negative
    mov ebx, dword[lst+rsi*4]
    cmp ebx, 0
    jl isNeg
    jmp nNeg
    isNeg:
        ; Increment Negative Count
        mov ebx, dword[negCnt]
        inc ebx
        mov dword[negCnt], ebx
        ; Add Sum
        mov ebx, dword[negSum]
        add ebx, dword[lst+rsi*4]
        mov dword[negSum], ebx
    nNeg:
    mov dword[lstSum], eax
    mov ebx, 3
    mov eax, dword[lst+rsi*4]
    cdq
    idiv ebx
    mov eax, dword[lstSum]
    cmp edx, 0
    je divThree
    jmp nDivThree
    divThree:    
        ; Increment DivThree Count
        mov ebx, dword[threeCnt]
        inc ebx
        mov dword[threeCnt], ebx
        ; Add Sum
        mov ebx, dword[threeSum]
        add ebx, dword[lst+rsi*4]
        mov dword[threeSum], ebx
    nDivThree:
    ; Add to sum
    add eax, dword[lst+rsi*4]
    ; Increment loop
    inc rsi
    dec rcx
    cmp rcx, 0
    je calcLoopDone
    jmp calcLoop
    calcLoopDone:
mov dword[lstSum], eax
; Get average
cdq
idiv dword[length]
mov dword[lstAve], eax

; Get negative average
mov eax, dword[negSum]
cdq
idiv dword[negCnt]
mov dword[negAve], eax

; Get three divisible average
mov eax, dword[threeSum]
cdq
idiv dword[threeCnt]
mov dword[threeAve], eax

; find average
mov eax, dword[lstSum]
cdq
idiv dword[length]
mov dword[lstAve], eax

; ******************************************************
;   Done, terminate program

last:
    mov eax, SYS_exit       ; call for exit
    mov ebx, EXIT_SUCCESS   ; return cod 0 (no error)
    syscall
