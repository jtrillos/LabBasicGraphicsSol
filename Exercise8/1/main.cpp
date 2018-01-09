#include <iostream>

using namespace std;

int main()
{
    /**
      Assignment 1:
      a)
       Single precision:
       Usually used to represent the "float" type in the C language family.
       This is a binary format that occupies 32 bits (4 bytes) and its significand has a precision of 24 bits (about 7 decimal
       digits).
       Double precision:
       Usually used to represent the "double" type in the C language family.
       This is a binary format that occupies 64 bits (8 bytes) and its significand has a precision of 53 bits (about 16 decimal
       digits).

      b)
       Any integer with absolute value less than 2^24 can be exactly represented in the single precision format.
       Any integer with absolute value less than 2^53 can be exactly represented in the double precision format.

      c)
       Addition and Subtraction (most errors):
       First represent the numbers with the same exponent, and then rounding and normalization

       Multiplication and Division:
       To multiply, the significands are multiplied while the exponents are added, and the result is rounded and normalized.
       Division is accomplished by subtracting the divisor's exponent from the dividend's exponent, and dividing the dividend's
       significand by the divisor's significand.
     */
    return 0;
}
