#  MIPS Assignment #4

#  MIPS assembly language program to calculate
#  the Manhattan Distance between two grids.


###########################################################
#  data segment

.data

hdr:    .ascii  "\nMIPS Assignment #4\n"
    .asciiz "Program to Calculate Manhattan Distance.\n\n"

# -----
#  Game boards.

goalAMsg:   .asciiz "3x3 Goal Board #1"

boardAsize: .word   3
goalA:      .word   1, 2, 3
        .word   4, 5, 6
        .word   7, 8, 0

boardA0msg: .asciiz "3x3 Game Board 0"
boardA0:    .word   1, 2, 0
        .word   4, 5, 3
        .word   7, 8, 6

boardA1msg: .asciiz "3x3 Game Board 1"
boardA1:    .word   0, 1, 3
        .word   4, 2, 5
        .word   7, 8, 6

boardA2msg: .asciiz "3x3 Game Board 2"
boardA2:    .word   4, 1, 2
        .word   5, 8, 3
        .word   7, 0, 6

boardA3msg: .asciiz "3x3 Game Board 3"
boardA3:    .word   0, 5, 2
        .word   1, 8, 3
        .word   4, 7, 6

boardA4msg: .asciiz "3x3 Game Board 4"
boardA4:    .word   4, 1, 3
        .word   0, 2, 6
        .word   7, 5, 8

boardA5msg: .asciiz "3x3 Game Board 5"
boardA5:    .word   1, 2, 3
        .word   0, 7, 6
        .word   5, 4, 8

boardA6msg: .asciiz "3x3 Game Board 6"
boardA6:    .word   2, 3, 5
        .word   1, 0, 4
        .word   7, 8, 6 

boardA7msg: .asciiz "3x3 Game Board 7"
boardA7:    .word   1, 0, 2
        .word   7, 5, 4
        .word   8, 6, 3

boardA8msg: .asciiz "3x3 Game Board 8"
boardA8:    .word   8, 1, 3
        .word   4, 0, 2
        .word   7, 6, 5

boardA9msg: .asciiz "3x3 Game Board 9"
boardA9:    .word   3, 5, 6
        .word   1, 4, 0
        .word   0, 7, 2

boardA10msg:    .asciiz "3x3 Game Board 10"
boardA10:   .word   5, 6, 2
        .word   1, 8, 4
        .word   7, 3, 0

boardA11msg:    .asciiz "3x3 Game Board 11"
boardA11:   .word   2, 8, 5
        .word   0, 1, 7
        .word   4, 3, 6

boardA12msg:    .asciiz "3x3 Game Board 12"
boardA12:   .word   8, 0, 5
        .word   2, 1, 7
        .word   4, 3, 6

boardA13msg:    .asciiz "3x3 Game Board 13"
boardA13:   .word   1, 2, 7
        .word   0, 4, 3
        .word   6, 5, 8

boardA14msg:    .asciiz "3x3 Game Board 14"
boardA14:   .word   1, 6, 4
        .word   7, 0, 8
        .word   2, 3, 5

boardA15msg:    .asciiz "3x3 Game Board 15"
boardA15:   .word   5, 1, 3
        .word   4, 7, 0
        .word   8, 6, 1

boardA16msg:    .asciiz "3x3 Game Board 16"
boardA16:   .word   4, 8, 2
        .word   3, 6, 5
        .word   1, 7, 0

boardA17msg:    .asciiz "3x3 Game Board 17"
boardA17:   .word   2, 4, 5
        .word   0, 1, 7
        .word   3, 8, 6

boardA18msg:    .asciiz "3x3 Game Board 18"
boardA18:   .word   5, 0, 4
        .word   2, 3, 8
        .word   7, 1, 6

boardA19msg:    .asciiz "3x3 Game Board 19"
boardA19:   .word   5, 7, 4
        .word   3, 0, 8
        .word   1, 6, 2

