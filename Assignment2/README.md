# Data Structures Assignment 2

This repository contains solutions for Assignment 2 of the Data Structures course (CS 2001) at the National University of Computer and Emerging Sciences, Lahore Campus.

## Assignment Overview

The assignment consists of three main problems:

1. **XML Tag Matching**: Implementation of a stack-based XML parser to validate tag and quote matching
2. **Invertible Stack**: Implementation of a stack with O(1) flip operation
3. **Undo Stack**: Implementation of a stack with limited memory (last 100 elements)

## Files Included

- `22L-6991-Q1.cpp`: Solution for XML Tag Matching problem
- `22L-6991-Q2.cpp`: Solution for Invertible Stack problem
- `22L-6991-Q3.cpp`: Solution for Undo Stack problem
- `DS Assignment#2.pdf`: Original assignment instructions and requirements

## Problem Details and Solutions

### 1. XML Tag Matching (Q1)

**Problem Statement**:  
Implement a stack-based XML parser that validates:
- Proper nesting of XML tags
- Matching quotes in attributes
- Proper XML prolog and comments
- Reports errors with line numbers

**Key Features**:
- Template-based Stack implementation using singly linked list
- XMLData class to store tag information and line numbers
- Comprehensive error checking for:
  - Missing or mismatched tags
  - Unclosed quotes in attributes
  - Invalid XML prolog
  - Improper comment syntax
- Line-by-line parsing with accurate error reporting

**How to Run**:
1. Compile: `g++ 22L-6991-Q1.cpp -o xmlvalidator`
2. Run: `./xmlvalidator`
3. Ensure `test.txt` contains the XML to be validated

### 2. Invertible Stack (Q2)

**Problem Statement**:  
Implement a stack with O(1) flip operation that logically inverts the stack order without physically rearranging elements.

**Key Features**:
- Circular array implementation
- O(1) flip operation using flag-based logic
- Dynamic resizing:
  - Doubles capacity when full
  - Halves capacity when less than half full
- Maintains proper element ordering after multiple flips
- Comprehensive test cases in main()

**How to Run**:
1. Compile: `g++ 22L-6991-Q2.cpp -o invertiblestack`
2. Run: `./invertiblestack`

### 3. Undo Stack (Q3)

**Problem Statement**:  
Implement a stack that remembers only the last 100 elements (for undo functionality).

**Key Features**:
- Doubly-linked list implementation
- Automatic removal of oldest elements when capacity exceeds 100
- Efficient push/pop operations
- "Forget" operation to remove oldest elements
- Test cases demonstrating the 100-element limit

**How to Run**:
1. Compile: `g++ 22L-6991-Q3.cpp -o undostack`
2. Run: `./undostack`

## Common Implementation Details

All solutions feature:
- Template-based implementations for generic data handling
- Proper memory management with destructors
- Comprehensive error handling
- Clean, commented code with proper indentation
- Test cases in main() demonstrating functionality

## Academic Integrity

As per the assignment instructions:
- This code is my own original work
- Plagiarism is strictly prohibited
- Late submissions are not allowed

## Compilation and Requirements

- C++11 or later compatible compiler
- No additional libraries required
- For Q1, input XML file should be named `test.txt`

## Author

M Waiz Shabbir
BS(CS/SE)  
National University of Computer and Emerging Sciences, Lahore Campus  
Fall 2023
