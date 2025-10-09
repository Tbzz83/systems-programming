#include <assert.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int global = 0;
pthread_mutex_t mutex;


typedef struct {
  pthread_t t;
  int idx;
} MyThread;

void* increment(void *arg) {
  pthread_mutex_lock(&mutex);
  MyThread thread = *(MyThread*) arg;
  printf("Thread %d incrementing\n", thread.idx);
  global++;
  pthread_mutex_unlock(&mutex);

  return NULL;
}

int main() {
  printf("\nToday we will do some practice with threads, locks, and condition variables!\n");
  printf("\nOur global variable is initially %d\n", global);

  MyThread *threads[10];

  printf("\nCreating five threads to increment global...\n");
  for (int i = 0; i < 5; i++ ) {
    MyThread *thread = (MyThread *)malloc(sizeof(MyThread));
    assert(thread != NULL);
    thread->idx = i;
    threads[i] = thread;

    printf("Thread %d starting\n", i);
    pthread_create(&(thread->t), NULL, increment, (MyThread*) thread);

  }

  printf("\nWaiting for our five threads to finish incrementing global...\n");
  for (int i = 0; i < 5; i++ ) {
    printf("Thread %d joining\n", i);
    pthread_join(threads[i]->t, NULL);
    free(threads[i]);
  }

  printf("\nOur global variable is now %d!\n", global);

  return 0;
}
