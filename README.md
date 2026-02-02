# OS Process Management Project

**Name**: Kayla Gaynor
**Date**: February 2, 2026
**Environment**: macOS (Darwin), using gcc compiler and terminal

**How to compile the project**:
	Type 'make'

**Example of how to run the project**:
	./oss -n 5 -s 2 -t 3

## AI Assistance Acknowledgmenet

**Generative AI used**: Claude AI
**Prompts**:
	- "How do I implement oss.c?" - Requested guidance on the parent process with fork/exec/wait
	- "I'm getting compilation errors" - Debugging help for Makefile tab issues and missing function declarations
	- "How do I use git and push to GitHub?" - Assistance with version control workflow and authentication

The AI explained concepts like process management, system calls (for, exec, wait), Makefile syntax, and git commands. I understand how all the parts of my code work and was able to test and verify the functionality independently.


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

