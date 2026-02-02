#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void print_help(char *program_name) {
	printf("Usage: %s [-h] [-n proc] [-s simul] [-t iter]\n", program_name);
	printf("Options:\n");
	printf(" -h  Display this help message\n");
	printf(" -n proc  Total number of child processes to launch (default: 5)\n");
	printf(" -s simul  Maximum number of simultaneous processes (default: 3)\n");
	printf(" -t iter  Number of iterations for each user process (default: 3)\n");
}

int main(int argc, char *argv[]) {
	int n = 5;
	int s = 3;
	int t = 3;
	int opt;

	while ((opt = getopt(argc, argv, "hn:s:t:")) != -1) {
		switch(opt) {
			case 'h':
				print_help(argv[0]);
				return 0;
			case 'n':
				n = atoi(optarg);
				break;
			case 's':
				s = atoi(optarg);
				break;
			case 't':
				t = atoi(optarg);
				break;
			default:
				print_help(argv[0]);
				return 1;
		}
	}

	if (n <= 0 || s <= 0 || t <= 0) {
		fprintf(stderr, "Error: All numeric arguments must be positive\n");
		return 1;
	}

	if (s > n) {
		s = n;
	}

	printf("OSS: Starting with n=%d processes, s=%d simultaneous, t=%d iterations\n", n, s, t);

	int c = 0;
	int total = 0;

	char iter_str[20];
	snprintf(iter_str, sizeof(iter_str), "%d", t);

	while (c < s && total < n) {
		pid_t pid = fork();

	if (pid < 0) {
		perror("fork failed");
		return 1;
	}
	else if (pid == 0) {
		execl("./user", "user", iter_str, NULL);
		perror("execl failed");
		exit(1);
	}
	else {
		total++;
		printf("OSS: Launching process %d (PID: %d)\n", total, pid);
		c++;
	}
}

while (total < n) {
	int status;
	pid_t finished_pid = wait(&status);

	if (finished_pid > 0) {
		printf("OSS: Process with PID %d finished\n", finished_pid);

		pid_t pid = fork();

		if (pid < 0) {
			perror("fork failed");
			return 1;
		}
		else if (pid == 0) {
			execl("./user", "user", iter_str, NULL);
			perror("execl failed");
			exit(1);
		}
		else {
			total++;
			printf("OSS: Launching process %d (PID: %d)\n", total, pid);
		}
	}
}

printf("OSS: All processes launched. Waiting for remaining children to finish... \n");
while (c > 0) {
	int status;
	pid_t finished_pid = wait(&status);

	if (finished_pid > 0) {
		printf("OSS: Process with PID %d finished\n", finished_pid);
		c--;
	}
}

printf("\nOSS: Summary - Successfully launched and completed %d processes\n", total);

return 0;
}
