/* Data Types in C (Primitive)
- when creating variables we need to first specify "what data type" it is
- generally we have 5 primary data types (int, char, float, double, void)

1. int
- data type that stores integers like -1, 0, 1, 2, 3, etc.
- integers always take 4 bytes of memory (32bits)
- range of values for integers is limited -2^31 - 2^31 (2 billion)

* unsigned int
- unsigned is a qualifier that can be applied to certain data types, like int, which doubles the positive range of variables while disabling any negative values
-> 0 to 2^31

2. char
- character data type used for variables that store single character
- characters always take 1 byte of memory (8bit)
- ASCII standard is a standard that gives a numeric value to a specific character

3. float (decimal)
- float (decimal) data type is used for variables that will store floating-point values, known as real numbers
- floating points take 4 bytes of memory (32bits)
- floats are limited in precision

4. double (decimal)
- double data type is used for variables that will store floating-point values, like real numbers
- difference is that it's "double precision", taking 8 bytes (64bits)
- allows to specify much more float-point numbers

5. void (null)
- void is a type, NOT A DATA TYPE
- functions have a "void" return type, which means they don't return a value
- parameter of a function can also be void (no arguments passed)
- printf() -> common function because it doesn't return a value back

6. bool
- data type used for variables that store a boolean value. true or false only
- need #include <cs50.h> library to use bool data type

7. string
- data type used for variables that store a series of characters called a string
- strings include words, sentences, paragraphs, etc.
- need #include <cs50.h> library to use string data type

--

Create a variable
- specify data type and name the variable
int num;
char letter;
- can create multiple variables of same type
int height, width;
float sqrt2, sqrt3, pi;

How to use a variable
int number; // declaration
number = 16; // assignment of variable
char letter; // declaration
letter = 'a'; // assignment of variable
int num = 17; initialize (declare) variable

// Loops

1. while loop (infinite loop)
- when we have a while loop with "true" it runs infinitely
- we can "break" out of a while loop when we use "break" or just kill the program

2. do-while loop

3. for loop

*/ 