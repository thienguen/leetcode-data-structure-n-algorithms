#  Program to find the:
#   min, max, and average of a list of numbers.
#   min, max, and average of the positive values.
#   min, max, and average of the values divisible by 4.

###########################################################
#  data segment

.data

array:  .word    124,  193,  982, -339,  564, -631,  421, -148,  936, -157
        .word   -117,  171, -697,  161, -147,  137, -327,  151, -147,  354
        .word    432, -551,  176, -487,  490, -810,  111, -523,  532, -445
        .word   -163,  745, -571,  529, -218,  219, -122,  934, -370,  121
        .word    315, -145,  313, -174,  118, -259,  672, -126,  230, -135
        .word   -199,  104, -106,  107, -124,  625, -126,  229, -248,  992
        .word    132, -133,  936,  136,  338, -941,  843, -645,  447, -449
        .word   -171,  271, -477, -228,  178,  184, -586,  186, -388,  188
        .word    950, -852,  754,  256, -658, -760,  161, -562,  263, -764
        .word   -199,  213, -124, -366,  740,  356, -375,  387, -115,  426
len:    .word   100

min:    .word   0
max:    .word   0
ave:    .word   0

pMin:   .word   0
pMax:   .word   0
pAve:   .word   0

d4Min:  .word   0
d4Max:  .word   0
d4Ave:  .word   0

hdr:    .ascii  "MIPS Assignment #1\n\n"
        .ascii  "Program to find: \n"
        .ascii  "   * min, max, and average for a list of numbers.\n"
        .ascii  "   * min, max, and average of the positive values.\n"
        .ascii  "   * min, max, and average of the values divisible by 4."
new_ln: .asciiz "\n"

a1_st:  .asciiz "\n    List min = "
a2_st:  .asciiz "\n    List max = "
a3_st:  .asciiz "\n    List ave = "

a4_st:  .asciiz "\n\n    Positive min = "
a5_st:  .asciiz "\n    Positive max = "
a6_st:  .asciiz "\n    Positive ave = "

a7_st:  .asciiz "\n\n    Divisible by 4 min = "
a8_st:  .asciiz "\n    Divisible by 4 max = "
a9_st:  .asciiz "\n    Divisible by 4 ave = "


###########################################################
#  text/code segment

.text
.globl  main
.ent    main
main:

# -----
#  Display header.

    la  $a0, hdr
    li  $v0, 4
    syscall

