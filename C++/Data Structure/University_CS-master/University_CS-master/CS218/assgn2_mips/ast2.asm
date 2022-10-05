###########################################################
#  data segment

.data

aSides: .word     233,   214,   273,   231,   255 
    .word     264,   273,   274,   223,   256 
    .word     244,   252,   231,   242,   256 
    .word     255,   224,   236,   275,   246 
    .word     253,   223,   253,   267,   235 
    .word     254,   229,   264,   267,   234 
    .word     256,   253,   264,   253,   265 
    .word     226,   252,   257,   267,   234 
    .word     217,   254,   217,   225,   253 
    .word     223,   273,   235,   261,   259 
    .word     225,   224,   263,   247,   223 
    .word     234,   234,   256,   264,   242 
    .word     236,   252,   232,   231,   246 
    .word     250,   254,   278,   288,   292 
    .word     282,   295,   247,   252,   257 
    .word     257,   267,   279,   288,   294 
    .word     234,   252,   274,   286,   297 
    .word     244,   276,   242,   236,   253 
    .word     232,   251,   236,   287,   290 
    .word     220,   241,   223,   232,   245 

cSides: .word     157,   187,   199,   111,   123 
    .word     124,   125,   126,   175,   194 
    .word     149,   126,   162,   131,   127 
    .word     177,   199,   197,   175,   114 
    .word     164,   141,   142,   173,   166 
    .word     104,   146,   123,   156,   163 
    .word     121,   118,   177,   143,   178 
    .word     112,   111,   110,   135,   110 
    .word     127,   144,   210,   172,   124 
    .word     125,   116,   162,   128,   192 
    .word     117,   114,   115,   172,   124 
    .word     125,   116,   162,   138,   192 
    .word     121,   183,   133,   130,   137 
    .word     142,   135,   158,   123,   135 
    .word     127,   126,   126,   127,   227 
    .word     177,   199,   177,   175,   114 
    .word     194,   124,   112,   143,   176 
    .word     134,   126,   132,   156,   163 
    .word     124,   119,   122,   183,   110 
    .word     191,   192,   129,   129,   122 

heights:
    .word     117,   114,   115,   172,   124
    .word     125,   116,   162,   138,   192
    .word     111,   183,   133,   130,   127
    .word     111,   115,   158,   113,   115
    .word     117,   126,   116,   117,   227
    .word     177,   199,   177,   175,   114
    .word     194,   124,   112,   143,   176
    .word     134,   126,   132,   156,   163
    .word     124,   119,   122,   183,   110
    .word     191,   192,   129,   129,   122
    .word     135,   226,   162,   137,   127
    .word     127,   159,   177,   175,   144
    .word     179,   153,   136,   140,   235
    .word     112,   154,   128,   113,   132
    .word     161,   192,   151,   213,   126
    .word     269,   114,   122,   115,   131
    .word     194,   124,   114,   143,   176
    .word     134,   126,   122,   156,   163
    .word     149,   144,   114,   134,   167
    .word     143,   129,   161,   165,   136

len:    .word   100 

tAreas:
        .space  400 

tMin:   .word   0 
tMid:   .word   0 
tMax:   .word   0 
tSum:   .word   0 
tAve:   .word   0 

LN_CNTR = 7

# -----

hdr:    .ascii  "MIPS Assignment #2 \n"
        .ascii  "  Trapezoid Areas Program:\n"
        .ascii  "  Also finds minimum, middle value, maximum, sum,"
        .asciiz " and average for the areas.\n\n"

a1_st:  .asciiz "\nTrapezoid Areas Minimum = "
a2_st:  .asciiz "\nTrapezoid Areas Middle  = "
a3_st:  .asciiz "\nTrapezoid Areas Maximum = "
a4_st:  .asciiz "\nTrapezoid Areas Sum     = "
a5_st:  .asciiz "\nTrapezoid Areas Average = "

newLn:  .asciiz "\n"
blnks:  .asciiz "  "


###########################################################
#  text/code segment

# --------------------
#  Compute trapezoid areas.
#  Then find middle, max, sum, and average for the areas.

.text
.globl main
.ent main
main:

# -----
#  Display header.

    la  $a0, hdr
    li  $v0, 4
    syscall             # print header

