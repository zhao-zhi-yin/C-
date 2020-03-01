#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define STACKINCREMENT 10

//STL 动态分配二维数组的空间
typedef struct
{
	int x;
	int y;
	int d;
}DataType;
typedef struct {
  DataType *data; //在栈构造之前和销毁之后，data的值为空。
  int top;       //top指示栈顶
  int stacksize; //当前已分配的存储空间，以数据元素为单位
}SeqStack,*PSeqStack;

//构造一个空栈
PSeqStack createEmptyStack_seq(int m)
{
	 PSeqStack S=(PSeqStack)malloc(sizeof(SeqStack));
	 if (S)
	 {  S->data=(DataType*)malloc(m*sizeof(DataType));
		if(!S->data)
		{ free(S);return 0; }//存储分配失败
		S->top=-1;
		S->stacksize=m;
		return S;
	 }
}//createEmptyStack_seq

//若栈S为空栈，返回1；否则，返回0
int isEmptyStack_seq(PSeqStack S)
{
    return (S->top==-1?1:0);
}

//入栈
void Push_Seq(PSeqStack S,DataType x)
{
  //插入元素x为新的栈顶元素
  if(S->top == S->stacksize - 1)
  {
     printf("\n Stack is full!");
  }
  else
  {
	  S->top++;
	  S->data[S->top]=x;
  }
}//Push_Seq

//出栈
int Pop_Seq(PSeqStack S){
  //若栈不为空，删除栈顶元素并返回OK;否则返回ERROR.
  if(isEmptyStack_seq(S)){
       printf("\n Stack is free!");
       return 0;
  }
  S->top--;
  return 1;
}//Pop_Seq

//取栈顶元素
DataType Top_Seq(PSeqStack S)
{ //若栈S不空，则返回栈顶元素; 否则给出相应提示.
  if(isEmptyStack_seq(S))
      printf("\n Stack is free!");
  else
  {
      return (S->data[S->top]);
  }
}//GetTop

//遍历栈
void Travers(PSeqStack S)
{
	while (!isEmptyStack_seq(S))
	{
		printf("%d\n",Top_Seq(S));
		Pop_Seq(S);
	}
}
void mazePath(int maze[][10],int derection[3][2],int x1,int y1,int x2,int y2)
{
	//(x1,y1)为入口；(x2,y2)为出口
	int i,j,k;  //k表示试探的方向，分别为0，1，2，3
	int g,h;  //（g,h)为(i,j)的下一探索方向
	int a=0;
	int p[25][2];
	DataType term;
	DataType term1;
	DataType term2;
	PSeqStack S=NULL;
	PSeqStack G=NULL;
	if (S)
		free(S);
	S=createEmptyStack_seq(25);
    G=createEmptyStack_seq(25);
	maze[x1][y1]=2;  //标记入口
	term.x=x1;
	term.y=y1;
	term.d=-1;
	Push_Seq(S,term);
	while (!isEmptyStack_seq(S))
	{
		//取栈顶元素并出栈
		term=Top_Seq(S);
		Pop_Seq(S);
		//记录当前位置（i,j)
		i=term.x;
		j=term.y;
		//当前位置的下一探索方向
		k=term.d+1;
		while (k<=2)
		{
			g=i+derection[k][0];
			h=j+derection[k][1];

			if (g==x2 && h==y2)
			{
                term1.x=x2;term1.y=y2;term1.d=0;
				Push_Seq(G,term1);
				term2.x=i;term2.y=j;term2.d=k;
				Push_Seq(G,term2);
				while (!isEmptyStack_seq(S))
				{

					term=Top_Seq(S);
					Pop_Seq(S);
					Push_Seq(G,term);
					//printf("(%d,%d,%d)\n",term.x,term.y,term.d);
				}
				break;
			}
			if (maze[g][h]==0)
			{
				//标记下一个位置为已访问。并且将当前位置（i,j,k)入栈，同时将下一位置作为当前位置
				maze[g][h]=2;
				term.x=i;  term.y=j; term.d=k;
				Push_Seq(S,term);
				i=g;
				j=h;
				k=-1;
			}
			k++;
		}
	}
	if (!isEmptyStack_seq(S))
		printf("没找到路径\n");
printf("迷宫出口路径：\n");
		while (!isEmptyStack_seq(G))
	{
	    DataType temp;
		temp=Top_Seq(G);
		Pop_Seq(G);
		printf("(%d,%d,%d)-",temp.x,temp.y,temp.d);
		a++;
		maze[temp.x][temp.y]=3;
	}
	 printf("\b ");printf("\n");
	 printf("迷宫路径长度：%d\n",a);
}

void main()
{
	int maze[10][10]={{1,1,1,1,1,1,1,1,1,1},
	                  {0,0,0,1,0,0,0,1,0,1},
                      {1,0,0,1,0,0,0,1,0,1},
	                  {1,0,0,0,0,1,1,0,0,1},
	                  {1,0,1,1,1,0,0,0,0,1},
	                  {1,0,0,0,1,0,0,0,0,1},
	                  {1,0,1,0,0,0,1,0,0,1},
                      {1,0,1,1,1,0,1,1,0,1},
	                  {1,1,0,0,0,0,0,0,0,0},
	                  {1,1,1,1,1,1,1,1,1,1},};

	int derection[3][2]={{0,1},{1,1},{1,0}};
	int i,j,p;
	p=0;
	printf("\n原始迷宫：\n");
	 for(int i=0;i<10;i++)
    {
       for(int j=0;j<10;j++)
     {
       printf("%d ",maze[i][j]);
     }
     printf("\n");
   }
    printf("\n");
	/*
	printf("输入迷宫：\n");
	for (i=0;i<10;i++)
		for (j=0;j<10;j++)
			scanf("%d",&maze[i][j]);
	*/

	mazePath(maze,derection,1,0,8,9);
	printf("\n输出迷宫路径：\n");
    for(int i=0;i<10;i++)
    {
       for(int j=0;j<10;j++)
     {
       if(maze[i][j]==3)
           printf("x ");
       else if(maze[i][j]==2)
        printf("0 ");
       else printf("%d ",maze[i][j]);
     }
     printf("\n");
   }
	system("pause");
}
