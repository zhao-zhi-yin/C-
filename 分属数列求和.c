#include <stdio.h>

int main()
{
    double i=1.0,j=2.0,k,n,m,sum=0.0;
    for (m=0;m<20;m++)
    {
        n=i+j;
        sum=j/i+sum;
        k=j;
        j=n;
        i=k;
    }
    printf("2/1+3/2+5/3+8/5+....=%f\n",sum);
}
