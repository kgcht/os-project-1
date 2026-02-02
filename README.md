# OS Process Management Project

Name: Kayla Gaynor
Date: February 2, 2026
Environment: macOS (Darwin), using gcc compiler and terminal
How to compile the project:
	Type 'make'
Example of how to run the project:
	./oss -n 5 -s 2 -t 3

## Project Description
This project implements a simple process management simulator consisting of two programs:
- **oss**: The operating system simulator that launches and manages child processes
- **user**: A child process that performs iterations and reports its status

# How to Run
./oss [-h] [-n proc] [-s simul] [-t iter]
# Options:
- **h**: Display help message
- **n proc**: Total number of child processes to launch
- **s simul**: Maximum number of simultaneous child processes
- **t iter**: Number of iterations each user process should perform

# How to Clean
make clean

# Files
- **oss.c** - Operating system simulator (parent process)
- **user.c** - User process (child process)
- **Makefile** - Build configuration

