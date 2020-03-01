#include <stdio.h>

int main()
{
    int a[5]={8,6,5,4,1};
    int k,i;
    for(i=0;i<5/2;i++)
    {
        k=a[i];
        a[i]=a[4-i];
        a[4-i]=k;
    }
    printf("a[5]=");
    for(i=0;i<5;i++)
    printf("%d ",a[i]);
}
