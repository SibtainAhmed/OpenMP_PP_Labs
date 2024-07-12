// lab_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <omp.h>
#include <stdio.h>
///*--
int main() {
#pragma omp parallel
    {
     printf("The parallel region is executed by thread %d\n",
     omp_get_thread_num());
    } 
}
//--*/

///*--
int main() {
    omp_set_dynamic(0);
    omp_set_num_threads(16);
#pragma omp parallel num_threads(10)
    {
     printf("Num threads in parallel region=%d\n", 
     omp_get_num_threads());
    }
}
//--*/

///*--
int main() {

    omp_set_dynamic(1);
    omp_set_num_threads(10);
#pragma omp parallel //parallel region 1
    {
     printf("Num threads in dynamic region=%d\n", 
            omp_get_num_threads());
    }

 omp_set_dynamic(0);
 omp_set_num_threads(10);
#pragma omp parallel //parallel region 2
    {
     printf("Num threads in non-dynamic region=%d\n",
            omp_get_num_threads());
    }
 
 omp_set_dynamic(1);
#pragma omp parallel //parallel region 3
    {
    #pragma omp parallel
        {
         printf("Num threads in nesting disabled region=%d\n",
                omp_get_num_threads());
        }
    }

omp_set_nested(1);
#pragma omp parallel //parallel region 4
    {
    #pragma omp parallel
        {
         printf("Num threads in nested region=%d\n", 
                omp_get_num_threads());
        }
    }
}

//--*/


///*--
int main() {
#pragma omp parallel
    {
        // Infinite loop
        while (1) {  
        }
    }
    return 0;
}
//--*/