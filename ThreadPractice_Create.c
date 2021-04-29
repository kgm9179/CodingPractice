#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void *start_function (void *data){
pid_t pid; // process id
pthread_t tid; // Thread id

pid = getpid();
tid = pthread_self();

char* thread_name = (char*) data;
int i = 0;

while(i<3){
printf("[%s] pid: %u, tid:%x --- %d\n",
		thread_name, (unsigned int)pid, (unsigned int)tid, i);
i++;
sleep(1);

}



}

int main(){

pthread_t p_thread[2];
int thr_id;
int status;

char p1[] = "thread_1";
char p2[] = "thread_2";
char pM[] = "thread_m";

sleep(1);

thr_id = pthread_create(&p_thread[0],NULL,start_function,(void *)p1); 
			
if (thr_id < 0)
{
perror ("thread create error: ");
exit(0);
}

thr_id = pthread_create(&p_thread[1],NULL,start_function,(void *)p2);
if (thr_id < 0)
{
perror ("thread create error: ");
exit(0);
}

start_function((void *)pM);
pthread_join(p_thread[0], (void **)&status);
pthread_join(p_thread[1], (void **)&status);

printf ("when it ends?");
return 0;
			
			

}
