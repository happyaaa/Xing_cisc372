#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <omp.h>
#define SEED 478 //seed for generating random number

int main(int argc, char* argv)
{
   int niter=0;
   double x,y;
   int i,count=0; /* # of points in the 1st quadrant of unit circle */
   double z;
   double pi;

   printf("Enter the number of iterations used to estimate pi: ");
   scanf("%d",&niter);
   double st = omp_get_wtime();

   /* initialize random numbers */
   srand(SEED);
   count=0;
   for ( i=0; i<niter; i++) {
     /*randomly generate x,y points*/
      x = (double)rand()/RAND_MAX;
      y = (double)rand()/RAND_MAX;
     /*calculate x^2 + y^2 to check if it lies within the circle,
     if yes, increase the count*/
      z = x*x+y*y;
      if (z<=1) count++;
      }
   /*using the formala to calculate pi*/
   pi=(double)count/niter*4;
   double runtime = omp_get_wtime() - st;
   printf(" total: %f s\n", runtime);
   printf("# of trials= %d , estimate of pi is %g \n",niter,pi);
   return 0;
}
