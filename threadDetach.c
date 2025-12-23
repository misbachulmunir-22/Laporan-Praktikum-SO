#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define _REENTRANT
//
void *ThreadRoutine(int number)
{
	int i;
	for (i=0; i<10; i++)
		{
			printf("thread %d running %d\n",number,i);
			sleep(number);
		}
}

int main(void)
{
	pthread_t tid1,tid2;
	//
	pthread_create(&tid1,NULL, (void *)ThreadRoutine, (int *)1);
	pthread_create(&tid2,NULL, (void *)ThreadRoutine, (int *)2);
	pthread_detach(tid1);

	if(pthread_join(tid1,NULL)>0)
		printf("unable to join thread 1\n");
	if(pthread_join(tid2,NULL)>0)
		printf("unable to join thread 2\n");

	printf("parent finished\n");
	exit(1);
}
