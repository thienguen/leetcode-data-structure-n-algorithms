;  Provided Template

; -----
;  The provided main calls four functions.

;  1) checkParameters()
;   Get command line arguments (word, match case flag, and
;   file descriptor), performs appropriate error checking,
;   opens file, and returns the word, match case flag, and
;   the file descriptor and word.  Ifthere any errors in
;   command line arguments, display appropriate error
;   message, and return NOSUCCESS status code.

;  2) getWord()
;   Get a single word of text (which is expected to be
;   no more than MAXWORDLENGTH characters).
;   Returned word is terminated with an NULL.
;   Note, this routine performs all buffer management.

;  NOTE: The buffer management is a significant portion of
;   the assignment.  Omitting or skipping the I/O
;   buffering will significantly impact the score.

;  3) checkWord()
;       Given the new word from the file and the user specified
;       word and the current count, update the count if the 
;   words match.

;  4) displayResults()
;   Display a formatted summary of the results.


;----------------------------------------------------------------------------

; Arguments:
;   %1 -> <interger>, value
;   %2 -> <stirng>, string address

section .data

; -----
;  Define standard constants.

LF      equ 10              ; line feed
NULL        equ 0           ; end of string
SPACE       equ 0x20        ; space

TRUE        equ 1
FALSE       equ 0

SUCCESS     equ 0           ; Successful operation
NOSUCCESS   equ 1           ; Unsuccessful operation

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

O_CREAT     equ 0x40
O_TRUNC     equ 0x200
O_APPEND    equ 0x400

O_RDONLY    equ 000000q         ; file permission - read only
O_WRONLY    equ 000001q         ; file permission - write only
O_RDWR      equ 000002q         ; file permission - read and write

S_IRUSR     equ 00400q
S_IWUSR     equ 00200q
S_IXUSR     equ 00100q

; -----
;  Variables for getFileDescriptors()

usageMsg    db  "Usage: ./wc -w <searchWord> <-mc|-ic> -f <inputFile>"
        db  LF, NULL

errbadCLQ   db  "Error, invalid command line arguments."
        db  LF, NULL

errWordSpec db  "Error, invalid search word specifier."
        db  LF, NULL

errWordLength   db  "Error, search word length must be < 80 "
        db  "characters."
        db  LF, NULL

errFileSpec db  "Error, invalid input file specifier."
        db  LF, NULL

errCaseSpec db  "Error, invalid match case specifier."
        db  LF, NULL

errOpenIn   db  "Error, can not open input file."
        db  LF, NULL

; -----
;  Define constants and variables for getWord()

MAXWORDLENGTH   equ 80
BUFFSIZE    equ 250000
;BUFFSIZE   equ 3

bfMax       dq  BUFFSIZE
curr        dq  BUFFSIZE

wasEOF      db  FALSE

errFileRead db  "Error reading input file."
        db  LF, NULL

; -----
;  Define constants and variables for displayResults()

resultStart db  "Found '", NULL
resultSpace db  "' ", NULL
resultEnd   db  " times.", LF, NULL

; -------------------------------------------------------

section .bss

buff        resb    BUFFSIZE+1
tmpString   resb    MAXWORDLENGTH+1


; -------------------------------------------------------

section .text

; -------------------------------------------------------
;  Check and return command line parameters.
;   Assignment #11 requires a word and file name.
;   Example:    % ./wc -w <searchWord> <-mc|-ic> -f <infile>

; -----
; HLL Call:
;   bool = checkParameters(ARGC, ARGV, searchWord, matchCase, rdFileDesc)

;  Arguments passed:
;   1) argc, value
;   2) argv, address
;   3) search word string, address
;   4) match case boolean, address
;   5) input file descriptor, address


