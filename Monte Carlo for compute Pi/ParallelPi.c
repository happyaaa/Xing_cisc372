#include <omp.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define SEED 42

int main(int argc, char* argv)
{
    int niter=0;
    double x,y;
    int i,tid,count = 0; /* # of points in the 1st quadrant of unit circle
*/
 //   omp_set_num_threads(8);
    double z;
    double pi;
  //  time_t rawtime;
  //  struct tm * timeinfo;

    printf("Enter the number of iterations used to estimate pi: ");
    scanf("%d",&niter);
   // time ( &rawtime );
   // timeinfo = localtime ( &rawtime );
   // printf ( "The current date/time is: %s", asctime (timeinfo) );
     double st = omp_get_wtime();
    /* initialize random numbers */
    srand(SEED);
    count = 0;
    #pragma omp parallel  for  private(x,y,z,tid) reduction(+:count)
    for ( i=0; i<niter; i++) {
      unsigned int seed;
        x = (double)rand_r(&seed)/RAND_MAX;
        y = (double)rand_r(&seed)/RAND_MAX;
        z = (x*x+y*y);
      if (z<=1) count++;
      }
      pi=(double)count/niter*4;
    double runtime = omp_get_wtime() - st;
    printf(" total: %f s\n", runtime);
    printf(" the total count is %i\n",count);
    printf("# of trials= %d , estimate of pi is %g \n",niter,pi);
    return 0;
}

