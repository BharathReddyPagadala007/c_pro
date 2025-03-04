# Linked List Project

This project is an implementation of various operations on a singly linked list in C. It covers basic linked list operations, utility functions, and some advanced techniques that are commonly encountered in technical interviews. The project is organized with a modular structure to ensure clarity and maintainability.

## Table of Contents
1. [Project Structure](#project-structure)
2. [Linked List Operations](#linked-list-operations)
3. [Building the Project](#building-the-project)
4. [Running the Program](#running-the-program)
5. [Future Improvements](#future-improvements)

## Project Structure

The project is organized into multiple directories to keep the code modular and maintainable. Here is the folder structure:


### Directory Descriptions
- `build/`: Directory where the compiled output files are placed.
- `inc/`: Contains all the header files. These define the data structures and function prototypes.
- `src/`: Source files containing the implementation of various linked list functions.
- `Makefile`: Used for building the project. Supports compiling, cleaning, and running the program.
- `README.md`: Documentation for the project.

## Linked List Operations

### 1. Basic Linked List Operations
These functions form the core of the linked list implementation:
- **Node Creation**: Creates a new node.
- **Insert at Beginning/End**: Adds a node at the start or end of the list.
- **Delete Node**: Removes a node with a specific value.
- **Print List**: Displays the entire list.
- **Free List**: Releases all memory associated with the list.

### 2. Advanced Operations
These operations provide additional functionality:
- **Reverse the List**: Reverses the order of the nodes.
- **Detect a Loop**: Checks whether a cycle exists in the list using Floyd's Cycle Detection algorithm.
- **Merge Two Sorted Lists**: Merges two sorted lists into one sorted list.
- **Find the Middle Element**: Finds the middle node of the list.
- **Find the N-th Node from the End**: Locates the N-th last node.

### 3. Utility Functions
These functions help perform common tasks:
- **Find Maximum and Minimum**: Returns the largest and smallest values in the list.
- **List Length**: Counts the number of nodes in the list.
- **Sum and Average of Elements**: Computes the sum and average of the node values.
- **Remove Duplicates**: Removes duplicate values from a sorted list.

## Building the Project

To compile the project, you need to have `gcc` installed on your system. The build process uses a `Makefile` to manage the compilation.

### Build Steps
1. Open a terminal in the project's root directory.
2. Run the following command:
   ```bash
   make

