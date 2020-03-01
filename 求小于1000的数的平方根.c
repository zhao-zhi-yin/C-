#include <stdio.h>

int main()
{
    int a,n,S,k,m;
    S=0;
    k=1;
    printf("Please input two numbers a:  n:\n");
    scanf("%d%d",&a,&n);
    m=a;
    if(a>0&&n>0)
    {
    while(k<=n)
    {
      S=a+S;
      a=m+a*10;
      k++;
    }
    printf("S=a+aa+aaa+...+aa...a(n¸öa)=%d\n",S);
    }
    else  printf("It is fault£¡£¡£¡\n");
}
