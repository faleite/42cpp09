#!/bin/bash

output_file="test_output.txt"

program="RPN"

inputs=(
    "5 5 +"
    "10 2 * 3 / 4 + 5 -"
    "7 3 * 2 / 1 + 6 -"
    "6 6 * 3 / 2 + 8 - 4 +"
    "2 3 * 4 / 5 + 6 * 7 - 8 9 * + 10 /"
    "-5 6 +"
    "2 0 /"
    ""
    "4"
    "+8 8 +"
    "-8 8 +"
    "8 8 8 +"
    "8 8 8 * -"
    "8 8 * 8 -"
    "2 3 * 3 / 3 * 3 5 - +"
    "(2 + 2)"
    "world apple"
    "4   6   +    /     -"
    " 4 5 +"
    "4 5 +"
    "2 3 /"
    "456456456456456 456456456456456456 +"
    "2f 3 /"
    " 2 300 /"
    " 	 	"
    "6 6 * 3 / 2 + 8 - 4.1 +"
)

# remove output_file if it exists
rm -f $output_file

# through inputs and run
for input in "${inputs[@]}"
do
	echo -e "input is: \"$input\""  >> $output_file
    ./$program "$input" >> $output_file 2>&1
	echo -e  >> $output_file
done