boardA20msg:    .asciiz "3x3 Game Board 20"
boardA20:   .word   5, 8, 7
        .word   1, 4, 6
        .word   3, 0, 2

boardA21msg:    .asciiz "3x3 Game Board 21"
boardA21:   .word   0, 5, 7
        .word   2, 4, 1
        .word   3, 6, 8

boardA22msg:    .asciiz "3x3 Game Board 22"
boardA22:   .word   8, 7, 6
        .word   5, 4, 3
        .word   2, 1, 0

boardA23msg:    .asciiz "3x3 Game Board 23"
boardA23:   .word   1, 2, 3
        .word   4, 5, 6
        .word   8, 7, 9

boardA24msg:    .asciiz "3x3 Game Board 24"
boardA24:   .word   1, 2, 3
        .word   8, 0, 4
        .word   7, 6, 5

# -----

goalBMsg:   .asciiz "3x3 Goal Board #2"

boardBsize: .word   3
goalB:      .word   1, 2, 3
        .word   8, 0, 4
        .word   7, 6, 5

boardB0msg: .asciiz "3x3 Game Board 0"
boardB0:    .word   1, 2, 0
        .word   4, 5, 3
        .word   7, 8, 6

boardB1msg: .asciiz "3x3 Game Board 1"
boardB1:    .word   0, 1, 3
        .word   4, 2, 5
        .word   7, 8, 6

boardB2msg: .asciiz "3x3 Game Board 2"
boardB2:    .word   4, 1, 2
        .word   5, 8, 3
        .word   7, 0, 6

boardB3msg: .asciiz "3x3 Game Board 3"
boardB3:    .word   0, 5, 2
        .word   1, 8, 3
        .word   4, 7, 6

# -----

goalCMsg:   .asciiz "4x4 Goal Board #1"

boardCsize: .word   4
goalC:      .word    1,  2,  3,  4
        .word    5,  6,  7,  8
        .word    9, 10, 11, 12
        .word   13, 14, 15,  0

boardC0msg: .asciiz "4x4 Game Board 0"
boardC0:    .word    0,  1,  2,  3
        .word    5,  6,  7,  4
        .word    9, 10, 11,  8
        .word   13, 14, 15, 12

boardC1msg: .asciiz "4x4 Game Board 1"
boardC1:    .word    2, 12,  0,  3
        .word   13,  6, 14,  4
        .word    9, 10, 15,  8
        .word    5,  7, 11, 15

boardC2msg: .asciiz "4x4 Game Board 2"
boardC2:    .word    3,  6,  2,  0
        .word   13,  9,  8, 12
        .word   14, 10,  7, 15
        .word    5,  1, 11,  4

boardC3msg: .asciiz "4x4 Game Board 3"
boardC3:    .word    0, 15, 14, 13
        .word   12, 11, 10,  9
        .word    8,  7,  6,  5
        .word    4,  3,  2,  1

# -----

goalDMsg:   .asciiz "4x4 Goal Board #2"

boardDsize: .word   4
goalD:      .word   15, 14, 13, 12
        .word   11, 10,  9,  8
        .word    7,  6,  5,  4
        .word    3,  2,  1,  0

boardD0msg: .asciiz "4x4 Game Board 0"
boardD0:    .word    0,  1,  2,  3
        .word    5,  6,  7,  4
        .word    9, 10, 11,  8
        .word   13, 14, 15, 12

boardD1msg: .asciiz "4x4 Game Board 1"
boardD1:    .word    2, 12,  0,  3
        .word   13,  6, 14,  4
        .word    9, 10, 15,  8
        .word    5,  7, 11,  1

boardD2msg: .asciiz "4x4 Game Board 2"
boardD2:    .word    3,  6,  2,  0
        .word   13,  9,  8, 12
        .word   14, 10,  7, 15
        .word    5,  2, 11,  4

