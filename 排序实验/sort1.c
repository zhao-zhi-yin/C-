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
	LARGE_INTEGER time_start;//��ʼʱ��
	LARGE_INTEGER time_over;	//����ʱ��
	double dqFreq;		//��ʱ��Ƶ��
	LARGE_INTEGER f;	//��ʱ��Ƶ��
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;
	QueryPerformanceCounter(&time_start);
    /* ��ʱ��ʼ */
    for (i = 0; i < len - 1; i++)
      for (j = 0; j < len - 1 - i; j++)
        if (arr[j] > arr[j + 1])
        {
          temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
        }
    /* ��ʱ���� */
    QueryPerformanceCounter(&time_over);
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;	//����1000000�ѵ�λ���뻯Ϊ΢�룬����Ϊ1000 000/��cpu��Ƶ��΢��
	printf("\nð����������ʱ�䣺%fus\n",run_time);

    //printf("�����\n");
    //print_arr(arr,len);
}
void sort(int num[], int len)
{
    int i, j, temp;
    int arr[len];
    for(int i=0;i<len;i++)
    arr[i]=num[i];
    double run_time;
	LARGE_INTEGER time_start;//��ʼʱ��
	LARGE_INTEGER time_over;	//����ʱ��
	double dqFreq;		//��ʱ��Ƶ��
	LARGE_INTEGER f;	//��ʱ��Ƶ��
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;
	QueryPerformanceCounter(&time_start);
    /* ��ʱ��ʼ */
    for (i = 0; i < len - 1; i++)
      for (j = 0; j < len - 1 - i; j++)
        if (arr[j] < arr[j + 1])
        {
          temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
        }
    /* ��ʱ���� */
    QueryPerformanceCounter(&time_over);
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;	//����1000000�ѵ�λ���뻯Ϊ΢�룬����Ϊ1000 000/��cpu��Ƶ��΢��
	//printf("\nð����������ʱ�䣺%fus\n",run_time);

    //printf("�����\n");
    //print_arr(arr,len);
}

void swapp(int *a,int *b) //���Q�ɂ�׃��
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
	LARGE_INTEGER time_start;//��ʼʱ��
	LARGE_INTEGER time_over;	//����ʱ��
	double dqFreq;		//��ʱ��Ƶ��
	LARGE_INTEGER f;	//��ʱ��Ƶ��
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;
	QueryPerformanceCounter(&time_start);
    /* ��ʱ��ʼ */
    for (i = 0 ; i < len - 1 ; i++)
    {
        int min = i;
        for (j = i + 1; j < len; j++)     //���Lδ�����Ԫ��
            if (arr[j] < arr[min])    //�ҵ�Ŀǰ��Сֵ
                min = j;    //�o���Сֵ
           swapp(&arr[min], &arr[i]);    //�����Q
    }
    /* ��ʱ���� */
    QueryPerformanceCounter(&time_over);
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;	//����1000000�ѵ�λ���뻯Ϊ΢�룬����Ϊ1000 000/��cpu��Ƶ��΢��
	printf("\nѡ����������ʱ�䣺%fus\n",run_time);

    //printf("�����\n");
    //print_arr(arr,len);
}

void insertion_sort(int num[], int len)
{
    int i,j,temp;
    int arr[len];
    for(int i=0;i<len;i++)
    arr[i]=num[i];
    double run_time;
	LARGE_INTEGER time_start;//��ʼʱ��
	LARGE_INTEGER time_over;	//����ʱ��
	double dqFreq;		//��ʱ��Ƶ��
	LARGE_INTEGER f;	//��ʱ��Ƶ��
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;
	QueryPerformanceCounter(&time_start);
    /* ��ʱ��ʼ */

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
           }else{         //����Ҫ����
               break;
           }
       }
   }*/
     /* ��ʱ���� */
    QueryPerformanceCounter(&time_over);
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;	//����1000000�ѵ�λ���뻯Ϊ΢�룬����Ϊ1000 000/��cpu��Ƶ��΢��
	printf("\n������������ʱ�䣺%fus\n",run_time);

    //printf("�����\n");
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
	LARGE_INTEGER time_start;//��ʼʱ��
	LARGE_INTEGER time_over;	//����ʱ��
	double dqFreq;		//��ʱ��Ƶ��
	LARGE_INTEGER f;	//��ʱ��Ƶ��
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;
	QueryPerformanceCounter(&time_start);
    /* ��ʱ��ʼ */
   /*while(1){
       incre = incre/2;

       for(int k = 0;k<incre;k++){    //����������Ϊ����������

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
  /* ��ʱ���� */
    QueryPerformanceCounter(&time_over);
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;	//����1000000�ѵ�λ���뻯Ϊ΢�룬����Ϊ1000 000/��cpu��Ƶ��΢��
	printf("\nϣ����������ʱ�䣺%fus\n",run_time);

    //printf("�����\n");
    //print_arr(arr,len);
}

void merge_sort(int num[],int len)
{
    int arr[len];
    for(int i=0;i<len;i++)
    arr[i]=num[i];
    double run_time;
	LARGE_INTEGER time_start;//��ʼʱ��
	LARGE_INTEGER time_over;	//����ʱ��
	double dqFreq;		//��ʱ��Ƶ��
	LARGE_INTEGER f;	//��ʱ��Ƶ��
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;
	QueryPerformanceCounter(&time_start);
    /* ��ʱ��ʼ */
    merge_sort1(arr,0,len);
    /* ��ʱ���� */
    QueryPerformanceCounter(&time_over);
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;	//����1000000�ѵ�λ���뻯Ϊ΢�룬����Ϊ1000 000/��cpu��Ƶ��΢��
	printf("\n�鲢��������ʱ�䣺%fus\n",run_time);
    //printf("�����\n");
    //print_arr(arr,len);
}

