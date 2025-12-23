#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define _REENTRANT

//
void *ThreadRoutine(int number)
{
	printf("thread %d running\n",number);
	sleep(number);
	printf("thread %d finish , joining... \n",number);
}
int main(void)
{
	int t;
	pthread_t tid;
	//
	for (t=1; t<5; t++)
		pthread_create(&tid,NULL,(void *)ThreadRoutine, (int *)t);

	//
	pthread_join(tid,NULL);
	printf("All kids joined, parent running\n");
	exit(1);
}
