; *****************************************************************

section  .data

; -----
;  Define constants.

NULL            equ 0           ; end of string

TRUE            equ 1
FALSE           equ 0

EXIT_SUCCESS    equ 0           ; successful operation
SYS_exit        equ 60          ; call code for terminate

; -----
;  Data Set

aSides      dw  2148,  794, 2622, 2623, 2138
            dw  1671, 2145, 1552, 1219, 1675
            dw   812,  800,  815, 2633, 1205
            dw  1676, 2147, 1555, 2140, 3113
            dw   808, 2145, 2651, 2645, 3615
            dw  1677,  820, 1526, 2147, 3611
            dw  1552, 1219, 1675, 1671

pDiags      dw  1133, 1114, 1123, 1131, 1134
            dw  1164, 1153, 2234, 1123, 1165
            dw  1144, 1112, 1123, 1142, 1123
            dw  1165, 1164, 2273, 1156, 1134
            dw  1153, 1153, 1243, 1153, 1135
            dw  1144, 1169, 2134, 1133, 1132
            dw  2234, 1123, 1165, 1164

qDiags      dd  4145, 1134, 5123, 5123, 4123
            dd  3134, 4134, 2156, 2164, 3142
            dd  1153, 1153, 1184, 5142, 2134
            dd  3145, 4134, 2123, 4123, 6123
            dd  1134, 4134, 5156, 5164, 7142
            dd  3153, 1153, 2184, 4142, 7134
            dd  2156, 2164, 3142, 3134

length      dd  34

aMin        dd  0
aMid        dd  0
aMax        dd  0
aSum        dd  0
aAve        dd  0

pMin        dd  0
pMid        dd  0
pMax        dd  0
pSum        dd  0
pAve        dd  0

sMin        dd  0
sMid        dd  0
sMax        dd  0
sSum        dd  0
sAve        dd  0
; -----
; Additional variables (if any)



; --------------------------------------------------------------
; Uninitialized data

section .bss

areas       resd    34
perims      resd    34
sPerims     resd    34


section .text
global _start
_start:

mov ecx, dword[length]
mov rsi, 0  ; Counter
mov r8, 0  ; Area Sum
mov r9, 0  ; Perimeter Sum
mov r10, 0 ; Semi-Perimeter Sum
; Set our Min to max integer signed value
mov eax, 0x7FFFFFFF
mov dword[aMin], eax
mov dword[pMin], eax
mov dword[sMin], eax
calcLoop:
    ; Calculate Area of
    mov ebx, 2
    mov eax, 0
    mov ax, word[pDiags+rsi*2]
    mul dword[qDiags+rsi*4]
    div ebx
    mov dword[areas+rsi*4], eax    
    ; Add Area Sum
    add r8d, dword[areas+rsi*4]
    ; Check Min Area
    cmp eax, dword[aMin]
    jb AreaLess
    jmp AreaNotLess
AreaLess:
    mov dword[aMin], eax
AreaNotLess:
    ; Check Max Area
    cmp eax, dword[aMax]
    ja AreaMore
    jmp AreaNotMore
AreaMore:
    mov dword[aMax], eax
AreaNotMore:
    
    ; Calculate Perimeter
    mov ebx, 4
    mov eax, 0
    mov ax, word[aSides+rsi*2]
    mul ebx
    mov dword[perims+rsi*4], eax
    ; Add Perimeter Sum
    add r9d, dword[perims+rsi*4]
    ; Check Min Perimeter
    cmp eax, dword[pMin]
    jb PerimeterLess
    jmp PerimeterNotLess
PerimeterLess:
    mov dword[pMin], eax
PerimeterNotLess:
    ; Check Max Perimeter
    cmp eax, dword[pMax]
    ja PerimeterMore
    jmp PerimeterNotMore
PerimeterMore:
    mov dword[pMax], eax
PerimeterNotMore:
    ; Caclulate Semi-Perimeter    
    mov ebx, 2
    mov eax, dword[perims+rsi*4]
    div ebx
    mov dword[sPerims+rsi*4], eax
    ; Add Semi-Perimeter Sum
    add r10d, dword[sPerims+rsi*4]
    ; Check Min Semi-Perimeter
    cmp eax, dword[sMin]
    jb sPerimeterLess
    jmp sPerimeterNotLess
sPerimeterLess:
    mov dword[sMin], eax
sPerimeterNotLess:   
    ; Check Max Semi-Perimeter
    cmp eax, dword[sMax]
    ja sPerimeterMore
    jmp sPerimeterNotMore
sPerimeterMore:
    mov dword[sMax], eax
sPerimeterNotMore:
    inc rsi
    dec rcx
    cmp rcx, 0
    je calcLoopDone
    jmp calcLoop
calcLoopDone:

; Move Area Sum and Area Average
mov edx, 0
mov dword[aSum], r8d
mov eax, r8d
div dword[length]
mov dword[aAve], eax

; Move Perimeter Sum and Perimeter Average
mov edx, 0
mov dword[pSum], r9d
mov eax, r9d
div dword[length]
mov dword[pAve], eax

; Move SemiPerimeter Sum and SemiPerimeter Average
mov edx, 0
mov dword[sSum], r10d
mov eax, r10d
div dword[length]
mov dword[sAve], eax

mov edx, 0
; Find midpoint of areas
mov ebx, 2
mov eax, dword[length]
div ebx
mov ebx, dword[areas+eax*4]
dec eax
add ebx, dword[areas+eax*4]
mov eax, ebx
mov ebx, 2
div ebx
mov dword[aMid], eax

mov edx, 0
; Find midpoint of perimeter
mov ebx, 2
mov eax, dword[length]
div ebx
mov ebx, dword[perims+eax*4]
dec eax
add ebx, dword[perims+eax*4]
mov eax, ebx
mov ebx, 2
div ebx
mov dword[pMid], eax

mov edx, 0
; Find midpoint of sperimeter
mov ebx, 2
mov eax, dword[length]
div ebx
mov ebx, dword[sPerims+eax*4]
dec eax
add ebx, dword[sPerims+eax*4]
mov eax, ebx
mov ebx, 2
div ebx
mov dword[sMid], eax

; program finished
last:
    mov eax, SYS_exit       ; call for exit
    mov ebx, EXIT_SUCCESS   ; return 0
    syscall
