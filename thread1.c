#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
// we must make the compiler
//
//
#define _REENTRANT

//
void *ThreadRoutine(int number)
{
	while(1) //loop forever
	{
		printf("pid %d : thread %d running\n",getpid(), number);
		sleep(number);
	}
}
int main(void)
{
	int t;

	pthread_t tid[5];
	//
	for (t=1; t<5; t++)
		pthread_create(&tid[t],NULL,(void *)ThreadRoutine, &t);

	//
	while(1)
		{
		printf("pid %d : parent running\n", getpid());
		sleep(10);
		}
	exit(1);
}
