# CS332HW3

## Overview
This program performs file manipulation and manages multiple child processes to perform tasks on files in a specified directory. It traverses the directory, retrieves information about each file, and prints the file name, size, and word count (for .txt files) in separate child processes.

## Features
- Accepts a directory as a command-line argument.
- Prints the file name, size, and word count (for .txt files) for each file in the directory.
- Creates a child process for each file to perform the above tasks.
- Waits for all child processes to complete before exiting.
- Implements basic error handling for invalid directories, inaccessible files, and failed process creation.

## Requirements
- A POSIX-compliant operating system (Linux, macOS).
- GCC (GNU Compiler Collection) for compilation.

## Installation
1. Clone the repository or download the source code.
2. Navigate to the directory containing the source code.
3. Compile the program using the following command:

