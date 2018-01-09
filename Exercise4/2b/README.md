# Exercise 4: Basic Classes

## Assignment 2: Basic Classes and Scopes

a) Shortly describe the following terms: member variable, member function, constructor, destructor, default argument, public, private.

- Member variable: is a variable (an object) that is part of a class.
- Member functions: are operators and functions that are declared as members of a class.
- Constructor: is a special member function of a class that is executed whenever we create new
objects of that class.
- Destructor: is a special member function of a class that is executed whenever an object of its
class goes out of scope or whenever the delete expression is applied to a pointer to the object
of that class.
- Default argument: is an argument to a function that a programmer is not required to specify.
- Public: anything declared in public can be used by any object within the class or outside the
class.
- Private: can only be used by the objects within the class and could not be changed through
direct access.

b) What is the output of the following code ? Please explain !
- We initialize two objects: a1(4) and a2(2)
- For a1, we pass 4 to a, then counter = 4, we
print it. The same happens with a2
- The object a1(4) calls the member function
use(), --count = 3, we print it “3 times left”
- We initialize a new object a3 with no
parameter so we use the default parameter a
= 1, then print it.
- a3 calls the use() function, print nothing
(counter=0)
- then again a1 calls use() function, and print
“2 times left”
- a3 calls the use() function, --counter = -1,
destruct it, and print “destruct A: -1”
- a1 calls the use() function, print “1 times left”
- Then destruct a2, print “destruct A: 2”
- And finally destruct a1, print “destruct A: 1”

Results:
construct A: 4 construct A: 2 3 times left construct A: 1 2 times left destruct A: -1 1 times left destruct A: 2 destruct A: 1