boardD3msg: .asciiz "4x4 Game Board 3"
boardD3:    .word    0, 15, 14, 13
        .word   12, 11, 10,  9
        .word    8,  7,  6,  5
        .word    4,  3,  2,  1

# -----

goalEMsg:   .asciiz "5x5 Goal Board #1"

boardEsize: .word   5
goalE:      .word    1,  2,  3,  4,  5
        .word    6,  7,  8,  9, 10
        .word   11, 12, 13, 14, 15
        .word   16, 17, 18, 19, 20
        .word   21, 22, 23, 24,  0

boardE0msg: .asciiz "5x5 Game Board 0"
boardE0:    .word    0,  1,  2,  3, 16
        .word    5,  6,  7,  4, 17
        .word    9, 10, 11,  8, 18
        .word   13, 14, 15, 12, 19
        .word   20, 24, 21, 23, 22

boardE1msg: .asciiz "5x5 Game Board 1"
boardE1:    .word    2, 16, 12,  0,  3
        .word   20,  9, 22, 15,  1
        .word   13,  6, 14, 17,  4
        .word   18, 21, 10, 23,  8
        .word    5,  7, 19, 11, 24

boardE2msg: .asciiz "5x5 Game Board 2"
boardE2:    .word   20,  3,  6,  2,  0
        .word   24,  5,  9, 21, 22
        .word   13, 19, 22,  8, 12
        .word   14, 23, 10,  7, 15
        .word   21, 19,  1, 11,  4

boardE3msg: .asciiz "5x5 Game Board 3"
boardE3:    .word    0, 15, 14, 13, 16
        .word   12, 19, 10,  9,  3
        .word   18, 11,  7,  5,  2
        .word    8, 20,  6, 21, 24
        .word    4, 23, 22,  1, 17

boardE4msg: .asciiz "5x5 Game Board 1"
boardE4:    .word    2, 16, 12,  0,  3
        .word   20,  9, 22, 15,  1
        .word   13,  6, 14, 17,  4
        .word   18, 20, 10, 23,  8
        .word    5,  7, 19, 11, 24

# -----

goalFMsg:   .asciiz "6x6 Goal Board #1"

boardFsize: .word   6
goalF:      .word    1,  2,  3,  4,  5, 6
        .word    7,  8,  9, 10, 11, 12
        .word   13, 14, 15, 16, 17, 18
        .word   19, 20, 21, 22, 23, 24
        .word   25, 26, 27, 28, 29, 30
        .word   31, 32, 33, 34, 35,  0

boardF0msg: .asciiz "6x6 Game Board 0"
boardF0:    .word    0,  1,  2,  3,  4, 28
        .word    5,  6,  7, 34, 17, 27
        .word    9, 10, 32,  8, 18, 25
        .word   29, 31, 11, 33, 16, 20
        .word   13, 14, 15, 12, 19, 30
        .word   35, 24, 21, 23, 26, 22

boardF1msg: .asciiz "6x6 Game Board 1"
boardF1:    .word    2, 16, 27, 12,  0, 34
        .word   18, 28, 21, 10, 23,  8
        .word   20, 31, 22, 35, 29,  1
        .word   13, 26,  6, 14, 17,  4
        .word   30,  9, 32,  7,  3, 15
        .word   25,  5, 33, 19, 11, 24

boardF2msg: .asciiz "6x6 Game Board 2"
boardF2:    .word   20,  3,  6,  2,  0, 25
        .word    1, 31, 14, 33, 34,  1
        .word   24, 29,  5,  9, 21, 22
        .word   26, 13, 19, 22,  8, 12
        .word   32, 23, 10, 28,  7, 15
        .word   27, 21, 19, 30, 11,  4

# -----
#  Local variables for displayBoard() function.

brdSection: .asciiz "************************************\n"
brdHdr:     .asciiz "------------------------------------\n"
newLine:    .asciiz "\n"
bar:        .asciiz " | "
blnk:       .asciiz " "
dashes:     .asciiz " ----"

# -----
#  Local variables for makeCalls() function.

