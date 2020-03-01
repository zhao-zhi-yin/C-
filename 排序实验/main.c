#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "create.h"
#include "sort.h"

int main()
{
    int num[880];
    srand( (unsigned)time( NULL ) );
    RangedRandDemo(0 ,800 ,800,num);   //生成0-100的100个随机数
    //冒泡排序
    bubble_sort(num,Len);
    sort(num,Len);
    //选择排序
    selection_sort(num,Len);
    sort(num,Len);
    //插入排序
    insertion_sort(num,Len);
    sort(num,Len);
    //希尔排序
    shell_sort(num,Len);
    sort(num,Len);
    //归并排序
    merge_sort(num,Len);
    sort(num,Len);
    //快速排序
    quick_sort(num,Len);
    sort(num,Len);
    //堆排序
    MinHeap_Sort(num,Len);
    sort(num,Len);
    //计数排序
    Counting_Sort(num,Len);
    sort(num,Len);
    //基数排序
    Radix_Sort(num,Len);
    sort(num,Len);
    //for(int i=0;i<Len;i++)
    //printf(" %6d ",num[i]);
}