# ********************

    lw $s0, len     # load length into s0 
    la $s1, array   # load address into s1 
    li $s2, 0       # register to find sum of array
    lw $t0, array   # register to find min of array
    move $t1, $t0   # register to find max of array
    
    move $s4, $zero # set pos num count to zero
    move $s5, $zero # set div by 4 count to zero 

    sw $t0, pMin    # set pos min to first element
    sw $t0, pMax    # set pos max to first element
    sw $t0, d4Min   # set d4 min to first element
    sw $t0, d4Max   # set d4 max to first element

    calcLoop:
        lw $t2, ($s1)               # get number from array
        add $s2, $s2, $t2           # s2 += t2
        
        bge $t2, $t0, notSmaller    # skip if t2 is bigger than min
            move $t0, $t2               # new min        
        notSmaller:
        ble $t2, $t1, notBigger     # skip if t2 is smaller than max
            move $t1, $t2               # new max
        notBigger:
        bltz $t2, notPositive       # skip if t2 is negative
            lw $t3, pMin                # load pMin into t3
            bge $t2, $t3, pNotSmaller   # skip if not less than t2
                move $t3, $t2           # set new min
                sw $t3, pMin            # store back into pMin
            pNotSmaller:
            lw $t3, pMax                # load pMax into t3
            ble $t2, $t3, pNotBigger    # skip if not bigger than t2
                move $t3, $t2           # set new max
                sw $t3, pMax            # store back into pMax
            pNotBigger:
            lw $t3, pAve                # load sum into t3
            add $t3, $t3, $t2           # t3 += t2
            sw $t3, pAve                # store back into pAve
            addu $s4, $s4, 1
        notPositive: 
        rem $t5, $t2, 4             # find remainder of t2 / 4
        bnez $t5, notDivBy4         # if not zero not divisible by 4
            lw $t3, d4Min               # load d4Min into t3
            bge $t2, $t3, d4NotSmaller  # skip if not less than t2
                move $t3, $t2           # set new min
                sw $t3, d4Min           # store back into d4Min
            d4NotSmaller:
            lw $t3, d4Max               # load d4Max into t3
            ble $t2, $t3, d4NotBigger   # skip if not bigger than t2
                move $t3, $t2           # set new max
                sw $t3, d4Max           # store back into d4Max
            d4NotBigger:
            lw $t3, d4Ave               # load sum into t3
            add $t3, $t3, $t2           # t3 += t2
            sw $t3, d4Ave               # store back into d4Ave
            addu $s5, $s5, 1
        notDivBy4:
        sub $s0, $s0, 1             # subtract 1 from len
        addu $s1, $s1, 4            # move forward one element in array
        bnez $s0, calcLoop          # jump to calcLoop if len is not zero

    lw $s0, len                     # load length back into s0
    div $s3, $s2, $s0               # s3 = s2 / s0
    sw $s3, ave                     # store result into ave
    sw $t0, min                     # store min
    sw $t1, max                     # store max
    
    lw $s2, pAve                    # load pAve into s2
    div $s3, $s2, $s4               # s3 = s2 / s4
    sw $s3, pAve                    # store pAve

    lw $s2, d4Ave                   # load d4Ave into s2
    div $s3, $s2, $s5               # s3 = s2 / s5
    sw $s3, d4Ave                   # store d4Ave

# ********************
#  Display results.

#  Print list min message followed by result.

    la  $a0, a1_st
    li  $v0, 4
    syscall                     # print "List min = "

    lw  $a0, min
    li  $v0, 1
    syscall                     # print list min

#  Print max message followed by result.

    la  $a0, a2_st
    li  $v0, 4
    syscall                     # print "List max = "

    lw  $a0, max
    li  $v0, 1
    syscall                     # print max

#  Print average message followed by result.

    la  $a0, a3_st
    li  $v0, 4
    syscall                     # print "List ave = "

    lw  $a0, ave
    li  $v0, 1
    syscall                     # print average

# -----
#  Display results - positive numbers.

#  Print min message followed by result.

    la  $a0, a4_st
    li  $v0, 4
    syscall                     # print "Positive min = "

    lw  $a0, pMin
    li  $v0, 1
    syscall                     # print pos min

#  Print max message followed by result.

    la  $a0, a5_st
    li  $v0, 4
    syscall                     # print "Positive max = "

    lw  $a0, pMax
    li  $v0, 1
    syscall                     # print pos max

#  Print average message followed by result.

    la  $a0, a6_st
    li  $v0, 4
    syscall                     # print "Psoitive ave = "

    lw  $a0, pAve
    li  $v0, 1
    syscall                     # print odd average

# -----
#  Display results - divisible by 4 numbers.

#  Print min message followed by result.

    la  $a0, a7_st
    li  $v0, 4
    syscall                     # print "Positive min = "

    lw  $a0, d4Min
    li  $v0, 1
    syscall                     # print pos min

#  Print max message followed by result.

    la  $a0, a8_st
    li  $v0, 4
    syscall                     # print "Positive max = "

    lw  $a0, d4Max
    li  $v0, 1
    syscall                     # print pos max

#  Print average message followed by result.

    la  $a0, a9_st
    li  $v0, 4
    syscall                     # print "Psoitive ave = "

    lw  $a0, d4Ave
    li  $v0, 1
    syscall                     # print odd average

    la  $a0, new_ln             # print a newline
    li  $v0, 4
    syscall


# -----
#  Done, terminate program.

    li  $v0, 10
    syscall                     # all done!

.end main