badBoardMsg:    .asciiz "Error, invalid board."

# -----
#  Local variables for manhattanDistance() function.

MDmsg:      .asciiz "Manhattan Distance: "

# -----
#  Local variables for validateBoard() function.

TRUE = 1
FALSE = 0

.align 4
tstArr:     .space      400


###########################################################
#  text/code segment

.text

.globl main
.ent main
main:

# -----
#  Display main program header.

    la  $a0, hdr
    li  $v0, 4
    syscall                 # print header

# -----
#  Display goal board
#  Display game boards and distances

    la  $a0, brdSection
    li  $v0, 4
    syscall                 # print header

    la  $a0, goalA
    lw  $a1, boardAsize
    la  $a2, goalAMsg
    jal displayBoard

    la  $a0, goalA
    la  $a1, boardA0
    lw  $a2, boardAsize
    la  $a3, boardA0msg
    jal makeCalls

    la  $a0, goalA
    la  $a1, boardA1
    lw  $a2, boardAsize
    la  $a3, boardA1msg
    jal makeCalls

    la  $a0, goalA
    la  $a1, boardA2
    lw  $a2, boardAsize
    la  $a3, boardA2msg
    jal makeCalls

    la  $a0, goalA
    la  $a1, boardA3
    lw  $a2, boardAsize
    la  $a3, boardA3msg
    jal makeCalls

    la  $a0, goalA
    la  $a1, boardA4
    lw  $a2, boardAsize
    la  $a3, boardA4msg
    jal makeCalls

    la  $a0, goalA
    la  $a1, boardA5
    lw  $a2, boardAsize
    la  $a3, boardA5msg
    jal makeCalls

    la  $a0, goalA
    la  $a1, boardA6
    lw  $a2, boardAsize
    la  $a3, boardA6msg
    jal makeCalls

    la  $a0, goalA
    la  $a1, boardA7
    lw  $a2, boardAsize
    la  $a3, boardA7msg
    jal makeCalls

    la  $a0, goalA
    la  $a1, boardA8
    lw  $a2, boardAsize
    la  $a3, boardA8msg
    jal makeCalls

    la  $a0, goalA
    la  $a1, boardA9
    lw  $a2, boardAsize
    la  $a3, boardA9msg
    jal makeCalls

    la  $a0, goalA
    la  $a1, boardA10
    lw  $a2, boardAsize
    la  $a3, boardA10msg
    jal makeCalls

    la  $a0, goalA
    la  $a1, boardA11
    lw  $a2, boardAsize
    la  $a3, boardA11msg
    jal makeCalls

    la  $a0, goalA
    la  $a1, boardA12
    lw  $a2, boardAsize
    la  $a3, boardA12msg
    jal makeCalls

    la  $a0, goalA
    la  $a1, boardA13
    lw  $a2, boardAsize
    la  $a3, boardA13msg
    jal makeCalls

    la  $a0, goalA
    la  $a1, boardA14
    lw  $a2, boardAsize
    la  $a3, boardA14msg
    jal makeCalls

    la  $a0, goalA
    la  $a1, boardA15
    lw  $a2, boardAsize
    la  $a3, boardA15msg
    jal makeCalls

    la  $a0, goalA
    la  $a1, boardA16
    lw  $a2, boardAsize
    la  $a3, boardA16msg
    jal makeCalls

    la  $a0, goalA
    la  $a1, boardA17
    lw  $a2, boardAsize
    la  $a3, boardA17msg
    jal makeCalls

    la  $a0, goalA
    la  $a1, boardA18
    lw  $a2, boardAsize
    la  $a3, boardA18msg
    jal makeCalls

    la  $a0, goalA
    la  $a1, boardA19
    lw  $a2, boardAsize
    la  $a3, boardA19msg
    jal makeCalls

    la  $a0, goalA
    la  $a1, boardA20
    lw  $a2, boardAsize
    la  $a3, boardA20msg
    jal makeCalls

    la  $a0, goalA
    la  $a1, boardA21
    lw  $a2, boardAsize
    la  $a3, boardA21msg
    jal makeCalls

    la  $a0, goalA
    la  $a1, boardA22
    lw  $a2, boardAsize
    la  $a3, boardA22msg
    jal makeCalls

    la  $a0, goalA
    la  $a1, boardA23
    lw  $a2, boardAsize
    la  $a3, boardA23msg
    jal makeCalls

    la  $a0, goalA
    la  $a1, boardA24
    lw  $a2, boardAsize
    la  $a3, boardA24msg
    jal makeCalls