global checkParameters
checkParameters:
    push rbx
    push r12
    push r13

    mov r13, r8                 ; move r8 since r8 not preserved
    mov r12, rcx                ; move rcx since rcx not preserved
    cmp rdi, 1                  ; if no args
    jne noUsage
        mov rdi, usageMsg       ; move usage message into rdi
        call printString        ; call print function
        mov rax, FALSE          ; return false
    jmp dn
    noUsage:
    cmp rdi, 6                  ; if correct amount of args 
    je goodArgCount
        mov rdi, errbadCLQ      ; move bad arg counts into rdi
        call printString        ; call print function
        mov rax, FALSE          ; return false
    jmp dn
    goodArgCount:
    mov rbx, qword[rsi+8]       ; rbx = argv[1] ( word specifier )
    cmp byte[rbx], 0x2D
    jne errorWordSpec
    cmp byte[rbx+1], 0x77
    jne errorWordSpec
    cmp byte[rbx+2], 0x00
    jne errorWordSpec
    jmp noErrorWordSpec
    errorWordSpec:
        mov rdi, errWordSpec    ; move bad word specifier into rdi
        call printString        ; call print functino
        mov rax, FALSE          ; return false
    jmp dn
    noErrorWordSpec:
    mov rbx, qword[rsi+16]      ; rbx = argv[2] ( word value )
    xor r11, r11
    xor r10, r10                ; set r10 to zero
    length:                 
        mov r11b, byte[rbx+r10]
        cmp r11b, NULL          ; end loop if NULL reached
        je endLength
        mov byte[rdx], r11b
        inc rdx
        inc r10                 ; find length
        jmp length
    endLength:
    mov byte[rdx], NULL
    cmp r10, MAXWORDLENGTH      ; compare length to max word length
    jb goodLength
        mov rdi, errWordLength  ; move error word length into rdi
        call printString        ; call print function
        mov rax, FALSE          ; return false
    jmp dn
    goodLength:
    mov rbx, qword[rsi+24]      ; rbx = argv[3] ( search specifier )
    cmp dword[rbx], 0x00636D2D  ; check search specifier (mc)
    jne checkTwo
        mov byte[r12], TRUE     ; set match case specifier to true
    jmp caseGood                ; skip next check
    checkTwo:
    cmp dword[rbx], 0x0063692D  ; check search specifier (ic)    
    je caseGood
        mov rdi, errCaseSpec    ; move match case error into rdi
        call printString        ; call print function
        mov rax, FALSE          ; return false
    jmp dn
    mov byte[r12], FALSE        ; set match case sepcifier to false
    caseGood:
    mov rbx, qword[rsi+32]      ; rbx = argv[4] ( file specifier )
    cmp byte[rbx], 0x2D
    jne fileSpecError
    cmp byte[rbx+1], 0x66
    jne fileSpecError
    cmp byte[rbx+2], 0x00
    jne fileSpecError
    jmp goodFileSpec
    fileSpecError:
        mov rdi, errFileSpec    ; move error file specifier into rdi
        call printString        ; call printString
        mov rax, FALSE          ; return false
    jmp dn
    goodFileSpec:
    mov rbx, qword[rsi+40]      ; rbx = argv[5] ( file string )
    mov rax, SYS_open           ; read file
    mov rdi, rbx                ; move file name
    mov rsi, O_RDONLY           ; read only
    syscall                     ; attempt to open file
    cmp rax, 0
    jge noError
        mov rdi, errOpenIn      ; move error file open into rdi
        call printString        ; call print function
        mov rax, FALSE          ; return false
    jmp dn
    noError:
    mov dword[r13], eax         ; save descriptor
    mov rax, TRUE               ; function ran successfully
    dn:
    pop r13
    pop r12
    pop rbx
    ret

; -------------------------------------------------------
;  Get a single word of text and return.
;  Implements standard C++ (searchWord << inFile) functionality.

;  A "word" is considered a set of contiguous non-white space
;  characters.  White space includes spaces, tabs, and LF.
;  Any character <= a space character is considered white space.
;  Function terminates word string with a NULL.

;  This routine handles the I/O buffer management.
;   - if buffer is empty, get more chars from file
;   - return word and update buffer pointers

;  If a word is returned, return TRUE.
;  Otherwise, return FALSE.