##########################################################

    lw $s0, len         # load length into s0
    la $s1, aSides      # load aSides into s1
    la $s2, cSides      # load cSides into s2
    la $s3, heights     # load heights into s3
    la $s4, tAreas      # load tAreas into s4
    move $s5, $zero     # max var
    move $s7, $zero     # sum var
    li $s6, 0x10000000  # min var
    li $a0, 2           # shortcut for 2
    calcLoop:
        lw $t1, ($s1)               # get aSides
        lw $t2, ($s2)               # get cSides
        add $t0, $t1, $t2           # t0 = aSides[n] + cSides[n]
        div $t0, $t0, $a0           # (aSides[n] + cSides[n]) / 2
        lw $t3, ($s3)               # get height
        mul $t0, $t0, $t3           # height * (aSides[n] + cSides[n]) / 2
        sw $t0, ($s4)               # set tAreas to value

        add $s7, $s7, $t0           # sum += area

        bge $t0, $s6, notSmaller
            move $s6, $t0           # move t0 into min as new minimum
        notSmaller:        
        ble $t0, $s5, notBigger
            move $s5, $t0           # move t0 into max as new maximum 
        notBigger:
         

        sub $s0, $s0, 1             # subtract 1 from len
        addu $s1, $s1, 4            # move data forward one element
        addu $s2, $s2, 4
        addu $s3, $s3, 4
        addu $s4, $s4, 4
        bnez $s0, calcLoop          # jump to calcLop if len is not zero

    sw $s6, tMin        # store min into min var
    sw $s5, tMax        # store max into max var
    sw $s7, tSum        # store sum into sum var

    lw $s6, len         # load length
    div $s7, $s7, $s6   # sum / len
    sw $s7, tAve        # store average into ave var

    rem $s6, $s6, $a0   # len = len mod 2
    bnez $s6, oddLen
        move $s5, $zero
        la $s1, tAreas
        lw $s6, len                 # load len
        div $s6, $s6, $a0           # len = len / 2
        mul $s6, $s6, 4             # mul s6 by 4 bytes
        add $s1, $s1, $s6           # move tAreas forward len / 2 times 
        lw $t1, ($s1)
        add $s5, $s5, $t1           # add tAreas[len / 2] into s5
        sub $s1, $s1, 4             # len / 2 - 1
        lw $t1, ($s1)
        add $s5, $s5, $t1           # add tAreas[len / 2 - 1] into s5
        div $s5, $s5, $a0           # s5 / 2
        sw $s5, tMid
        b doneMidPoint
    oddLen:
        la $s1, tAreas              # load address of tAreas
        lw $s6, len                 # load len
        div $s6, $s6, $s0           # len / 2
        mul $s6, $s6, 4             # mul by 4 bytes
        add $s1, $s1, $s6           # add to tAreas
        lw $t1, ($s1)
        sw $t1, tMid
    doneMidPoint:

##########################################################
#  Display results.

    la $s1, tAreas      # prepare to print array
    lw $s6, len
    printAreas:
        lw $t1, ($s1)
        move $a0, $s1
        li $v0, 1
        syscall
        
        la $a0, blnks
        li $v0, 4
        syscall

        sub $s6, $s6, 1             # subtract 1 from len
        addu $s1, $s1, 4            # incr data by one element
        bnez $s6, printAreas
#  Print min message followed by result.

    la  $a0, newLn
    li  $v0, 4
    syscall

    la  $a0, a1_st
    li  $v0, 4
    syscall             # print "min = "

    lw  $a0, tMin
    li  $v0, 1
    syscall             # print min

# -----
#  Print middle message followed by result.

    la  $a0, a2_st
    li  $v0, 4
    syscall             # print "med = "

    lw  $a0, tMid
    li  $v0, 1
    syscall             # print mid

# -----
#  Print max message followed by result.

    la  $a0, a3_st
    li  $v0, 4
    syscall             # print "max = "

    lw  $a0, tMax
    li  $v0, 1
    syscall             # print max

# -----
#  Print sum message followed by result.

    la  $a0, a4_st
    li  $v0, 4
    syscall             # print "sum = "

    lw  $a0, tSum
    li  $v0, 1
    syscall             # print sum

# -----
#  Print average message followed by result.

    la  $a0, a5_st
    li  $v0, 4
    syscall             # print "ave = "

    lw  $a0, tAve
    li  $v0, 1
    syscall             # print average

# -----
#  Done, terminate program.

endit:
    la  $a0, newLn      # print a newline
    li  $v0, 4
    syscall

    li  $v0, 10
    syscall             # all done!

.end main