# -----
#  Display goal board
#  Display game boards and distances

    la  $a0, brdSection
    li  $v0, 4
    syscall                 # print header

    la  $a0, goalB
    lw  $a1, boardBsize
    la  $a2, goalBMsg
    jal displayBoard

    la  $a0, goalB
    la  $a1, boardB0
    lw  $a2, boardBsize
    la  $a3, boardB0msg
    jal makeCalls

    la  $a0, goalB
    la  $a1, boardB1
    lw  $a2, boardBsize
    la  $a3, boardB1msg
    jal makeCalls

    la  $a0, goalB
    la  $a1, boardB2
    lw  $a2, boardBsize
    la  $a3, boardB2msg
    jal makeCalls

    la  $a0, goalB
    la  $a1, boardB3
    lw  $a2, boardBsize
    la  $a3, boardB3msg
    jal makeCalls

# -----
#  Display goal board
#  Display game boards and distances

    la  $a0, brdSection
    li  $v0, 4
    syscall                 # print header

    la  $a0, goalC
    lw  $a1, boardCsize
    la  $a2, goalCMsg
    jal displayBoard

    la  $a0, goalC
    la  $a1, boardC0
    lw  $a2, boardCsize
    la  $a3, boardC0msg
    jal makeCalls

    la  $a0, goalC
    la  $a1, boardC1
    lw  $a2, boardCsize
    la  $a3, boardC1msg
    jal makeCalls

    la  $a0, goalC
    la  $a1, boardC2
    lw  $a2, boardCsize
    la  $a3, boardC2msg
    jal makeCalls

    la  $a0, goalC
    la  $a1, boardC3
    lw  $a2, boardCsize
    la  $a3, boardC3msg
    jal makeCalls

# -----
#  Display goal board
#  Display game boards and distances

    la  $a0, brdSection
    li  $v0, 4
    syscall                 # print header

    la  $a0, goalD
    lw  $a1, boardDsize
    la  $a2, goalDMsg
    jal displayBoard

    la  $a0, goalD
    la  $a1, boardD0
    lw  $a2, boardDsize
    la  $a3, boardD0msg
    jal makeCalls

    la  $a0, goalD
    la  $a1, boardD1
    lw  $a2, boardDsize
    la  $a3, boardD1msg
    jal makeCalls

    la  $a0, goalD
    la  $a1, boardD2
    lw  $a2, boardDsize
    la  $a3, boardD2msg
    jal makeCalls

    la  $a0, goalD
    la  $a1, boardD3
    lw  $a2, boardDsize
    la  $a3, boardD3msg
    jal makeCalls

# -----
#  Display goal board
#  Display game boards and distances

    la  $a0, brdSection
    li  $v0, 4
    syscall                 # print header

    la  $a0, goalE
    lw  $a1, boardEsize
    la  $a2, goalEMsg
    jal displayBoard

    la  $a0, goalE
    la  $a1, boardE0
    lw  $a2, boardEsize
    la  $a3, boardE0msg
    jal makeCalls

    la  $a0, goalE
    la  $a1, boardE1
    lw  $a2, boardEsize
    la  $a3, boardE1msg
    jal makeCalls

    la  $a0, goalE
    la  $a1, boardE2
    lw  $a2, boardEsize
    la  $a3, boardE2msg
    jal makeCalls

    la  $a0, goalE
    la  $a1, boardE3
    lw  $a2, boardEsize
    la  $a3, boardE3msg
    jal makeCalls

    la  $a0, goalE
    la  $a1, boardE4
    lw  $a2, boardEsize
    la  $a3, boardE4msg
    jal makeCalls

