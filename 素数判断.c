#include <stdio.h>

int main()
{
    int n,k;
    printf("Please input a integer number :\n");
    scanf("%d",&n);
    if(n<0)
     printf("%d 不是素数",n);
    for(k=2;k<=n;k++)
    {
        if(n%k==0)
        break;
    }
     if((k==n)||(n==1))
        printf("%d 是素数\n",n);
     else printf("%d 不是素数",n);
}
