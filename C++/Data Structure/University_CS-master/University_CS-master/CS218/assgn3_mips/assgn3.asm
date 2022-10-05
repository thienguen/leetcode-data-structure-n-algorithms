#  MIPS assembly language main program and procedures:

#  * MIPS assembly language function, prtHeaders() to 
#    display some headers as per assignment format example.

#  * MIPS assembly language function, calcDiagonals(), 
#    to calculate the diagonal for each trapezoid in a
#    series of trapezoids
#    NOTE: this function must call the shellSort() function.

#  * MIPS assembly language function, shellSort(), to sort
#    the diagonals array (small to large).

#  * MIPS assembly language function, diagonalsStats(),
#    that will find the minimum, maximum, median, and
#    average (float) of the diagonals array.

#  * MIPS assembly language function, displayStats(), to
#    display the cSides[] array statistical information:
#    minimum, maximum, median, and average (float)
#    in the format shown in the example.  The numbers should be
#    printed seven (7) per line (see example).


#####################################################################
#  data segment

.data

# -----
#  Data declarations for main.

aSides1:    .word    34,  32,  31,  35,  34,  33,  32,  37,  38,  39
        .word    32,  30,  36,  38,  30
bSides1:    .word    44,  42,  41,  45,  44,  43,  42,  47,  48,  49
        .word    42,  40,  46,  48,  40
cSides1:    .word   119, 117, 115, 113, 111, 119, 117, 115, 113, 111
        .word   112, 114, 116, 118, 110
dSides1:    .word   129, 127, 125, 123, 121, 129, 127, 125, 123, 121
        .word   122, 124, 126, 128, 120
diags1:     .space  60
len1:       .word   15
min1:       .word   0
med1:       .word   0
max1:       .word   0
fAve1:      .float  0.0

aSides2:    .word    42,  71,  76,  57,  45,  50,  41,  53,  42,  45
        .word    44,  52,  44,  76,  57,  44,  46,  40,  46,  53
        .word    52,  53,  42,  69,  44,  51,  61,  78,  46,  47
        .word    53,  45,  51,  69,  48,  59,  62,  74,  50,  51
        .word    40,  44,  46,  57,  54,  55,  46,  49,  48,  52
        .word    41,  43,  44,  56,  50,  56,  75,  57,  50,  56
        .word    42,  55,  57,  42,  47,  47,  67,  79,  48,  44
        .word    50,  41,  43,  42,  45
bSides2:    .word    52,  81,  86,  67,  55,  60,  51,  63,  52,  55
        .word    54,  62,  54,  86,  67,  54,  56,  50,  56,  63
        .word    62,  63,  52,  79,  54,  61,  71,  88,  56,  57
        .word    63,  55,  61,  79,  58,  69,  72,  84,  60,  61
        .word    50,  54,  56,  67,  64,  65,  56,  59,  58,  62
        .word    51,  53,  54,  66,  60,  66,  85,  67,  60,  66
        .word    52,  75,  77,  62,  57,  57,  77,  89,  58,  54
        .word    60,  51,  53,  52,  55
cSides2:    .word   145, 155, 143, 154, 168, 159, 142, 156, 149, 141
        .word   147, 141, 157, 141, 157, 147, 147, 151, 151, 149
        .word   142, 149, 145, 149, 143, 145, 141, 142, 144, 149
        .word   146, 142, 142, 141, 146, 150, 154, 148, 158, 152
        .word   157, 147, 159, 144, 143, 144, 145, 146, 145, 144
        .word   151, 153, 146, 159, 151, 142, 150, 158, 141, 149
        .word   159, 144, 147, 149, 152, 154, 146, 148, 152, 153
        .word   142, 151, 156, 157, 146
dSides2:    .word   155, 165, 153, 164, 178, 169, 152, 166, 159, 151
        .word   157, 151, 167, 151, 167, 157, 157, 161, 161, 159
        .word   152, 159, 155, 159, 153, 155, 151, 152, 154, 159
        .word   156, 152, 152, 151, 156, 160, 164, 158, 168, 162
        .word   167, 157, 169, 154, 153, 154, 155, 156, 155, 154
        .word   161, 163, 156, 169, 161, 152, 160, 168, 151, 159
        .word   169, 164, 167, 169, 162, 164, 156, 168, 162, 163
        .word   152, 161, 166, 167, 156
diags2:     .space  300
len2:       .word   75
min2:       .word   0
med2:       .word   0
max2:       .word   0
fAve2:      .float  0.0

aSides3:    .word    71,  48,  55,  43,  52,  40,  58,  71,  54,  52
        .word    35,  62,  76,  52,  53,  59,  56,  42,  58,  41
        .word    72,  45,  46,  47,  45,  34,  46,  30,  56,  53
        .word    53,  42,  31,  31,  51,  34,  42,  46,  58,  53
        .word    52,  59,  45,  39,  51,  45,  39,  42,  44,  49
        .word    50,  44,  46,  77,  54,  25,  26,  29,  48,  62
        .word    41,  43,  46,  49,  51,  52,  54,  58,  41,  65
        .word    69,  74,  39,  52,  77,  44,  46,  51,  52,  53
        .word    41,  53,  34,  36,  40,  56,  85,  47,  40,  46
bSides3:    .word    81,  58,  65,  53,  62,  50,  68,  81,  64,  62
        .word    45,  72,  86,  62,  63,  69,  66,  52,  68,  51
        .word    82,  55,  56,  57,  55,  44,  56,  40,  66,  63
        .word    63,  52,  41,  41,  61,  44,  52,  56,  68,  63
        .word    62,  69,  55,  49,  64,  55,  49,  52,  54,  59
        .word    60,  54,  56,  87,  64,  35,  36,  39,  58,  72
        .word    51,  53,  56,  59,  61,  72,  74,  68,  51,  75
        .word    79,  84,  49,  62,  87,  74,  66,  61,  62,  63
        .word    51,  63,  44,  46,  61,  66, 105,  57,  50,  56
