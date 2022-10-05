;  Procedures Template.

; --------------------------------------------------------------------
;  Write assembly language functions.

;  The function readSenaryNum() should read a senary number
;  from the user (STDIN) and perform apprpriate error checking.

;  The procedure, shellSort(), sorts the numbers into ascending
;  order (small to large).  Uses the shell sort algorithm
;  modified to sort in ascending order.

;  The function lstSum() to return the sum of a list.
;  The function lstAverage() to return the average of a list.
;  Must call the lstSum() function.

;  The fucntion basicStats() finds the minimum, median, and maximum,
;  sum, and average for a list of numbers.
;  The median is determined after the list is sorted.
;  Must call the lstSum() and lstAverage() functions.

;  The function linearRegression() computes the linear regression.
;  for the two data sets.


; ********************************************************************************

section .data

; -----
;  Define standard constants.

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

; -----
;  Define program specific constants.

SUCCESS     equ 0
NOSUCCESS   equ 1
OUTOFRANGEMIN   equ 2
OUTOFRANGEMAX   equ 3
INPUTOVERFLOW   equ 4
ENDOFINPUT  equ 5

LIMIT       equ 1510

MIN     equ -1000000
MAX     equ 1000000
BUFFSIZE    equ 50          ; 50 chars including NULL

; -----
;  NO static local variables allowed...


; ********************************************************************************

section .text

; --------------------------------------------------------
;  Read an ASCII senary number from the user

;  Return codes:
;   SUCCESS         Successful conversion
;   NOSUCCESS       Invalid input entered
;   OUTOFRANGEMIN       Input below minimum value
;   OUTOFRANGEMAX       Input above maximum value
;   INMPUTOPVERFLOW     User entry character count exceeds maximum length
;   ENDOFINPUT      End of the input

; -----
;  Call:
;   status = readSenaryNum(&numberRead);

;  Arguments Passed:
;   1) numberRead, addr - rdi

;  Returns:
;   number read (via reference)
;   status code (as above)

global readSenaryNum
readSenaryNum:
    push rbp
    mov rbp, rsp
    sub rsp, 55
    push rbx
    push r12
    push r14
    mov r14, rdi

    mov dword[rbp-55], 0    ; runningSum = 0
    lea rbx, byte[rbp-50]   ; rbx points to head of buffer
    getNxtChar:
        mov rax, SYS_read       ; read a character
        mov rdi, STDIN          ; input in
        lea rsi, byte[rbp-51]   ; rsi is char
        mov rdx, 1              ; 1 char read
        syscall                 ; call
        mov al, byte[rbp-51]    ; move char into al
        cmp al, LF              ; if al is linefeed done
        je exit             
        mov byte[rbx], al       ; else add to buffer
        inc rbx                 ; inc rbx
        jmp getNxtChar          ; loop
    exit:
    mov byte[rbx], NULL         ; add NULL terminiating character

    pop r14
    pop r12
    pop rbx
    mov rsp, rbp
    pop rbp
    ret

; --------------------------------------------------------
;  Shell sort procedure.

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

;  Local Variables
;   h =     rbp - 4
;   i =     rbp - 8
;   j =     rbp - 12
;   tmp =   rbp - 16

global  shellSort
shellSort:
    push rbp
    mov rbp, rsp
    sub rsp, 16
    push rbx
     
    mov rax, 1
    mov dword[rbp-4], eax
    whileLoop1:
        mov eax, 3
        mul dword[rbp-4]
        inc eax
        cmp eax, esi
        jge exitWhileLoop1
        mov dword[rbp-4], eax
        jmp whileLoop1
    exitWhileLoop1

    whileLoop2:
        mov rcx, 0
        mov ecx, dword[rbp-4]
        cmp rcx, 0
        jle exitWhileLoop2
        dec rcx
        mov dword[rbp-8], ecx
        forLoop1:
            cmp ecx, esi
            jge exitForLoop1
            mov eax, dword[rdi+rcx*4]
            mov dword[rbp-16], eax
            mov dword[rbp-12], ecx
            forLoop2:
                mov r8, 0
                mov r8d, dword[rbp-12]
                cmp r8d, dword[rbp-4]
                jl exitForLoop2
                mov r9, 0
                mov r9d, r8d
                sub r9d, dword[rbp-4]
                mov r9d, dword[rdi+r9*4]
                cmp r9d, dword[rbp-16]
                jge exitForLoop2
                mov r10, 0
                mov r10d, dword[rbp-12]
                mov dword[rdi+r10*4], r9d
                sub r10d, dword[rbp-4]
                mov dword[rbp-12], r10d
                jmp forLoop2
            exitForLoop2:
            mov r9d, dword[rbp-12]
            mov r10d,  dword[rbp-16]
            mov dword[rdi+r9*4], r10d
            inc ecx
            jmp forLoop1
        exitForLoop1
        mov eax, dword[rbp-4]
        cdq
        mov rbx, 3
        idiv rbx
        mov dword[rbp-4], eax
        jmp whileLoop2
    exitWhileLoop2

    pop rbx
    mov rsp, rbp
    pop rbp
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
    push r13
    mov rbx, qword[rbp+16]      ; get var on stack

    mov r13, 2                  ; dTwo
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
    
    div r13d                    ; length / 2
    cmp edx, 0                  ; even ? odd ?
    jne aveOdd
        mov r12d, dword[rdi+rax*4]  ; lst[len/2]
        dec eax
        add r12d, dword[rdi+rax*4]  ; lst[(len/2)-1]
        cdq
        idiv r13d
        mov dword[rcx], eax
    aveOdd:
        mov r12d, dword[rdi+rax*4]
        mov dword[rcx], r12d
    pop r13
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

global lstSum
lstSum:
    mov r11, 0 ; i
    mov rax, 0 ; running sum
    sumLoop:
        add eax, dword[rdi+r11*4]   ; sum += lst[i]
        inc r11                     ; i++
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

global lstAve
lstAve:
    call lstSum ; sum = eax
    cdq         ; extend sign bit
    idiv esi    ; sum / length
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
    sub rsp, 12
    push rbx
    push r14        ; length of lists

    mov rbx, qword[rbp+16]  ; grab address from stack 
    mov r14, rdx            ; move length from rdx to r14
    mov r10, 0              ; counter
    mov qword[rbp-12], r10  ; set qSum to 0
    mov dword[rbp-4], r10d  ; set dSum to 0
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
        add dword[rbp-12], eax     ; (x[i] - xAve)(y[i] - yAve)
        adc dword[rbp-8], edx      ; add carry bit

        mov rax, 0                  ; prepare registers for arith
        mov rdx, 0
        mov eax, dword[rdi+r10*4]   ; x[i]
        sub eax, ecx                ; x[i] - xAve
        imul eax                    ; (x[i] - xAve) ^ 2
        add dword[rbp-4], eax       ; place in dSum

        inc r10                     ; i++
        jmp forLoopb1               ; loop
    forLoopExitb1:
    mov rax, qword[rbp-12]          ; dividend
    mov r11d, dword[rbp-4]          ; divisor
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


