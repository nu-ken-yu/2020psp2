#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double r_unif(void);
extern double r_norm(void);

int main(void)
{
    double val;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
        printf("%lf  %lf\n", val, val + r_norm());
    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
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

