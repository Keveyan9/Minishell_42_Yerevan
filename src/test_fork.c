// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// int main(int argc, char *argv[]) {
//     if (argc != 2) {
//         printf("Usage: %s <num_children>\n", argv[0]);
//         exit(1);
//     }

//     int num_children = atoi(argv[1]);

//     for (int i = 0; i < num_children; i++) {
//         pid_t pid = fork();

//         if (pid == 0) {
//             printf("Child process %d (PID=%d)\n", i, getpid());
//             exit(0);
//         } else if (pid < 0) {
//             printf("Error: Failed to fork process\n");
//             exit(1);
//         }
//     }

//     printf("Parent process (PID=%d)\n", getpid());

//     return 0;
// }

