#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#ifdef CONST_SEED
#define RAND_SEED 2020
#else
#include<time.h>
#define RAND_SEED ((unsigned)time(NULL))
#endif

extern double r_unif(void);
extern double r_norm(void);

int main(int argc, char* argv[])
{
    int i, n;
    double x, mu, stdvar;
   
    sscanf(argv[1], "%lf", &mu);
    sscanf(argv[2], "%lf", &stdvar);
    sscanf(argv[3], "%d", &n);

    printf("============================================\n");
    printf("template mean: %lf\n", mu);
    printf("template standard deviation: %lf\n", stdvar);
    printf("Num of dummy data: %d\n", n);
    printf("============================================\n");

    srand(RAND_SEED);
    for(i = 0; i < n; i++){
        x = sqrt(stdvar) * r_norm() + mu;
        printf("%lf\n", x);
    }

    return 0;


}

double r_unif(void)
{
    return (double)(rand()+1)/(RAND_MAX+2);
}
  
double r_norm(void)
{  
    return sqrt( -2.0*log(r_unif()) ) * sin( 2.0*M_PI*r_unif() );
} 

