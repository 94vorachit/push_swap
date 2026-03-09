*This Project Has Been Created As Part Of The 42 Curriculum By Vorhansa*

## Description

Push Swap is a sorting algorithm implementation project and part of the Codam/school 42 core curriculum. The project tasks the students with writing a program in C that takes an unsorted list of integers as input and sorts them in ascending order using only two "stacks" and a limited set of operations. The aim of the project is to test the student's understanding of various sorting algorithms, their corresponding complexities and data structures, and the student's ability to implement this in code.

**Push_Swap Rules and Grading**

The program is only allowed two stacks to work with, stack A and stack B. All the numbers are initially added to stack A, and B is empty.

The possible actions are:

* ```pa``` (push A): Take the first element at the top of B and put it at the top of A. Do nothing if B is empty.
* ```pb``` (push B): Take the first element at the top of A and put it at the top of B. Do nothing if A is empty.
* ```sa``` (swap A): Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.
* ```sb``` (swap B): Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.
* ```ss```: ```sa``` and ```sb``` at the same time.
* ```ra``` (rotate A): Shift all elements of stack A up by 1. The first element becomes the last one.
* ```rb``` (rotate B): Shift all elements of stack B up by 1. The first element becomes the last one.
* ```rr```: ```ra``` and ```rb``` at the same time.
* ```rra``` (reverse rotate A): Shift all elements of stack A down by 1. The last element becomes the first one.
* ```rrb``` (reverse rotate B): Shift all elements of stack b down by 1. The last element becomes the first one.
* ```rrr``` : ```rra``` and ```rrb``` at the same time.

* For maximum project validation (100%) and eligibility for bonuses, you must:
    * Sort 100 random numbers in fewer than 700 operations. 'mcom'
    * Sort 500 random numbers in no more than 5500 operations.
* For minimal project validation (which implies a minimum grade of 80%), you can succeed with different averages:
    * 100 numbers in under 1100 operations and 500 numbers in under 8500 operations '42Y'
    * 100 numbers in under 700 operations and 500 numbers in under 11500 operations
    * 100 numbers in under 1300 operations and 500 numbers in under 5500 operation

## Instrctions



## Resources
https://github.com/arommers/push_swap/tree/master 
https://github.com/mcombeau/push_swap/tree/main 
https://github.com/hu8813/push_swap/tree/main
https://github.com/42YerevanProjects/push_swap/tree/master
https://www.youtube.com/watch?v=4dMsuxfqufg
https://42-cursus.gitbook.io/guide
https://oyhoyhk.github.io/


## Additional

$@: The filename representing the target.
$%: The filename element of an archive member specification.
$<: The filename of the first prerequisite.
$?: The names of all prerequisites that are newer than the target, separated by spaces.
$^: The filenames of all the prerequisites, separated by spaces. This list has duplicate filenames removed since for most uses, such as compiling, copying, etc., duplicates are not wanted.