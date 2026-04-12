#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex, wrt;
int readcount = 0;

// Reader function
void *reader(void *arg) {
    int id = *((int *)arg);

    sem_wait(&mutex);
    readcount++;
    if(readcount == 1) {
        sem_wait(&wrt); // first reader blocks writer
    }
    sem_post(&mutex);

    // Reading section
    printf("Reader %d is reading\n", id);

    sem_wait(&mutex);
    readcount--;
    if(readcount == 0) {
        sem_post(&wrt); // last reader allows writer
    }
    sem_post(&mutex);
}

// Writer function
void *writer(void *arg) {
    int id = *((int *)arg);

    sem_wait(&wrt); // writer gets exclusive access

    // Writing section
    printf("Writer %d is writing\n", id);

    sem_post(&wrt);
}

int main() {
    pthread_t r[5], w[5];
    int i, id[5];

    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    // Create reader threads
    for(i = 0; i < 5; i++) {
        id[i] = i + 1;
        pthread_create(&r[i], NULL, reader, &id[i]);
    }

    // Create writer threads
    for(i = 0; i < 5; i++) {
        id[i] = i + 1;
        pthread_create(&w[i], NULL, writer, &id[i]);
    }

    // Join threads
    for(i = 0; i < 5; i++) {
        pthread_join(r[i], NULL);
        pthread_join(w[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}
