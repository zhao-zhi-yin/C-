#include <stdio.h>
#include <string.h>
#define n 3
    struct student
    {
        char num[10];
        char name[10];
        char sub[4];
        float usual;
        float exam;
        float total;
    }stu[n];
 int Input(struct student stu[])
    {
        int i;
        for(i=0;i<n;i++)
        {
            printf("NO.%d student number:",i+1);
            scanf("%s",&stu[i].num);
            printf("NO.%d name:",i+1);
            scanf("%s",&stu[i].name);
            printf("NO.%d usual score and exam score:",i+1);
            scanf("%2f%2f",&stu[i].usual,&stu[i].exam);
            printf("\n");
        }

    }

float count(float usu,float exa)
    {
        float toul;
        toul=0.2*usu+0.8*exa;
        return(toul);
    }
int Output(struct student stu[n])
    {
        int i;
        for(i=0;i<n;i++)
         printf("%5s %8s %8s       %.2f        %.2f       %.2f\n",stu[i].num,stu[i].name,stu[i].sub,stu[i].usual,stu[i].exam,stu[i].total);
    }
 int Compare_1(struct student stu[n])
    {
       int i,k;
       float max;
       max=0;
       for(i=0;i<n;i++)
        if(stu[i].total>max)
        {max=stu[i].total;
          k=i;
        }
        return k;
    }

    int Compare_2(struct student stu[n])
    {
       int i,k;
       float min;
       min=100;
       for(i=0;i<n;i++)
        if(stu[i].total<min)
          {min=stu[i].total;
          k=i;
          }
        return k;
    }

int main()
{
    int i;
    int max;
    int min;
    struct student stu[n];
    Input(stu);
    for(i=0;i<n;i++)
    {
     strcpy(stu[i].sub,"math");
     stu[i].total=count(stu[i].usual,stu[i].exam);
    }
    printf("\n The students' information is:\n");
    printf(" number   name  subject  usual score  exam score   total score  \n");

    Output(stu);
    max=Compare_1(stu);
    min=Compare_2(stu);
    printf("the max total score student is %s %s\n",stu[max].num,stu[max].name);
    printf("the min total score student is %s %s\n",stu[min].num,stu[min].name);
}


