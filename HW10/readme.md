### Homework 10 Description

Write a program that reads in a list of integers into an array with base type `int`. Provide the facility to either read this array from the keyboard or from a file, at the user’s option. If the user chooses file input, the program should request a file name. You may assume that there are fewer than 50 entries in the array.

Your program determines how many entries there are. The output is to be a two-column list:
- The first column is a list of the distinct array elements.
- The second column is the count of the number of occurrences of each element.

The list should be sorted on entries in the first column, from largest to smallest.

#### Example
For the input:

-12 3 -12 4 1 1 -12 1 -1 1 2 3 4 2 3 -12


The output should be:

N Count 
4 2 
3 3 
2 2 
1 4 
-1 1 
-12 4
