# Push Swap

Because Swap_push isn’t as natural

The goal is to write a program in C called push_swap which calculates and displays on the standard output the smallest program, made of Push swap language instructions, that sorts the integers received as arguments

## Instruction sets

| Code  | Instruction                         | Action                                                 |
| ----- | ----------------------------------- | ------------------------------------------------------ |
| `sa`  | swap a                              | swaps the 2 top elements of stack a                    |
| `sb`  | swap b                              | swaps the 2 top elements of stack b                    |
| `ss`  | swap a + swap b                     | both `sa` and `sb`                                     |
| `pa`  | push a                              | moves the top element of stack b at the top of stack a |
| `pb`  | push b                              | moves the top element of stack a at the top of stack b |
| `ra`  | rotate a                            | shifts all elements of stack a from bottom to top      |
| `rb`  | rotate b                            | shifts all elements of stack b from bottom to top      |
| `rr`  | rotate a + rotate b                 | both `ra` and `rb`                                     |
| `rra` | reverse rotate a                    | shifts all elements of stack a from top to bottom      |
| `rrb` | reverse rotate b                    | shifts all elements of stack b from top to bottom      |
| `rrr` | reverse rotate a + reverse rotate b | both `rra` and `rrb`                                   |

## Algorithm

The algorithm I employ is an optimization of an existing algorithm. Initially, I push each number onto stack B in such a way that all numbers lower than the median are on one side, and those higher are on the other, until there's only 3 remaining on stack A. Consequently, I obtain a somewhat sorted list.

```
1 7 6 3 8 4 5 2
```
Here is an example of this part of the algorithm.
|Stack a| Stack b  |
|--|--|
| 0 | 0 |
| 0 | 0 |
| 0 | 0 |
| 0 | 8 |
| 0 | 3 |
| 4 | 1 | 
| 5 | 7 |
| 2 | 6 |

Here, the median is 4.  Therefore, I will place 1, 3 on one side of stack B and 8, 7, 6 on the other.  Afterward, I sort stack A, which is quite straightforward given its small size of 3. Finally I proceed with an optimized insertion sort, aiming for the best possible cost.

For example **8** asks one move : `pa`
If i can find a better cost i will search for it.

|Stack a| Stack b  |
|--|--|
| 0 | 0 |
| 0 | 0 |
| 0 | 0 |
| 0 | 8 |
| 0 | 3 |
| 2 | 1 | 
| 4 | 7 |
| 5 | 6 |

Then, **3** requests to be positioned between **2** and **4**, which entails 3 operations: `ra`  `ra`  `pa`. However, the algorithm achieves a more efficient cost by placing **1** in the correct positions with only 2 operations: `rr`  `pa`.

|Stack a| Stack b  |
|--|--|
| 0 | 0 |
| 0 | 0 |
| 0 | 0 |
| 1 | 0 |
| 2 | 0 |
| 4 | 7 | 
| 5 | 6 |
| 8 | 3 |

Finally it sorts everything by pushing the smallest number at the top.

## Performance of the Algorithm

To calculate the best performance i use this tester found on Github. https://github.com/SimonCROS/push_swap_tester

My push_swap sorts

    3 numbers with maximum 2 instructions,
    4 numbers with maximum 7 instructions,
    5 numbers with maximum 12 instructions,
    100 numbers with maximum 640 instructions => 5 points,
    500 numbers with maximum 4700 instructions => 5 points.
   
My algorithm allow a complete 125%, including the bonus part.

# Bonus

The program, named checker, takes a formatted list of integers as an argument representing stack A. If no argument is provided, it stops without displaying anything. The program reads instructions from the standard input, executes them on the given stack, and checks if, after execution, stack a is sorted and stack b is empty. If so, it outputs "OK"; otherwise, it outputs "KO". In case of errors such as non-integer arguments, integers exceeding the limit, duplicates, or incorrectly formatted instructions, it outputs "Error" on the standard error.

# Credits

* [**Contré Yavin**](https://github.com/TheRedShip) : Creator of the project.
