#include <stdio.h>
#include <stdlib.h>

void populate_array(int *array,size_t arraySize,int(*getNextValue)(void))
{
    for (size_t i=0;i<arraySize;i++)
        array[i]=getNextValue();
}

int getNextRandomValue(void)
{
    return rand();
}

int main(void)
{
    int myarray[10];
    populate_array(myarray,10,getNextRandomValue);
    for(int i=0;i<10;i++)
    {
        printf("%d  ",myarray[i]);
    }
    printf("\n");
    return 0;
}
