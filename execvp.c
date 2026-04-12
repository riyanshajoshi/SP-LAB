// stdio.h → used for input/output functions like printf(), scanf()
#include <stdio.h>

// unistd.h → used for system calls like fork(), execvp()
#include <unistd.h>

// sys/types.h → defines data types like pid_t (process ID type)
#include <sys/types.h>

// sys/wait.h → used for wait() function to make parent wait for child
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if(pid < 0) {
        printf("Fork failed\n");
    }
    else if(pid == 0) {
        // Child process
        printf("Child process before exec\n");
        printf("Child will now be replaced by 'ls -l' program\n");

        char *args[] = {"ls", "-l", NULL};

        execvp(args[0], args);

        // Runs only if exec fails
        printf("Exec failed\n");
    }
    else {
        // Parent process
        wait(NULL);
        printf("Parent process\n");
    }

    return 0;
}
