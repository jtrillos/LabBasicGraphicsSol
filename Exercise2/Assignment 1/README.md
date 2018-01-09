# Exercise 2: Basic Data types

## Assignment 1: Number Ranges

a) Explain the terms signed and unsigned. How are negative numbers stored?
- Signed: Allow you to represent numbers both in positive and negative ranges
- Unsigned?: Allow you to represent numbers in positive.


Nowadays, negative numbers are stored in what is called two’s complement.

In two’s complement representation, positive numbers are represented as themselves and in the case of negative numbers are represented by the two’s complement of their absolute value.

The first bit indicates the sign and the remaining bits count down from -1, with -1 represent as all “1” bits:

7: 0111 6: 0110 5: 0101 4: 0100 3: 0011 2: 0010 1: 0001 0: 0000 -1: 1111 -2: 1110 -3: 1101 -4: 1100 -5: 1011 -6: 1010 -7: 1001 -8: 1000

b) State the interval of all constructible number types with char, int, long, signed, unsigned.

- Signed: 
	- char: -128 to 127
	- int: –2,147,483,648 to 2,147,483,647
	- long: –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
- Unsigned:
	- char: 0 to 255
	- int: 0 to 4,294,967,295
	- long: 0 to 18,446,744,073,709,551,615

c) What happens if you leave this interval? What is the result of Listing 1 and 2? 
- Listing 1:
```
char res = 0;
for( int c = 0; c < 1000; ++ c ) {
	res = res + 1; 
}
cout << (int) res << std::endl;
```
When c=128 then rest=-128/128 then after that the rest variable is going to subtract until c=1000. And the result is -24/232.
- Listing 2:
```
int res = 0;
for(unsigned char c=100; c>=0; --c){
	res = res + 1;
}
cout << (int) res << std::endl;
```
When c = 0, res = 100, then It starts with c=255, rest=101. Now when c=0, res=356, and starts again with c=255, rest=357 and so on, creating a infinite loop.