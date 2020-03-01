#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define STACKINCREMENT 10

//STL ��̬�����ά����Ŀռ�
typedef struct
{
	int x;
	int y;
	int d;
}DataType;
typedef struct {
  DataType *data; //��ջ����֮ǰ������֮��data��ֵΪ�ա�
  int top;       //topָʾջ��
  int stacksize; //��ǰ�ѷ���Ĵ洢�ռ䣬������Ԫ��Ϊ��λ
}SeqStack,*PSeqStack;

//����һ����ջ
PSeqStack createEmptyStack_seq(int m)
{
	 PSeqStack S=(PSeqStack)malloc(sizeof(SeqStack));
	 if (S)
	 {  S->data=(DataType*)malloc(m*sizeof(DataType));
		if(!S->data)
		{ free(S);return 0; }//�洢����ʧ��
		S->top=-1;
		S->stacksize=m;
		return S;
	 }
}//createEmptyStack_seq

//��ջSΪ��ջ������1�����򣬷���0
int isEmptyStack_seq(PSeqStack S)
{
    return (S->top==-1?1:0);
}

//��ջ
void Push_Seq(PSeqStack S,DataType x)
{
  //����Ԫ��xΪ�µ�ջ��Ԫ��
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

//��ջ
int Pop_Seq(PSeqStack S){
  //��ջ��Ϊ�գ�ɾ��ջ��Ԫ�ز�����OK;���򷵻�ERROR.
  if(isEmptyStack_seq(S)){
       printf("\n Stack is free!");
       return 0;
  }
  S->top--;
  return 1;
}//Pop_Seq

//ȡջ��Ԫ��
DataType Top_Seq(PSeqStack S)
{ //��ջS���գ��򷵻�ջ��Ԫ��; ���������Ӧ��ʾ.
  if(isEmptyStack_seq(S))
      printf("\n Stack is free!");
  else
  {
      return (S->data[S->top]);
  }
}//GetTop

//����ջ
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
	//(x1,y1)Ϊ��ڣ�(x2,y2)Ϊ����
	int i,j,k;  //k��ʾ��̽�ķ��򣬷ֱ�Ϊ0��1��2��3
	int g,h;  //��g,h)Ϊ(i,j)����һ̽������
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
	maze[x1][y1]=2;  //������
	term.x=x1;
	term.y=y1;
	term.d=-1;
	Push_Seq(S,term);
	while (!isEmptyStack_seq(S))
	{
		//ȡջ��Ԫ�ز���ջ
		term=Top_Seq(S);
		Pop_Seq(S);
		//��¼��ǰλ�ã�i,j)
		i=term.x;
		j=term.y;
		//��ǰλ�õ���һ̽������
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
				//�����һ��λ��Ϊ�ѷ��ʡ����ҽ���ǰλ�ã�i,j,k)��ջ��ͬʱ����һλ����Ϊ��ǰλ��
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
		printf("û�ҵ�·��\n");
printf("�Թ�����·����\n");
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
	 printf("�Թ�·�����ȣ�%d\n",a);
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
	printf("\nԭʼ�Թ���\n");
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
	printf("�����Թ���\n");
	for (i=0;i<10;i++)
		for (j=0;j<10;j++)
			scanf("%d",&maze[i][j]);
	*/

	mazePath(maze,derection,1,0,8,9);
	printf("\n����Թ�·����\n");
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
