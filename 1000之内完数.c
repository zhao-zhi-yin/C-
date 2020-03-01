#include <stdio.h>
int main()
{
    int n,i,k;

    for(n=6;n<=1000;n++)
    {
        k=0;
        for (i=1;i<n;i++)
            if(n%i==0)
             k=i+k;
              if(n==k)
              {
                printf("%d its factors are 1",n);
                for(i=2;i<=n;i++)
                 if(n%i==0)
                 printf(",%d",i);
                 printf("\n");
              }
    }
}
