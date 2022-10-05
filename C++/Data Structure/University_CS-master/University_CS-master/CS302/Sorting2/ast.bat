#!/bin/bash
# CS 302, assignment #3 test script.

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
		echo "The total execution times may exceed 4 hours"
		echo "depending on the machine..."
		echo
		echo "The times are recorded in 'a1times.txt' " 
		echo
		echo
		echo
		echo
		echo "Press return when ready to start."
		read
		clear
	fi
}

# ---------------------------------------------------------
# Display initial page

clear
echo
echo
echo ${bolded}Assignment 3 - Execution Times Utility${normal}
echo
echo
echo
pause $2

echo -e "Executions Times for Sorting Algorithms Program.\n\n" > a3times.txt

# ---------------------------------------------------------
#  Begin executions -> bubble sort.

echo "Executions for Bubble Sort."
echo -e "Executions for Bubble Sort." >> a3times.txt
echo

echo -e "\n------------------------------------" >> a3times.txt
echo "Execution Test, 100000 numbers."
echo -e "Execution Test, 100000 numbers." >> a3times.txt
(time ./$1 -bs -n 100000) 2>> a3times.txt

echo -e "\n------------------------------------" >> a3times.txt
echo "Execution Test, 200000 numbers."
echo -e "Execution Test, 200000 numbers." >> a3times.txt
(time ./$1 -bs -n 200000) 2>> a3times.txt

echo -e "\n------------------------------------" >> a3times.txt
echo "Execution Test, 300000 numbers."
echo -e "Execution Test, 300000 numbers." >> a3times.txt
(time ./$1 -bs -n 300000) 2>> a3times.txt

echo -e "\n------------------------------------" >> a3times.txt
echo "Execution Test, 400000 numbers."
echo -e "Execution Test, 400000 numbers." >> a3times.txt
(time ./$1 -bs -n 400000) 2>> a3times.txt

echo -e "\n------------------------------------" >> a3times.txt
echo "Execution Test, 500000 numbers."
echo -e "Execution Test, 500000 numbers." >> a3times.txt
(time ./$1 -bs -n 500000) 2>> a3times.txt

echo -e "\n------------------------------------" >> a3times.txt
echo "Execution Test, 600000 numbers."
echo -e "Execution Test, 600000 numbers." >> a3times.txt
(time ./$1 -bs -n 600000) 2>> a3times.txt

echo -e "\n------------------------------------" >> a3times.txt
echo "Execution Test, 700000 numbers."
echo -e "Execution Test, 700000 numbers." >> a3times.txt
(time ./$1 -bs -n 700000) 2>> a3times.txt

echo -e "\n------------------------------------" >> a3times.txt
echo "Execution Test, 800000 numbers."
echo -e "Execution Test, 800000 numbers." >> a3times.txt
(time ./$1 -bs -n 800000) 2>> a3times.txt

echo -e "\n------------------------------------" >> a3times.txt
echo "Execution Test, 900000 numbers."
echo -e "Execution Test, 900000 numbers." >> a3times.txt
(time ./$1 -bs -n 900000) 2>> a3times.txt

echo -e "\n------------------------------------" >> a3times.txt
echo "Execution Test, 1000000 numbers."
echo -e "Execution Test, 1000000 numbers." >> a3times.txt
(time ./$1 -bs -n 1000000) 2>> a3times.txt

echo -e "\n------------------------------------\n" >> a3times.txt

# ---------------------------------------------------------
#  Begin executions -> selection sort.

echo "Executions for Selection Sort."
echo -e "Executions for Selection Sort." >> a3times.txt
echo

echo -e "\n------------------------------------" >> a3times.txt
echo "Execution Test, 100000 numbers."
echo -e "Execution Test, 100000 numbers." >> a3times.txt
(time ./$1 -ss -n 100000) 2>> a3times.txt

echo -e "\n------------------------------------" >> a3times.txt
echo "Execution Test, 200000 numbers."
echo -e "Execution Test, 200000 numbers." >> a3times.txt
(time ./$1 -ss -n 200000) 2>> a3times.txt

echo -e "\n------------------------------------" >> a3times.txt
echo "Execution Test, 300000 numbers."
echo -e "Execution Test, 300000 numbers." >> a3times.txt
(time ./$1 -ss -n 300000) 2>> a3times.txt