cSides3:    .word   143, 142, 141, 141, 141, 144, 142, 146, 158, 143
        .word   142, 149, 145, 149, 141, 155, 149, 142, 144, 149
        .word   140, 144, 146, 157, 144, 135, 146, 129, 148, 142
        .word   141, 143, 146, 149, 151, 152, 154, 158, 161, 165
        .word   169, 174, 127, 179, 152, 141, 144, 156, 142, 133
        .word   141, 153, 154, 146, 140, 156, 175, 167, 150, 146
        .word   154, 155, 145, 162, 152, 141, 142, 156, 156, 143
        .word   168, 159, 151, 142, 153, 141, 176, 151, 149, 156
        .word   146, 179, 149, 137, 146, 154, 154, 156, 164, 142
dSides3:    .word   153, 152, 151, 151, 151, 154, 152, 156, 168, 153
        .word   152, 159, 155, 159, 151, 165, 159, 152, 154, 159
        .word   150, 154, 156, 167, 154, 145, 156, 139, 158, 152
        .word   151, 153, 156, 159, 161, 162, 164, 168, 171, 175
        .word   179, 184, 137, 189, 162, 151, 154, 166, 152, 143
        .word   151, 163, 164, 156, 150, 166, 185, 177, 160, 156
        .word   164, 165, 155, 172, 162, 161, 163, 166, 166, 153
        .word   178, 169, 161, 152, 163, 163, 196, 161, 159, 166
        .word   156, 189, 159, 147, 176, 164, 164, 166, 174, 152
diags3:     .space  360
len3:       .word   90
min3:       .word   0
med3:       .word   0
max3:       .word   0
fAve3:      .float  0.0

aSides4:    .word    53,  52,  46,  76,  50,  56,  64,  65,  55,  56
        .word    71,  47,  50,  27,  74,  65,  51,  67,  61,  59
        .word    53,  52,  46,  56,  50,  56,  64,  56,  55,  52
        .word    51,  63,  53,  50,  55,  59,  55,  58,  53,  55
        .word    64,  41,  42,  53,  66,  54,  46,  53,  56,  63
        .word    27,  64,  50,  72,  54,  55,  56,  62,  58,  62
        .word    51,  53,  53,  50,  57,  51,  55,  58,  53,  55
        .word    57,  26,  62,  57,  57,  67,  69,  77,  75,  54
        .word    53,  54,  52,  43,  76,  54,  56,  52,  56,  63
        .word    54,  59,  52,  53,  50,  61,  52,  59,  59,  52
        .word    55,  56,  62,  57,  57,  57,  59,  77,  75,  44
        .word    79,  53,  56,  40,  55,  52,  54,  58,  53,  52
        .word    61,  72,  51,  53,  56,  69,  54,  52,  55,  51
        .word    64,  54,  54,  43,  76,  54,  56,  52,  56,  63
        .word    49,  44,  54,  54,  67,  43,  59,  61,  65,  56
bSides4:    .word    63,  62,  56,  86,  60,  66,  74,  75,  65,  66
        .word    81,  57,  60,  37,  84,  75,  61,  77,  71,  69
        .word    63,  62,  56,  66,  60,  66,  74,  66,  65,  62
        .word    61,  73,  63,  60,  65,  69,  65,  68,  63,  65
        .word    74,  51,  52,  63,  76,  64,  56,  63,  66,  73
        .word    37,  74,  60,  82,  64,  65,  66,  72,  68,  72
        .word    61,  63,  63,  60,  67,  61,  65,  68,  63,  65
        .word    67,  36,  72,  67,  67,  77,  79,  87,  85,  64
        .word    63,  64,  62,  53,  86,  64,  66,  62,  66,  73
        .word    64,  69,  62,  63,  60,  71,  62,  69,  69,  62
        .word    65,  66,  72,  67,  67,  67,  69,  87,  85,  54
        .word    89,  63,  66,  50,  65,  62,  64,  68,  63,  62
        .word    71,  82,  61,  63,  66,  79,  64,  62,  65,  61
        .word    74,  64,  64,  53,  86,  64,  66,  62,  66,  73
        .word    59,  54,  64,  64,  77,  53,  69,  71,  75,  66
cSides4:    .word   145, 144, 143, 157, 153, 154, 154, 156, 164, 142
        .word   166, 152, 152, 151, 146, 150, 154, 178, 178, 192
        .word   182, 195, 157, 152, 157, 147, 167, 179, 188, 194
        .word   154, 152, 174, 186, 197, 154, 156, 150, 156, 153
        .word   152, 151, 156, 187, 190, 150, 151, 153, 152, 145
        .word   157, 187, 199, 151, 153, 154, 155, 156, 175, 194
        .word   149, 156, 162, 151, 157, 177, 199, 197, 175, 154
        .word   164, 141, 142, 153, 166, 154, 146, 153, 156, 163
        .word   151, 158, 177, 143, 178, 152, 151, 150, 155, 150
        .word   157, 144, 150, 172, 154, 155, 156, 162, 158, 192
        .word   153, 152, 146, 176, 151, 156, 164, 165, 195, 156
        .word   157, 153, 153, 140, 155, 151, 154, 158, 153, 152
        .word   169, 156, 162, 127, 157, 157, 159, 177, 175, 154
        .word   181, 155, 155, 152, 157, 155, 150, 159, 152, 154
        .word   161, 152, 151, 152, 171, 159, 154, 152, 155, 151
