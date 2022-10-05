;  Procedures Template.

; --------------------------------------------------------------------
;  Write some assembly language functions.

;  The function, shellSort(), sorts the numbers into ascending
;  order (small to large).  Uses the shell sort algorithm from
;  assignment #7 (modified to sort in ascending order).

;  The function, basicStats(), finds the minimum, median, and maximum,
;  sum, and average for a list of numbers.
;  Note, the median is determined after the list is sorted.
;   This function must call the lstSum() and lstAvergae()
;   functions to get the corresponding values.
;   The lstAvergae() function must call the lstSum() function.

;  The function, linearRegression(), computes the linear regression of
;  the two data sets.  Summation and division performed as integer.


; ********************************************************************************

section .data

; -----
;  Define constants.

TRUE        equ 1
FALSE       equ 0

; -----
;  Local variables for shellSort() function (if any).

h           dd  0
i           dd  0
j           dd  0
tmp         dd  0
dThree      dd  3
dTwo        dd  2
; -----
;  Local variables for basicStats() function (if any).



section .bss

; -----
;  Local variables for linearRegression() function (if any).

qSum        resq    1
dSum        resd    1


; ********************************************************************************

section .text

; --------------------------------------------------------
;  Shell sort function.

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

; -----
;  HLL Call:
;   call shellSort(list, len)

;  Arguments Passed:
;   1) list, addr - rdi
;   2) length, value - rsi

;  Returns:
;   sorted list (list passed by reference)

global  shellSort
shellSort:

    mov rax, 1
    mov dword[h], eax
    whileLoop1:
        mov eax, dword[dThree]
        mul dword[h]
        inc eax
        cmp eax, esi
        jge exitWhileLoop1
        mov dword[h], eax
        jmp whileLoop1
    exitWhileLoop1

    whileLoop2:
        mov rcx, 0
        mov ecx, dword[h]
        cmp rcx, 0
        jle exitWhileLoop2
        dec rcx
        mov dword[i], ecx
        forLoop1:
            cmp ecx, esi
            jge exitForLoop1
            mov eax, dword[rdi+rcx*4]
            mov dword[tmp], eax
            mov dword[j], ecx
            forLoop2:
                mov r8, 0
                mov r8d, dword[j]
                cmp r8d, dword[h]
                jl exitForLoop2
                mov r9, 0
                mov r9d, r8d
                sub r9d, dword[h]
                mov r9d, dword[rdi+r9*4]
                cmp r9d, dword[tmp]
                jge exitForLoop2
                mov r10, 0
                mov r10d, dword[j]
                mov dword[rdi+r10*4], r9d
                sub r10d, dword[h]
                mov dword[j], r10d
                jmp forLoop2
            exitForLoop2:
            mov r9d, dword[j]
            mov r10d,  dword[tmp]
            mov dword[rdi+r9*4], r10d
            inc ecx
            jmp forLoop1
        exitForLoop1:
        mov eax, dword[h]
        cdq
        idiv dword[dThree]
        mov dword[h], eax
        jmp whileLoop2
    exitWhileLoop2

    ret

; --------------------------------------------------------
;  Find basic statistical information for a list of integers:
;   minimum, median, maximum, sum, and average

;  Note, for an odd number of items, the median value is defined as
;  the middle value.  For an even number of values, it is the integer
;  average of the two middle values.

;  This function must call the lstSum() and lstAvergae() functions
;  to get the corresponding values.

;  Note, assumes the list is already sorted.

; -----
;  Call:
;   call basicStats(list, len, min, med, max, sum, ave)

;  Arguments Passed:
;   1) list, addr - rdi
;   2) length, value - rsi
;   3) minimum, addr - rdx
;   4) median, addr - rcx
;   5) maximum, addr - r8
;   6) sum, addr - r9
;   7) ave, addr - stack, rbp+16

;  Returns:
;   minimum, median, maximum, sum, and average
;   via pass-by-reference (addresses on stack)

