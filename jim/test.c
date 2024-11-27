#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>

#define READ_END 0
#define WRITE_END 1

int main(int argc, char* argv[]) {
    // Declare pipes
    int fd1[2], fd2[2];
    pid_t pid;

    // Create pipes
    if (pipe(fd1) == -1 || pipe(fd2) == -1) {
        fprintf(stderr, "Pipe failed");
        return 1;
    }

    pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Fork Failed");
        return 1;
    }

    if (pid > 0) { // Parent process
        close(fd1[READ_END]);
        close(fd2[WRITE_END]);

        FILE* fp = fopen("input.txt", "r");
        if (fp == NULL) {
            fprintf(stderr, "Failed to open file\n");
            exit(1);
        }

        char line[BUFSIZ];
        while (fgets(line, BUFSIZ, fp)) {
            write(fd1[WRITE_END], line, strlen(line));
            memset(line, 0, BUFSIZ);
        }

        fclose(fp);
        close(fd1[WRITE_END]);

        // Wait for children to finish
        wait(NULL);
        close(fd2[READ_END]);
        wait(NULL);

    } else { // Child processes
        pid = fork();

        if (pid > 0) { // Second process (first child)
            close(fd1[WRITE_END]);
            close(fd2[READ_END]);

            char line[BUFSIZ];
            while (read(fd1[READ_END], line, BUFSIZ) > 0) {
                for (int i = 0; i < strlen(line); i++) {
                    // Change lower to upper and upper to lower cases
                    // write code here
                }
                write(fd2[WRITE_END], line, strlen(line));
                memset(line, 0, BUFSIZ);
            }

            close(fd1[READ_END]);
            close(fd2[WRITE_END]);
            exit(0);

        } else { // Third process (second child)
            // Close unused pipes
            // write code here
            if (out_fp == NULL) {
                perror("Error opening output.txt");
                exit(1);
            }

            char line[BUFSIZ];
            while (read(fd2[READ_END], line, BUFSIZ) > 0) {
                // Prints to the output file
                // write code here
            }

            fclose(out_fp);
            close(fd2[READ_END]);
            exit(0);
        }
    }

    return 0;
}