echo -e "\n------------------------------------" >> a3times.txt
echo "Execution Test, 400000 numbers."
echo -e "Execution Test, 400000 numbers." >> a3times.txt
(time ./$1 -ss -n 400000) 2>> a3times.txt

echo -e "\n------------------------------------" >> a3times.txt
echo "Execution Test, 500000 numbers."
echo -e "Execution Test, 500000 numbers." >> a3times.txt
(time ./$1 -ss -n 500000) 2>> a3times.txt

echo -e "\n------------------------------------" >> a3times.txt
echo "Execution Test, 600000 numbers."
echo -e "Execution Test, 600000 numbers." >> a3times.txt
(time ./$1 -ss -n 600000) 2>> a3times.txt

echo -e "\n------------------------------------" >> a3times.txt
echo "Execution Test, 700000 numbers."
echo -e "Execution Test, 700000 numbers." >> a3times.txt
(time ./$1 -ss -n 700000) 2>> a3times.txt

echo -e "\n------------------------------------" >> a3times.txt
echo "Execution Test, 800000 numbers."
echo -e "Execution Test, 800000 numbers." >> a3times.txt
(time ./$1 -ss -n 800000) 2>> a3times.txt

echo -e "\n------------------------------------" >> a3times.txt
echo "Execution Test, 900000 numbers."
echo -e "Execution Test, 900000 numbers." >> a3times.txt
(time ./$1 -ss -n 1000000) 2>> a3times.txt

echo -e "\n------------------------------------" >> a3times.txt
echo "Execution Test, 1000000 numbers."
echo -e "Execution Test, 1000000 numbers." >> a3times.txt
(time ./$1 -ss -n 1000000) 2>> a3times.txt

echo -e "\n------------------------------------\n" >> a3times.txt

# ---------------------------------------------------------
#  Begin executions -> quick sort.

echo "Executions for Quick Sort."
echo -e "Executions for Quick Sort." >> a3times.txt
echo

echo -e "\n------------------------------------" >> a3times.txt
echo "Execution Test, 100000 numbers."
echo -e "Execution Test, 100000 numbers." >> a3times.txt
(time ./$1 -qs -n 100000) 2>> a3times.txt

echo -e "\n------------------------------------" >> a3times.txt
echo "Execution Test, 200000 numbers."
echo -e "Execution Test, 200000 numbers." >> a3times.txt
(time ./$1 -qs -n 200000) 2>> a3times.txt

echo -e "\n------------------------------------" >> a3times.txt
echo "Execution Test, 300000 numbers."
echo -e "Execution Test, 300000 numbers." >> a3times.txt
(time ./$1 -qs -n 300000) 2>> a3times.txt

echo -e "\n------------------------------------" >> a3times.txt
echo "Execution Test, 400000 numbers."
echo -e "Execution Test, 400000 numbers." >> a3times.txt
(time ./$1 -qs -n 400000) 2>> a3times.txt

echo -e "\n------------------------------------" >> a3times.txt
echo "Execution Test, 500000 numbers."
echo -e "Execution Test, 500000 numbers." >> a3times.txt
(time ./$1 -qs -n 500000) 2>> a3times.txt

echo -e "\n------------------------------------" >> a3times.txt
echo "Execution Test, 600000 numbers."
echo -e "Execution Test, 600000 numbers." >> a3times.txt
(time ./$1 -qs -n 600000) 2>> a3times.txt

echo -e "\n------------------------------------" >> a3times.txt
echo "Execution Test, 700000 numbers."
echo -e "Execution Test, 700000 numbers." >> a3times.txt
(time ./$1 -qs -n 700000) 2>> a3times.txt

echo -e "\n------------------------------------" >> a3times.txt
echo "Execution Test, 800000 numbers."
echo -e "Execution Test, 800000 numbers." >> a3times.txt
(time ./$1 -qs -n 800000) 2>> a3times.txt

echo -e "\n------------------------------------" >> a3times.txt
echo "Execution Test, 900000 numbers."
echo -e "Execution Test, 900000 numbers." >> a3times.txt
(time ./$1 -qs -n 900000) 2>> a3times.txt

echo -e "\n------------------------------------" >> a3times.txt
echo "Execution Test, 1000000 numbers."
echo -e "Execution Test, 1000000 numbers." >> a3times.txt
(time ./$1 -qs -n 1000000) 2>> a3times.txt

echo -e "\n------------------------------------\n" >> a3times.txt

