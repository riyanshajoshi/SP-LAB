#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define SIZE 5

int main() {
    int fd[2];
    pid_t pid;
    int buffer[SIZE], i;

    // Create pipe
    if(pipe(fd) == -1) {
        printf("Pipe failed\n");
        return 1;
    }

    pid = fork();

    if(pid < 0) {
        printf("Fork failed\n");
    }
    else if(pid == 0) {
        // Child process → Consumer
        close(fd[1]); // close write end

        read(fd[0], buffer, sizeof(buffer));

        printf("Consumer:\n");
        for(i = 0; i < SIZE; i++) {
            printf("Consumed: %d\n", buffer[i]);
        }

        close(fd[0]);
    }
    else {
        // Parent process → Producer
        close(fd[0]); // close read end

        printf("Producer:\n");
        for(i = 0; i < SIZE; i++) {
            buffer[i] = i;
            printf("Produced: %d\n", buffer[i]);
        }

        write(fd[1], buffer, sizeof(buffer));

        close(fd[1]);
    }

    return 0;
}