dSides4:    .word   155, 154, 153, 167, 163, 164, 164, 166, 174, 152
        .word   176, 162, 162, 161, 156, 160, 164, 188, 188, 202
        .word   192, 205, 167, 162, 167, 157, 177, 189, 198, 204
        .word   164, 162, 184, 196, 207, 164, 166, 160, 166, 163
        .word   162, 161, 166, 197, 204, 160, 161, 163, 162, 155
        .word   167, 197, 209, 161, 163, 164, 165, 166, 185, 204
        .word   159, 166, 172, 161, 167, 187, 207, 203, 185, 164
        .word   174, 151, 152, 163, 176, 164, 156, 163, 166, 173
        .word   161, 168, 187, 153, 188, 162, 161, 160, 165, 160
        .word   167, 154, 160, 182, 164, 165, 166, 172, 168, 202
        .word   163, 162, 156, 186, 161, 166, 174, 175, 205, 166
        .word   167, 163, 163, 150, 165, 161, 164, 168, 163, 162
        .word   179, 166, 172, 137, 167, 167, 169, 187, 185, 164
        .word   191, 165, 165, 162, 167, 165, 160, 169, 162, 164
        .word   171, 162, 161, 162, 181, 169, 164, 162, 165, 161
len4:       .word   150
diags4:     .space  600
min4:       .word   0
med4:       .word   0
max4:       .word   0
fAve4:      .float  0.0

aSides5:    .word    99,  74,  77,  79,  72,  64,  66,  68,  62,  73
        .word    50,  54,  56,  57,  54,  55,  56,  59,  48,  72
        .word    45,  75,  55,  52,  57,  55,  50,  59,  52,  54
        .word    50,  51,  54,  59,  40,  55,  61,  64,  58,  73
        .word    51,  53,  54,  56,  40,  56,  65,  67,  70,  76
        .word    44,  54,  54,  43,  76,  54,  56,  52,  56,  63
        .word    54,  52,  57,  66,  77,  54,  56,  50,  36,  53
        .word    69,  74,  77,  79,  82,  64,  66,  68,  72,  73
        .word    55,  52,  56,  55,  40,  57,  63,  79,  52,  74
        .word    56,  52,  52,  51,  46,  50,  54,  78,  58,  72
        .word    57,  57,  57,  57,  47,  57,  67,  77,  57,  77
        .word    57,  67,  59,  51,  53,  54,  55,  56,  75,  74
        .word    54,  52,  74   66,  67,  54,  56,  50,  36,  53
        .word    62,  65,  57,  52,  57,  47,  67,  59,  58,  73
        .word    85,  82,  96,  95,  60,  87,  23,  69,  42,  84
        .word    90,  90,  90,  90,  90,  90,  90,  90,  90,  90
        .word    90,  90,  90,  90,  90,  90,  90,  90,  90,  90
        .word    82,  64,  65,  67,  51,  68,  73,  76,  86,  91
        .word    81,  63,  74,  96,  90,  26,  95,  97,  99,  96
        .word    59,  51,  59,  31,  49,  51,  69,  71,  79,  71
        .word    41,  43,  46,  49,  51,  23,  78,  82,  21,  87
bSides5:    .word   103,  84,  87,  89,  82,  74,  76,  78,  72,  83
        .word    60,  64,  66,  67,  64,  65,  66,  69,  58,  82
        .word    55,  85,  65,  62,  67,  65,  60,  69,  62,  64
        .word    60,  61,  69,  69,  50,  65,  71,  74,  68,  83
        .word    61,  63,  63,  66,  55,  66,  75,  77,  81,  86
        .word    54,  64,  64,  53,  86,  64,  66,  62,  66,  73
        .word    64,  62,  67,  76,  87,  64,  66,  60,  46,  63
        .word    79,  84,  87,  89,  92,  74,  76,  78,  82,  83
        .word    65,  62,  66,  65,  50,  67,  73,  89,  62,  84
        .word    66,  62,  62,  61,  56,  60,  64,  88,  68,  82
        .word    67,  67,  67,  67,  57,  67,  77,  87,  67,  87
        .word    67,  77,  69,  61,  63,  64,  65,  66,  85,  84
        .word    64,  62,  84   76,  77,  64,  66,  60,  46,  63
        .word    72,  75,  67,  62,  67,  57,  77,  69,  68,  83
        .word    95,  92, 106, 105,  70,  97,  33,  79,  52,  94
        .word    99, 100, 101, 102,  99, 101, 110, 104, 102, 100
        .word    93, 102, 102, 109, 100, 107, 111, 105, 108, 101
        .word    92,  74,  75,  77,  61,  78,  83,  86,  96, 103
        .word    91,  73,  84, 106, 110,  36, 105, 107, 109, 106
        .word    69,  61,  69,  41,  59,  61,  79,  81,  89,  81
        .word    51,  53,  56,  59,  61,  33,  88,  92,  31,  97
