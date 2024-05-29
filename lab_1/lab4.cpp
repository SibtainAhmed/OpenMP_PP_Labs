#include <omp.h>
#include <stdio.h>
#include <cstdlib>



/*

//Exercise 1

////////////Serial Version/////////////////
void MatMul(double* A, double* B, double* C, int n)
{
	int i, j, k;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			double dot = 0;
			for (k = 0; k < n; k++) {
				dot += A[i * n + k] * B[k * n + j];
			}
			C[i * n + j] = dot;
		}
	}
}

////////////////Parallel Version/////////////////
void MatMul_omp(double* A, double* B, double* C, int n, int numThreads)
{
	omp_set_dynamic(0);
	omp_set_num_threads(numThreads);
#pragma omp parallel
	{
		int i, j, k;
#pragma omp for
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				double dot = 0;
				for (k = 0; k < n; k++) {
					dot += A[i * n + k] * B[k * n + j];
				}
				C[i * n + j] = dot;
			}
		}
	}
}

int main() {
	int i, j, k, n, threadEvoke;
	int arryDimension[5] = { 2, 64, 1024, 2048 };
	int numThreads[5] = { 1, 2 , 4, 8, 16 };


	double* A, * B, * C, dtime1, dtime2, speedUp, Eff, cost;
	for (j = 0; j < 5; j++)
	{
		n = arryDimension[j];
		A = (double*)malloc(sizeof(double) * n * n);
		B = (double*)malloc(sizeof(double) * n * n);
		C = (double*)malloc(sizeof(double) * n * n);
		for (i = 0; i < n * n; i++)
		{
			A[i] = (double)rand() / RAND_MAX;
			B[i] = (double)rand() / RAND_MAX;
		}
		printf("================================\nArray Dimension = %d\n", n);
		dtime1 = omp_get_wtime();
		MatMul(A, B, C, n);
		dtime1 = omp_get_wtime() - dtime1;
		printf("Serial execution = %f s\n", dtime1);

		for (k = 0; k < 5; k++)
		{
			threadEvoke = numThreads[k];
			printf("\nUsing %d Threads\n", threadEvoke);
			dtime2 = omp_get_wtime();
			MatMul_omp(A, B, C, n, threadEvoke);
			dtime2 = omp_get_wtime() - dtime2;
			printf("Parallel execution = %fs\n", dtime2);
			speedUp = dtime1 / dtime2;
			printf("SpeedUp = %f\n", speedUp);
			Eff = speedUp / omp_get_num_procs();
			printf("Efficiency = %f\n", Eff);
			cost = dtime2 * omp_get_num_procs();
			printf("cost = %f\n", cost);

		}

	free(A);free(B);free(C);

	}
}


*/

/*



//Exercise 2

////////////Serial Version/////////////////
void MatMul(double* A, double* B, double* C, int n)
{
	for (int i = 0; i < n; ++i)
	{
		C[i] = A[i] + B[i];
	}
}

////////////////Parallel Version/////////////////
void MatMul_omp(double* A, double* B, double* C, int n, int numThreads)
{
	omp_set_dynamic(0);
	omp_set_num_threads(numThreads);
#pragma omp parallel
	{
#pragma omp for
		for (int i = 0; i < n; ++i)
		{
			C[i] = A[i] + B[i];
		}
	}
}

int main() {
	int i, j, k, n, threadEvoke;
	int arryDimension[5] = { 2, 4, 8, 16, 8192 };
	int numThreads[5] = { 1, 2 , 4, 8, 16 };


	double* A, * B, * C, dtime1, dtime2, speedUp, Eff, cost;
	for (j = 0; j < 5; j++)
	{
		n = arryDimension[j];
		A = (double*)malloc(sizeof(double) * n * n);
		B = (double*)malloc(sizeof(double) * n * n);
		C = (double*)malloc(sizeof(double) * n * n);
		for (i = 0; i < n * n; i++)
		{
			A[i] = rand() / RAND_MAX;
			B[i] = rand() / RAND_MAX;
		}
		printf("================================\nArray Dimension = %d\n", n);
		dtime1 = omp_get_wtime();
		MatMul(A, B, C, n);
		dtime1 = omp_get_wtime() - dtime1;
		printf("Serial execution = %f\n", dtime1);

		for (k = 0; k < 5; k++)
		{
			threadEvoke = numThreads[k];
			printf("\nUsing %d Threads\n", threadEvoke);
			dtime2 = omp_get_wtime();
			MatMul_omp(A, B, C, n, threadEvoke);
			dtime2 = omp_get_wtime() - dtime2;
			printf("Parallel execution = %f\n", dtime2);
			speedUp = dtime1 / dtime2;
			printf("SpeedUp = %f\n", speedUp);
			Eff = speedUp / omp_get_num_procs();
			printf("Efficiency = %f\n", Eff);
			cost = dtime2 * omp_get_num_procs();
			printf("cost = %f\n", cost);

		}
		
		free(A);free(B);free(C);

	}
}

*/