# -----
#  Display goal board
#  Display game boards and distances

    la  $a0, brdSection
    li  $v0, 4
    syscall                 # print header

    la  $a0, goalF
    lw  $a1, boardFsize
    la  $a2, goalFMsg
    jal displayBoard

    la  $a0, goalF
    la  $a1, boardF0
    lw  $a2, boardFsize
    la  $a3, boardF0msg
    jal makeCalls

    la  $a0, goalF
    la  $a1, boardF1
    lw  $a2, boardFsize
    la  $a3, boardF1msg
    jal makeCalls

    la  $a0, goalF
    la  $a1, boardF2
    lw  $a2, boardFsize
    la  $a3, boardF2msg
    jal makeCalls

# -----
#  Done, terminate program.

    li  $v0, 10
    syscall
.end main

######################################################################
#  Procedure to make calls...

# -----
#  Arguments
#   $a0 - goal board address
#   $a1 - board address
#   $a2 - board order
#   $a3 - board title message

.globl  makeCalls
.ent    makeCalls
makeCalls:
    subu    $sp, $sp, 28            #  Save registers.
    sw  $s0, ($sp)
    sw  $s1, 4($sp)
    sw  $s2, 8($sp)
    sw  $s4, 12($sp)
    sw  $s5, 16($sp)
    sw  $s6, 20($sp)
    sw  $ra, 24($sp)

    move    $s0, $a0
    move    $s1, $a1
    move    $s2, $a2
    move    $s3, $a3

    move    $a0, $s1
    move    $a1, $s2
    move    $a2, $s3
    jal displayBoard

    move    $a0, $s1
    move    $a1, $s2
    jal validateBoard

    beq $v0, TRUE, showDist

    li  $v0, 4
    la  $a0, badBoardMsg
    syscall

    li  $v0, 4
    la  $a0, newLine
    syscall
    li  $v0, 4
    la  $a0, newLine
    syscall

    j   makeCallsDone

showDist:
    move    $a0, $s0
    move    $a1, $s1
    move    $a2, $s2
    jal manhattanDistance

makeCallsDone:
    lw  $s0, ($sp)
    lw  $s1, 4($sp)
    lw  $s2, 8($sp)
    lw  $s4, 12($sp)
    lw  $s5, 16($sp)
    lw  $s6, 20($sp)
    lw  $ra, 24($sp)
    add $sp, $sp, 28

    jr  $ra
.end    makeCalls

######################################################################
#  Function to print a formatted game board.

# -----
#  Formula for multiple dimension array indexing:
#   addr(r,c) = baseAddr + (r * colSize + c) * dataSize

# -----
#  Arguments:
#   $a0 - board address
#   $a1 - order (size) of the board
#   $a2 - title address

