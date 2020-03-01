#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define LEN sizeof(struct student)

struct student
{
    char num[10];
    char name[10];
    char sex[2];
    int age;
    struct student* next;
}stu[10];
int n;
struct student* creat()
{
   struct student* head;
   struct student* curp,*prep;
   n=0;
   int length,i;
   if((struct student*)malloc(LEN)==NULL)
   {
       printf("Mem alloc failure!\n");
       return 0;
   }
   curp=prep=(struct student*)malloc(LEN);
   printf("please input the length:");
   scanf("%d",&length);
   for(i=0;i<length;i++)
   {
       n=n+1;
       curp=(struct student*)malloc(LEN);
       if(n==1)head=curp;
       else prep->next=curp;
       printf("please input the student's number:");
       scanf("%s",&curp->num);
       getchar();
       printf("please input the student's name:");
       scanf("%s",&curp->name);
       getchar();
       printf("please input the student's sex:");
       scanf("%s",&curp->sex);
       getchar();
       printf("please input the student's age:");
       scanf("%d",&curp->age);
       curp->next=NULL;
       prep=curp;
   }
   prep->next=NULL;
   return(head);
}
void print(struct student *head)
{
    struct student *p;
    printf("\n The students are:\n",n);
    printf("number    name    sex   age   \n");
    p=head;
    if(head!=NULL)
        for ( p = head; p != NULL; p = p->next )
        printf("%4s%8s%7s%7d\n", p->num, p->name, p->sex,p->age);
}
struct student* Delete(struct student* head,char* delnum)
{
    struct student *p,*pl;
    int k=0;
    p=head;
    if(strcmp(p->num,delnum)==0)
        {
            k=1;
            head=p->next;
            free(p);
            p=head;
        }
            while((p->next)!=NULL)
        {
           pl=p;
           p=pl->next;
           if(strcmp(p->num,delnum)==0)
           {
              k=1;
              pl->next=p->next;
              free(p);
           }
        }
    if(k==0)
     printf("Not found!!!\n");
     return head;
}
int main()
{
    struct student *head;
    char delnum[10];
    head=creat();
    printf("Please input the number you want to delete:");
    scanf("%s",&delnum);
    head=Delete(head,delnum);
    print(head);
}