/*
//Exercise 3

////////////Serial Version/////////////////
void MatMul(double** A, double* B, double* C, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			C[i] += (A[i][j] * B[i]);
	}
}
////////////////Parallel Version/////////////////
void MatMul_omp(double** A, double* B, double* C, int n, int numThreads)
{
	omp_set_dynamic(0); 
	omp_set_num_threads(numThreads);  

#pragma omp parallel for
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			C[i] += A[i][j] * B[j];
		}
	}
}

int main() {
	int i, j, k, n, threadEvoke;
	int arryDimension[5] = { 2, 4, 8, 8192,16384  };
	int numThreads[5] = { 1, 2 , 4, 8, 16 };
	double dtime1, dtime2, speedUp, Eff, cost;
	for (j = 0; j < 5; j++)
	{
		n = arryDimension[j];
		// Allocate and initialize matrices A, B, and C
		double** A = (double**)malloc(n * sizeof(double*));
		for (int i = 0; i < n; i++) {
			A[i] = (double*)malloc(n * sizeof(double));
			for (int j = 0; j < n; j++) {
				A[i][j] = (double)rand() / RAND_MAX;
			}
		}
		double* B = (double*)malloc(n * sizeof(double));
		for (int i = 0; i < n; i++) {
			B[i] = (double)rand() / RAND_MAX;
		}
		double* C = (double*)malloc(sizeof(double) * n );

		printf("======================\nArray Dimension = %d\n", n);
		dtime1 = omp_get_wtime();
		MatMul(A, B, C, n);
		dtime1 = omp_get_wtime() - dtime1;
		printf("Serial execution = %f\n", dtime1);

		for (k = 0; k < 5; k++)
		{
			threadEvoke = numThreads[k];
			printf("\nUsing %d Threads\n", threadEvoke);
			dtime2 = omp_get_wtime();
			MatMul_omp(A, B, C, n, threadEvoke);
			dtime2 = omp_get_wtime() - dtime2;
			printf("Parallel execution = %f\n", dtime2);
			speedUp = dtime1 / dtime2;
			printf("SpeedUp = %f\n", speedUp);
			Eff = speedUp / omp_get_num_procs();
			printf("Efficiency = %f\n", Eff);
			cost = dtime2 * omp_get_num_procs();
			printf("cost = %f\n", cost);

		}

		// Free allocated memory
		for (int i = 0; i < n; i++) {
			free(A[i]);
		}
		free(A);free(B);free(C);
	}
}
*/


