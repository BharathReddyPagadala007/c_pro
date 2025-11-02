#include <stdio.h>
#include <pthread.h>

void* print_message(void* arg) {
    int thread_id = *(int*)arg; // Thread ID passed directly
    printf("Hello from Thread %d!\n", thread_id);
    return NULL;
}

int main() {
    pthread_t thread1, thread2, thread3, thread4, thread5;

    int id1 = 1, id2 = 2, id3 = 3, id4= 4, id5 = 5;

    pthread_create(&thread1, NULL, print_message, &id1);
    pthread_create(&thread2, NULL, print_message, &id2);
    pthread_create(&thread3, NULL, print_message, &id3);
    pthread_create(&thread4, NULL, print_message, &id4);
    pthread_create(&thread5, NULL, print_message, &id5);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
    pthread_join(thread5, NULL);

    return 0;
}

