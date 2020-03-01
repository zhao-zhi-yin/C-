#include <stdio.h>
#define N 3
#define M 80
 void main
{
    char a[N][M];
    int i,j;
    int little=0,big=0,number=0,blank=0,other=0;
    puts("请输入3行80字符的文章：\n");
    gets(a[N][M]);
    for(i=0;i<=N;i++)
        for(j=0;j<=M;j++)
            if(a[N][M]!='\0')
          if(a[N][M]>='a'&&a[N][M]<='z')
               little++;
          else if(a[N][M]>='A'&&a[N][M]<='Z')
                big++;
          else if(a[N][M]>='0'&&a[N][M]<='9')
                number++;
          else if(a[N][M]==' ')
                blank++;
            else other++;

}
