#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>


#define FIFO_NAME "thread_fifo"
#define BUFFER_SIZE 256


void* producer_thread(void * arg){

	int fd;

	char message[BUFFER_SIZE];

	printf("producer : opening fifo for writing\n");

	fd = open(FIFO_NAME, O_WRONLY);

	for(int i=0; i<5; i++){
		snprintf(message,BUFFER_SIZE,"message %d from producer",i+1);	
		printf("producer: wrirting - %s\n",message);
		write(fd, message, strlen(message)+1);
		sleep(1);

	}		

	  close(fd);
    pthread_exit(NULL);
}

void *consumer_thread(void *arg) {
    int fd;
    char buffer[BUFFER_SIZE];
    printf("Consumer: Opening FIFO for reading...\n");

    fd = open(FIFO_NAME, O_RDONLY);
    if (fd < 0) {
        perror("Consumer: Failed to open FIFO");
        pthread_exit(NULL);
    }

    while (1) {
        ssize_t bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read > 0) {
            printf("Consumer: Read - %s\n", buffer);
        } else {
            break; // Exit when no more data
        }
    }

    close(fd);
    pthread_exit(NULL);
}





int main(){


	pthread_t producer, consumer;


	mkfifo(FIFO_NAME,0666);

	pthread_create(&producer,NULL,  producer_thread, NULL);

	pthread_create(&consumer, NULL , consumer_thread, NULL);


	pthread_join(producer,NULL);
	pthread_join(consumer,NULL);
return 0;
}
