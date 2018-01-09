# Exercise 1: Basic control flow

## Assignment 1: Getting started

a) Setup your development environment and create an empty project with a file ’main.cpp’.

b) Insert, compile and run the following snipped:
```
#include <iostream>
using namespace std;
int main( int argc, char** argv) {
cout << "Hello world" << endl;
}
```

c) Write a program asking the user for his/her name and birth day, month and year. Output a welcome message to the user including his name and age (The current date is not needed to be queried, you can explicitly encode it)

## Assignment 2: Numbers and Operators

a) Basic Operations:
```
int i = 10;
int j = 23;
float f = 3.141f;
double d = 2.718281828459045;
```
What is the result of the following expressions ? State the type of the result (int/float/double) and the numerical value.
```
i/j, j/i, i/2, j/2, i%2, j%2, (j/3) * 3 + j%3, f*f*5, f/d, d/f, d*i, d/i.
```
b) Basic Functions
```
int min( int a, int b ) {
    if( a < b ) {
		return a;
	} else {
		return b; 
	}
}
```

Implement also the functions max, abs (absolute value), square and mean for int. 

c) Whatistheresultof mean( min( max( 10, 1 ), abs( -9 ) ), 6 )?

## Assignment 3: Loops

A loop execute the same code several times in a row. Here is an example:
```
int a = 0;
while( a < 10 ) {
cout << "This is the " << a << " th time !" << endl;
a ++;
      
}
```
Execute and understand this program. Rewrite the while-loop with 
- a for loop
- a do .. while() loop
- a while loop where the conditional is set to true using if(...)

b) Write a function sumfirstN(n) that sums up the first 𝑛 natural numbers using a loop. (Extra:
Can you do it as well without loops and recursion ?)

c) Fibonacci-Numbers are given by the formula 𝑎_0 = 0, 𝑎_1 = 1, 𝑎_𝑛 = 𝑎_(𝑛−1) + 𝑎_(𝑛−2). Implement a function fib_loop(i) that calculates 𝑎𝑖. Implement it using a loop (e.g. for or while but without recursion).

## Assignment 4: Recursion

a) Implement the function ’fib recursion(i)’ calculating the Fibonacci numbers - this time using recursion. What are the Fibonacci numbers 𝑎_1, 𝑎_5, 𝑎_6. What happens if you calculate 𝑎_100 ?

b) Write a function to calculate the binomial coefficient using the recursion.

c) Output Pascal’s triangle1 until level 6.