/*

//Exercise 5

////////////Serial Version/////////////////
void TransposeMul(double** A, double** B, int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			B[j][i] = A[i][j];
		}
	}
}
////////////////Parallel Version/////////////////
void TransposeMul_omp(double** A, double** B, int n, int numThreads)
{
	omp_set_dynamic(0);
	omp_set_num_threads(numThreads);
#pragma omp parallel for
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			B[j][i] = A[i][j];
		}
	}
}

int main() {
	int i, j, k, n, threadEvoke;
	int arryDimension[5] = { 2, 4, 8, 8192,16384 };
	int numThreads[5] = { 1, 2 , 4, 8, 16 };
	double dtime1, dtime2, speedUp, Eff, cost;
	for (j = 0; j < 5; j++)
	{
		n = arryDimension[j];
		// Allocate and initialize matrices A, B
		double** A = (double**)malloc(n * sizeof(double*));
		for (int i = 0; i < n; i++) {
			A[i] = (double*)malloc(n * sizeof(double));
			for (int j = 0; j < n; j++) {
				A[i][j] = (double)rand() / RAND_MAX;
			}
		}
		double** B = (double**)malloc(n * sizeof(double*));

		for (int i = 0; i < n; i++) {
			B[i] = (double*)malloc(n * sizeof(double));
		}
		
		printf("======================\nArray Dimension = %d\n", n);
		dtime1 = omp_get_wtime();
		TransposeMul(A, B, n);
		dtime1 = omp_get_wtime() - dtime1;
		printf("Serial execution = %f\n", dtime1);

		for (k = 0; k < 5; k++)
		{
			threadEvoke = numThreads[k];
			printf("\nUsing %d Threads\n", threadEvoke);
			dtime2 = omp_get_wtime();
			TransposeMul_omp(A, B, n, threadEvoke);
			dtime2 = omp_get_wtime() - dtime2;
			printf("Parallel execution = %f\n", dtime2);
			speedUp = dtime1 / dtime2;
			printf("SpeedUp = %f\n", speedUp);
			Eff = speedUp / omp_get_num_procs();
			printf("Efficiency = %f\n", Eff);
			cost = dtime2 * omp_get_num_procs();
			printf("cost = %f\n", cost);

		}

		// Free allocated memory
		for (int i = 0; i < n; i++) {
			free(A[i]);
		}
		for (int i = 0; i < n; i++) {
			free(B[i]);
		}
		free(A);free(B);
	}
}
*/




//=====Exercise 4=====
////////////Serial Version/////////////////
long long Factorial_func(long n)
{
	long long factorial = 1;
	for (int i = 1; i <= n; i++)
	{
		factorial *= i;
	}
	return factorial;
}
////////////////Parallel Version/////////////////
long long Factorial_omp(long n, int numThreads)
{
	long long factorial = 1;  
	omp_set_dynamic(0);
	omp_set_num_threads(numThreads);

#pragma omp parallel for reduction(*:factorial)
	for (int i = 1; i <= n; i++) {
		factorial *= i;
	}
	return factorial;
}

int main() {
	int k, n, threadEvoke;
	int arryDimension[5] = {1024, 2048, 4096, 8192,16384 };
	int numThreads[5] = { 1,2, 4, 8, 16};
	double dtime1, dtime2, speedUp, Eff, cost;
	for (int j = 0; j < 5; j++)
	{
		n = arryDimension[j];
		
		printf("======================\nN size = %d\n", n);
		dtime1 = omp_get_wtime();
		Factorial_func(n);
		//long long ans = Factorial_func(n);
		//printf("Serial ans = %lld\n", ans);
		dtime1 = omp_get_wtime() - dtime1;
		printf("Serial execution = %fs\n", dtime1);

		for (k = 0; k < 5; k++)
		{
			threadEvoke = numThreads[k];
			printf("\nUsing %d Threads\n", threadEvoke);
			dtime2 = omp_get_wtime();
			Factorial_omp(n, threadEvoke);
			//printf("Parllel ans = %lld\n",Factorial_omp(n, threadEvoke));
			dtime2 = omp_get_wtime() - dtime2;
			printf("Parallel execution = %fs\n", dtime2);
			speedUp = dtime1 / dtime2;
			printf("SpeedUp = %f\n", speedUp);
			Eff = speedUp / omp_get_num_procs();
			printf("Efficiency = %f\n", Eff);
			cost = dtime2 * omp_get_num_procs();
			printf("cost = %f\n", cost);

		}

		
	}
}