.globl  displayBoard
.ent    displayBoard
displayBoard:

    subu $sp, $sp, 28
    sw $s0, ($sp)
    sw $s1, 4($sp)
    sw $s2, 8($sp)
    sw $s3, 12($sp)
    sw $s4, 16($sp)
    sw $s5, 20($sp)
    sw $ra, 24($sp)

    move $s0, $a0   # board address
    move $s1, $a1   # size of board
    move $s2, $a2   # title address

    la $a0, brdHdr  # print message header
    li $v0, 4
    syscall    

    move $a0, $a2   # print title
    li $v0, 4
    syscall

    la $a0, newLine # new line
    li $v0, 4
    syscall

    la $a0, blnk    # space for top boarder
    li $v0, 4
    syscall

    move $s3, $s1   # get copy of size of board
    topBorder:
        la $a0, dashes      # print dashes
        li $v0, 4
        syscall

        sub $s3, $s3, 1
        bnez $s3, topBorder

    la $a0 newLine  # next row
    li $v0, 4
    syscall

    move $s4, $s1   # s4 counts down from data size to zero as rows
    printDataRow:
        move $s3, $s1       # s3 counts down from data size to zero as cols
        printDataCol:
            la $a0, bar         # print first bar
            li $v0, 4
            syscall
   
                                # note we are counting DOWN from the size so,
            sub $t4, $s4, $s1   # theoretically we are at row | ROW - sz |
            abs $t4, $t4    

            sub $t3, $s3,$s1    # theoretically we are at col | COL - sz |
            abs $t3, $t3
 
            move $s5, $s0       # get board address
            mul $t1, $t4, $s1   # r * colSize
            add $t1, $t1, $t3   # r * colSize + c
            mul $t1, $t1, 4     # multiply by data size

            add $s5, $s5, $t1   # get address to location of element
            lw $s5, ($s5)

            div $t1, $s5, 10    # check if double digit
            bnez $t1, skipSpace # if not double digit add extra space
                la $a0, blnk
                li $v0, 4
                syscall
            skipSpace:

            move $a0, $s5       # print num
            li $v0, 1
            syscall            
            
            sub $s3, $s3, 1     # decrement col count
            bnez $s3, printDataCol
        la $a0, bar         # print last bar on row
        li $v0, 4
        syscall        

        la $a0, newLine     # end line and move to next row
        li $v0, 4
        syscall

        sub $s4, $s4, 1     # decrement row count
        bnez $s4, printDataRow

    la $a0, blnk    # add extra space for bottom row dashes
    li $v0, 4
    syscall

    move $s3, $s1   # get copy of size of board
    bottomBorder:
        la $a0, dashes      # print dashes for bottom row
        li $v0, 4
        syscall

        sub $s3, $s3, 1
        bnez $s3, bottomBorder


    la $a0, newLine # end function with newline 
    li $v0, 4
    syscall

    la $a0, newLine 
    li $v0, 4
    syscall

    lw $s0, ($sp)
    lw $s1, 4($sp)
    lw $s2, 8($sp)
    lw $s3, 12($sp)
    lw $s4, 16($sp)
    lw $s5, 20($sp)
    lw $ra, 24($sp)
    add $sp, $sp, 28
    jr $ra

.end displayBoard

######################################################################
#  Function to compute the manhattan distance
#  between two game boards.

# -----
#  Formula for multiple dimension array indexing:
#   addr(r,c) = baseAddr + (r * colSize + c) * dataSize

# -----
#    Arguments:
#   $a0 - goal board address
#   $a1 - board address
#   $a2 - order (size) of the board

#    Returns:
#   manhattan distance, $v0

