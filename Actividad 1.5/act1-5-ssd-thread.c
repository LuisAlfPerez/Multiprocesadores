#include <stdio.h>
#include <omp.h>
#include <math.h>
#define NUM_THREADS 6

   FILE *fptr;
   FILE *fptr1;
   FILE *fptr2;
   FILE *fptr3;
   FILE *fptr4;
   FILE *fptr5;
void iteracion(int N,FILE *x);

int main(){
  long N = 2000000;  
  omp_set_num_threads(NUM_THREADS);
  const double startTime = omp_get_wtime();
  fptr=fopen("Euler_n_0.txt","w");
  fptr1=fopen("Euler_n_1.txt","w");
  fptr2=fopen("Euler_n_2.txt","w");
  fptr3=fopen("Euler_n_3.txt","w");
  fptr4=fopen("Euler_n_4.txt","w");
  fptr5=fopen("Euler_n_5.txt","w");

  #pragma omp parallel
  {
    #pragma omp sections
    {
      #pragma omp section
        (void)iteracion(N,fptr);//20//2000900
      #pragma omp section
        (void)iteracion(N+1,fptr1);//200//2000400
      #pragma omp section
        (void)iteracion(N+2,fptr2);//2000//2000700
      #pragma omp section
        (void)iteracion(N+3,fptr3);//20000//2000800
      #pragma omp section
        (void)iteracion(N+4,fptr4);//200000//2000500
      #pragma omp section
        (void)iteracion(N+5,fptr5);//2000000//2000100
    }
  }
  fclose(fptr);
  fclose(fptr1);
  fclose(fptr2);
  fclose(fptr3);
  fclose(fptr4);
  fclose(fptr5);
  const double endTime = omp_get_wtime();
  printf("%lf", (endTime - startTime));
  return (0);
}

void iteracion(int N, FILE *x){
  printf("Numero de pasos:%d Atendido por thread:%d\n", N,omp_get_thread_num());
  fprintf(x, "Datos que encuentra el metodo de Euler(variable ind.\t variable dep.\t numero de thread)\n");
  double h,t,w,ab;
  double w0=0.5,a=0,b=2.0;
  int i;
  w=w0;
  //fprintf(x, "%f\t %f\n", a, w);
  h=(b-a)/N;
  for(i=0;i<N;i++){
      t=a+(h*i);
      // ab=t*t;
      w=w+h*(w-log(t)+1.0); //w=w+h*(w-ab+1); 
      fprintf(x, "%f\t %f \t numero de thread:%d\n", t+h, w,omp_get_thread_num());
  } 
}