cSides5:    .word   852, 159, 155, 159, 151, 155, 159, 152, 144, 149
        .word   162, 165, 157, 152, 157, 147, 167, 159, 168, 174
        .word   159, 154, 156, 157, 154, 155, 156, 159, 148, 172
        .word   141, 143, 146, 149, 151, 152, 154, 158, 161, 165
        .word   159, 153, 154, 156, 140, 156, 175, 187, 155, 156
        .word   152, 151, 176, 187, 170, 150, 151, 153, 152, 145
        .word   147, 153, 153, 140, 165, 151, 154, 158, 153, 152
        .word   151, 153, 154, 156, 140, 156, 175, 187, 160, 196
        .word   134, 152, 174, 186, 167, 154, 156, 150, 156, 153
        .word   182, 165, 157, 152, 157, 147, 167, 179, 168, 194
        .word   159, 151, 159, 151, 149, 151, 169, 171, 169, 191
        .word   153, 153, 153, 150, 155, 159, 143, 148, 153, 155
        .word   151, 155, 157, 163, 166, 168, 171, 177, 164, 176
        .word   152, 159, 155, 159, 151, 155, 159, 142, 144, 149
        .word   441, 443, 446, 449, 451, 452, 454, 458, 461, 465
        .word   352, 352, 352, 352, 352, 352, 352, 352, 352, 352
        .word   352, 352, 352, 352, 352, 352, 352, 352, 352, 352
        .word   262, 265, 257, 252, 257, 247, 267, 259, 268, 274
        .word   152, 159, 155, 159, 151, 155, 159, 152, 154, 159
        .word   152, 154, 158, 161, 165, 121, 232, 567, 211, 121
        .word   141, 143, 146, 149, 151, 152, 154, 158, 161, 265
dSides5:    .word   862, 169, 165, 169, 171, 165, 189, 172, 154, 159
        .word   172, 175, 167, 162, 177, 157, 187, 179, 178, 184
        .word   169, 164, 166, 167, 174, 165, 186, 179, 158, 192
        .word   151, 153, 156, 169, 161, 162, 184, 178, 171, 185
        .word   169, 163, 164, 166, 160, 166, 185, 197, 175, 196
        .word   162, 161, 186, 197, 190, 160, 181, 193, 172, 185
        .word   157, 163, 163, 160, 175, 161, 184, 198, 173, 182
        .word   161, 163, 164, 166, 170, 166, 185, 197, 180, 206
        .word   144, 162, 184, 196, 187, 164, 186, 160, 186, 173
        .word   192, 175, 167, 162, 167, 167, 187, 199, 188, 204
        .word   169, 161, 169, 161, 169, 161, 189, 191, 189, 201
        .word   163, 163, 163, 160, 165, 169, 183, 198, 183, 175
        .word   161, 165, 167, 173, 176, 178, 181, 197, 194, 176
        .word   162, 169, 165, 179, 161, 175, 189, 192, 194, 179
        .word   451, 453, 466, 459, 461, 472, 484, 478, 491, 485
        .word   362, 362, 362, 362, 362, 372, 382, 372, 392, 382
        .word   362, 362, 362, 362, 372, 372, 382, 372, 362, 382
        .word   272, 275, 267, 262, 277, 277, 287, 279, 288, 284
        .word   162, 169, 165, 169, 171, 175, 189, 172, 174, 199
        .word   162, 164, 168, 171, 175, 171, 282, 577, 271, 191
        .word   151, 153, 166, 159, 181, 172, 184, 178, 171, 275
diags5:     .space  840
len5:       .word   210
min5:       .word   0
med5:       .word   0
max5:       .word   0
fAve5:      .float  0.0

# -----
#  Variables for main.

asstHeader: .ascii  "\nMIPS Assignment #3\n"
        .asciiz "Trapezoid Diagonals Program\n\n"

# -----
#  Local variables/constants for prtHeaders() procedure.

hdrTitle:   .ascii  "\n*******************************************************************"
        .asciiz "\nTrapezoid Data Set #"
hdrLength:  .asciiz "\nLength: "

hdrStats:   .asciiz "\nDiagonals - Stats: \n"
hdrVolumes: .asciiz "\n\nDiagonals - Values: \n"

# -----
#  Local variables/constants for diagonals() function (if any).


# -----
#  Local variables/constants for shellSort() function (if any).

# -----
#  Local variables/constants for diagonalsStats() function.

# -----
#  Local variables/constants for displayStats() function.

NUMS_PER_ROW = 7

spc:        .asciiz "     "
newLine:    .asciiz "\n"

str1:       .asciiz "   min  = "
str2:       .asciiz "\n   max  = "
str3:       .asciiz "\n   med  = "
str4:       .asciiz "\n   float ave = "

#####################################################################
#  text/code segment

# -----
#  Basic flow:
#   for each data set:
#     * display headers
#     * calculate diagonals, including sort
#     * calculate diagonals stats (min, max, med, sum, and fAve)
#     * display diagonals and diagonals stats

.text
.globl  main
.ent main
main:

# --------------------------------------------------------
#  Display Program Header.

    la  $a0, asstHeader
    li  $v0, 4
    syscall                 # print header
    li  $s0, 1              # counter, data set number

# --------------------------------------------------------
#  Data Set #1

    move    $a0, $s0
    lw  $a1, len1
    jal prtHeaders
    add $s0, $s0, 1

#  Trapezoid diagonal calculation function
#  Note, function also calls the shellSort() function to
#  sort the diagonals array.
#   calcDiagonals(aSides, bSides, cSides, dSides, len, diags)

    la  $a0, aSides1
    la  $a1, bSides1
    la  $a2, cSides1
    la  $a3, dSides1
    subu    $sp, $sp, 8
    lw  $t0, len1
    sw  $t0, ($sp)          # arg 5, on stack
    la  $t0, diags1
    sw  $t0, 4($sp)         # arg 6, on stack
    jal calcDiagonals
    addu    $sp, $sp, 8         # clear stack

#  Generate diagonals stats.
#  Note, function also calls the findSum() and findAverage() functions.
#   diagonalsStats(diags, len, min, max, med, fAve)

    la  $a0, diags1         # arg 1
    lw  $a1, len1           # arg 2
    la  $a2, min1           # arg 3
    la  $a3, max1           # arg 4
    subu    $sp, $sp, 8
    la  $t0, med1
    sw  $t0, ($sp)          # arg 5, on stack
    la  $t6, fAve1
    sw  $t6, 4($sp)         # arg 6, on stack
    jal diagonalsStats
    addu    $sp, $sp, 8     # clear stack

