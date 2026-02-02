#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
  //Check if I got the required command-line argument
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <number_of_iterations>\n", argv[0]);
    return 1;
  }

//Convert the argument to an integer
int iterations = atoi(argv[1]);

//Get the PID and PPID
pid_t pid = getpid();
pid_t ppid = getppid();
