# CS332HW3
-name: Colin Mabry

-blazerid:ctmabry
## Overview
This program manipulates files and manages multiple child processes to perform tasks on files in a specified directory. It traverses the directory, retrieves information about each file, and prints the file name, size, and word count (for .txt files) in separate child processes.

## Features
- Accepts a directory as a command-line argument.
- Prints the file name, size, and word count (for .txt files) for each file in the directory.
- Creates a child process for each file to perform the above tasks.
- Waits for all child processes to be completed before exiting.
- Implements basic error handling for invalid directories, inaccessible files, and failed process creation.

## Requirements
- A POSIX-compliant operating system (Linux, macOS).
- GCC (GNU Compiler Collection) for compilation.

## Installation
1. Clone the repository or download the source code.
2. Navigate to the directory containing the source code.
3. Compile the program using the following command:
gcc -o HW3 HW3.c

## Usage
To run the program, use the following command:
./Hw3 <directory>

an example is if you have a file called "test_dir", you would replace <directory> with it. This will read out the word number count, and name of the files in the directory, and will give you the byte count (not in this order)

## Error handling
  If there is no argument, an error message would be produced and would exit out of the run.
  The output would read an error message if the directory does not exist.
  If the code cannot read the file an error message would be produced.
  This code will only process normal files and skip subdirectories.
