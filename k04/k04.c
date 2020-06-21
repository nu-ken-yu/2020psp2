#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct heights{
    double id;
    char gender[10];
    double heights;
} man_data;

int main(void)
{
    int i;
    int tbl_gender;
    int n = 0;
    char fname_height[FILENAME_MAX];
    char fname_ID[FILENAME_MAX];
    char buf_height[256];
    char buf_ID[254];
    double input_id;
    man_data man[100];
    FILE* fp_height, * fp_ID;

    printf("input the filename of sample height:");
    fgets(fname_height,sizeof(fname_height),stdin);
    fname_height[strlen(fname_height)-1] = '\0';
    
    printf("input the filename of sample ID:");
    fgets(fname_ID,sizeof(fname_ID),stdin);
    fname_ID[strlen(fname_ID)-1] = '\0';
    printf("Which ID's data do you want? : ");
    scanf("%lf", &input_id);

    fp_height = fopen(fname_height,"r");
    if(fp_height==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    fp_ID = fopen(fname_ID, "r");
    if(fp_ID==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    fgets(buf_height, sizeof(buf_height), fp_height);
    while(fgets(buf_height, sizeof(buf_height), fp_height) != NULL && fgets(buf_ID, sizeof(buf_ID), fp_ID) != NULL){
        sscanf(buf_ID, "%lf", &man[n].id);
        sscanf(buf_height, "%d, %lf", &tbl_gender, &man[n].heights);
        if(tbl_gender == 1){
            strcpy(man[n].gender, "Male");
        }
        else{
            strcpy(man[n].gender, "Female");
        }
        n++;
    }

    printf("\n");
    for(i = 0; i < n; i++){
        if(input_id == man[i].id){
            printf("ID : %.0lf\n", man[i].id);
            printf("Gender : %s\n", man[i].gender);
            printf("Heights : %.2lf\n", man[i].heights);
            break;
        }
        else{
            continue;
        }
    }

    if(i == n){
        printf("NO data\n");
    }

    if(fclose(fp_height) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    if(fclose(fp_ID) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    return 0;


}