# Monty ByteCode Interpreter
## Description
This is a simple Monty ByteCode interpreter written in C. Monty is a minimalistic programming language that uses a stack data structure. This interpreter can read Monty ByteCode files and execute the specified instructions.

* Monty byte code files:
Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument

All your files will be compiled on `Ubuntu 22.04.2 LTS` using `gcc`, using the options `-Wall -Werror -Wextra -pedantic -std=c89`

## Installation
### Clone the repository:
```
git clone https://github.com/Ali-Mahmoud98/monty.git
```
### Usage:
1. Enter monty directory
```
cd monty
```
2. Compile:
```
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```
3. Run:
```
./monty byteCodes/file.m
```

## The monty program
* Usage: monty file
    * where file is the path to the file containing Monty byte code
* If the user does not give any file or more than one argument to your program, print the error message `USAGE: monty file`, followed by a new line, and exit with the status `EXIT_FAILURE`
* If, for any reason, it’s not possible to open the file, print the error message `Error: Can't open file <file>`, followed by a new line, and exit with the status EXIT_FAILURE
    * where <file> is the name of the file
* If the file contains an invalid instruction, print the error message `L<line_number>: unknown instruction <opcode>`, followed by a new line, and exit with the status EXIT_FAILURE
    * where is the line number where the instruction appears.
    * Line numbers always start at 1
* The monty program runs the bytecodes line by line and stop if either:
    * it executed properly every line of the file
    * it finds an error in the file
    * an error occured
* If you can’t malloc anymore, print the error message `Error: malloc failed`, followed by a new line, and exit with status `EXIT_FAILURE`.
* You have to use malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …)

## Monty Instructions
`push`, `pall`, `swap`, `pop`, `pint`, `add`, `nop`, `sub`, `div`, `mul`, `mod`, `pchar`, `pstr`, `rotl`, `rotr`, `stack`, `queue`.
* the comment is done by using `#`
### The push opcode
The opcode `push` pushes an element to the stack.
* Usage: `push <int>`
    * where <int> is an integer
* if <int> is not an integer or if there is no argument given to push, print the error message `L<line_number>: usage: push integer`, followed by a new line, and exit with the status `EXIT_FAILURE`
    * where is the line number in the file
### The pall opcode
The opcode pall prints all the values on the stack, starting from the top of the stack.

Example of using `push` and `pall`:
```
ali@DESKTOP-U1U0AC7:~/monty$ cat -e byteCodes/00.m
push 1$
push 2$
push 3$
pall$
ali@DESKTOP-U1U0AC7:~/monty$ ./monty byteCodes/00.m
3
2
1
ali@DESKTOP-U1U0AC7:~/monty$
```
