#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <number_of_iterations>\n", argv[0]);
    return 1;
  }

int iterations = atoi(argv[1]);

pid_t pid = getpid();
pid_t ppid = getppid();

for (int i = 1; i <= iterations; i++) {
  //Print before sleeping
  printf("USER PID: %d PPID: %d Iteration: %d before sleeping\n", pid, ppid, i);
  fflush(stdout);

  //Sleep for one second
  sleep(1);

  //Print after sleeping
  printf("USER PID: %d PPID: %d Iteration: %d after sleeping\n", pid, ppid, i);
  fflush(stdout);
}
return 0;
}
