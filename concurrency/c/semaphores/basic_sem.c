#include <pthread.h>
#include <threads.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

sem_t empty;
sem_t full;
sem_t mutex;
sem_t end;
pthread_cond_t begin = PTHREAD_COND_INITIALIZER;
pthread_mutex_t begin_t = PTHREAD_MUTEX_INITIALIZER;
int next_i = 0;
int buffer_fill = 0;
int consumer_get_sleep_time = 1; // in seconds

typedef struct {
  int * buffer_arr;
  int buffer_size;
} Buffer;

typedef struct {
  pthread_t t;
  int thread_idx;
  Buffer *buffer;
} Producer;

typedef struct {
  pthread_t t;
  int thread_idx;
  Buffer *buffer;
} Consumer;

void print_buffer(Buffer *buffer, int thread_idx, char *thread_type) {
  printf("\nThread type: %s\n", thread_type);
  printf("Thread index: %d\n", thread_idx);
  printf("[");
  for (int i = 0; i < buffer->buffer_size; i++) {
    printf("%d,", buffer->buffer_arr[i]);
  }
  printf("]\n");
}

void put(Producer *producer) {
  sem_wait(&mutex);
  producer->buffer->buffer_arr[next_i] = 1;
  print_buffer(producer->buffer, producer->thread_idx, "producer");
  next_i++;
  sem_post(&mutex);
}

void get(Consumer *consumer) {
  sem_wait(&mutex);
  consumer->buffer->buffer_arr[next_i - 1] = 0;
  print_buffer(consumer->buffer, consumer->thread_idx, "consumer");
  next_i--;
  sem_post(&mutex);
  printf("Consumer %d sleeping for %d seconds\n", consumer->thread_idx, consumer_get_sleep_time);
  sleep(consumer_get_sleep_time);
}

void produce(void *arg) {
  Producer *producer= (Producer *) arg;
  sem_wait(&empty);
  put(producer);
  sem_post(&full);
}

void *consume(void *arg) {
  Consumer *consumer = (Consumer *) arg;
  while (true) {
    sem_wait(&full);
    get(consumer);
    sem_post(&empty);
  }
  return NULL;
}

void *producer_waiting_room(void *arg) {
  Producer *producer = (Producer *) arg;
  pthread_mutex_lock(&begin_t);
  pthread_cond_wait(&begin, &begin_t);
  produce(producer);
  pthread_mutex_unlock(&begin_t);
  return NULL;
}

int main() {
  printf("Today we'll be working with some basic semaphores :)\n");
  int producer_count = 3;
  int consumer_count = 3;
  int buffer_size = 3;
  int buffer_arr[buffer_size];
  Producer producers[producer_count];
  Consumer consumers[consumer_count];

  sem_init(&empty, 0, buffer_size);
  sem_init(&full, 0, 0);
  sem_init(&mutex, 0, 1);
  sem_init(&end, 0, 0);

  Buffer buffer = {buffer_arr, buffer_size};
  
  printf("\n###Thread trace###\n");
  // Create producers and consumer threads
  for (int i = 0; i < producer_count; i++) {
    Producer new_producer = {0, i, &buffer};
    producers[i] = new_producer;
    pthread_create(&(producers[i].t), NULL, producer_waiting_room, &(producers[i]));
  }
  for (int i = 0; i < consumer_count; i++) {
    Consumer new_consumer = {0, i, &buffer};
    consumers[i] = new_consumer;
    pthread_create(&(consumers[i].t), NULL, consume, &(consumers[i]));
  }

  // Signal all producers to start producing
  pthread_cond_broadcast(&begin);

  // Wait for all our producers and consumers to finish
  for (int i = 0; i < producer_count; i++) {
    pthread_join(producers[i].t, NULL);
  }

  // Wait for all our consumers and consumers to finish
  for (int i = 0; i < consumer_count; i++) {
    pthread_join(consumers[i].t, NULL);
  }

  while (true) {
    sem_wait(&mutex);
    int n = next_i;
    sem_post(&mutex);
    if (n == 0) {break;}
  }

  printf("\n###End thread trace###\n");

  return 0;
}
