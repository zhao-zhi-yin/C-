#include <stdio.h>
#include <stdlib.h>

#define NUM 3

struct person
{
    char name[20];
    char phone[10];
};

void main()
{
    struct person man[NUM];
    int i;

    for(i=0;i<NUM;i++)
    {
        printf("please input name:\n");
        gets(man[i].name);
        printf("please input phone number:\n");
        gets(man[i].phone);

    }
    printf("\tname\t\t\t\t\tphone\n\n");
    for(i=0;i<NUM;i++)
    {
        printf("%20s\t\t\t%20s\n",man[i].name,man[i].phone);
    }

}
