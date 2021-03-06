#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

long long fibonacci(long long n0, long long n1)
{
	return n0 + n1;
}

void *child(void *arg)
{
	long long n0 = 0;
	long long n1 = 1;
	long long v = 0;
	for (int n = 2; n > 0; n++) {
		v = fibonacci(n0, n1);
		n0 = n1;
		n1 = v;
		printf("%dth => %lld\n", n, v);
		sleep(1);
	}
}


int main(void)
{
	pthread_t tid;
	pthread_create(&tid, NULL, child, NULL);
	pthread_join(tid, NULL);
	printf("main thread exit\n");
	return 0;
}