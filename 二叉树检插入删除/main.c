#include <stdio.h>
#include <stdlib.h>
#include "BSTree.h"
int main()
{
  BiTree bt;
  int n,k=0,count;
  int elem[40]={40,10,5,2,-1,-1,8,-1,9,-1,-1,-1,55,45,-1,48,47,-1,-1,5,-1,-1,60,-1,70,-1,-1};
  //printf("����������������������У�\n");
  bt=createBiTree(elem);
  printf("�ö���������������������У�\n");
  InOrder_Recursion(bt);
  printf("\n\n");

  printf("�ö�����������Ҷ�ӽڵ��У�\n");
  count=CountLeaf(bt);
  printf("\n");
  printf("����%d��\n",count);
  printf("\n");

  printf("����Ҫ���ҵĶ�����������Ԫ�أ�\n");
  scanf("%d",&n);
  Search(bt,n);
   printf("\n");

  printf("����Ҫ����Ķ�����������Ԫ�أ�\n");
  scanf("%d",&n);
  k=BinInsert(bt,n);
  if(k==1) printf("����ɹ���");
  else printf("���벻�ɹ���");
   printf("\n\n");

  printf("�ö���������������������У�\n");
  InOrder_Recursion(bt);
   printf("\n\n");

  printf("����Ҫɾ���Ķ�����������Ԫ�أ�\n");
  scanf("%d",&n);
  k=BinDelete(&bt,n);
   printf("\n");
  if(k==1) printf("ɾ���ɹ���");
  else printf("ɾ�����ɹ���");
   printf("\n");

  printf("�ö���������������������У�\n");
  InOrder_Recursion(bt);
   printf("\n");
}
