#include <stdio.h>
#include <stdlib.h>
#include "BSTree.h"

BiTree createBiTree(int *elem)
{
    DataType c;
    BiTree t=(BiTree)malloc(sizeof(TreeNode));
    static int i=0;
     c=elem[i];
     //scanf_s("%d",&c);
    if(c == -1)//当遇到-1时，令根节点为NULL，结束掉该分支的递归
             {t = NULL;i++;}
        else{
                i++;
                //t =(BiTree)malloc(sizeof(TreeNode));
        		t->data = c;
                t->lchild=createBiTree(elem);
        		t->rchild=createBiTree(elem);
            }
    return t;
}

void InOrder_Recursion(BiTree bt) //递归中序遍历
{
   if(bt==NULL) return;
   InOrder_Recursion(bt->lchild);
   printf("%d ",bt->data);
   InOrder_Recursion(bt->rchild);
}

int CountLeaf(BiTree bt)
{
    static int count=0;
    if(bt!=NULL)
    {
        if(bt->lchild==NULL&&bt->rchild==NULL)
        {
            count++;
            printf("%d ",bt->data);
        }
        count=CountLeaf(bt->lchild);
        count=CountLeaf(bt->rchild);
    }
    return count;
}

BiTree Search(BiTree bt,DataType key)
{
    BiTree p,parent;
    p=bt;parent=p;
    while(p)
    {
       parent=p;
       if(p->data==key)
       {
           printf("该节点存在！！！\n");
          // printf("该节点的父母节点是：%d\n",parent->data);
           return NULL;
       }
       if(p->data>key)
         p=p->lchild;
        else p=p->rchild;
    }
    //printf("该节点不存在！！！\n");
    return parent;
}

int BinInsert(BiTree bt,DataType key)
{
    BiTree pt,temp;
    //p=bt;parent=p;
    temp=Search(bt,key);
    /*while(p)
    {
       parent=p;
       if(p->data==key)
        break;
       if(p->data>key)
        p=p->lchild;
        else p=p->rchild;
    }
    temp=parent;*/
    if(temp==NULL)
    {
        printf("不存在该节点!\n");
        return 0;
    }
    pt=(BiTree)malloc(sizeof(TreeNode));
    if(pt==NULL)
    {
        printf("Alloc Failure!\n");
        return 0;
    }
    pt->data=key;
    pt->lchild=pt->rchild=NULL;
    if(key<temp->data)
        temp->lchild=pt;
    else temp->rchild=pt;
     return 1;
}

int BinDelete(BiTree *bt,DataType key)
{
    BiTree parent,p,temp;
    p=*bt;
    parent=NULL;
    while(p!=NULL)
    {
        if(p->data==key) break;
        parent =p;
        if(p->data>key)
          p=p->lchild;
        else p=p->rchild;
    }
    if(p==NULL)
    {
        printf("Not exist!");
        return 0;
    }
    if(p->lchild==NULL)
    {
        if(parent==NULL)
            *bt=p->rchild;
        else if(parent->lchild==p)
            parent->lchild=p->rchild;
        else parent->rchild=p->rchild;
    }
    if(p->lchild!=NULL)
    {
       temp=p->lchild;
       while(temp->rchild!=NULL)
        temp=temp->rchild;
       temp->rchild=p->rchild;
       if(parent==NULL)
        *bt=p->lchild;
        else if(parent->lchild==p)
            parent->lchild=p->lchild;
        else parent->rchild=p->lchild;
    }
    free(p);
    return 1;
}


