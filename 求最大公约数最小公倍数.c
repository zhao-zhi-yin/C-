#include <stdio.h>

int main()
{
    int a,b,c,n,m;
    printf("Please input two numbers:\n");
    scanf("%d %d",&a,&b);
    if(a<b)
    {
        m=a;
        a=b;
        b=m;
    }
    n=a*b;
    c=a%b;
    while(c!=0)  //Õ·×ªÏà³ý·¨
    {
        a=b;
        b=c;
        c=a%b;
    }
    printf("The greatest common divisor is :%d\n",b);
    printf("The least common multiple is :%d\n",n/b);
    return 0;
}
