#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct tagNode
{
	float coef;
	int exp;
	struct tagNode *next;
};

typedef struct tagNode Node;
typedef struct tagNode* pNode;


pNode Create_llist()
{
   pNode head=(pNode)malloc(sizeof(struct tagNode));
   if(head!=NULL)  head->next=NULL;
    else printf("Out of space!\n");
    return head;
}
void interList(pNode head,pNode pnode)
{
  pNode pre=head;
  while(pre->next!=NULL)
  {
      if(pre->next->exp>pnode->exp)
      {
          pnode->next=pre->next;
          pre->next=pnode;
          break;
      }
      pre=pre->next;
  }
  if(pre->next==NULL)
    pre->next=pnode;
}


void Input_polynomial(pNode head)
{
    float coef;
    int exp;int i=0;
    pNode p1;
    pNode p=(pNode)malloc(sizeof(struct tagNode));
    head->next=p;
    printf("请依次输入多项式的系数和指数：\n");
    printf("()x^()+()x^()+()x^()+()x^()+()x^()\n");
    printf("第%d项:",i+1);
    scanf("%f,%d",&coef,&exp);
    while(coef!=0&&exp!=0)
   {
       p=(pNode)malloc(sizeof(struct tagNode));
       p->coef=coef;
       p->exp=exp;
       p->next=NULL;
       i++;
       interList(head,p);
       printf("第%d项:",i+1);
       scanf("%f,%d",&coef,&exp);
   }
    p->next=NULL;
}

void Add_poly(Node *pa,Node *pb)
{
	Node *p=pa->next;
	Node *q=pb->next;
	Node *prep=pa;
	Node *temp;
	float x;
	while(p!=NULL && q!=NULL)
	{
		if(p->exp<q->exp) //第二个多项式的系数大于第一个
		{
			prep=p;
			p=p->next;   //第一个多项式指向下一项
		}
		else if(p->exp==q->exp)//第一个多项式链表当前节点指数和第二个多项式的指数相等，系数相加
		{
			x=p->coef+q->coef;
			if (x!=0)//相加后的系数不为0将相加后的系数赋给链表1的节点
			{
				p->coef=x;
				prep=p;
			}
			else //相加后，系数是0，删除节点
			{
				prep->next=p->next;
				free(p);
			}
			p=prep->next;//p指向要比较的下一个结点
			temp=q;  //删除链表2的当前节点
			q=q->next;
			free(temp);
		}
		else if(p->exp>q->exp) //第二个多项式的系数大于第一个
		{
			temp=q->next;
            q->next=p;
			prep->next=q;
			prep=q;
			q=temp;
		}
	}
//如果链表2比链表1长
	if (q)	prep->next=q;
	free(pb);
}
void Print_poly(pNode pc)
{
    pNode poly;
    poly=pc->next;
    while(poly!=NULL)
    {
        printf("%.2fx^%d ",poly->coef,poly->exp);
        poly=poly->next;
    }
    printf("\b ");
}
int main()
{
    pNode pa,pb,pc;
    pa=Create_llist(pa);
    pb=Create_llist(pb);
    pc=Create_llist(pc);
    Input_polynomial(pa);
    printf("\n");
    Input_polynomial(pb);
    printf("\n");
    printf("多项式1为：\n");
    Print_poly(pa);
    printf("\n");
    printf("多项式2为：\n");
    Print_poly(pb);
    printf("\n");
    Add_poly(pa,pb);
    printf("相加后的多项式为：\n");
    Print_poly(pa);
}

