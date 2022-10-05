;  Ed Jorgensen
;  Threading program, provided template

; ***************************************************************

section	.data

; -----
;  Define standard constants.

LF		equ	10			; line feed
NULL		equ	0			; end of string
ESC		equ	27			; escape key

TRUE		equ	1
FALSE		equ	-1

SUCCESS		equ	0			; Successful operation
NOSUCCESS	equ	1			; Unsuccessful operation

STDIN		equ	0			; standard input
STDOUT		equ	1			; standard output
STDERR		equ	2			; standard error

SYS_read	equ	0			; system call code for read
SYS_write	equ	1			; system call code for write
SYS_open	equ	2			; system call code for file open
SYS_close	equ	3			; system call code for file close
SYS_fork	equ	57			; system call code for fork
SYS_exit	equ	60			; system call code for terminate
SYS_creat	equ	85			; system call code for file open/create
SYS_time	equ	201			; system call code for get time

O_CREAT		equ	0x40
O_TRUNC		equ	0x200
O_APPEND	equ	0x400

O_RDONLY	equ	000000q			; file permission - read only
O_WRONLY	equ	000001q			; file permission - write only
O_RDWR		equ	000002q			; file permission - read and write

S_IRUSR		equ	00400q
S_IWUSR		equ	00200q
S_IXUSR		equ	00100q

; -----
;  Message strings

header		db	LF, "*******************************************", LF
		    db	ESC, "[1m", "Program Start", ESC, "[0m", LF, LF, NULL

msgFinal	db	"Final Counter Value should be: ", NULL
msgDoneMain	db	"Non-Threaded Counter -> Final Value: ", NULL
msgDoneThread	db	"Threaded Counter -> Final Value: ", NULL

msgProgDone	db	LF, "Completed.", LF, NULL

errUsage	db	"Usage: ast12 <-sq|-pt|-tg>", LF, NULL
errSpec		db	"Error, invalid argument.", LF, NULL

msgStart	db	LF, "--------------------------------------", LF	
		    db	"Compute Formula -> Non-Threaded", LF, NULL
msgStartThread	db	LF, "--------------------------------------", LF
		    db	"Compute Formula -> Threaded", LF, NULL

; -----

fltZero		dq	0.0
fltMax		dq	8589934590.0
max		    dq	8589934590

; -----
;  Variables for thread functions.

myValue		dq	0.0
limit			dq	0

; -----
;  Thread data structures

pthreadID0	dd	0, 0, 0, 0, 0
pthreadID1	dd	0, 0, 0, 0, 0
pthreadID2	dd	0, 0, 0, 0, 0
pthreadID3	dd	0, 0, 0, 0, 0

; -----
;  Local variables for compute functions.

x		dq	1.0
y		dq	1.0

msgMain		db	" ...Main starting...", LF, NULL
msgThread0	db	" ...Thread 0 starting...", LF, NULL
msgThread1	db	" ...Thread 1 starting...", LF, NULL

; -----
;  Local variables for printMessageValue

newLine		db	LF, NULL


section	.bss
tmpString	resb	12


; ***************************************************************

section	.text

; -----
; External statements for thread functions in another file.

extern	pthread_create, pthread_join

; ================================================================
;  Main program

global main
main:

; ================================================================
;  Set limit to 0x1fffffffe (8,589,934,590 = 0x1fffffffe)
;	nothing magic, just a really big number...

	mov	dword [limit], 0xfffffffe
	mov	dword [limit+4], 1

	movsd	xmm0, qword [fltZero]
	movsd	qword [myValue], xmm0

; ================================================================
;  Sequential thread functions.

;  Initial actions:
;	Display start message
;	Display final value in senary (for reference)
;	Display message for sequential, non-threaded start message

	mov	rdi, header
	call	printString

	mov	rdi, msgFinal
	mov	rsi, qword [limit]
	call	printMessageValue

	mov	rdi, msgStart
	call	printString

; -----
;  Create new thread 0
;	pthread_create(&pthreadID0, NULL, &threadFunction0, NULL);
;  Wait for thread to complete.
;	pthread_join (pthreadID0, NULL);

	mov	rdi, pthreadID0
	mov	rsi, NULL
	mov	rdx, threadFunction0
	mov	rcx, NULL
	call	pthread_create
	
	mov	rdi, qword [pthreadID0]
	mov	rsi, NULL
	call	pthread_join

;  Create new thread 1
;	pthread_create(&threadID1, NULL, threadFunction1, NULL);
;  Wait for thread to complete.
;	pthread_join (pthreadID1, NULL);

	mov	rdi, pthreadID1
	mov	rsi, NULL
	mov	rdx, threadFunction1
	mov	rcx, NULL
	call	pthread_create

	mov	rdi, qword [pthreadID1]
	mov	rsi, NULL
	call	pthread_join

; -----
;  Display final result for sequential, non-threaded result.

	mov	rdi, msgDoneMain
	movsd	xmm0, qword [myValue]
	cvtsd2si	rsi, xmm0
	call	printMessageValue


