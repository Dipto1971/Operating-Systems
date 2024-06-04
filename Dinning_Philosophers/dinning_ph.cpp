#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define THINKING 2
#define HUNGRY 1
#define EATING 0

int N; // Number of philosophers
int *state;
int *phil;

sem_t mutex;
sem_t *S;

void test(int phnum);
void take_fork(int phnum);
void put_fork(int phnum);
void* philosopher(void* num);

int main() {
    printf("Enter the number of philosophers (odd number): ");
    scanf("%d", &N);

    if (N % 2 == 0) {
        printf("The number of philosophers must be odd.\n");
        return 1;
    }

    state = (int *)malloc(N * sizeof(int));
    phil = (int *)malloc(N * sizeof(int));
    S = (sem_t *)malloc(N * sizeof(sem_t));

    pthread_t thread_id[N];

    sem_init(&mutex, 0, 1);

    for (int i = 0; i < N; i++) {
        sem_init(&S[i], 0, 0);
        phil[i] = i;
    }

    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        pthread_create(&thread_id[i], NULL, philosopher, &phil[i]);
    }

    for (int i = 0; i < N; i++) {
        pthread_join(thread_id[i], NULL);
    }

    free(state);
    free(phil);
    free(S);
    return 0;
}

void* philosopher(void* num) {
    while (1) {
        int* i = num;
        int hunger_percentage = rand() % 100;

        printf("Philosopher %d is thinking...\n", *i + 1);
        sleep(1);

        if (hunger_percentage > 50) {
            printf("Philosopher %d is more than 50%% hungry\n", *i + 1);
            take_fork(*i);
            sleep(1); // simulate eating time
            put_fork(*i);
        } else {
            printf("Philosopher %d is less than or equal to 50%% hungry and gives up the forks\n", *i + 1);
        }
        sleep(1); // simulate thinking time
    }
}

void test(int phnum) {
    int LEFT = (phnum + N - 1) % N;
    int RIGHT = (phnum + 1) % N;

    if (state[phnum] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
        state[phnum] = EATING;
        printf("Philosopher %d takes fork %d and %d\n", phnum + 1, LEFT + 1, phnum + 1);
        printf("Philosopher %d is Eating\n", phnum + 1);
        sem_post(&S[phnum]);
    }
}

void take_fork(int phnum) {
    sem_wait(&mutex);
    state[phnum] = HUNGRY;
    printf("Philosopher %d is Hungry\n", phnum + 1);
    test(phnum);
    sem_post(&mutex);
    sem_wait(&S[phnum]);
    sleep(1);
}

void put_fork(int phnum) {
    sem_wait(&mutex);
    state[phnum] = THINKING;
    printf("Philosopher %d putting fork %d and %d down\n", phnum + 1, (phnum + N - 1) % N + 1, phnum + 1);
    printf("Philosopher %d is thinking\n", phnum + 1);
    test((phnum + N - 1) % N);
    test((phnum + 1) % N);
    sem_post(&mutex);
}