#include <stdio.h>

int main()
{
    int a[10]={1,3,5,7,9};
    int k,i,j;
    printf("请输入一个要插入的数:\n");
    scanf("%d",&k);
    for (i=0;i<=4;i++)
      if(k<=a[i]&&k>a[i-1])
        {
            for(j=4;j>=i;j--)
            a[j+1]=a[j];
            a[i]=k;
        }
        for(i=0;i<=5;i++)
        printf("%d ",a[i]);
}
