#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//学生番号・性別・身長
struct student{
    int num;
    int gen;
    double height;
};

int main(){
    int num;
    int gen;
    double height;
    int input;
    int i;
    int count;
    struct student* sp;

    //ファイルオープン処理===========================
    char fname[FILENAME_MAX];
    char buf1[256];
    char buf2[256];
    FILE* fp1;
    FILE* fp2;

    printf("input the filename of height:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp1 = fopen(fname,"r");
    if(fp1==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("input the filename of IDs:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp2 = fopen(fname,"r");
    if(fp2==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
    //============================================

    struct student stData[14];
    fgets(buf1,sizeof(buf1),fp1);//一行目の[gender, hight(cm)]を読み飛ばす

    sp=stData;
    count=0;
    while (1){
        if(fgets(buf1,sizeof(buf1),fp1) ==NULL)//height読み込み,最後までロードしたら終了
            break;
        fgets(buf2,sizeof(buf2),fp2);   //IDs読み込み

        sscanf(buf1,"%d, %lf",&gen,&height);
        sscanf(buf2,"%d",&num);

        sp->gen=gen;
        sp->height=height;
        sp->num=num;

        sp++;
        count++;
    }

    //検索numの入力
    printf("which ID's data do you want?:");
    scanf("%d",&input);

    for (i=0; i<count; i++)
    {
        if (stData[i].num == input)
        {
            printf("---\n");
            printf("ID:%d\n",stData[i].num);
            if(stData[i].gen==1)
                printf("gender:male\n");
            else
                printf("gender:female\n");
            printf("height:%.3lf\n",stData[i].height);
            printf("---\n");
            return 0;
        }
    }
    printf("no data\n");
    return 0;

}