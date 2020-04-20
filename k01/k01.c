#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(int n, double val, double ave);
extern double var_online(int n, double val, double ave, double square_ave);

int main(void)
{
    int n = 1;
    double ave, square_ave, var;
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

    ave = 0;
    square_ave = 0;
    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
        ave = ave_online(n, val, ave);
        var = var_online(n, val, ave, square_ave);
        square_ave = ave_online(n, val * val, square_ave);
        n++;
    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("average : %lf\n", ave);
    printf("variance : %lf\n", var);
    return 0;


}

double ave_online(int n, double val, double ave){
    return ((n - 1) * ave + val) / n;
}

double var_online(int n, double val, double ave, double square_ave){
    return ((n - 1) * square_ave / n) + (val * val / n) - ave * ave;
}

