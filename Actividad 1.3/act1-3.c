#include <stdio.h>
#include "omp.h"
#define NUM_THREADS 18

//3,6,9,12,15,18

int main(){
    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel
    {
        int ID = omp_get_thread_num();
        //printf("Procesadores (%d)", ID);
        //printf("Multiples (%d)", ID);
        //printf("En Accion (%d) --- %d\n", ID);
        printf("%d\n", ID);
    }
}

// gcc -fopenmp _file.c_ 
// export OMP_NUM_THREADS = 6
// ./a.out