# MathParser

School project. A simple expression evaluator, written in C++.

## Building the project

This project uses CMake. Run the following commands to generate
Makefiles and build the project, assuming that you have CMake installed, 
as well as a valid C++20 compiler:

```
mkdir build
cd build
cmake ..
make
```

This will generate two executables, MathRepl and MathTests.

In order to use the REPL, run MathRepl.

(MathTests may not work, due to some file path issues).

## Usage

MathParser is capable of solving simple expressions, made up of a series of
additions, subtractions, multiplications, divisions, powers and parenthesis:

```
> 1 + 1
Evaluated: 2
> 2 + 3 * 4
Evaluated: 14
> (2 + 3) * 4
Evaluated: 20
> 3 ^ 3 + 1
Evaluated: 28
```

The REPL is also capable of storing expression results in variables, which can
then be used later in calculations:

```
> x = 3 ^ 2 + 5
Evaluated: 14
> x
Evaluated: 14
> 3 * x + 1
Evaluated: 43
> x = 2 * x
Evaluated: 28
> x
Evaluated: 28
```

### To be implemented

The following features are not yet implemented, but are to be added in the future:

[-] Functions and function calls
[-] Floating point numbers
[-] The `-x` unary operator
