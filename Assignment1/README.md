# Data Structures Assignment 3

This repository contains solutions for Assignment 3 of the Data Structures course (CS 2001) at the National University of Computer and Emerging Sciences, Lahore Campus.

## Assignment Overview

The assignment consists of two main problems:

1. **Josephus Problem**: A historical counting-out problem implemented using a circular queue data structure with graphical visualization.
2. **Radix Sort**: Implementation of radix sort algorithm for both integer and string data types using queue data structures.

## Files Included

- `Q1.cpp`: Solution for the Josephus Problem with SFML graphical interface
- `Q2.cpp`: Solution for Radix Sort implementation (both integer and string versions)
- `soldier.png`: Image asset used in the Josephus Problem visualization
- `Assignment 3.pdf`: Original assignment instructions and requirements

## How to Run

### Josephus Problem (Q1.cpp)

1. Ensure you have SFML library installed
2. Compile with: `g++ Q1.cpp -o josephus -lsfml-graphics -lsfml-window -lsfml-system`
3. Run with: `./josephus`
4. Enter values for N (number of soldiers) and K (counting interval) when prompted

### Radix Sort (Q2.cpp)

1. Compile with: `g++ Q2.cpp -o radixsort`
2. Run with: `./radixsort`
3. The program will demonstrate sorting for both integers and strings

## Key Features

### Josephus Problem Implementation
- Uses circular queue data structure  
- Graphical visualization of soldiers in a circle  
- Dynamic adjustment of circle radius as soldiers are eliminated  
- SFML-based graphical interface  

### Radix Sort Implementation
- Template-based implementation  
- Supports both integer and string sorting  
- Uses an array of queues for sorting buckets  
- Handles negative numbers in integer sorting  

## Academic Integrity

As per the assignment instructions:
- This code is my own original work  
- Plagiarism is strictly prohibited  
- Late submissions are not allowed  

## Dependencies

- SFML (for Q1 graphical interface)  
- C++11 or later  

## Author

M Waiz Shabbir
BS(CS/SE)  
National University of Computer and Emerging Sciences, Lahore Campus  
Fall 2023  
