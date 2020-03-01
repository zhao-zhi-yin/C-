#include <stdio.h>
#include <stdlib.h>
#include "BSTree.h"
int main()
{
  BiTree bt;
  int n,k=0,count;
  int elem[40]={40,10,5,2,-1,-1,8,-1,9,-1,-1,-1,55,45,-1,48,47,-1,-1,5,-1,-1,60,-1,70,-1,-1};
  //printf("输入二叉排序树的先序数列：\n");
  bt=createBiTree(elem);
  printf("该二叉排序树的中序遍历数列：\n");
  InOrder_Recursion(bt);
  printf("\n\n");

  printf("该二叉排序树的叶子节点有：\n");
  count=CountLeaf(bt);
  printf("\n");
  printf("共有%d个\n",count);
  printf("\n");

  printf("输入要查找的二叉排序树的元素：\n");
  scanf("%d",&n);
  Search(bt,n);
   printf("\n");

  printf("输入要插入的二叉排序树的元素：\n");
  scanf("%d",&n);
  k=BinInsert(bt,n);
  if(k==1) printf("插入成功！");
  else printf("插入不成功！");
   printf("\n\n");

  printf("该二叉排序树的中序遍历数列：\n");
  InOrder_Recursion(bt);
   printf("\n\n");

  printf("输入要删除的二叉排序树的元素：\n");
  scanf("%d",&n);
  k=BinDelete(&bt,n);
   printf("\n");
  if(k==1) printf("删除成功！");
  else printf("删除不成功！");
   printf("\n");

  printf("该二叉排序树的中序遍历数列：\n");
  InOrder_Recursion(bt);
   printf("\n");
}
