#include <stdio.h>

int main()
{
    int n,i,k;
    k=1;
    for(i=0;i<9;i++)
    {
       n=2*(k+1);
       k=n;
    }

        printf("��һ��ժ��%d����",n);
}
