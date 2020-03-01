#include <stdio.h>
#include <stdlib.h>


typedef char DataType;
int a=0,b=0,c=0,d=0;

typedef struct TreeNode
{	DataType data;
    struct TreeNode *lchild,*rchild;
}TreeNode,*BiTree;

typedef struct StackNode
{	TreeNode *data;
	struct StackNode *next;
}StackNode,*LinkStack,*PNode;

LinkStack SetNullStack_Link()
{
  LinkStack top=(LinkStack)malloc(sizeof(struct StackNode));
  if(top!=NULL) top->next=NULL;
  else printf("Alloc failure");
  return top;
}

int GetHeight(BiTree BT)
{	int hl, hr, max;
	if (BT != NULL)
   {
       hl = GetHeight(BT->lchild);
       hr = GetHeight(BT->rchild);
       max = hl > hr ? hl : hr;
       return (max + 1);
   }
   else	return 0;
}

int CountLeaf(BiTree bt)
{
    static int count=0;
    if(bt!=NULL)
    {
        if(bt->lchild==NULL&&bt->rchild==NULL)
            count++;
        count=CountLeaf(bt->lchild);
        count=CountLeaf(bt->rchild);
    }
    return count;
}

 int IsNullStack_link(LinkStack top)
 {
     if(top->next==NULL)
        return 1;
     else return 0;
 }

 void Push_link(LinkStack top,BiTree x)
 {
     PNode p;
     p=(PNode)malloc(sizeof(struct StackNode));
     if(p==NULL) printf("Alloc failure");
     else
     {
       p->data=x;
       p->next=top->next;
       top->next=p;
     }
 }
 void Pop_link(LinkStack top)
 {
     PNode p;
     if(top->next==NULL) printf("it is empty!");
     else
     {
         p=top->next;
         top->next=p->next;
         free(p);
     }
 }
 BiTree Pop_seq_return(LinkStack top)
{
    PNode p;BiTree temp=(BiTree)malloc(sizeof(TreeNode));
    if(top->next==NULL)
    {
        printf("It is empty stack!");
        return 0;
    }
    else
    {
        p=top->next;
        top->next=p->next;
        temp=p->data;
        free(p);
        return temp;
    }
}
 BiTree Top_link(LinkStack top)
 {
     if(top->next==NULL)
    {
        printf("It is empty stack!");
        return 0;
    }
    else return top->next->data;
 }


 void PreOrder_NPrcursion1(BiTree bt)
 {
     LinkStack lstack;
     lstack=SetNullStack_Link();
     BiTree p;
     Push_link(lstack,bt);
     while(!IsNullStack_link(lstack))
     {
         p=Top_link(lstack);
         Pop_link(lstack);
         printf("%c",p->data);
         if(p->rchild)
         Push_link(lstack,p->rchild);
         if(p->lchild)
         Push_link(lstack,p->lchild);
     }
 }

BiTree createBiTree(char *elem)
{
    DataType c;
    BiTree t=(BiTree)malloc(sizeof(TreeNode));
    static int i=0;
     c=elem[i];
     //scanf("%c",&c);
    if(c == '#')//当遇到 #时，令根节点为NULL，结束掉该分支的递归
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

void PreOrder_Recursion(BiTree bt) //递归先序遍历
{
   if(bt==NULL) return;
   printf("%c",bt->data);
   if(bt->data=='A') a++;
   else if(bt->data=='B') b++;
   else if(bt->data=='C') c++;
   else if(bt->data=='D') d++;
   PreOrder_Recursion(bt->lchild);
   PreOrder_Recursion(bt->rchild);
}

void InOrder_Recursion(BiTree bt) //递归中序遍历
{
   if(bt==NULL) return;
   InOrder_Recursion(bt->lchild);
   printf("%c",bt->data);
   InOrder_Recursion(bt->rchild);
}

void PostOrder_Recursion(BiTree bt) //递归后序遍历
{
   if(bt==NULL) return;
   PostOrder_Recursion(bt->lchild);
   PostOrder_Recursion(bt->rchild);
   printf("%c",bt->data);
}

void DestroyBinTree(BiTree bt)  //销毁二叉树
{
    if(bt!=NULL)
    {
        DestroyBinTree(bt->lchild);
        DestroyBinTree(bt->rchild);
        free(bt);
    }
}

int main()
{
    BiTree bt=NULL;int k=0;int n;
    //printf("输入树的先序遍历序列：\n");
    char elem[20]={'A','B','#','D','#','#','C','A','#','#','#'};
    bt=createBiTree(elem);
    printf("该二叉树的先序遍历序列为：\n");
    PreOrder_Recursion(bt);
    printf("\n");
    printf("该二叉树的中序遍历序列为：\n");
    InOrder_Recursion(bt);
    printf("\n");
    printf("该二叉树的后序遍历序列为：\n");
    PostOrder_Recursion(bt);
    printf("\n");
    printf("该二叉树的非递归先序遍历序列为：\n");
    PreOrder_NPrcursion1(bt);
    printf("\n");
    k=GetHeight(bt);
    printf("该二叉树的高度：%d\n",k);
    printf("\n");
    n=CountLeaf(bt);
    printf("该二叉树的叶子节点的个数：%d\n",n);
    printf("\n");
    printf("该二叉树中各节点的次数：\n");
    printf("A：%d ",a);printf("B：%d ",b);printf("C：%d ",c);printf("D：%d ",d);
    printf("\n");
    printf("销毁二叉树\n");
    DestroyBinTree(bt);
}
