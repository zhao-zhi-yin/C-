#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "sort.h"


void print_arr(int arr[], int len)
{
    for(int i=0;i<len;i++)
    printf(" %6d ",arr[i]);
}

void bubble_sort(int num[], int len)
{
    int i, j, temp;
    int arr[len];
    for(int i=0;i<len;i++)
    arr[i]=num[i];
    double run_time;
	LARGE_INTEGER time_start;//开始时间
	LARGE_INTEGER time_over;	//结束时间
	double dqFreq;		//计时器频率
	LARGE_INTEGER f;	//计时器频率
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;
	QueryPerformanceCounter(&time_start);
    /* 计时开始 */
    for (i = 0; i < len - 1; i++)
      for (j = 0; j < len - 1 - i; j++)
        if (arr[j] > arr[j + 1])
        {
          temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
        }
    /* 计时结束 */
    QueryPerformanceCounter(&time_over);
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;	//乘以1000000把单位由秒化为微秒，精度为1000 000/（cpu主频）微秒
	printf("\n冒泡排序运行时间：%fus\n",run_time);

    //printf("排序后：\n");
    //print_arr(arr,len);
}
void sort(int num[], int len)
{
    int i, j, temp;
    int arr[len];
    for(int i=0;i<len;i++)
    arr[i]=num[i];
    double run_time;
	LARGE_INTEGER time_start;//开始时间
	LARGE_INTEGER time_over;	//结束时间
	double dqFreq;		//计时器频率
	LARGE_INTEGER f;	//计时器频率
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;
	QueryPerformanceCounter(&time_start);
    /* 计时开始 */
    for (i = 0; i < len - 1; i++)
      for (j = 0; j < len - 1 - i; j++)
        if (arr[j] < arr[j + 1])
        {
          temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
        }
    /* 计时结束 */
    QueryPerformanceCounter(&time_over);
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;	//乘以1000000把单位由秒化为微秒，精度为1000 000/（cpu主频）微秒
	//printf("\n冒泡排序运行时间：%fus\n",run_time);

    //printf("排序后：\n");
    //print_arr(arr,len);
}

void swapp(int *a,int *b) //交換兩個變數
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int num[], int len)
{
    int i,j;
    int arr[len];
    for(int i=0;i<len;i++)
    arr[i]=num[i];
    double run_time;
	LARGE_INTEGER time_start;//开始时间
	LARGE_INTEGER time_over;	//结束时间
	double dqFreq;		//计时器频率
	LARGE_INTEGER f;	//计时器频率
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;
	QueryPerformanceCounter(&time_start);
    /* 计时开始 */
    for (i = 0 ; i < len - 1 ; i++)
    {
        int min = i;
        for (j = i + 1; j < len; j++)     //走訪未排序的元素
            if (arr[j] < arr[min])    //找到目前最小值
                min = j;    //紀錄最小值
           swapp(&arr[min], &arr[i]);    //做交換
    }
    /* 计时结束 */
    QueryPerformanceCounter(&time_over);
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;	//乘以1000000把单位由秒化为微秒，精度为1000 000/（cpu主频）微秒
	printf("\n选择排序运行时间：%fus\n",run_time);

    //printf("排序后：\n");
    //print_arr(arr,len);
}

void insertion_sort(int num[], int len)
{
    int i,j,temp;
    int arr[len];
    for(int i=0;i<len;i++)
    arr[i]=num[i];
    double run_time;
	LARGE_INTEGER time_start;//开始时间
	LARGE_INTEGER time_over;	//结束时间
	double dqFreq;		//计时器频率
	LARGE_INTEGER f;	//计时器频率
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;
	QueryPerformanceCounter(&time_start);
    /* 计时开始 */

    for (i=1;i<len;i++)
    {
      temp = arr[i];
      for (j=i;j>0&&arr[j-1]>temp;j--)
         arr[j] = arr[j-1];
      arr[j] = temp;
    }

   /*
   for(int i=0;i<len-1;i++){
       for(int j=i+1;j>0;j--){
           if(arr[j] < arr[j-1]){
               temp = arr[j-1];
               arr[j-1] = arr[j];
               arr[j] = temp;
           }else{         //不需要交换
               break;
           }
       }
   }*/
     /* 计时结束 */
    QueryPerformanceCounter(&time_over);
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;	//乘以1000000把单位由秒化为微秒，精度为1000 000/（cpu主频）微秒
	printf("\n插入排序运行时间：%fus\n",run_time);

    //printf("排序后：\n");
    //print_arr(arr,len);
}

