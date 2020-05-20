#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _USE_MATH_DEFINES 
#include <math.h>

extern double p_stdnorm(double z);
extern double Normalization(double x,double mu,double s);
double mu_A = 170.8;//A 県平均
double mu_B = 169.7;//B 県平均
double s_A=5.43;    //A 県標準偏差（s^2 =分散）
double s_B=5.5;     //B 県標準偏差

double L_A=1;//尤度
double L_B=1;
double y_A,y_B;

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

        y_A =Normalization(val,mu_A,s_A);
        y_B =Normalization(val,mu_B,s_B);

        L_A*=p_stdnorm(y_A);
        L_B*=p_stdnorm(y_B);

        //  printf("%lf, %lf\n",y_A,L_A);
        //  printf("%lf, %lf\n\n",y_B,L_B);

    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("L_A: %f\n",L_A);
    printf("L_B: %f\n",L_B);

    return 0;


}

//標準正規分布の確率密度関数
double p_stdnorm(double z)
{
    return exp(-z*z/2) / sqrt(2*M_PI);
}

//標準化の計算
double Normalization(double x,double mu,double s)
{
    return (x-mu)/s;
}