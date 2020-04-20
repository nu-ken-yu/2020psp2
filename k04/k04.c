#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct heights{
    int gender;
    double heights;
} man_data;

int main(void)
{
    int n = 0;
    char fname[FILENAME_MAX];
    char buf[256];
    man_data man[100];
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
    fgets(buf, sizeof(buf), fp);
    while(fgets(buf, sizeof(buf), fp) != NULL){
        sscanf(buf, "%d, %lf", &man[n].gender, &man[n].heights);
        printf("%d, %lf\n", man[n].gender, man[n].heights);
        n++;
    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }


    return 0;


}