void shell_sort(int num[],int len)
{

   //int temp = 0;
  // int incre = len;
    int arr[len];
    for(int i=0;i<len;i++)
    arr[i]=num[i];
    double run_time;
	LARGE_INTEGER time_start;//开始时间
	LARGE_INTEGER time_over;	//结束时间
	double dqFreq;		//计时器频率
	LARGE_INTEGER f;	//计时器频率
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;
	QueryPerformanceCounter(&time_start);
    /* 计时开始 */
   /*while(1){
       incre = incre/2;

       for(int k = 0;k<incre;k++){    //根据增量分为若干子序列

           for(int i=k+incre;i<len;i+=incre){

               for(int j=i;j>k;j-=incre){
                   if(arr[j]<arr[j-incre]){
                       temp = arr[j-incre];
                       arr[j-incre] = arr[j];
                       arr[j] = temp;
                   }else{
                       break;
                   }
               }
           }
       }

       if(incre == 1){
           break;
       }
   }
   */
   int gap, i, j;
    int temp;
    for (gap = len >> 1; gap > 0; gap = gap >> 1)
        for (i = gap; i < len; i++) {
            temp = arr[i];
            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
                arr[j + gap] = arr[j];
            arr[j + gap] = temp;
        }
  /* 计时结束 */
    QueryPerformanceCounter(&time_over);
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;	//乘以1000000把单位由秒化为微秒，精度为1000 000/（cpu主频）微秒
	printf("\n希尔排序运行时间：%fus\n",run_time);

    //printf("排序后：\n");
    //print_arr(arr,len);
}

void merge_sort(int num[],int len)
{
    int arr[len];
    for(int i=0;i<len;i++)
    arr[i]=num[i];
    double run_time;
	LARGE_INTEGER time_start;//开始时间
	LARGE_INTEGER time_over;	//结束时间
	double dqFreq;		//计时器频率
	LARGE_INTEGER f;	//计时器频率
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;
	QueryPerformanceCounter(&time_start);
    /* 计时开始 */
    merge_sort1(arr,0,len);
    /* 计时结束 */
    QueryPerformanceCounter(&time_over);
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;	//乘以1000000把单位由秒化为微秒，精度为1000 000/（cpu主频）微秒
	printf("\n归并排序运行时间：%fus\n",run_time);
    //printf("排序后：\n");
    //print_arr(arr,len);
}

void merge_sort1(int num[],int first,int last)
{

  if(first < last){
      int middle = (first + last)/2;
      merge_sort1(num,first,middle);//左半部分
      merge_sort1(num,middle+1,last);//右半部分
      mergeArray(num,first,middle,last); //合并左右部分
  }
}

void mergeArray(int arr[],int first,int middle,int end)
{
  int len_l,len_r;
  len_l=middle-first+1;
  len_r=end-middle;
  int l[len_l],r[len_r];
  memcmp(l,arr+first,sizeof(int)*len_l);
  memcmp(r,arr+middle+1,sizeof(int)*len_r);
  int i=0,j=0,k=first;
  while(i<len_l&&j<len_r)
  {
      arr[k++]=l[i]<r[j]?l[i++]:r[j++];
  }
  while(i<len_l)
  {
      arr[k++]=l[i++];
  }

}

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

void quick_sort_recursive(int arr[], int start, int end)
{
    if (start >= end)
        return;
    int mid = arr[end];
    int left = start, right = end - 1;
    while (left < right) {
        while (arr[left] < mid && left < right)
            left++;
        while (arr[right] >= mid && left < right)
            right--;
        swap(&arr[left], &arr[right]);
    }
    if (arr[left] >= arr[end])
        swap(&arr[left], &arr[end]);
    else
        left++;
    if (left)
        quick_sort_recursive(arr, start, left - 1);
    quick_sort_recursive(arr, left + 1, end);
}

void quick_sort(int num[], int len)
{
    int arr[len];
    for(int i=0;i<len;i++)
    arr[i]=num[i];
    double run_time;
	LARGE_INTEGER time_start;//开始时间
	LARGE_INTEGER time_over;	//结束时间
	double dqFreq;		//计时器频率
	LARGE_INTEGER f;	//计时器频率
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;
	QueryPerformanceCounter(&time_start);
    /* 计时开始 */
    quick_sort_recursive(arr, 0, len - 1);
    /* 计时结束 */
    QueryPerformanceCounter(&time_over);
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;	//乘以1000000把单位由秒化为微秒，精度为1000 000/（cpu主频）微秒
	printf("\n快速排序运行时间：%fus\n",run_time);
    //printf("排序后：\n");
    //print_arr(arr,len);
}

