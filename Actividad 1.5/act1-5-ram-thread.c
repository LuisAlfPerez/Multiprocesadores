#include <stdio.h>
#include <omp.h>
#include <math.h>
#define NUM_THREADS 6
#define STEPS 2000000

FILE *fptr;
//int N = 2000000;
double result[NUM_THREADS][STEPS];
void iteracion(int N);

int main(){  
  
  omp_set_num_threads(NUM_THREADS);
  const double startTime = omp_get_wtime();

  #pragma omp parallel
  {
    #pragma omp sections
    {
      #pragma omp section
        (void)iteracion(STEPS);//20//2000900
      #pragma omp section
        (void)iteracion(STEPS+1);//200//2000400
      #pragma omp section
        (void)iteracion(STEPS+2);//2000//2000700
      #pragma omp section
        (void)iteracion(STEPS+3);//20000//2000800
      #pragma omp section
        (void)iteracion(STEPS+4);//200000//2000500
      #pragma omp section
        (void)iteracion(STEPS+5);//2000000//2000100
    }
  }
  const double endTime = omp_get_wtime();
  printf("%lf", (endTime - startTime));
  fptr=fopen("Euler_ram.txt","w");
  fprintf(fptr, "Thread\t Step\t Result\n");
  double h=2.0/STEPS;
    for(int i=0;i<STEPS;i++)
      for(int j=0; j<NUM_THREADS; j++)
        fprintf(fptr, "%d\t %f\t %f\n", j, h*i, result[j][i]);
  fclose(fptr);
  return (0);
}

void iteracion(int N){
  printf("Numero de pasos:%d Atendido por thread:%d\n", N,omp_get_thread_num());
  //fprintf(x, "Datos que encuentra el metodo de Euler(variable ind.\t variable dep.\t numero de thread)\n");
  double h,t,w,ab;
  double w0=0.5,a=0,b=2.0;
  int i;
  w=w0;
  //fprintf(x, "%f\t %f\n", a, w);
  h=(b-a)/N;
  for(i=0;i<N;i++){
      t=a+(h*i);
      // ab=t*t;
      w=w+h*(w-t*t+1.0); //w=w+h*(w-ab+1); 
      result[omp_get_thread_num()][i] = w;
      // fprintf(x, "%f\t %f \t numero de thread:%d\n", t+h, w,omp_get_thread_num());
  } 
}