global basicStats
basicStats:
    push rbp 
    mov rbp, rsp
    push rbx
    push r12

    mov rbx, qword[rbp+16]      ; get var on stack
        
    mov eax, esi                ; length
    dec eax                     ; length--
    mov eax, dword[rdi+rax*4]   ; lst[length--]
    mov dword[rdx], eax         ; max = lst[length--]
    mov rax, 0
    mov eax, dword[rdi+rax*4]   ; lst[0]
    mov dword[r8], eax          ; min = lst[0]
    mov rax, 0
    call lstSum                 ; sum = eax
    mov dword[r9], eax          ; move sum into address
    call lstAve                 ; average = eax
    mov dword[rbx], eax         ; move average
    mov rax, 0
    mov r12, 0
    mov eax, esi                ; length
    mov edx, 0
    div dword[dTwo]             ; length / 2
    cmp edx, 0                  ; even ? odd ?
    jne aveOdd
        mov r12d, dword[rdi+rax*4]  ; lst[len/2]
        dec eax
        add r12d, dword[rdi+rax*4]  ; lst[(len/2)-1]
        cdq
        idiv dword[dTwo]
        mov dword[rcx], eax
    aveOdd:
        mov r12d, dword[rdi+rax*4]
        mov dword[rcx], r12d
    pop r12
    pop rbx
    pop rbp
    ret

; --------------------------------------------------------
;  Function to calculate the sum of a list.

; -----
;  Call:
;   ans = lstSum(lst, len)

;  Arguments Passed:
;   1) list, address - rdi
;   1) length, value - rsi

;  Returns:
;   sum (in eax)


global  lstSum
lstSum:
    mov r11, 0  ; i
    mov rax, 0  ; running sum
    sumLoop:
        add eax, dword[rdi+r11*4]   ; sum += lst[i]
        inc r11                     ; i ++ 
        cmp r11d, esi               ; i < length ?
        jne sumLoop
    ret

; --------------------------------------------------------
;  Function to calculate the average of a list.
;  Note, must call the lstSum() fucntion.

; -----
;  Call:
;   ans = lstAve(lst, len)

;  Arguments Passed:
;   1) list, address - rdi
;   1) length, value - rsi

;  Returns:
;   average (in eax)


global  lstAve
lstAve:
    call lstSum     ; sum = eax
    cdq             ; extend sign bit
    idiv esi        ; sum / length
    ret

; --------------------------------------------------------
;  Function to calculate the linear regression
;  between two lists (of equal size).

; -----
;  Call:
;   linearRegression(xList, yList, len, xAve, yAve, b0, b1)

;  Arguments Passed:
;   1) xList, address - rdi
;   2) yList, address - rsi
;   3) length, value - rdx
;   4) xList average, value - rcx
;   5) yList average, value - r8
;   6) b0, address - r9
;   7) b1, address - stack, rpb+16

;  Returns:
;   b0 and b1 via reference

global linearRegression
linearRegression:
    push rbp
    mov rbp, rsp
    push rbx
    push r14        ; length of lists
   
    mov rbx, qword[rbp+16]  ; grab address from stack 
    mov r14, rdx            ; move length from rdx to r14
    mov r10, 0              ; counter
    mov qword[qSum], r10    ; set qSum to 0
    mov dword[dSum], r10d   ; set dSum to 0
    forLoopb1:              ; for( i = 0 ; i < len ; i++ )
        cmp r10d, r14d              ; for loop condition
        je forLoopExitb1            ; break if condition no longer met
        mov rax, 0                  ; prepare registers for arith
        mov r11, 0
        mov rdx, 0
        mov eax, dword[rdi+r10*4]   ; x[i]
        sub eax, ecx                ; x[i] - xAve
        mov r11d, dword[rsi+r10*4]  ; y[i]
        sub r11d, r8d               ; y[i] - yAve
        imul r11d         
        add dword[qSum], eax        ; (x[i] - xAve)(y[i] - yAve)
        adc dword[qSum+4], edx      ; add carry bit

        mov rax, 0                  ; prepare registers for arith
        mov rdx, 0
        mov eax, dword[rdi+r10*4]   ; x[i]
        sub eax, ecx                ; x[i] - xAve
        imul eax                    ; (x[i] - xAve) ^ 2
        add dword[dSum], eax        ; place in dSum

        inc r10                     ; i++
        jmp forLoopb1               ; loop
    forLoopExitb1:
    mov rax, qword[qSum]            ; dividend
    mov r11d, dword[dSum]           ; divisor
    cqo                             ; extend sign bit
    idiv r11                        ; dividend / divisor
    mov dword[rbx], eax             ; b1 = ^
    mov r10, 0                      ; clear r10
    mov r10d, r8d                   ; yAve
    mov rdx, 0                      ; clear rdx
    imul ecx                        ; b1 * xAve
    sub r10d, eax                   ; yAve - b1 * xAve
    mov dword[r9], r10d             ; b0 = ^

    pop r14                 ; pop used registers back off
    pop rbx
    pop rbp
    ret

; ********************************************************************************