void MinHeap_Sort(int num[],int len)
{
    int temp = 0;
    int arr[len];
    for(int i=0;i<len;i++)
    arr[i]=num[i];
    double run_time;
    LARGE_INTEGER time_start;//开始时间
	LARGE_INTEGER time_over;	//结束时间
	double dqFreq;		//计时器频率
	LARGE_INTEGER f;	//计时器频率
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;
	QueryPerformanceCounter(&time_start);
    /* 计时开始 */
    MakeMinHeap(arr,len);

   for(int i=len-1;i>0;i--)
  {
      temp = arr[0];
      arr[0] = arr[i];
      arr[i] = temp;
      MinHeapFixdown(arr,0,i);
  }
  /* 计时结束 */
    QueryPerformanceCounter(&time_over);
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;	//乘以1000000把单位由秒化为微秒，精度为1000 000/（cpu主频）微秒
	printf("\n堆排序运行时间：  %fus\n",run_time);
    //printf("排序后：\n");
    //print_arr(arr,len);
}

void MakeMinHeap(int a[], int n)
{
 for(int i=(n-1)/2 ; i>=0 ; i--)
 {
     MinHeapFixdown(a,i,n);
 }
}
//从i节点开始调整,n为节点总数 从0开始计算 i节点的子节点为 2*i+1, 2*i+2
void MinHeapFixdown(int a[],int i,int n)
{

   int j = 2*i+1; //子节点
   int temp = 0;

   while(j<n)
    {
       //在左右子节点中寻找最小的
       if(j+1<n && a[j+1]<a[j]){
           j++;
       }
       if(a[i] <= a[j])
           break;

       //较大节点下移
       temp = a[i];
       a[i] = a[j];
       a[j] = temp;
       i = j;
       j = 2*i+1;
   }
}
void Counting_Sort(int num[],int len)
 {
    int arr[len];
    for(int i=0;i<len;i++)
    arr[i]=num[i];
    double run_time;
	LARGE_INTEGER time_start;//开始时间
	LARGE_INTEGER time_over;	//结束时间
	double dqFreq;		//计时器频率
	LARGE_INTEGER f;	//计时器频率
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;
	QueryPerformanceCounter(&time_start);
    /* 计时开始 */
    int bias, min = arr[0], max = arr[0];
    for (int i = 1; i < len; i++)
    {
        if (arr[i] > max)
         max = arr[i];
        if (arr[i] < min)
         min = arr[i];
    }
    bias = 0 - min;
    int bucket[max - min + 1];
    for (int i = 0; i < len; i++)
        {
            bucket[arr[i] + bias]++;
        }
    int index = 0, i = 0;
     while (index < len)
        {
            if (bucket[i] != 0)
            {
                arr[index] = i - bias;
                bucket[i]--;
                index++;
            } else  i++;

        }
    /* 计时结束 */
    QueryPerformanceCounter(&time_over);
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;	//乘以1000000把单位由秒化为微秒，精度为1000 000/（cpu主频）微秒
	printf("\n计数排序运行时间：%fus\n",run_time);
    //printf("排序后：\n");
    //print_arr(arr,len);
}
void Radix_Sort(int num[],int len)
{
   //A:原数组
   //temp:临时数组
   //n:序列的数字个数
   //k:最大的位数2
   //r:基数10
   //cnt:存储bin[i]的个数
    int temp[len];int n=len, k=3,r=800;int cnt[len];
    int arr[len];
    for(int i=0;i<len;i++)
    arr[i]=num[i];
    double run_time;
	LARGE_INTEGER time_start;//开始时间
	LARGE_INTEGER time_over;	//结束时间
	double dqFreq;		//计时器频率
	LARGE_INTEGER f;	//计时器频率
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;
	QueryPerformanceCounter(&time_start);
    /* 计时开始 */
   for(int i=0 , rtok=1; i<k ; i++ ,rtok = rtok*r){

       //初始化
       for(int j=0;j<r;j++){
           cnt[j] = 0;
       }
       //计算每个箱子的数字个数
       for(int j=0;j<n;j++){
           cnt[(arr[j]/rtok)%r]++;
       }
       //cnt[j]的个数修改为前j个箱子一共有几个数字
       for(int j=1;j<r;j++){
           cnt[j] = cnt[j-1] + cnt[j];
       }
       for(int j = n-1;j>=0;j--){      //重点理解
           cnt[(arr[j]/rtok)%r]--;
           temp[cnt[(arr[j]/rtok)%r]] = arr[j];
       }
       for(int j=0;j<n;j++){
           arr[j] = temp[j];
       }
   }
    /* 计时结束 */
    QueryPerformanceCounter(&time_over);
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;	//乘以1000000把单位由秒化为微秒，精度为1000 000/（cpu主频）微秒
	printf("\n基数排序运行时间：%fus\n",run_time);
    //printf("排序后：\n");
    //print_arr(arr,len);
}