; -----
; HLL Call:
;   bool = getWord(currentWord, rdFileDesc)

;  Arguments passed:
;   1) word buffer, address
;   2) file descriptor, value

global getWord
getWord:
    push rbx   
    push r12
    push r13 
    push r14
    
    mov rbx, rdi                    ; move first param into rbx    
    mov r14, rsi                    ; move file descriptor into r14
    xor r8, r8                      ; xor r8 to keep track of word length

    reBuffer:
    mov r10, qword[bfMax]           ; move bfMax into r10
    cmp qword[curr], r10            ; check if we still have data in buffer
    jb underBuffSize                ; if not read below
        cmp byte[wasEOF], TRUE      ; check if EOF has been reached
        jne notEOF
            mov rax, FALSE          ; return false , no word
        jmp _dn
        notEOF:
        mov rax, SYS_read           ; set read option
        mov rdi, r14                ; set file descriptor
        mov rsi, buff               ; set buffer to file buffer
        mov rdx, BUFFSIZE           ; set buffer size
        syscall                     ; read

        cmp rax, 0                  ; check for errors in read
        jge readFine
            mov rax, errFileRead    ; put read file into rdi
            call printString        ; call print function
            mov rax, FALSE          ; return false
        jmp _dn
        readFine:
        
        cmp rax, BUFFSIZE           ; compare actual read - requested read
        je notEof       
            mov byte[wasEOF], TRUE  ; set eof
            mov qword[bfMax], rax   ; set max to actual read
        notEof 
        xor r10, r10                ; set curr to zero
        mov qword[curr], r10        ; move value into variable
    underBuffSize:                  ; now attempt to read

    xor r9, r9                      ; clear r9 register 
    xor r11, r11                    ; clear r11 register
    mov r12, buff                   ; move buffer address into r12
    mov r9, qword[curr]             ; move value of curr into r9

    getNextWord:
        mov r11b, byte[r12+r9]      ; get character from buffer
        cmp r11b, 0x20              ; ensure character is not a space
        jbe endNextWord
        cmp r8, MAXWORDLENGTH
        jae ignoreSpaces 
        mov byte[rbx], r11b         ; move a byte from the buffer into string
        inc rbx                     ; increment rbx
        inc r9                      ; inc curr
        inc r8
    jmp getNextWord
    endNextWord:
    
    cmp r9, qword[bfMax]                  ; if what casued the loop above to break was EOF
    jb noReBuffer
        mov qword[curr], r9         ; put value back into curr
        jmp reBuffer                ; refill buffer
    noReBuffer:   
 
    ;mov byte[rbx+r13], NULL
    ignoreSpaces:
        mov r11b, byte[r12+r9]      ; move character into buffer again
        cmp r11b, 0x2F              ; ignore slashes(to prevent overflow)
        je _inc                     ; increment if slash found
        cmp r11b, 0x20              ; check if below or equal to a space
        ja endIgnoreSpaces  
        cmp r11b, 0x00              ; also ensure we don't skip EOF
        je endIgnoreSpaces
        _inc:
        inc r9                      ; increment curr
    jmp ignoreSpaces
    endIgnoreSpaces:
    
    mov byte[rbx], NULL             ; move null into end of rbx
    mov qword[curr], r9             ; move curr back into variable
    mov rax, TRUE                   ; return true
    _dn:
    pop r14
    pop r13
    pop r12
    pop rbx
    ret

; -------------------------------------------------------
;  Compare strings, searchWord to currWord.
;  If same, increment word count.

; -----
;  HLL Call:
;   call checkWord(searchWord, currentWord, matchCase, wordCount)

;  Argument passed:
;   1) searchWord, address
;   2) currentWord, address
;   3) match case flag, value
;   4) word count, address

