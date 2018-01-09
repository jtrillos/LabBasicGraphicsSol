# Exercise 3: Pointers and Memory Management

## Assignment 1: Pointers & References

a) Explain the terms variable, reference and pointer. What is the semantic difference between reference and pointer ? What is the difference for the compiler ?

- Variable: A variable is a location in your computer's memory in which you can store a value and from which you can later retrieve that value.
- Reference: A reference variable is an alias which is another name for an already existing variable. Once a reference is initialized with a variable, either the variable name or the reference name may be used to refer to the variable.
- Pointer: A pointer is a variable which can store a piece of data. The pointer’s value is the address of another variable.

Difference between reference and pointer:
- We cannot have NULL references. We must always be able to assume that a reference is connected to a legitimate
piece of storage.
- Once a reference is initialized to an
object, it cannot be changed to refer another. Pointers in the other hand can be pointed to another object at any time.
- A reference must be initialized when it is created. In the case of pointers, they can be initialized at any moment.

Difference for the compiler:
- The C++ standard is very careful to avoid
dictating how a compiler must implement references, but every C++ compiler implements references as pointers
- Compilers often elide references entirely, especially when they're locals

b) Understand and explain the following code snippet
```
double number = 10.0;
double& reference(number); // reference to variable number
double* pointer(&number); // pointer to variable number
std::cout << &number << "; " << &reference << "; " << pointer << std::endl;
std::cout << number << "; " << reference << "; " << *pointer << std::endl;
*pointer = 15;
std::cout << number << "; " << reference << "; " << *pointer << std::endl;
reference = 50;
std::cout << number << "; " << reference << "; " << *pointer << std::endl;
number = 10;
std::cout << number << "; " << reference << "; " << *pointer << std::endl;
```
- Explanation:
	- We declared a simple variable (double) number to 10.0, and create the reference and the pointer for the variable number, as you can see below:
	- We print the reference of the variable number, the reference of reference and the pointer, the result is the memory location of the variable number (0x61fe90; 0x61fe90; 0x61fe90)
	- We print then, the number, the reference and the point of the pointer. In this case, the result is a number (10; 10; 10)
	- Then we initialized pointer as 15, and print the results (15; 15; 15)
	- The same we do with reference, we initialized it in 50, and the result is (50; 50; 50)
	- And then the number = 10, the result again is (10; 10; 10)

- In resume:
	**number** is the value stored in the variable double 

	**pointer** is the address stored in pointer variable 

	***pointer** is the value stored in pointer variable 

	**&number** is the address stored in the variable double

	**&reference** is the address stored in the reference variable

	**reference** is the value stored in the reference variable

c) Explain *call by value*, *call by reference* and *call by pointer*. What exactly is done on calling? Give detailed runtime costs for large Objects? Which objects can be written to?
- call by value: Call by value means taking a value, you will get the copy of the instance. And in this case changes of parameter variable will not influence on variable that was in call method.
- call by reference: Call by reference passes a reference to an object, and change the value of the variable.
- call by pointer: Call by pointer passes a pointer to an object, and change the value of the variable.

d) Understand and explain the following code. What are the results? Is there undefined behavior?
- We have an array with 5 positions (0 to 4)
and it is initialized.
- Then we create a pointer variable called
begin with it is pointing the array.
- We print the position 0, 1 and 2 of begin.
- Then we create a pointer variable called
end that is pointing to array + 5.
- We create a variable diff that is the end –
begin.
- Then we do the operation diff = diff /2.
- We create a variable value that contains
the value of (begin + 1) + value of (end –
(diff)).
- And last we print value and the value of
end.

e) Understand and explain how the elements of the array are accessed without using operator[]:
- In the first while loop we are printing the
values of the array or in this case of the pointer begin; what the program does is taking the value of each position +1 (ptr
++)
- For the second while loop we are printing
the values of the pointer end; but in this case we are printing it backwards (-- ptr)

f) Below are three versions for printing array backwards. Which versions work and what problems do the others have?

The last version or last for loop works correctly.
- The problem for the first loop is that we are not saying that the ptr is printing the position – 1 but not the actual position and then the next one, in this case 50 is not printed.
- The problem for the second loop is that we are saying that ptr must be different as begin, in this case we are not printing the begin position that is 10.