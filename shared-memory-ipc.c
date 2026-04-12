#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SIZE 5

int main() {
    int shmid;
    int *buffer;

    // Create shared memory
    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(int), 0666 | IPC_CREAT);
    if (shmid < 0) {
        printf("Shared memory creation failed\n");
        exit(1);
    }

    // Attach shared memory
    buffer = (int *)shmat(shmid, NULL, 0);

    int i;

    // Producer
    printf("Producer:\n");
    for(i = 0; i < SIZE; i++) {
        buffer[i] = i;
        printf("Produced: %d\n", buffer[i]);
        sleep(1);
    }

    printf("\nConsumer:\n");
    // Consumer
    for(i = 0; i < SIZE; i++) {
        printf("Consumed: %d\n", buffer[i]);
        sleep(1);
    }

    // Detach shared memory
    shmdt(buffer);

    // Delete shared memory
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
