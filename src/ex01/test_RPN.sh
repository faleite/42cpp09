#!/bin/bash

# out file
out_file="test_RPN_output.txt"
program="RPN"
#test inputs
inputs=(
	" "
	"98 9 * 9 - 9 - 9 - 4 - 1 +"
	"8 9 * 9 - 9 - 9 - 4 - 1 +"
	"9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -"
	"1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 / "
	"-3 4 +"
	" 1 0 /"
	""
    "3"
    "+7 7 +"
    "-7 7 +"
    "7 7 7 +"
    "7 7 7 * -"
    "7 7 * 7 -"
    "1 2 * 2 / 2 * 2 4 - +"
    "(1 + 1)"
    "hello potato"
    "3   5   +    /     -"
    " 3 4 +"
    "3 4 +"
	"1 2 /"
	"123123123123123 123123123123123123 +"
	"1f 2 /"
	" 1 200 /"
	" 	 	"
)

#remove previous outfile if it exists
rm -f $out_file

#loop through inputs and run
for input in "${inputs[@]}"
do
	echo -e "input is: \"$input\""  >> $out_file
    ./$program "$input" >> $out_file 2>&1
	echo -e  >> $out_file
done
