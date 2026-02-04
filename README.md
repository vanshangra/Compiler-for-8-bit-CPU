# Compiler for 8-bit CPU

A simple compiler written in C that translates a custom high-level programming language into assembly code for an 8-bit CPU architecture.

## Overview

This project implements a basic compiler consisting of a lexical analyzer (lexer), parser, and code generator. It processes source code written in a simple programming language and generates assembly instructions suitable for an 8-bit CPU.

## Features

- **Lexical Analysis**: Tokenizes source code into meaningful tokens
- **Parsing**: Builds an Abstract Syntax Tree (AST) from tokens
- **Code Generation**: Converts AST into assembly code for 8-bit CPU
- **Variable Declarations**: Support for integer variable declarations
- **Arithmetic Operations**: Addition and subtraction operations
- **Conditional Statements**: Basic `if` statement support
- **Assignment Statements**: Variable assignment with expressions

## Project Structure

```
.
├── main.c                  # Main entry point of the compiler
├── lexer.c                 # Lexical analyzer implementation
├── parser.c                # AST node structure definitions
├── parserimplementation.c  # Parser implementation
├── generation.c            # Assembly code generation
├── input.txt               # Sample input source file
└── LICENSE                 # Apache License 2.0
```

## Supported Language Syntax

The compiler supports a simple C-like syntax:

### Variable Declarations
```c
int x;
int y;
int z;
```

### Assignments
```c
x = 5;
y = 8;
z = x + y;
```

### Conditional Statements
```c
if(z != 15) {
  c--;
}
```

### Supported Operators
- Arithmetic: `+`, `-`
- Comparison: `==`, `!=`
- Assignment: `=`

## Building the Compiler

To compile the project, use a C compiler such as GCC:

```bash
gcc main.c lexer.c parser.c parserimplementation.c generation.c -o compiler
```

## Usage

1. Create or modify the `input.txt` file with your source code
2. Run the compiler:
```bash
./compiler
```

3. The compiler will read from `input.txt` and output the generated assembly code to the console

## Example

**Input** (`input.txt`):
```c
int x;
int y;
int z;
x=5;
y=8;
z=x+y;

if(z!=15){
  c--;
}
```

**Output** (Assembly):
```
Assembly code generated from simpleLang
DECLARE x
ASSIGN x
...
```

## Components

### Lexer (lexer.c)
The lexer performs lexical analysis by reading the source file character by character and converting it into tokens. It recognizes:
- Keywords: `int`, `if`
- Identifiers: variable names
- Numbers: integer literals
- Operators: `+`, `-`, `=`, `==`, `!=`
- Delimiters: `{`, `}`, `;`, `(`, `)`

### Parser (parser.c, parserimplementation.c)
The parser takes the token stream from the lexer and builds an Abstract Syntax Tree (AST). It implements a recursive descent parser that handles:
- Variable declarations
- Assignment statements
- Arithmetic expressions
- Conditional statements

### Code Generator (generation.c)
The code generator traverses the AST and emits assembly instructions for an 8-bit CPU. It generates appropriate assembly code for:
- Variable declarations
- Arithmetic operations (ADD, SUB)
- Assignments
- Conditional branches (CMP, JNZ)

## AST Node Types

The compiler recognizes the following AST node types:
- `NODE_VAR_DECL`: Variable declaration
- `NODE_ASSIGN`: Assignment statement
- `NODE_ARITH_OP`: Arithmetic operation
- `NODE_CONDITIONAL`: Conditional statement (if)

## Token Types

Supported token types include:
- `TOKEN_IDENTIFIER`: Variable names
- `TOKEN_NUMBER`: Numeric literals
- `TOKEN_INT`: 'int' keyword
- `TOKEN_IF`: 'if' keyword
- `TOKEN_ASSIGN`: Assignment operator (=)
- `TOKEN_PLUS`: Addition operator (+)
- `TOKEN_MINUS`: Subtraction operator (-)
- `TOKEN_EQUAL`: Equality operator (==)
- `TOKEN_LBRACE`, `TOKEN_RBRACE`: Curly braces
- `TOKEN_SEMICOLON`: Statement terminator

## Limitations

This is a basic compiler implementation with the following limitations:
- Limited data types (only integers)
- Basic arithmetic operations (addition and subtraction only)
- Simple control flow (if statements without else)
- No function definitions or calls
- No loops
- No advanced operators (multiplication, division, modulo, etc.)

## Future Enhancements

Potential improvements could include:
- Support for more data types (float, char, etc.)
- Additional operators (*, /, %, etc.)
- Loop constructs (for, while)
- Function definitions and calls
- Else clauses for if statements
- More sophisticated error handling and reporting
- Optimization passes
- Symbol table management
- 

## Contributing

Contributions are welcome! Feel free to submit issues or pull requests to improve the compiler.

## Author

Created by vanshangra
