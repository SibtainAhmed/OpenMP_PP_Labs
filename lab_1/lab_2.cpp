#include <omp.h>
#include <stdio.h>


// Example 1
//int main() {
//	int n = 9;
//	int i;
//	//int a;
//
//#pragma omp parallel shared(n) private(i)
//	{
//#pragma omp for
//	
//	for (i = 0; i < n; i++)
//	{
//
//		//a = i + 1;
//		printf("thread %d execute loop iteration %d \n ", omp_get_thread_num(), i);
//
//	}
//	//printf("value of a  after execution = %d\n ", a);
//
//}
//}



//Example 2
//int main() {
//	int n = 9;
//	int i;
//	int a;
//#pragma omp parallel for private(i,a)
//	for (i = 0; i < n; i++)
//	{
//		a = i + 1;
//		printf("Thread %d has a value of a = %d for i = %d\n",
//			omp_get_thread_num(), a, i);
//	} /*-- End of parallel for --*/
//}



//
//Example 5
//int main() {
//	int vlen = 9;
//	int a[9] = { 0 };
//	int indx, i, TID;
//	int n = 9;
//	for (i = 0; i < vlen; i++) a[i] = -i - 1;
//	indx = 4;
//	{
//#pragma omp parallel default(none) firstprivate(indx) private(i,TID) shared(n, a)
//		{
//			TID = omp_get_thread_num();
//			indx += n * TID;
//			for (i = indx; i < indx + n; i++) {
//
//				a[i] = TID + 1;
//			}
//		}
//	}
//	printf("After the parallel region:\n");
//	for (i = 0; i < vlen; i++)
//		printf("a[%d] = %d\n", i, a[i]);
//}


//
//#pragma omp parallel for private(i) lastprivate(a)
//for (i = 0; i < n; i++)
//{
//	a = i + 1;
//	printf("Thread %d has a value of a = %d for i = %d\n",
//		omp_get_thread_num(), a, i);
//} /*-- End of parallel for --*/
//printf("Value of a after parallel for: a = %d\n", a);





/*--
int main() {

	int n = 9;
	int i;
	int a;

#pragma omp parallel for shared(n) private(i, a)
		for (i = 0; i < n; i++)
	{

			a = i + 1;
			printf("Thread %d execute loop iteration %d ,value of a = %d\n ", omp_get_thread_num(), i, a);

	}
		printf("value of a  after execution = %d\n ", a);

}
--*/

/*--
int main() {

	int n = 9;
	int i;
	int a[9] = { 0 };

#pragma omp parallel for shared(n)
	for (i = 0; i < n; i++)
	{

		a[i] += i;
		printf("Thread %d has a value of a = %d for i = %d\n", omp_get_thread_num(), a[i], i);

	}
	for (i = 0; i < n; i++)
	{

	printf("value of a = %d; for i = %d\n", a[i], i);
		
	}

}
--*/




//
//int main() {
//	int i, n, chunk;
//	float a[100], b[100], result;
//	n = 100;
//	chunk = 10;
//	result = 0.0;
//	for (i = 0; i < n; i++)
//	{
//		a[i] = i * 1.0;
//		b[i] = i * 2.0;
//	}
//#pragma omp parallel for default(shared) private(i) schedule(static, chunk) reduction(+:result)
//	for (i = 0; i < n; i++)
//	{
//		result = result + (a[i] * b[i]);
//	}
//	printf("final result = %f\n", result);
//}



//Example 7
/*main()
{
	int i, n, chunk;
	float a[100], b[100], result;
	n = 100;
	chunk = 10;
	result = 0.0;
	for (i = 0; i < n; i++)
	{
		a[i] = i * 1.0;
		b[i] = i * 2.0;
	}
#pragma omp parallel for default(shared) private(i) schedule(static, chunk) reduction(+:result)
	{
		for (i = 0; i < n; i++)
		{
			result = result + (a[i] * b[i]);
		}
		printf("Final result= %f\n", result);
	}
}*/
