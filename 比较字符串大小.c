#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    char s1[80],s2[80];
    printf("Please input s1:\n");
    gets(s1);
    printf("Please input s2:\n");
    gets(s2);
    n=strcmp(s1,s2);
    printf("s1-s2=%d\n",n);
}
