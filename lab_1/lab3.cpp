#include <omp.h>
#include <stdio.h>


//
//void funcA(void)
//{
//	printf("id = %d, \n", omp_get_thread_num());
//}
//void funcB(void)
//{
//	printf("id = %d, \n", omp_get_thread_num());
//}
//
//int main()
//{
//#pragma omp parallel sections
//	{
//#pragma omp section
//		{
//			//printf("id = %d, \n", omp_get_thread_num());
//			funcA();
//
//		}
//#pragma omp section
//		{
//			//printf("id = %d, \n", omp_get_thread_num());
//			funcB();
//
//		}
//	}
//}




//
//int main()
//{
//	int a, i;
//	int n = 9;
//	int b[9] = { 0 };
//#pragma omp parallel shared(a,b) private(i)
//	{
//#pragma omp single
//		{
//			a = 10;
//			printf("Single construct executed by thread %d\n", omp_get_thread_num());
//
//		}
//#pragma omp for 
//		for (i = 0; i < n; i++)
//			b[i] = a;
//			//printf("using thread = %d\n", omp_get_thread_num());
//
//	}
//	printf("\nAfter the parallel region: \n");
//	for (i = 0; i < n; i++)
//		printf("b[%d] = %d\n", i, b[i]);
//}




//
//int main()
//{
//	printf("This is the main thread. \n");
//	omp_set_dynamic(0);
//	int id;
//#pragma omp parallel private(id) num_threads(6)
//	{
//		id = omp_get_thread_num();
//#pragma omp single
//		{
//			printf("Total number of threads: <<# %d \n", omp_get_num_threads());
//			printf("In single directive, this is thread# %d \n", id);
//
//
//		}
//#pragma omp sections
//		{
//#pragma omp section
//			printf("In section a, this is thread# %d \n", id);
//#pragma omp section
//			printf("In section b, this is thread# %d \n", id);
//#pragma omp section
//			printf("In section c, this is thread# %d \n", id);
//
//		}
//	}
//	printf("Back to the main thread. Goodbye! \n");
//}