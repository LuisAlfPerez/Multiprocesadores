#include <stdio.h>
#include <time.h>
#include "omp.h"
#define NUM_SAMPLES 10000000000 //10,000,000,000

//3,6,9,12,15,18
double area, delta, area_delta, x;

int main(){
    printf("Inicia\n");
    // time_t seconds;
    // seconds = time(NULL);
    area = 0;
    delta = 1.0/NUM_SAMPLES;
    // printf("%f\n", delta);
    for(int i = 1; i<=NUM_SAMPLES; i++){
        // printf("%d\n", i);
        x = i*delta;
        area += 4.0/(1.0+x*x);
    }
    printf("El resultado es %f\n",area*delta);
    //printf("El resultado es %d y se realizo en %ld segundos\n",area, seconds-time(NULL));
    return 0;
}

// gcc -fopenmp _file.c_ 
// export OMP_NUM_THREADS = 6
// ./a.out