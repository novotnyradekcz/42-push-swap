# 42 push_swap

The push_swap project from the 42 core curriculum, completed in Prague in November 2023.

Imagine you have two stacks that can hold numbers, stack **a** and stack **b**, and two following set of instructions to manipulate the numbers on the stack:

- `sa` (swap **a**): Swap the first 2 elements at the top of stack **a**. Do nothing if there is only one or no elements.

- `sb` (swap **b**): Swap the first 2 elements at the top of stack **b**. Do nothing if there is only one or no elements.

- `ss`: `sa` and `sb` at the same time.

- `pa` (push **a**): Take the first element at the top of **b** and put it at the top of **a**. Do nothing if **b** is empty.

- `pb` (push **b**): Take the first element at the top of **a** and put it at the top of **b**. Do nothing if **a** is empty.

- `ra` (rotate **a**): Shift up all elements of stack **a** by 1. The first element becomes the last one.

- `rb` (rotate **b**): Shift up all elements of stack **b** by 1. The first element becomes the last one.

- `rr`: `ra` and `rb` at the same time.

- `rra` (reverse rotate **a**): Shift down all elements of stack **a** by 1. The last element becomes the first one.

- `rrb` (reverse rotate **b**): Shift down all elements of stack **b** by 1. The last element becomes the first one.

- `rrr`: `rra` and `rrb` at the same time.

### Mandatory part

Pass a list of 32-bit integers to the `push_swap` program as arguments, which represent numbers on the stack **a**, order from top to bottom. The program will print out a set of instructions to order the stack with the smallest number being on the bottom and the largest on top. In case of incorrectly formatted input, it will simply print `Error`.

Example:
```
$>./push_swap 8 -1 6 3 20
pb
pb
pb
rb
pb
rb
rb
pa
pa
pa
pa
$>./push_swap 8 -1 6 3 twenty
Error
```

### Bonus part

If you feed the output of the `push_swap` to the `checker` (using the pipe `|` operator, or simply typing the intructions into the standard input, one on each line, ending with **Ctrl + D**) program while passing the same list of numbers as arguments, the program will print `OK`, if the instructions do indeed order the stack correctly, or `KO`, if they don't. In case of incorrectly formatted input, it will simply print `Error`.

Example:
```
$>./push_swap 8 -1 6 3 20 | ./checker 8 -1 6 3 20
OK
$>./push_swap 8 -1 6 3 20 | ./checker 8 -1 6
KO
$>./push_swap 8 -1 6 3 20 | ./checker 8 -1 6 3 twenty
Error
$>./push_swap 8 -1 6 3 twenty | ./checker 8 -1 6 3 20
Error
```