; **********
;  Program done, display final 'done' message
;	and terminate.

	mov	rdi, msgProgDone
	call	printString

progDone:
	mov	rax, SYS_exit			; system call for exit
	mov	rdi, SUCCESS			; return code SUCCESS
	syscall

; ******************************************************************
;  Thread function #0
;	Accesses a global variable 'myValue'
;	Computes -> myValue = (myValue / x) + y

; -----
;  Arguments:
;	N/A (global variable accessed)
;  Returns:
;	N/A (global variable accessed)

global threadFunction0
threadFunction0:

; -----
;  Initial message for thread 0.

	mov	rdi, msgThread0
	call	printString

	xor r10, r10					; clear r10 register
	mov rbx, 2						; move 2 into rbx
	mov rdx, 0						; extend positive sign bit
	mov rax, qword[limit]	; move limit into rax
	div rbx								; limit / 2

	calculate_lim0:
		movsd xmm0, qword[myValue]
		divsd xmm0, qword[x]
		addsd xmm0, qword[y]
		movsd qword[myValue], xmm0
		inc r10
		cmp r10, rax
		jl calculate_lim0	

	ret

; ******************************************************************
;  Thread function #1
;	Accesses a global variable 'myValue'
;	Computes -> myValue = (myValue / x) + y
;	Loops LIMIT/2 times

; -----
;  Arguments:
;	N/A (global variable accessed)
;  Returns:
;	N/A (global variable accessed)

global threadFunction1
threadFunction1:

; -----
;  Initial message for thread 1.

	mov	rdi, msgThread1
	call	printString

	xor r10, r10						; set r10 to zero
	mov rbx, 2							; move 2 into rbx
	mov rdx, 0							; extend positive sign bit
	mov rax, qword[limit]		; move limit into rax
	div rbx									; limit/2
	
	calculate_lim1:
		movsd xmm0, qword[myValue]
		divsd xmm0, qword[x]
		addsd xmm0, qword[y]
		movsd qword[myValue], xmm0
		inc r10
		cmp r10, rax
		jl calculate_lim1

	ret

; ******************************************************************
;  Convert integer to ASCII/Senary string.
;	Note, no error checking required on integer.

; -----
;  Arguments:
;	1) integer, value
;	2) string, address
; -----
;  Returns:
;	ASCII/Senary string (NULL terminated)

global	intToSenary
intToSenary:
    ; rdi -> integer value
    ; rsi -> string address

    mov rax, rdi
    mov r10, 6      ; move senary base value into rsi
    mov r11, 0x30   ; move ascii conversion shortcut into rdx
    mov rcx, 0      ; length starts at zero
    cnt:
        mov rdx, 0  ; extend positive sign bit
        div r10     ; divide by radix
        inc rcx     ; length++
        cmp rax, 0  ; if nothing left end
        jne cnt
    mov rax, rdi
    add rsi, rcx
    mov byte[rsi], NULL
    dec rsi
    sen_loop:
        mov rdx, 0          ; extend positive sign bit
        div r10             ; divide by radix
        add rdx, r11        ; convert to ascii
        mov byte[rsi], dl   ; add converted ascii number to string
        dec rsi
        cmp rax, 0
        jne sen_loop
	ret

; ******************************************************************
;  Display message and hex value in specified format.
;	format: <messageString> <value> <newLine>

;  Basic steps:
;	- print message string (via passed address)
;	- convert value into ASCII/Hex string
;	- print ASCII/Hex string
;	- print newLine (for nice formatting)

; -----
;  Arguments:
;	1) message, address
;	2) value, value
; -----
;  Returns:
;	N/A

global	printMessageValue
printMessageValue:
	push	rbx
	mov	rbx, rsi		; save value

	call	printString

	mov	rdi, rbx
	mov	rsi, tmpString
	call	intToSenary

	mov	rdi, tmpString
	call	printString

	mov	rdi, newLine
	call	printString

	pop	rbx
	ret

; ******************************************************************
;  Generic procedure to display a string to the screen.
;  String must be NULL terminated.
;  Algorithm:
;	Count characters in string (excluding NULL)
;	Use syscall to output characters

;  Arguments:
;	1) address, string
;  Returns:
;	nothing

global	printString
printString:

; -----
; Count characters to write.

	mov	rdx, 0
strCountLoop:
	cmp	byte [rdi+rdx], NULL
	je	strCountLoopDone
	inc	rdx
	jmp	strCountLoop
strCountLoopDone:
	cmp	rdx, 0
	je	printStringDone

; -----
;  Call OS to output string.

	mov	rax, SYS_write			; system code for write()
	mov	rsi, rdi			; address of characters to write
	mov	rdi, STDOUT			; file descriptor for standard in
						; rdx=count to write, set above
	syscall					; system call

; -----
;  String printed, return to calling routine.

printStringDone:
	ret

; ******************************************************************