.globl  manhattanDistance
.ent    manhattanDistance
manhattanDistance:

    subu $sp, $sp, 20
    sw $s0, ($sp)       # x_1
    sw $s1, 4($sp)      # y_1
    sw $s2, 8($sp)      # x_2
    sw $s3, 12($sp)     # y_2
    sw $ra, 16($sp)

    move $v0, $zero
    li $t0, 1           # start loop at 1
    mul $t5, $a2, $a2   # order_size^2
    sub $t5, $t5, 1     # order_size^2 - 1
    _loopNumbers:

        move $t1, $zero             # rows
        loopGoalRows:
            move $t2, $zero             # cols
            loopGoalCols:

                move $t3, $a0               # get address of goal
                mul $t4, $t1, $a2           # r * order_size
                add $t4, $t4, $t2           # r * order_size + c
                mul $t4, $t4, 4             # mult by data size
            
                add $t3, $t3, $t4           # add to address    
                lw $t3, ($t3)               # goal_board[r][c]
    
                bne $t3, $t0, skip          # check if value matches one were looking for
                move $s0, $t1               # set row of correct value
                move $s1, $t2               # set col of correct value
                skip:
    
                add $t2, $t2, 1             # cols++
                bne $t2, $a2, loopGoalCols  # loop while cols < col_size
       
            add $t1, $t1, 1             # rows++
            bne $t1, $a2, loopGoalRows  # loop while rows < row_size

        move $t1, $zero             # rows
        loopRows:
            move $t2, $zero             # cols
            loopCols:
                
                move $t3, $a1               # get address of goal
                mul $t4, $t1, $a2           # r * order_size
                add $t4, $t4, $t2           # r * order_size + c
                mul $t4, $t4, 4             # mult by data size
            
                add $t3, $t3, $t4           # add to address    
                lw $t3, ($t3)               # goal_board[r][c]
    
                bne $t3, $t0, _skip          # check if value matches one were looking for
                move $s2, $t1               # set row of correct value
                move $s3, $t2               # set col of correct value
                _skip:

                add $t2, $t2, 1             # cols++
                bne $t2, $a2, loopCols      # loop while cols < col_size
        
            add $t1, $t1, 1             # rows++
            bne $t1, $a2, loopRows      # loop while rows < row_size

        sub $t4, $s0, $s2           # x_1 - x_0
        abs $t4, $t4                # | x_1 - x_0 |
        
        sub $t3, $s1, $s3           # y_1 - y_0
        abs $t3, $t3                # | y_1 - y_0 |

        add $t4, $t4, $t3           # | x_1 - x_0 | + | y_1 - y_0 |
        add $v0, $v0, $t4           # add to running sum

        add $t0, $t0, 1             # increment num
        bne $t0, $t5, _loopNumbers 

    move $s1, $v0   # save sum

    la $a0, MDmsg
    li $v0, 4
    syscall

    move $a0, $s1
    li $v0, 1
    syscall

    la $a0, newLine
    li $v0, 4
    syscall

    la $a0, newLine
    li $v0, 4
    syscall

    lw $s0, ($sp)
    lw $s1, 4($sp)
    lw $s2, 8($sp)
    lw $s3, 12($sp)
    lw $ra, 16($sp)
    add $sp, $sp, 20
    jr $ra

.end    manhattanDistance

######################################################################
#  Validate board
#   Must have numbers 1 to (order^2)-1
#   Each must appear only once.

#  Arguments:
#   $a0 - board address
#   $a1 - board order

#  Returns:
#   $v0 TRUE or FALSE

.globl  validateBoard
.ent    validateBoard
validateBoard:

    move $t0, $zero         # counter for checking board
    mul $t1, $a1, $a1       # boardOrder^2
    sub $t1, $t1, 1         # boardOrder^2 - 1
    loopNumbers:
        move $t3, $zero         # rows
        move $a3, $zero         # number count
        loopBoardRows:
            move $t4, $zero         # cols
            loopBoardCols:
            
            move $t5, $a0               # get board address
            mul $t6, $t3, $a1           # rows * colSize
            add $t6, $t6, $t4           # rows * colsSize + cols
            mul $t6, $t6, 4             # multiply by data size
            
            add $t5, $t5, $t6           # move list to board location
            lw $t5, ($t5)               # board[r][c]
 
            bne $t5, $t0, noEq          # check if board contains this number
            add $a3, $a3, 1             # increment count
            noEq:
    
            add $t4, $t4, 1             # cols = cols + 1
            bne $t4, $a1, loopBoardCols # loop while cols < order

        add $t3, $t3, 1             # rows = rows + 1
        bne $t3, $a1, loopBoardRows # loop while rows < order

        beq $a3, $zero, inValid # if no number found, invalid

        add $t0, $t0, 1         # increment number to look for
        bne $t0, $t1, loopNumbers

    li $v0, 1               # if function finishes set to true
    b valid                 # skip returning false 
    inValid:
        li $v0, 0
    valid:
    jr $ra

.end validateBoard

######################################################################


