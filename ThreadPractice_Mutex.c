#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t m; // create Mutex m

int g_count = 0; // Threads SHARE this resource


void *thread_function(void * data){

int i;
char *thread_name = (char *)data;

pthread_mutex_lock(&m);
g_count = 0;
for (i = 0; i<3; i++){

	printf("%s COUNT %d\n", thread_name, g_count);
	g_count++;
	sleep(1);
}
pthread_mutex_unlock(&m);

}
int main(){
pthread_t testThread1, testThread2;
int status;

pthread_create(&testThread1,NULL,thread_function,(void *) "testThread1");
pthread_create(&testThread2,NULL,thread_function,(void *) "testThread2");

pthread_join(testThread1,(void *)&status);
pthread_join(testThread2,(void *)&status);

}
