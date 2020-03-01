#include <stdio.h>
int main()
{
    int a,b,c;
    for (a=0;a<10;a++)
      for (b=0;b<10;b++)
        for (c=0;c<10;c++)
        if((a*a*a+b*b*b+c*c*c)==(a+b*10+c*100))
        printf("水仙花数是%d \n",a+b*10+c*100);
}
