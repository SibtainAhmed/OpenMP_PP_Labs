#include <omp.h>
#include <stdio.h>

int main() {

	int n = 9;
	int i;

#pragma omp parallel shared(n) private(i)
	{
#pragma omp for
	for (i=0; i<n; i++)
		printf("Thread %d execute loop iteration %d\n ", omp_get_thread_num(), i)

	}

}