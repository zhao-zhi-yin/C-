#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "create.h"
#include "sort.h"

int main()
{
    int num[880];
    srand( (unsigned)time( NULL ) );
    RangedRandDemo(0 ,800 ,800,num);   //����0-100��100�������
    //ð������
    bubble_sort(num,Len);
    sort(num,Len);
    //ѡ������
    selection_sort(num,Len);
    sort(num,Len);
    //��������
    insertion_sort(num,Len);
    sort(num,Len);
    //ϣ������
    shell_sort(num,Len);
    sort(num,Len);
    //�鲢����
    merge_sort(num,Len);
    sort(num,Len);
    //��������
    quick_sort(num,Len);
    sort(num,Len);
    //������
    MinHeap_Sort(num,Len);
    sort(num,Len);
    //��������
    Counting_Sort(num,Len);
    sort(num,Len);
    //��������
    Radix_Sort(num,Len);
    sort(num,Len);
    //for(int i=0;i<Len;i++)
    //printf(" %6d ",num[i]);
}