global checkWord
checkWord:
    push rbx

    xor r11, r11                ; zero out r11
    xor r12, r12                ; zero out r12
    wordLoop:
        mov r11b, byte[rdi]     ; move byte into r11b
        mov r12b, byte[rsi]     ; move byet into r12b
        cmp rdx, TRUE           ; check if match case flag is set
        je contCompare
            cmp r11b, 0x41      ; check if search word is upper case
            jb skipSearchWrd   
                cmp r11b, 0x5A
                ja skipSearchWrd
                add r11b, 0x20  ; move to lower case if so
            skipSearchWrd:
            cmp r12b, 0x41      ; check if current word is upper case
            jb skipCurrentWrd
                cmp r12b, 0x5A
                ja skipCurrentWrd
                add r12b, 0x20  ; move to lwoer case if so
            skipCurrentWrd:   
        contCompare:
        cmp r11b, r12b          ; check if bytes are equal
        jne endWordLoop         ; exit if not equal
        cmp r11b, NULL          ; if searchword is NULL then we know to exit
        je endWordLoopInc
        inc rdi
        inc rsi
    jmp wordLoop                ; loop up
    endWordLoopInc:
        mov ebx, dword[rcx]     ; move word count value into rbx
        inc ebx                 ; increment word count
        mov dword[rcx], ebx     ; move back into word address
    endWordLoop:                ; no increment done, mismatched words
    
    pop rbx
    ret

; -------------------------------------------------------
;  Display formatted results to screen.
;   includes search word and count (in senary).
;   format:
;       found <searchWord> <wordCount> times.

; -----
;  HLL Call:
;   displayResults(searchWord, wordCount)

;  Arguments passed:
;   1) search word string, address
;   2) word count, value

global displayResults
displayResults:
    push rbx
    push r12

    mov r12, rsi
    mov rbx, rdi

    mov rdi, resultStart    ; "found '"
    call printString        
    mov rdi, rbx            ; "<searchWord>"
    call printString
    mov rdi, resultSpace    ; "' "
    call printString
    
    mov eax, r12d           ; move int value into eax
    mov rsi, 6              ; senary radix
    mov r10, 0x30           ; constant for conversion to ascii
    mov rcx, 0              ; string length
    mov r9, tmpString       ; move string address into r9
    int2senaryloop1:    
        mov edx, 0          ; extend positive sign bit
        div esi             ; divide by radix
        inc rcx             ; increment length
        cmp eax, 0          ; compare to zero
        jne int2senaryloop1 
    mov eax, r12d           ; reset value of eax
    add r9, rcx             ; set string to last digit
    mov byte[r9], NULL      ; set last as NULL
    dec r9                  ; decrement r9 once
    int2senaryloop2:
        mov edx, 0          ; extend positive sign bit
        div esi             ; divide by radix
        add edx, r10d       ; convert to ascii
        mov byte[r9], dl    ; add converted ascii number to string  
        dec r9              ; move one down string
        cmp eax, 0          ; compare to zero
        jne int2senaryloop2
   
    xor rdi, rdi 
    mov edi, tmpString
    call printString        ; number of occurances of word
    
    mov rdi, resultEnd
    call printString

    pop r12
    pop rbx
    ret

; ******************************************************************
;  Generic procedure to display a string to the screen.
;  String must be NULL terminated.

;  Algorithm:
;   Count characters in string (excluding NULL)
;   Use syscall to output characters

; -----
;  HLL Call:
;   printString(stringAddr);

;  Arguments:
;   1) address, string
;  Returns:
;   nothing

global  printString
printString:

; -----
;  Count characters to write.

    mov rdx, 0
strCountLoop:
    cmp byte [rdi+rdx], NULL
    je  strCountLoopDone
    inc rdx
    jmp strCountLoop
strCountLoopDone:
    cmp rdx, 0
    je  printStringDone

; -----
;  Call OS to output string.

    mov rax, SYS_write      ; system code for write()
    mov rsi, rdi            ; address of characters to write
    mov rdi, STDOUT         ; file descriptor for standard in
                            ; rdx=count to write, set above
    syscall                 ; system call

; -----
;  String printed, return to calling routine.

printStringDone:
    ret

; ******************************************************************


