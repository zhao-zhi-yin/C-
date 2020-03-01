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
    printf("�������������ʽ��ϵ����ָ����\n");
    printf("()x^()+()x^()+()x^()+()x^()+()x^()\n");
    printf("��%d��:",i+1);
    scanf("%f,%d",&coef,&exp);
    while(coef!=0&&exp!=0)
   {
       p=(pNode)malloc(sizeof(struct tagNode));
       p->coef=coef;
       p->exp=exp;
       p->next=NULL;
       i++;
       interList(head,p);
       printf("��%d��:",i+1);
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
		if(p->exp<q->exp) //�ڶ�������ʽ��ϵ�����ڵ�һ��
		{
			prep=p;
			p=p->next;   //��һ������ʽָ����һ��
		}
		else if(p->exp==q->exp)//��һ������ʽ����ǰ�ڵ�ָ���͵ڶ�������ʽ��ָ����ȣ�ϵ�����
		{
			x=p->coef+q->coef;
			if (x!=0)//��Ӻ��ϵ����Ϊ0����Ӻ��ϵ����������1�Ľڵ�
			{
				p->coef=x;
				prep=p;
			}
			else //��Ӻ�ϵ����0��ɾ���ڵ�
			{
				prep->next=p->next;
				free(p);
			}
			p=prep->next;//pָ��Ҫ�Ƚϵ���һ�����
			temp=q;  //ɾ������2�ĵ�ǰ�ڵ�
			q=q->next;
			free(temp);
		}
		else if(p->exp>q->exp) //�ڶ�������ʽ��ϵ�����ڵ�һ��
		{
			temp=q->next;
            q->next=p;
			prep->next=q;
			prep=q;
			q=temp;
		}
	}
//�������2������1��
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
    printf("����ʽ1Ϊ��\n");
    Print_poly(pa);
    printf("\n");
    printf("����ʽ2Ϊ��\n");
    Print_poly(pb);
    printf("\n");
    Add_poly(pa,pb);
    printf("��Ӻ�Ķ���ʽΪ��\n");
    Print_poly(pa);
}

