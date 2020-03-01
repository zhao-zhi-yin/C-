#include <stdio.h>

int  main()
{
    int a[14][14];
     int i,j,k,n=10;
      printf("%d行杨辉三角如下：\n",n);
    for(i=1;i<=n;i++)
        a[i][1] = a[i][i] = 1;  /*两边的数令它为1，因为现在循环从1开始，就认为a[i][1]为第一个数*/
    for(i=3;i<=n;i++)
        for(j=2;j<=i-1;j++)
            a[i][j]=a[i-1][j-1]+a[i-1][j];  /*除两边的数外都等于上两顶数之和*/
  for(i=1;i<=n;i++)
    {
       // for(k=1;k<=n-i;k++)
         //   printf("   ");
        for(j=1;j<=i;j++)  /*j<=i的原因是不输出其它的数，只输出我们想要的数*/
            printf("%4d",a[i][j]);
         printf("\n");
    }
    printf("\n");  /*当一行输出完以后换行继续下一行的输出*/
}
