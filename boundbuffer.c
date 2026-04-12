#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define SIZE 5

int buffer[SIZE];
int in = 0, out = 0;

// Semaphores
sem_t empty, full, mutex;

// Producer function
void *producer(void *arg) {
    int item;

    for(int i = 0; i < 10; i++) {
        item = i; // produce item

        sem_wait(&empty);   // wait if buffer is full
        sem_wait(&mutex);   // enter critical section

        buffer[in] = item;
        printf("Produced: %d\n", item);
        in = (in + 1) % SIZE;

        sem_post(&mutex);   // exit critical section
        sem_post(&full);    // increase filled slots
    }
}

// Consumer function
void *consumer(void *arg) {
    int item;

    for(int i = 0; i < 10; i++) {

        sem_wait(&full);    // wait if buffer is empty
        sem_wait(&mutex);   // enter critical section

        item = buffer[out];
        printf("Consumed: %d\n", item);
        out = (out + 1) % SIZE;

        sem_post(&mutex);   // exit critical section
        sem_post(&empty);   // increase empty slots
    }
}

int main() {
    pthread_t p, c;

    // Initialize semaphores
    sem_init(&empty, 0, SIZE); // all slots empty initially
    sem_init(&full, 0, 0);     // no items initially
    sem_init(&mutex, 0, 1);    // binary semaphore

    // Create threads
    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    // Wait for threads
    pthread_join(p, NULL);
    pthread_join(c, NULL);

    // Destroy semaphores
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}
