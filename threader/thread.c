/*
 * thread.c
 *
 *  Created on: Mar 14, 2020
 *      Author: krunal.soni
 */


#include <stdio.h>
#include <pthread.h>


void* myprinter(void *arg)
{
	int t = *(int *) arg;
	for (int i = 0; i < t; i++)
	{
		printf("%d--\n", i);
	}
	return NULL;
}

int main()
{
	pthread_t t1;
	int i = 1000;
	pthread_create(&t1, NULL, myprinter, &i);
	pthread_join(t1, NULL);

	return 0;
}