#  Show final diagonals array stats.
#   displayStats(diags, len, min, max, med, fAve)

    la  $a0, diags1         # arg 1
    lw  $a1, len1           # arg 2
    lw  $a2, min1           # arg 3
    lw  $a3, max1           # arg 4
    subu    $sp, $sp, 8
    lw  $t0, med1
    sw  $t0, ($sp)          # arg 5, on stack
    l.s $f6, fAve1
    s.s $f6, 4($sp)         # arg 6, on stack
    jal displayStats
    addu    $sp, $sp, 8         # clear stack

# --------------------------------------------------------
#  Data Set #2

    move    $a0, $s0
    lw  $a1, len2
    jal prtHeaders
    add $s0, $s0, 1

#  Trapezoid diagonal calculation function
#  Note, function also calls the shellSort() function to
#  sort the diagonals array.
#   calcDiagonals(aSides, bSides, cSides, dSides, len, diags)

    la  $a0, aSides2
    la  $a1, bSides2
    la  $a2, cSides2
    la  $a3, dSides2
    subu    $sp, $sp, 8
    lw  $t0, len2
    sw  $t0, ($sp)          # arg 5, on stack
    la  $t0, diags2
    sw  $t0, 4($sp)         # arg 6, on stack
    jal calcDiagonals
    addu    $sp, $sp, 8         # clear stack

#  Generate diagonals stats.
#  Note, function also calls the findSum() and findAverage() functions.
#   diagonalsStats(diags, len, min, max, med, fAve)

    la  $a0, diags2         # arg 1
    lw  $a1, len2           # arg 2
    la  $a2, min2           # arg 3
    la  $a3, max2           # arg 4
    subu    $sp, $sp, 8
    la  $t0, med2
    sw  $t0, ($sp)          # arg 5, on stack
    la  $t6, fAve2
    sw  $t6, 4($sp)         # arg 6, on stack
    jal diagonalsStats
    addu    $sp, $sp, 8         # clear stack

#  Show final diagonals array stats.
#   displayStats(diags, len, min, max, med, fAve)

    la  $a0, diags2         # arg 1
    lw  $a1, len2           # arg 2
    lw  $a2, min2           # arg 3
    lw  $a3, max2           # arg 4
    subu    $sp, $sp, 8
    lw  $t0, med2
    sw  $t0, ($sp)          # arg 5, on stack
    l.s $f6, fAve2
    s.s $f6, 4($sp)         # arg 6, on stack
    jal displayStats
    addu    $sp, $sp, 8         # clear stack

# --------------------------------------------------------
#  Data Set #3

    move    $a0, $s0
    lw  $a1, len3
    jal prtHeaders
    add $s0, $s0, 1

#  Trapezoid diagonal calculation function
#  Note, function also calls the shellSort() function to
#  sort the diagonals array.
#   calcDiagonals(aSides, bSides, cSides, dSides, len, diags)

    la  $a0, aSides3
    la  $a1, bSides3
    la  $a2, cSides3
    la  $a3, dSides3
    subu    $sp, $sp, 8
    lw  $t0, len3
    sw  $t0, ($sp)          # arg 5, on stack
    la  $t0, diags3
    sw  $t0, 4($sp)         # arg 6, on stack
    jal calcDiagonals
    addu    $sp, $sp, 8         # clear stack

#  Generate diagonals stats.
#  Note, function also calls the findSum() and findAverage() functions.
#   diagonalsStats(diags, len, min, max, med, fAve)

    la  $a0, diags3         # arg 1
    lw  $a1, len3           # arg 2
    la  $a2, min3           # arg 3
    la  $a3, max3           # arg 4
    subu    $sp, $sp, 8
    la  $t0, med3
    sw  $t0, ($sp)          # arg 5, on stack
    la  $t6, fAve3
    sw  $t6, 4($sp)         # arg 6, on stack
    jal diagonalsStats
    addu    $sp, $sp, 8         # clear stack

#  Show final diagonals array stats.
#   displayStats(diags, len, min, max, med, fAve)

    la  $a0, diags3         # arg 1
    lw  $a1, len3           # arg 2
    lw  $a2, min3           # arg 3
    lw  $a3, max3           # arg 4
    subu    $sp, $sp, 8
    lw  $t0, med3
    sw  $t0, ($sp)          # arg 5, on stack
    l.s $f6, fAve3
    s.s $f6, 4($sp)         # arg 6, on stack
    jal displayStats
    addu    $sp, $sp, 8         # clear stack

# --------------------------------------------------------
#  Data Set #4

    move    $a0, $s0
    lw  $a1, len4
    jal prtHeaders
    add $s0, $s0, 1

#  Trapezoid diagonal calculation function
#  Note, function also calls the shellSort() function to
#  sort the diagonals array.
#   calcDiagonals(aSides, bSides, cSides, dSides, len, diags)

    la  $a0, aSides4
    la  $a1, bSides4
    la  $a2, cSides4
    la  $a3, dSides4
    subu    $sp, $sp, 8
    lw  $t0, len4
    sw  $t0, ($sp)          # arg 5, on stack
    la  $t0, diags4
    sw  $t0, 4($sp)         # arg 6, on stack
    jal calcDiagonals
    addu    $sp, $sp, 8         # clear stack

