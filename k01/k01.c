#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave,int count);
extern double var_online(double val,double ave,double square_ave,int count);

int main(void)
{
    int gen;
    double val;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;

    double average=0;//平均
    double square_ave=0;//二乗の平均
    double variance=0;//分散

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    fgets(buf,sizeof(buf),fp);//一行目の[gender, hight(cm)]を読み飛ばす

    int count=0;
    double ave_before;//直前の平均を保持
    double sq_ave_before;//直前の二乗平均を保持
    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%d, %lf",&gen,&val);

        count ++;
        ave_before = average;
        sq_ave_before=square_ave;

        //平均値
        average = ave_online(val, ave_before,count);
        //分散値
        square_ave =ave_online(pow(val,2),sq_ave_before,count);
        variance = var_online(val,ave_before,sq_ave_before,count);

    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    double U_variance=variance/(count-1)*count;

    //表示
    printf("平均：%lf\n分散：%lf\n",average,variance);
    printf("母集団平均(推定値):%lf\n",average);
    printf("母集団分散(推定値):%lf\n",U_variance);
    

    return 0;

}

//平均計算
double ave_online(double val, double ave,int count)
{
    double N=(double)count;
    return ((N-1)/N*ave + val/N);

}
//分散計算
double var_online(double val, double ave, double square_ave,int count)
{
    double N=(double)count;
    return ((N-1)/N*square_ave + val*val/N) - pow(((N-1)/N*ave + val/N), 2);

}
