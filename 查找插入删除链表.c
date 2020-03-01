#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#define LEN sizeof(struct student)
#define N 6
struct student
{
    int num;
    int score;
    struct student* next;
}stu[10];

struct student* creat()
{
   struct student* head;
   struct student* curp,*prep;
   int a[6]={21,3,15,27,11,18};
   int k=0;
   int i;
   if((struct student*)malloc(LEN)==NULL)
   {
       printf("Mem alloc failure!\n");
       return 0;
   }
   curp=prep=(struct student*)malloc(LEN);
   for(i=0;i<N;i++)
   {
       k=k+1;
       curp=(struct student*)malloc(LEN);
       if(k==1)head=curp;
       else prep->next=curp;
       curp->num=i+1;
       curp->score=a[i];
       curp->next=NULL;
       prep=curp;
   }
   prep->next=NULL;
   return(head);
}
void print(struct student *head)
{
    struct student *p;
    printf("\n The students are:\n");
    printf("number    score \n");
    p=head;
    if(head!=NULL)
        for ( p = head; p != NULL; p = p->next )
        printf("%3d%4d\n", p->num, p->score);
}
int Serch_n(struct student* head,int serch)
{
   struct student *p,*pl;
   int k=0,sc;
   p=head;
   if(p->num==serch)
   {
      k=1;
      sc=p->score;
   }
   while((p->next)!=NULL)
        {
           pl=p;
           p=pl->next;
           if(p->num==serch)
           {
              k=1;
              sc=p->score;
           }
        }
    if(k==0)
     printf("Not found!!!\n");
     return sc;
}
int Serch_s(struct student* head,int serch)
{
   struct student *p,*pl;
   int k=0,sc;
   p=head;
   if(p->score==serch)
   {
      k=1;
      sc=p->num;
   }
   while((p->next)!=NULL)
        {
           pl=p;
           p=pl->next;
           if(p->score==serch)
           {
              k=1;
              sc=p->num;
           }
        }
    if(k==0)
     printf("Not found!!!\n");
     return sc;
}
struct student* Add(struct student* head,int add_n,int add_s)
{
    struct student *p,*p1,*p2;
    p=p1=p2=(struct student*)malloc(LEN);
    p=head;
    int i,k=0;
    if(p->num==add_n)
        {
            k=1;
            p1=p->next;
            p->next=p2;
            p2->num=add_n+1;
            p2->score=add_s;
            p2->next=p1;
            //free(p1);
        }
            while((p->next)!=NULL)
        {
           p=p->next;
           p1=p->next;
           if(p->num==add_n)
           {
              k=1;
              p2->num=add_n+1;
              p2->score=add_s;
              p2->next=p1;
              p->next=p2;
           }
        }
        if((p->next==NULL)&&(p->num==add_n))
        {
            p->next=p2;
            p2->num=add_n+1;
            p2->score=add_s;
            p2->next=NULL;
        }

    if(k==0)
     printf("Not found!!!\n");
     for(i=0,p=head;i<=N;i++)
       if(p->next!=NULL)
        {
          p->num=i+1;
          p=p->next;
        }else p->num=i+1;
        return head;
}
struct student* Delete(struct student* head,int delnum)
{
    struct student *p,*pl;
    int i,k=0;
    p=head;
    if(p->num==delnum)
        {
            k=1;
            head=p->next;
            free(p);
            p=head;
        }else while(1)
        {
           pl=p;
           p=pl->next;
           if(p->next!=NULL&&p->num==delnum)
           {
              k=1;
              pl->next=p->next;
              free(p);
              break;
           }else  if(p->next==NULL&&p->num==delnum)
                  {
                    k=1;
                    pl->next=NULL;
                    break;
                  }
        }

    if(k==0)
     printf("Not found!!!\n");
     for(i=0,p=head;i<N;i++)
       if(p->next!=NULL)
        {
          p->num=i+1;
          p=p->next;
        }else p->num=i+1;
     return head;
}
int main()
{
    struct student *head;
    //struct student stu[N];
    int delnum,add_n,add_s,serch_1,serch_2,a,b;
    head=creat();
    print(head);
    printf("Please input the number you want to serch:");
    scanf("%d",&serch_1);
    a=Serch_n(head,serch_1);
    printf("\nthe number score you serch is %d \n",a);
    printf("Please input the score you want to serch:");
    scanf("%d",&serch_2);
    b=Serch_s(head,serch_2);
    printf("\nthe number number you serch is %d \n",b);
    printf("Please input the number and score you want to add:");
    scanf("%d%d",&add_n,&add_s);
    head=Add(head,add_n,add_s);
    print(head);
    printf("Please input the number you want to delete:");
    scanf("%d",&delnum);
    head=Delete(head,delnum);
    print(head);
}