#  Generate diagonals stats.
#  Note, function also calls the findSum() and findAverage() functions.
#   diagonalsStats(diags, len, min, max, med, fAve)

    la  $a0, diags4         # arg 1
    lw  $a1, len4           # arg 2
    la  $a2, min4           # arg 3
    la  $a3, max4           # arg 4
    subu    $sp, $sp, 8
    la  $t0, med4
    sw  $t0, ($sp)          # arg 5, on stack
    la  $t6, fAve4
    sw  $t6, 4($sp)         # arg 6, on stack
    jal diagonalsStats
    addu    $sp, $sp, 8         # clear stack

#  Show final diagonals array stats.
#   displayStats(diags, len, min, max, med, fAve)

    la  $a0, diags4         # arg 1
    lw  $a1, len4           # arg 2
    lw  $a2, min4           # arg 3
    lw  $a3, max4           # arg 4
    subu    $sp, $sp, 8
    lw  $t0, med4
    sw  $t0, ($sp)          # arg 5, on stack
    l.s $f6, fAve4
    s.s $f6, 4($sp)         # arg 6, on stack
    jal displayStats
    addu    $sp, $sp, 8         # clear stack

# --------------------------------------------------------
#  Data Set #5

    move    $a0, $s0
    lw  $a1, len5
    jal prtHeaders
    add $s0, $s0, 1

#  Trapezoid diagonal calculation function
#  Note, function also calls the shellSort() function to
#  sort the diagonals array.
#   calcDiagonals(aSides, bSides, cSides, dSides, len, diags)

    la  $a0, aSides5
    la  $a1, bSides5
    la  $a2, cSides5
    la  $a3, dSides5
    subu    $sp, $sp, 8
    lw  $t0, len5
    sw  $t0, ($sp)          # arg 5, on stack
    la  $t0, diags5
    sw  $t0, 4($sp)         # arg 6, on stack
    jal calcDiagonals
    addu    $sp, $sp, 8         # clear stack

#  Generate diagonals stats.
#  Note, function also calls the findSum() and findAverage() functions.
#   diagonalsStats(diags, len, min, max, med, fAve)

    la  $a0, diags5         # arg 1
    lw  $a1, len5           # arg 2
    la  $a2, min5           # arg 3
    la  $a3, max5           # arg 4
    subu    $sp, $sp, 8
    la  $t0, med5
    sw  $t0, ($sp)          # arg 5, on stack
    la  $t6, fAve5
    sw  $t6, 4($sp)         # arg 6, on stack
    jal diagonalsStats
    addu    $sp, $sp, 8         # clear stack

#  Show final diagonals array stats.
#   displayStats(diags, len, min, max, med, fAve)

    la  $a0, diags5         # arg 1
    lw  $a1, len5           # arg 2
    lw  $a2, min5           # arg 3
    lw  $a3, max5           # arg 4
    subu    $sp, $sp, 8
    lw  $t0, med5
    sw  $t0, ($sp)          # arg 5, on stack
    l.s $f6, fAve5
    s.s $f6, 4($sp)         # arg 6, on stack
    jal displayStats
    addu    $sp, $sp, 8         # clear stack

# --------------------------------------------------------
#  Done, terminate program.

    li  $v0, 10
    syscall                 # au revoir...
.end

#####################################################################
#  Display headers.

.globl  prtHeaders
.ent    prtHeaders
prtHeaders:
    sub $sp, $sp, 8
    sw  $s0, ($sp)
    sw  $s1, 4($sp)

    move    $s0, $a0
    move    $s1, $a1

    la  $a0, hdrTitle
    li  $v0, 4
    syscall

    move    $a0, $s0
    li  $v0, 1
    syscall

    la  $a0, hdrLength
    li  $v0, 4
    syscall

    move    $a0, $s1
    li  $v0, 1
    syscall

    lw  $s0, ($sp)
    lw  $s1, 4($sp)
    add $sp, $sp, 8

    jr  $ra
.end    prtHeaders

#####################################################################
#  MIPS assembly language function to calculate the
#  diagonal for each trapezoid in a series of trapezoids.

#  Note, this function also calls the shellSort() function
#        after the diagonals are calculated.

#    Arguments:
#   $a0 - starting address of the aSides array
#   $a1 - starting address of the bSides array
#   $a2 - starting address of the cSides array
#   $a3 - starting address of the dSides array
#   ($fp)   - length
#   4($fp)  - starting address of the diags array

#    Returns:
#   diag[] areas array via passed address

