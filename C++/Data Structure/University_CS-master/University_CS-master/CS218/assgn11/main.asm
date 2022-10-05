;  Provided Main.

;  This program will open a text file, read the text information,
;  and count the number of occurrances of a user-specified word
;  in the file.

;  The word and input file name are read from the command line.

;  To ensure overall efficiency, the program performs buffered
;   I/O with a buffer size of BUFFSIZE.
;  The program performs basic error checking and issues
;   appropriate error messages.

; -----
;  The provided main calls four functions.

;  1) checkParameters()
;   Get command line arguments (word and file),
;   performs appropriate error checking, opens file,
;   and returns the file descriptor and word.  If any errors
;   in command line arguments, display appropriate error
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

; -------------------------------------------------------

section .data

; -----
;  Define standard constants.

TRUE        equ 1
FALSE       equ 0

LF      equ 10          ; line feed
NULL        equ 0           ; end of string

SUCCESS     equ 0           ; Successful operation
NOSUCCESS   equ 1           ; Unsuccessful operation

STDIN           equ 0       ; standard input
STDOUT      equ 1           ; standard output
STDERR      equ 2           ; standard error

SYS_read    equ 0           ; read
SYS_write   equ 1           ; write
SYS_open    equ 2           ; file open
SYS_close   equ 3           ; file clos
SYS_fork    equ 57          ; fork
SYS_exit    equ 60          ; terminate
SYS_creat   equ 85          ; file open/create
SYS_time    equ 201         ; get time

; -----
;  Define constants and variables for main.

MAXWORDLENGTH   equ 80

wordCount   dd  0
rdFileDesc  dd  0
matchCase   db  FALSE

; -------------------------------------------------------

section .bss

searchWord  resb    MAXWORDLENGTH+1
currentWord resb    MAXWORDLENGTH+1


; -------------------------------------------------------

section .text

extern  checkParameters
extern  getWord
extern  checkWord
extern  displayResults

extern printString


; --------------------------------------------
;  Main program

;  * Read & verify the command line qualifiers
;   - read word, verify > 0 length
;   - open the file to verify existance and access

;  * Main processing loop
;   - read word
;   - check for match
;   - repeat until end of file

;  * Wrap up
;   - close file
;   - display results (word and count)

global  main
main:

; -----
;  NOte, passed from OS
;   ARGC, # of arguments (rdi)
;   ARGV, ptr to argument table (rsi)

; -----
;  Get and verify command line information.
;   If arguments are not OK, end program.
;   If arguments are OK, returns word and file handle.

; HLL Call:
;   bool = checkParameters(ARGC, ARGV, searchWord, matchCase, rdFileDesc)

    mov rdx, searchWord
    mov rcx, matchCase
    mov r8, rdFileDesc
    call    checkParameters

    cmp eax, FALSE
    je  wordCountDone

; -----
;  * Main processing loop
;   - read a word
;   - check for match
;   - repeat until end of file

;  Note, all I/O buffering is done inside of the getWord routine.

; -----
;  HLL Call:
;   bool = getWord(currentWord, rdFileDesc)

getNextWord:
    mov rdi, currentWord
    mov rsi, 0
    mov esi, dword[rdFileDesc]
    call    getWord

    cmp eax, FALSE
    je  readDone

; -----
;  HLL Call:
;   call checkWord(searchWord, currentWord, matchCase, wordCount)

    mov rdi, searchWord
    mov rsi, currentWord
    mov rdx, 0
    mov dl, byte [matchCase]
    mov rcx, wordCount
    call    checkWord

    jmp getNextWord

; -----
;  Done, close file and display results.

;  HLL Call:
;   displayResults(searchWord, wordCount)

readDone:
    mov rax, SYS_close
    mov edi, dword [rdFileDesc]
    syscall

    mov rdi, searchWord
    mov esi, dword [wordCount]
    call    displayResults

; -----
;  Done, terminate program.

wordCountDone:
    mov rax, SYS_exit
    mov rdi, SUCCESS
    syscall

; -------------------------------------------------------


