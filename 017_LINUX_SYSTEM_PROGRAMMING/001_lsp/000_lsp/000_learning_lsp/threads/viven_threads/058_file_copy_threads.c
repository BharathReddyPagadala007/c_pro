#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<fcntl.h>
#include<unistd.h>



#define CHUNK_SIZE 1024
#define MAX_THREADS 4	

typedef struct{
	int src_fd;
	int dest_fd;
	off_t offset;
	size_t size;
}ThreadData;


void* copy_chunk(void* arg){
	ThreadData* data = (ThreadData*)arg;
	char* buffer = (char*)malloc(data->size);



	lseek(data->src_fd,data->offset, SEEK_SET);





 ssize_t bytes_read = read(data->src_fd,buffer,data->size);


 ssize_t bytes_written = write(data->dest_fd, buffer, bytes_read);

 free(buffer);
 return NULL;

}












int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }



     int src_fd = open(argv[1], O_RDONLY);

      int dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);

off_t file_size = lseek(src_fd, 0, SEEK_END);
    if (file_size < 0) {
        perror("lseek");
        close(src_fd);
        close(dest_fd);
        return 1;
    }



    // Create threads to copy the file in chunks
    pthread_t threads[MAX_THREADS];
    ThreadData thread_data[MAX_THREADS];
    size_t chunk_size = file_size / MAX_THREADS;

    for (int i = 0; i < MAX_THREADS; i++) {
        thread_data[i].src_fd = src_fd;
        thread_data[i].dest_fd = dest_fd;
        thread_data[i].offset = i * chunk_size;
        thread_data[i].size = (i == MAX_THREADS - 1) ? (file_size - (i * chunk_size)) : chunk_size;

        // Create a thread to copy a chunk of the file
        if (pthread_create(&threads[i], NULL, copy_chunk, (void*)&thread_data[i]) != 0) {
            perror("pthread_create");
            close(src_fd);
            close(dest_fd);
            return 1;
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Close the files
    close(src_fd);
    close(dest_fd);

    printf("File copied successfully.\n");

    return 0;
}