.globl  calcDiagonals
.ent calcDiagonals
calcDiagonals:

    subu $sp, $sp, 36   # preserve registers
    sw $a0, ($sp)
    sw $s0, 4($sp)
    sw $s1, 8($sp)
    sw $s2, 12($sp)
    sw $s3, 16($sp)
    sw $s4, 20($sp)
    sw $s5, 24($sp)
    sw $fp, 28($sp)
    sw $ra, 32($sp)

    addu $fp, $sp, 36    # set fp to first arg

    move $s0, $a0       # aSides
    move $s1, $a1       # bSides
    move $s2, $a2       # cSides
    move $s3, $a3       # dSides
    lw $s5, ($fp)       # len
    lw $s4, 4($fp)      # diags

    calcLoop:
        lw $t1, ($s0)       # aSides
        lw $t2, ($s1)       # bSides
        lw $t3, ($s2)       # cSides
        lw $t4, ($s3)       # dSides

        move $t5, $zero     # sub value here
        mul $t5, $t2, $t2   # b[i]^2
        mul $t5, $t5, $t1   # a[i] x b[i]^2

        move $t6, $zero     # sub value here
        mul $t6, $t1, $t1   # a[i]^2
        mul $t6, $t6, $t2   # a[i]^2 x b[i]

        sub $t5, $t5, $t6   # a[i] x b[i]^2 - a[i]^2 x b[i]

        move $t6, $zero     # sub value here
        mul $t6, $t3, $t3   # c[i]^2
        mul $t6, $t6, $t1   # a[i] x c[i]^2

        sub $t5, $t5, $t6   # a[i] x b[i]^2 - a[i]^2 x b[i] - a[i] x c[i]^2

        move $t6, $zero     # sub value here
        mul $t6, $t4, $t4   # d[i]^2
        mul $t6, $t6, $t2   # b[i] x d[i]^2

        add $t5, $t5, $t6   # a[i] x b[i]^2 - a[i]^2 x b[i] - a[i] x c[i]^2 + b[i] x d[i]^2

        move $t6, $zero     # denominator here
        sub $t6, $t2, $t1   # b[i] - a[i]

        div $t5, $t5, $t6   # numerator / denominator

        move $a0, $t5
        jal iSqrt

        sw $v0, ($s4)       # set diags

        sub $s5, $s5, 1
        addu $s0, $s0, 4
        addu $s1, $s1, 4
        addu $s2, $s2, 4
        addu $s3, $s3, 4
        addu $s4, $s4, 4
        bnez $s5, calcLoop  # jump back up if len is not zero

    lw $a0, 4($fp)
    lw $a1, ($fp)
    jal shellSort
           
    lw $a0, ($sp)       # restore registers
    lw $s0, 4($sp)
    lw $s1, 8($sp)
    lw $s2, 12($sp)
    lw $s3, 16($sp)
    lw $s4, 20($sp)
    lw $s5, 24($sp)
    lw $fp, 28($sp)
    lw $ra, 32($sp)
    addu $sp, $sp, 36    # set frame pointer to first arg
    jr $ra
.end calcDiagonals

#####################################################################
#  Integer square root function.

#    Arguments:
#   $a0   - integer

#    Returns:
#   $v0   - square root of integer

.globl  iSqrt
.ent    iSqrt
iSqrt:

    li $t2, 50          # iterate 50 times
    move $t1, $zero
    move $t0, $a0       # iSqrt_est
    estimateSqrt:
        div $t1, $a0, $t0       # iNumber / iSqrt_est
        add $t1, $t1, $t0       # (iNumber / iSqrt_est) + iSqrt_est
        div $t1, $t1, 2         # divide all by two
        move $t0, $t1           # set to new iSqrt_est
        sub $t2, $t2, 1         # decrement count
        bnez $t2, estimateSqrt  # loop if not zero yet

    move $v0, $t0       # set return value
    jr $ra             
.end    iSqrt

#####################################################################
#  Sort a list of numbers using shell sort algorithm.

#   h = 1#
#   while ( (h*3+1) < length ) {
#      h = 3 * h + 1#
#   }

#   while ( h>0 ) {
#      for (i = h-1# i < length# i++) {
#          tmp = lst[i]#
#          j = i#
#          for ( j=i# (j>=h) && (lst[j-h]>tmp)# j = j-h)
#             lst[j] = lst[j-h]#
#          lst[j] = tmp#
#      }
#      h = h / 3#
#   }

# -----
#    Arguments:
#   $a0 - starting address of the list
#   $a1 - list length

#    Returns:
#   sorted list (via reference)

.globl shellSort
.ent shellSort
shellSort:

    # t0 -> h
    # t1 -> i
    # t2 -> j
    # t3 -> tmp

    li $t0, 1      # load 1 into t0, this is our h
    whileLoop1:
        li  $t1, 3                  # load 3 into t0
        mul $t0, $t0, $t1           # h = h * 3
        add $t0, $t0, 1             # h = h * 3 + 1
        blt $t0, $a1, whileLoop1   # reloop if h is less than length

    move $t1, $zero
    move $t2, $zero
    move $t3, $zero
    whileLoop2:
        bnez $t0, exitWhileLoop2
        sub $t0, $t0, 1             # t - 1
        move $t1, $t0               # i = h - 1
        forLoop1:                       
            bge $t1, $a1, exitForLoop1  # break if i >= length
            move $t4, $a0               # get list addr
            move $t3, $t1               # move i into tmp
            mul $t3, $t3, 4             # len *= 4
            add $t4, $t4, $t3           # list[i]
            lw $t3, ($t4)               # tmp = list[i]
            move $t2, $t1               # j = i
            forLoop2:                       
                blt $t2, $t0, exitForLoop2  # break if j < h
                move $t4, $a0               # get list addr
                move $t5, $t2               # get j
                sub $t5, $t5, $t0           # j - h
                mul $t5, $t5, 4             # 4(j - h)
                add $t4, $t4, $t5           # lst[j-h]
                lw $t4, ($t4)
                ble $t4, $t3, exitForLoop2  # break if lst[j-h] <= tmp

                move $t5, $a0               # get list addr
                move $t6, $t2               # get j
                mul $t6, $t6, 4             # 4j
                add $t5, $t5, $t6           # move addr to lst[j]
                sw $t4, ($t5)               # lst[j] = lst[j-h] 

                sub $t2, $t2, $t0           # j = j - h
                b forLoop2
            exitForLoop2:

            move $t4, $a0                   # get lst addr
            move $t5, $t2                   # get j
            mul $t5, $t5, 4                 # 4j
            add $t4, $t4, $t5               # move lst to list[j]
            sw $t3, ($t4)                   # list[j] = tmp        

            add $t1, $t1, 1                 # i = i + 1
            b forLoop1
        exitForLoop1:
        div $t0, $t0, 3           # h = h / 3 
        b whileLoop2
    exitWhileLoop2:  
        
    jr $ra
.end shellSort

#####################################################################
#  Find sum function.
#   Find sum of passed array.

