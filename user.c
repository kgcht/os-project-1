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

//Loop for specified number of iterations
for (int i = 1; i <= iterations; i++) {
  //Print before sleeping
  printf("USER PID: %d PPID: %d Iteration: %d before sleeping\n", pid, ppid, i);
  fflush(stdout); //Make sure output appears immediately

  //Sleep for one second
  sleep(1);

  //Print after sleeping
  printf("USER PID: %d PPID: %d Iteration: %d after sleeping\n", pid, ppid, i);
  fflush(stdout); //Makre sure output appears immediately
}
return 0;
}
