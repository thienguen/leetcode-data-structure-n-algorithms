#!/bin/bash
# CS 302, assignment #1 test script.

# ---------------------------------------------------------
# Initial checks.
#	Ensure executable file exists.

if [ -z $1 ]; then
	echo "Error, must provide executable file name."
	exit
fi

if [ ! -e $1 ] || [ ! -x $1 ]; then
	echo "Error, unable to find $1 executable file."
	exit
fi

# ---------------------------------------------------------
# Define script variables and function

bolded=`tput bold`
normal=`tput sgr0`

pause() {
	if [ "$1" = "skip" ]; then
		echo
	else
		echo
		echo -n "Press return to continue"
		read
		clear
	fi
}

# ---------------------------------------------------------
# Display initial page

clear
echo
echo
echo ${bolded}Assignment 1 - Execution Times Utility${normal}
echo
echo
echo
echo
echo "This will take a while..."
echo
echo
pause $2

echo -e "Executions Times for Selection Problem Program.\n\n" > a1times.txt

# ---------------------------------------------------------
#  Begin executions -> sort select.

echo "Executions for Sort Select."
echo -e "Executions for Sort Select." >> a1times.txt
echo

echo -e "\n------------------------------------" >> a1times.txt
echo "Execution Test, 100000 numbers."
echo -e "Execution Test, 100000 numbers." >> a1times.txt
(time ./$1 -s << EOF) 2>> a1times.txt
100000
10
EOF

echo -e "\n------------------------------------" >> a1times.txt
echo "Execution Test, 200000 numbers."
echo -e "Execution Test, 200000 numbers." >> a1times.txt
(time ./$1 -s << EOF) 2>> a1times.txt
200000
10
EOF

echo -e "\n------------------------------------" >> a1times.txt
echo "Execution Test, 300000 numbers."
echo -e "Execution Test, 300000 numbers." >> a1times.txt
(time ./$1 -s << EOF) 2>> a1times.txt
300000
10
EOF

echo -e "\n------------------------------------" >> a1times.txt
echo "Execution Test, 400000 numbers."
echo -e "Execution Test, 400000 numbers." >> a1times.txt
(time ./$1 -s << EOF) 2>> a1times.txt
400000
10
EOF

echo -e "\n------------------------------------" >> a1times.txt
echo "Execution Test, 500000 numbers."
echo -e "Execution Test, 500000 numbers." >> a1times.txt
(time ./$1 -s << EOF) 2>> a1times.txt
500000
10
EOF

echo -e "\n------------------------------------" >> a1times.txt
echo "Execution Test, 600000 numbers."
echo -e "Execution Test, 600000 numbers." >> a1times.txt
(time ./$1 -s << EOF) 2>> a1times.txt
600000
10
EOF

echo -e "\n------------------------------------" >> a1times.txt
echo "Execution Test, 700000 numbers."
echo -e "Execution Test, 700000 numbers." >> a1times.txt
(time ./$1 -s << EOF) 2>> a1times.txt
700000
10
EOF

echo -e "\n------------------------------------" >> a1times.txt
echo "Execution Test, 800000 numbers."
echo -e "Execution Test, 800000 numbers." >> a1times.txt
(time ./$1 -s << EOF) 2>> a1times.txt
800000
10
EOF

echo -e "\n------------------------------------" >> a1times.txt
echo "Execution Test, 900000 numbers."
echo -e "Execution Test, 900000 numbers." >> a1times.txt
(time ./$1 -s << EOF) 2>> a1times.txt
900000
10
EOF

echo -e "\n------------------------------------" >> a1times.txt
echo "Execution Test, 1000000 numbers."
echo -e "Execution Test, 1000000 numbers." >> a1times.txt
(time ./$1 -s << EOF) 2>> a1times.txt
1000000
10
EOF

echo -e "\n------------------------------------\n" >> a1times.txt

# ---------------------------------------------------------
#  Begin executions -> quick select.

echo "Executions for Quick Select."
echo -e "Executions for Quick Select." >> a1times.txt
echo

echo -e "\n------------------------------------" >> a1times.txt
echo "Execution Test, 100000 numbers."
echo -e "Execution Test, 100000 numbers." >> a1times.txt
(time ./$1 -qs << EOF) 2>> a1times.txt
100000
10
EOF

echo -e "\n------------------------------------" >> a1times.txt
echo "Execution Test, 200000 numbers."
echo -e "Execution Test, 200000 numbers." >> a1times.txt
(time ./$1 -qs << EOF) 2>> a1times.txt
200000
10
EOF

echo -e "\n------------------------------------" >> a1times.txt
echo "Execution Test, 300000 numbers."
echo -e "Execution Test, 300000 numbers." >> a1times.txt
(time ./$1 -qs << EOF) 2>> a1times.txt
300000
10
EOF

echo -e "\n------------------------------------" >> a1times.txt
echo "Execution Test, 400000 numbers."
echo -e "Execution Test, 400000 numbers." >> a1times.txt
(time ./$1 -qs << EOF) 2>> a1times.txt
400000
10
EOF

echo -e "\n------------------------------------" >> a1times.txt
echo "Execution Test, 500000 numbers."
echo -e "Execution Test, 500000 numbers." >> a1times.txt
(time ./$1 -qs << EOF) 2>> a1times.txt
500000
10
EOF

echo -e "\n------------------------------------" >> a1times.txt
echo "Execution Test, 600000 numbers."
echo -e "Execution Test, 600000 numbers." >> a1times.txt
(time ./$1 -qs << EOF) 2>> a1times.txt
600000
10
EOF

echo -e "\n------------------------------------" >> a1times.txt
echo "Execution Test, 700000 numbers."
echo -e "Execution Test, 700000 numbers." >> a1times.txt
(time ./$1 -qs << EOF) 2>> a1times.txt
700000
10
EOF

echo -e "\n------------------------------------" >> a1times.txt
echo "Execution Test, 800000 numbers."
echo -e "Execution Test, 800000 numbers." >> a1times.txt
(time ./$1 -qs << EOF) 2>> a1times.txt
800000
10
EOF

echo -e "\n------------------------------------" >> a1times.txt
echo "Execution Test, 900000 numbers."
echo -e "Execution Test, 900000 numbers." >> a1times.txt
(time ./$1 -qs << EOF) 2>> a1times.txt
900000
10
EOF

echo -e "\n------------------------------------" >> a1times.txt
echo "Execution Test, 1000000 numbers."
echo -e "Execution Test, 1000000 numbers." >> a1times.txt
(time ./$1 -qs << EOF) 2>> a1times.txt
1000000
10
EOF

echo -e "\n------------------------------------\n" >> a1times.txt

