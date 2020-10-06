# ICPC Archive - #7794 - The Great Thief

A solution to ICPC's "The Great Thief" problem.
At the time of writing it is believed that this program exceeds the time limit, however it produces correct results.
Since it is determined to produce correct results, an output file has been included with the expected output; and
an input file with cases to 1000000.

## Compilation

The program is compiled with g++ with the following flags:

```~$ g++ -Wall -g -pedantic -pedantic-errors -std=c++11 -o <problemname> <problemname>.cpp```

and all programs has been compiled without compiler complaints, and ran with the corresponding input file.
To run with the input file:
```~$ ./<program> < input.txt```

## Description

Once upon a time, there was a great thief who used the codename FWX. He lived in a two-dimensional world named Flat Land. In this land, houses are built only on the grid locations having integer coordinates, e.g., for a square Flat Land with a highest coordinate of ```n```, there can be houses only at ```(0,0),(0,1),...,(0,n),(1,0),(1,1),...,(1,n),(2,0),(2,1),...,(2,n),...,(n,0),(n,1),...,(n,n)```. There are only non-negative coordinates in Flat Land. FWX liked the time between 4AM to 5AM for his work when all the inhabitants were sound asleep. In some houses, he slipped and fell with all the things he took in his bag, making a loud sound and knocking himself out. All the inhabitants of the house were awakened and they called the police. FWX was a great thief, so no jail could keep him for a long time. He broke out of jail and thought about why he was caught only in some particular houses. Then he discovered that there is a guard in the house at ```(0, 0)``` who can shoot slippery material in a straight line from ```(0, 0)``` which hits only the first house on that line and makes that house slippery. When the guard fires, say, along the line ```x = y```, it makes the house at ```(1, 1)``` slippery, but houses at ```(2, 2), (3, 3)```, etc. are not affected. Similarly, along theline ```2y = 5x, (2, 5)```becomes slippery but not ```(4, 10)```. The guard has an unlimited supply of slippery material and fires in any direction he wishes as often as he likes.

Your team is to write a program that will find the number of houses which are not safe for the great thief FWX, assuming that the guard has shot slippery material on every possible line. Remember, ```(0, 0)``` is not safe because of the guard

### Input

For each case, print a line containing the number of unsafe houses in that Flat Land on a separate line with no extra spaces or leading zeroes.

### Sample Input

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
1000000

### Sample Output

4
6
10
14
22
26
38
46
58
66
86
94
118
130
146
162
607927104786