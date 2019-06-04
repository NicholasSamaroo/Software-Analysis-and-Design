i. All parts of the assignment were completed INCLUDING the Extra credit

ii. I have encountered no bugs in my program

iii. RUN THE PROGRAM AS MENTIONED IN THE ASSIGNMENT PDF
	FIRST make clean THEN make all
	DO ./optimal_multiplications dimensions_file.txt
---------------------------------------------------------
PROGRAM INSTRUCTIONS

Given the sizes of a number of matrices, calculate the optimal multiplication ordering using dynamic
programming. The sizes will be presented in a file containing dimensions in a sequence:
For example
dimensions_file.txt can be
50
10
40
30
5

That means that c0 = 50, c1 = 10, c2 = 40, c3 = 30, and c4 = 5. Therefore the matrices to be multiplied
have sizes:
Matrix 1: 50 x 10
Matrix 2: 10 x 40
Matrix 3: 40 x 30
Matrix 4: 30 x 5

Write a program that runs as follows:
./optimal_multplications dimensions_file.txt
The program should produce the optimal number of multiplications.
For extra credit also produce the optimal ordering as well.