#    Arguments:
#   $a0   - starting address of list
#   $a1   - len

#    Returns:
#   $v0   - sum

.globl  findSum
.ent    findSum
findSum:

    move $t0, $zero
    move $t2, $a1   # move len into t2
    sumLoop:
        lw $t1, ($a0)       # lst[i]
        add $t0, $t0, $t1   # sum += lst[i]
        sub $t2, $t2, 1     # decrement count
        addu $a0, $a0, 4    # i = i + 1
        bnez $t2, sumLoop

    move $v0, $t0   # move sum into v0
    jr $ra

.end    findSum

#####################################################################
#  Find floating point average function.
#  Includes performing the required type conversions.
#  Note, must call findSum() function.

#    Arguments:
#   $a0   - starting address of list 
#   $a1   - len

#    Returns:
#   $v0   - sum

.globl  findAverage
.ent    findAverage
findAverage:

    subu $sp, $sp, 4
    sw $ra, ($sp)
    
    jal findSum         # get sum
    div $v0, $v0, $a1   # v0 = sum / length
    
    lw $ra, ($sp)
    addu $sp, $sp, 4
    jr $ra

.end    findAverage

#####################################################################
#  MIPS assembly language procedure, diagonalsStats() to find the
#    sum, average, minimum, maximum, median, and floating point
#    average of list.
#  Note, must call the findAverage() function.

# -----
#  HLL Call:
#   diagonalsStats(diags, len, min, max, med, fAve)

# -----
#    Arguments:
#   $a0 - starting address of the diagonals array
#   $a1 - list length
#   $a2 - addr of min
#   $a3 - addr of max
#   ($fp)   - addr of med
#   4($fp)  - addr of fAve

#    Returns (via reference):
#   min, max, med, fAve

.globl diagonalsStats
.ent diagonalsStats
diagonalsStats:

    subu $sp, $sp, 8    # preserve registers
    sw $fp, ($sp)       # fp in this case
    sw $ra, 4($sp)
     
    addu $fp, $sp, 8    # set fp to first argument to stack passed args

    lw $t7, ($fp)
    lw $t6, 4($fp)
    
    lw $t0, ($a0)       # get min of sorted array
    sw $t0, ($a2)       # store min into addr

    move $t0, $a0       # get copy of addr
    move $t1, $a1       # get length
    mul $t1, $t1, 4     # length *= 4
    sub $t1, $t1, 4     # subtract one
    add $t0, $t0, $t1   # get to end of list
    lw $t0, ($t0)       # get max
    sw $t0, ($a3)       # store max into addr

    move $t0, $a1       # get list length
    rem $t0, $t0 2      # check if even or odd
    bnez $t0, oddLen
        move $t1, $a0       # get copy of addr
        move $t2, $a1       # get length of list
        div $t2, $t2, 2     # len / 2
        mul $t2, $t2, 4     # multiply by data size
        add $t1, $t1, $t2   # move to location
        lw $t0, ($t1)       # get lst[len/2]
        sub $t1, $t1, 4     # move back one
        lw $t4, ($t4)       # get lst[len/2-1]
        add $t0, $t0, $t4   # lst[len/2] + lst[len/2-1]
        div $t0, $t0, 2     # median
        sw $t0, ($t7)       
        b doneMidPoint
    oddLen:
        move $t1, $a0       # get copy of addr
        move $t2, $a1       # get copy of lenth
        div $t2, $t2, 2     # len / 2
        mul $t2, $t2, 4     # mul by data size
        add $t1, $t1, $t2   # move lst to lst[len/2]
        lw $t0, ($t1)       # get lst[len/2]
        sw $t0, ($t7)
    doneMidPoint:

    jal findAverage         # calculate average
    sw $v0, ($t6)           # store return result into addr of ave

    lw $fp, ($sp)       # restore registers
    lw $ra, 4($sp)
    addu $sp, $sp, 8
    jr $ra

.end diagonalsStats

#####################################################################
#  MIPS assembly language procedure, displayStats(), to display
#    the statistical information to console.

#  Note, due to the system calls, the saved registers must be used.
#   As such, push/pop saved registers altered.

# HLL Call
#   displayStats(diags, len, min, max, med, fAve)

# -----
#    Arguments:
#   $a0 - starting address of diags[]
#   $a1 - length
#   $a2 - min
#   $a3 - max
#   ($fp)   - med
#   4($fp)  - fAve

#    Returns:
#   N/A

.globl  displayStats
.ent    displayStats
displayStats:
    
    subu $sp, $sp, 36
    sw $a0, ($sp)
    sw $s0, 4($sp)
    sw $s1, 8($sp)
    sw $s2, 12($sp)
    sw $s3, 16($sp)
    sw $s4, 20($sp)
    sw $s5, 24($sp)
    sw $fp, 28($sp)
    sw $ra, 32($sp)

    addu $fp, $sp, 36

    la $a0, hdrVolumes
    li $v0, 4
    syscall

    move $s1, $a0
    move $s2, $a1

    move $s3, $s1
    move $s4, $s2
    printVals:
        lw $t1, ($s3)
        move $a0, $s3
        li $v0, 1
        syscall
    
        la $a0, spc
        li $v0, 4
        syscall

        sub $s4, $s4, 1
        addu $s3, $s3, 4
        bnez $s4, printVals
    
    lw $a0, ($sp)
    lw $s0, 4($sp)
    lw $s1, 8($sp)
    lw $s2, 12($sp)
    lw $s3, 16($sp)
    lw $s4, 20($sp)
    lw $s5, 24($sp)
    lw $fp, 28($sp)
    lw $ra, 32($sp)
    addu $sp, $sp, 36
    jr $ra

.end displayStats

#####################################################################


