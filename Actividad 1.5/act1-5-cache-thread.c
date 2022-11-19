/*correr el programa
gcc -fopenmp nombre.c
a.exe >> prueba.txt
*/
#include <stdio.h>
#include <omp.h>
#define NUM_THREADS 6

static long long num_pasos = 12000000;//12,000,000;
double paso;

void main(){
	for(int j = NUM_THREADS; j<=NUM_THREADS; j++){
		int i, nthreads;
		double pi, sum[j], t1, t2, tiempo;
		paso = 1.0/num_pasos;
		omp_set_num_threads(j);
		const double startTime = omp_get_wtime();
		#pragma omp parallel
		{
			int i, id, nthrds;
			double x;
			id = omp_get_thread_num();
			nthrds = omp_get_num_threads();
			if(id == 0)
				nthreads = nthrds;
			for(i = id, sum[id]=0.0; i<num_pasos;i=i+nthrds){
				x=(i+0.5)*paso;
				sum[id]+=4.0/(1.0+x*x);
			}
		}

		for(i=0, pi=0.0; i<nthreads; i++){
			pi+=sum[i]*paso;
		}
		const double endTime = omp_get_wtime();
		tiempo = t2-t1;
		// printf("Pi = (%.16f)\n", pi);
		// printf("%lf) segundos con %d threads\n", (endTime - startTime), j);
		printf("%lf, %d", (endTime - startTime), j);
	}
}