#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// Buffer size
#define BUFFER_SIZE 10

// Buffer and indices
int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
int item = 0; // Sequential counter for produced items
int count = 0; // Track number of items in the buffer

// Semaphores and mutex
sem_t empty;
sem_t full;
pthread_mutex_t mutex;

// Producer function
void* producer(void* arg) {
    while (1) {
        sleep(1); // Simulate time taken to produce an item

        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        // Produce an item sequentially
        item++;
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;
        count++;
        printf("Producer produces item %d, total available items: %d\n", item, count);

        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
    return NULL;
}

// Consumer function
void* consumer(void* arg) {
    int consumed_item;
    long id = (long)arg;
    while (1) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        // Consume an item from the buffer
        consumed_item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        count--;
        printf("Consumer %ld consumes item %d\n", id, consumed_item);

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);

        sleep(1); // Simulate time taken to consume an item
    }
    return NULL;
}

int main() {
    int num_consumers;
    printf("Enter the number of consumers: ");
    scanf("%d", &num_consumers);

    pthread_t prod_thread;
    pthread_t cons_threads[num_consumers];

    // Initialize semaphores and mutex
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    // Create the producer thread
    pthread_create(&prod_thread, NULL, producer, NULL);

    // Create consumer threads
    for (long i = 0; i < num_consumers; i++) {
        pthread_create(&cons_threads[i], NULL, consumer, (void*)i);
    }

    // Wait for the producer thread to finish (it won't in this example)
    pthread_join(prod_thread, NULL);

    // Wait for consumer threads to finish (they won't in this example)
    for (int i = 0; i < num_consumers; i++) {
        pthread_join(cons_threads[i], NULL);
    }

    // Destroy semaphores and mutex
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}