void merge_sort1(int num[],int first,int last)
{

  if(first < last){
      int middle = (first + last)/2;
      merge_sort1(num,first,middle);//��벿��
      merge_sort1(num,middle+1,last);//�Ұ벿��
      mergeArray(num,first,middle,last); //�ϲ����Ҳ���
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
	LARGE_INTEGER time_start;//��ʼʱ��
	LARGE_INTEGER time_over;	//����ʱ��
	double dqFreq;		//��ʱ��Ƶ��
	LARGE_INTEGER f;	//��ʱ��Ƶ��
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;
	QueryPerformanceCounter(&time_start);
    /* ��ʱ��ʼ */
    quick_sort_recursive(arr, 0, len - 1);
    /* ��ʱ���� */
    QueryPerformanceCounter(&time_over);
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;	//����1000000�ѵ�λ���뻯Ϊ΢�룬����Ϊ1000 000/��cpu��Ƶ��΢��
	printf("\n������������ʱ�䣺%fus\n",run_time);
    //printf("�����\n");
    //print_arr(arr,len);
}

void MinHeap_Sort(int num[],int len)
{
    int temp = 0;
    int arr[len];
    for(int i=0;i<len;i++)
    arr[i]=num[i];
    double run_time;
    LARGE_INTEGER time_start;//��ʼʱ��
	LARGE_INTEGER time_over;	//����ʱ��
	double dqFreq;		//��ʱ��Ƶ��
	LARGE_INTEGER f;	//��ʱ��Ƶ��
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;
	QueryPerformanceCounter(&time_start);
    /* ��ʱ��ʼ */
    MakeMinHeap(arr,len);

   for(int i=len-1;i>0;i--)
  {
      temp = arr[0];
      arr[0] = arr[i];
      arr[i] = temp;
      MinHeapFixdown(arr,0,i);
  }
  /* ��ʱ���� */
    QueryPerformanceCounter(&time_over);
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;	//����1000000�ѵ�λ���뻯Ϊ΢�룬����Ϊ1000 000/��cpu��Ƶ��΢��
	printf("\n����������ʱ�䣺  %fus\n",run_time);
    //printf("�����\n");
    //print_arr(arr,len);
}

void MakeMinHeap(int a[], int n)
{
 for(int i=(n-1)/2 ; i>=0 ; i--)
 {
     MinHeapFixdown(a,i,n);
 }
}
//��i�ڵ㿪ʼ����,nΪ�ڵ����� ��0��ʼ���� i�ڵ���ӽڵ�Ϊ 2*i+1, 2*i+2
void MinHeapFixdown(int a[],int i,int n)
{

   int j = 2*i+1; //�ӽڵ�
   int temp = 0;

   while(j<n)
    {
       //�������ӽڵ���Ѱ����С��
       if(j+1<n && a[j+1]<a[j]){
           j++;
       }
       if(a[i] <= a[j])
           break;

       //�ϴ�ڵ�����
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
	LARGE_INTEGER time_start;//��ʼʱ��
	LARGE_INTEGER time_over;	//����ʱ��
	double dqFreq;		//��ʱ��Ƶ��
	LARGE_INTEGER f;	//��ʱ��Ƶ��
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;
	QueryPerformanceCounter(&time_start);
    /* ��ʱ��ʼ */
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
    /* ��ʱ���� */
    QueryPerformanceCounter(&time_over);
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;	//����1000000�ѵ�λ���뻯Ϊ΢�룬����Ϊ1000 000/��cpu��Ƶ��΢��
	printf("\n������������ʱ�䣺%fus\n",run_time);
    //printf("�����\n");
    //print_arr(arr,len);
}
void Radix_Sort(int num[],int len)
{
   //A:ԭ����
   //temp:��ʱ����
   //n:���е����ָ���
   //k:����λ��2
   //r:����10
   //cnt:�洢bin[i]�ĸ���
    int temp[len];int n=len, k=3,r=800;int cnt[len];
    int arr[len];
    for(int i=0;i<len;i++)
    arr[i]=num[i];
    double run_time;
	LARGE_INTEGER time_start;//��ʼʱ��
	LARGE_INTEGER time_over;	//����ʱ��
	double dqFreq;		//��ʱ��Ƶ��
	LARGE_INTEGER f;	//��ʱ��Ƶ��
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;
	QueryPerformanceCounter(&time_start);
    /* ��ʱ��ʼ */
   for(int i=0 , rtok=1; i<k ; i++ ,rtok = rtok*r){

       //��ʼ��
       for(int j=0;j<r;j++){
           cnt[j] = 0;
       }
       //����ÿ�����ӵ����ָ���
       for(int j=0;j<n;j++){
           cnt[(arr[j]/rtok)%r]++;
       }
       //cnt[j]�ĸ����޸�Ϊǰj������һ���м�������
       for(int j=1;j<r;j++){
           cnt[j] = cnt[j-1] + cnt[j];
       }
       for(int j = n-1;j>=0;j--){      //�ص����
           cnt[(arr[j]/rtok)%r]--;
           temp[cnt[(arr[j]/rtok)%r]] = arr[j];
       }
       for(int j=0;j<n;j++){
           arr[j] = temp[j];
       }
   }
    /* ��ʱ���� */
    QueryPerformanceCounter(&time_over);
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;	//����1000000�ѵ�λ���뻯Ϊ΢�룬����Ϊ1000 000/��cpu��Ƶ��΢��
	printf("\n������������ʱ�䣺%fus\n",run_time);
    //printf("�����\n");
    //print_arr(arr,len);
}
