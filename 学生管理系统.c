#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#define LEN sizeof(struct student)
/**********�ṹ�嶨��**********/
struct student
{
    char name[10];
    char num[10];
    char class_s[10];
    int M_usual;
    int M_exam;
    float M_total;
    int C_usual;
    int C_exam;
    float C_total;
    int E_usual;
    int E_exam;
    float E_total;
    float aver;
    struct student* next;
}stu[100];

/*******��������*******/
int begin();
void Write();
struct student* Read();
struct student* creat();
int print  (struct student *head);
int serch  (struct student* head);
int serch_1(struct student* head);
int serch_2(struct student* head);
int serch_3(struct student* head);
int serch_4(struct student* head);
int alter  (struct student* head);
int sort   (struct student* head);
int sort_1 (struct student* head);
int sort_2 (struct student* head);
int sort_2_1 (struct student* head);
int sort_2_2 (struct student* head);
int sort_2_3 (struct student* head);
int sort_3 (struct student* head);
int sort_4 (struct student* head);
int sort_5 (struct student* head);
int LengthList(struct student* head);
struct student* Add(struct student* head);
struct student* Delete(struct student* head);

/*********������*********/

int main()
{
   int i,j,k;
   char a,b;
   struct student *head;
   begin(head);

}

/*******�Ӻ���********/

int begin()  //��ʼ���溯��
{
   int k;
   struct student *head;
   printf("%549s\n", "ѧ���ɼ�����ϵͳ");
   printf("\n\n\n");
   system("pause");
    while(1)
   {
       system("cls");
       printf("\n****************************\n");
       printf("1��ѧ����Ϣ¼��\n");
       printf("2��ѧ����Ϣ��ѯ\n");
       printf("3��ѧ����Ϣ�޸�\n");
       printf("4��ѧ����Ϣͳ��\n");
       printf("5���˳�ϵͳ\n");
       printf("\n****************************\n\n");
       printf("��������Ҫ����Ĳ˵��ţ� ");
       scanf("%d",&k);
       switch(k)
       {
       case 1: system("cls"); head=creat(); break;
       case 2: system("cls"); head=Read(); serch(head); break;
       case 3: system("cls"); head=Read(); alter(head); break;
       case 4: system("cls"); head=Read(); sort(head);  break;
       case 5: system("TASKKILL /F /IM ѧ������ϵͳ.exe"); break;
        default:printf("error!!!\n");
       }
       printf("\n");
   }
}

int LengthList(struct student* head)
{
    int length = 0;
    struct student* p;
    p = head;
    while(p!= NULL)
    {
        ++length;
        p = p->next;
    }
    return length;
}


 void Write(struct student* head)
 {
     struct student *p;
     int i;
     FILE *fp;
     fp = fopen ("data.txt", "w+");
     p=head;
     while(1)
     {
        if(fp==NULL)
         {
           printf(" Open error!!!");
           break;
         }
       else if(p->next!=NULL)
        {
          fprintf(fp,"%s %s %s %d %d %.2f %d %d %.2f %d %d %.2f %.2f\n",p->name,p->num,p->class_s,p->M_usual,p->M_exam,\
                     p->M_total,p->C_usual,p->C_exam,p->C_total,p->E_usual,p->E_exam,p->E_total,p->aver);
          p=p->next;
        }else if(p->next==NULL) {
            fprintf(fp,"%s %s %s %d %d %.2f %d %d %.2f %d %d %.2f %.2f\n",p->name,p->num,p->class_s,p->M_usual,p->M_exam,\
            p->M_total,p->C_usual,p->C_exam,p->C_total,p->E_usual,p->E_exam,p->E_total,p->aver);
            break;
        }
     }
         fclose(fp);
 }

 struct student* Read()
 {
   struct student* head;
   struct student* curp,*prep,*p;
   FILE *fp;
   fp = fopen ("data.txt", "r+");
   int k=0;
   int i;
   if((struct student*)malloc(LEN)==NULL)
   {
       printf("Mem alloc failure!\n");
       return 0;
   }
   curp=prep=(struct student*)malloc(LEN);
   while(!feof(fp))
   {
       k=k+1;
       curp=(struct student*)malloc(LEN);
       if(k==1)head=curp;
         else prep->next=curp;
       fscanf(fp,"%s%s%s%d%d%f%d%d%f%d%d%f%f\n",&curp->name,&curp->num,&curp->class_s,&curp->M_usual,&curp->M_exam,\
                     &curp->M_total,&curp->C_usual,&curp->C_exam,&curp->C_total,&curp->E_usual,&curp->E_exam,&curp->E_total,&curp->aver);
       prep=curp;
   }
   prep->next=NULL;
   fclose(fp);
   return(head);
 }
struct student* creat() //�����캯��
{
   struct student* head;
   struct student* curp,*prep;
   int n,k=0;
   int i,j;
   char a[10];
   if((struct student*)malloc(LEN)==NULL)
   {
       printf("Mem alloc failure!\n");
       return 0;
   }
   curp=prep=(struct student*)malloc(LEN);
   printf("\n\n��������Ҫ������ٸ���ѧ����ѧ����Ϣ:\n");
   scanf("%d",&n);
   printf("\n");
   for(i=0;i<n;i++)
   {
       k=k+1;
       curp=(struct student*)malloc(LEN);
       if(k==1)head=curp;
       else prep->next=curp;
       printf("NO.%d ѧ��ѧ��:",i+1);
       scanf("%s",&curp->num);
       printf("NO.%d ѧ������:",i+1);
       scanf("%s",&curp->name);
       printf("NO.%d ѧ���༶:",i+1);
       scanf("%s",&curp->class_s);
       printf("��ѧ����ѧƽʱ�ɼ�:");
       scanf("%d",&curp->M_usual);
       printf("��ѧ����ѧ���Գɼ�:");
       scanf("%d",&curp->M_exam);
       curp->M_total=(0.2*curp->M_usual)+(0.8*curp->M_exam);
       printf("��ѧ������ƽʱ�ɼ�:");
       scanf("%d",&curp->C_usual);
       printf("��ѧ�����Ŀ��Գɼ�:");
       scanf("%d",&curp->C_exam);
       curp->C_total=(0.2*curp->C_usual)+(0.8*curp->C_exam);
       printf("��ѧ��Ӣ��ƽʱ�ɼ�:");
       scanf("%d",&curp->E_usual);
       printf("��ѧ��Ӣ�￼�Գɼ�:");
       scanf("%d",&curp->E_exam);
       curp->E_total=(0.2*curp->E_usual)+(0.8*curp->E_exam);
       curp->aver=(curp->M_total+curp->C_total+curp->E_total)/3;
       printf("\n");
       curp->next=NULL;
       prep=curp;
   }
   prep->next=NULL;
   Write(head);
   return(head);
   system("cls");
}
int print(struct student *p)
{
    int i;
    printf("\n ѧ����ϢΪ:\n");
    printf("ѧ��:%s\n",p->num);
    printf("����e:%s\n", p->name);
    printf("�༶:%s\n", p->class_s);
    printf("��ѧ�ɼ�:%.2f\n",p->M_total);
    printf("���ĳɼ�:%.2f\n",p->C_total);
    printf("Ӣ��ɼ�:%.2f\n",p->E_total);
    printf("ƽ���ɼ�:%.2f\n",p->aver);
}

int serch(struct student* head)  //��Ϣ���ҽ��溯��
{
    int k;
    system("cls");
    printf("\n****************************\n");
    printf("1����ѧ�Ų���\n");
    printf("2������������\n");
    printf("3�����༶����\n");
    printf("4����ƽ���ֲ���\n");
    printf("5���˳�");
    printf("\n****************************\n");
    printf("\n");
    while(1)
   {
       printf("��������������ݲ˵���ţ� ");
       scanf("%d",&k);
       switch(k)
       {
       case 1: system("cls"); serch_1(head); break;
       case 2: system("cls"); serch_2(head); break;
       case 3: system("cls"); serch_3(head);  break;
       case 4: system("cls"); serch_4(head);  break;
       case 5: system("cls"); return(main()); break;
        default:printf("error!!!\n");
       }
       Write(head);
       printf("\n");
   }
}

int serch_1(struct student* head)
{
   int k=0;
   char snum[10];
   struct student *s;
   struct student *p,*pl;
   printf("����������Ҫ���ҵ�ѧ����ѧ�ţ� ");
   scanf("%s",&snum);
   p=head;
   if(strcmp(p->num,snum)==0)
   {
      k=1;
      s=p;
      print(s);
   }
   while((p->next)!=NULL)
        {
           pl=p;
           p=pl->next;
           if(strcmp(p->num,snum)==0)
           {
              k=1;
              s=p;
              print(s);
           }
        }
    if(k==0)
     printf("\n Not found!!!\n");

   printf("\n");
   system("pause");
   return(serch(head));
}

int serch_2(struct student* head)
{
   int k=0;
   char sname[10];
   struct student *s;
   struct student *p,*pl;
   printf("����������Ҫ���ҵ�ѧ���������� ");
   scanf("%s",&sname);
   p=head;
   if(strcmp(p->name,sname)==0)
   {
      k=1;
      s=p;
      print(s);
   }
   while((p->next)!=NULL)
        {
           pl=p;
           p=pl->next;
           if(strcmp(p->name,sname)==0)
           {
              k=1;
              s=p;
              print(s);
           }
        }
    if(k==0)
     printf("\n Not found!!!\n");

   printf("\n");
   system("pause");
   return(serch(head));
}
int serch_3(struct student* head)
{
   int k=0;
   char sclass[10];
   struct student *s;
   struct student *p,*pl;
   printf("����������Ҫ���ҵ�ѧ���İ༶�� ");
   scanf("%s",&sclass);
   p=head;
   if(strcmp(p->class_s,sclass)==0)
   {
      k=1;
      s=p;
      print(s);
   }
   while((p->next)!=NULL)
        {
           pl=p;
           p=pl->next;
           if(strcmp(p->class_s,sclass)==0)
           {
              k=1;
              s=p;
              print(s);
           }
        }
    if(k==0)
     printf("\n Not found!!!\n");

   printf("\n");
   system("pause");
   return(serch(head));
}

int serch_4(struct student* head)
{
   int a,b,m,k=0;
   float saver;
   struct student *s;
   struct student *p,*pl;
   printf("�Ƿ���ģ����ѯ?(1����|2����):");
   scanf("%d",&m);
   if(m==2)
 {
   printf("����������Ҫ���ҵ�ѧ����ƽ���֣� ");
   scanf("%f",&saver);
   p=head;
   if(p->aver==saver)
   {
      k=1;
      s=p;
      print(s);
   }
   while((p->next)!=NULL)
        {
           pl=p;
           p=pl->next;
           if(p->aver==saver)
           {
              k=1;
              s=p;
              print(s);
           }
        }
    if(k==0)
     printf("\n Not found!!!\n");
   printf("\n");
   system("pause");
   return(serch(head));
 }else if(m==1)
  {
     printf("����������Ҫ���ҵ�ѧ����ƽ���ַ�Χ��a<=x<=b��\n");
     printf("a=");
     scanf("%d",&a);
     printf("b=");
     scanf("%d",&b);
     p=head;
     if((p->aver>=a)&&(p->aver<=b))
   {
      k=1;
      s=p;
      print(s);
   }
    while((p->next)!=NULL)
        {
           pl=p;
           p=pl->next;
           if((p->aver>=a)&&(p->aver<=b))
           {
              k=1;
              s=p;
              print(s);
           }
        }
     if(k==0)
      printf("\n Not found!!!\n");
    printf("\n");
    system("pause");
    return(serch(head));
  }
}
int alter(struct student* head)
{
   int k;
   while(1){
   printf("\n****************************\n");
   printf("\n1������ѧ����Ϣ\n2��ɾ��ѧ����Ϣ\n3���˳�\n");
   printf("\n****************************\n");
   printf("\n��ѡ��");
   scanf("%d",&k);
   if(k==1)
   {
    system("cls");
    head=Add(head);
    system("pause");
    system("cls");
   }
   else if(k==2)
    {
        system("cls");
        head=Delete(head);
        system("pause");
        system("cls");
    }
    else if(k==3)
    {
        system("cls");
        return(main());
        break;
    }
   }
}
struct student* Add(struct student* head)
{
    struct student *p,*p1;
    struct student *add;
    add=(struct student*)malloc(LEN);
    char add_n[10];
    printf("\n��ѧ������ǰѧ��:");
    scanf("%s",&add_n);
       printf("��ѧ��ѧ��:");
       scanf("%s",&add->num);
       printf("��ѧ������:");
       scanf("%s",&add->name);
       printf("��ѧ���༶:");
       scanf("%s",&add->class_s);
       printf("��ѧ����ѧƽʱ�ɼ�:");
       scanf("%d",&add->M_usual);
       printf("��ѧ����ѧ���Գɼ�:");
       scanf("%d",&add->M_exam);
       add->M_total=(0.2*add->M_usual)+(0.8*add->M_exam);
       printf("��ѧ������ƽʱ�ɼ�:");
       scanf("%d",&add->C_usual);
       printf("��ѧ�����Ŀ��Գɼ�:");
       scanf("%d",&add->C_exam);
       add->C_total=(0.2*add->C_usual)+(0.8*add->C_exam);
       printf("��ѧ��Ӣ��ƽʱ�ɼ�:");
       scanf("%d",&add->E_usual);
       printf("��ѧ��Ӣ�￼�Գɼ�:");
       scanf("%d",&add->E_exam);
       add->E_total=(0.2*add->E_usual)+(0.8*add->E_exam);
       add->aver=(add->M_total+add->C_total+add->E_total)/3;
       printf("\n");
    p=p1=(struct student*)malloc(LEN);
    p=head;
    int i,k=0;
    if(strcmp(p->num,add_n)==0)
        {
            k=1;
            p1=p->next;
            p->next=add;
            add->next=p1;
        }else while(1)
     {
           p=p->next;
           p1=p->next;
           if((p->next)!=NULL&&(strcmp(p->num,add_n)==0))
          {
              k=1;
              add->next=p1;
              p->next=add;
              break;
           }
        else if((p->next==NULL)&&(strcmp(p->num,add_n)==0))
        {
            k=1;
            p->next=add;
            add->next=NULL;
            break;
        }
        else if((p->next==NULL)&&k==0)
           {printf("Not found!!!\n");break;}
     }
     p=head;
     printf("���������ѧ����Ϣ��\n");
     while(1)
     {
       if(p->next!=NULL)
        {
         print(p);
         p=p->next;
        }else if(p->next==NULL)
        {
            print(p);
            break;
        }
     }
     Write(head);
        return head;
    system("pause");
}

struct student* Delete(struct student* head)
{
    struct student *p,*pl;
    int i,k=0;
    char delnum[10];
    printf("\n����������Ҫɾ����ѧ��ѧ�ţ�");
    scanf("%s",&delnum);
    p=head;
    if(strcmp(p->num,delnum)==0)
        {
            k=1;
            head=p->next;
            free(p);
            p=head;
        }else while(1)
        {
           pl=p;
           p=pl->next;
           if(p->next!=NULL&&(strcmp(p->num,delnum)==0))
           {
              k=1;
              pl->next=p->next;
              free(p);
              break;
           }else  if(p->next==NULL&&(strcmp(p->num,delnum)==0))
                  {
                    k=1;
                    pl->next=NULL;
                    break;
                  }
            else  if(p->next==NULL&&k==0)
                 {
                   printf("Not found!!!\n");
                   break;
                 }
        }

     p=head;
    printf("ɾ��������ѧ����Ϣ��\n");
     while(1)
     {
       if(p->next!=NULL)
        {
         print(p);
         p=p->next;
        }else if(p->next==NULL)
        {
            print(p);
            break;
        }
     }
     Write(head);
     return head;
      system("pause");
}
int sort(struct student* head)
{
  int k;
    system("cls");
    printf("\n****************************\n");
    printf("1���ܷ��������\n");
    printf("2������Ŀ�ɼ��������\n");
    printf("3���༶�ɼ��������\n");
    printf("4���༶�����ʹҿ������\n");
    printf("5���˳�");
    printf("\n****************************\n");
    printf("\n");
    while(1)
   {
       printf("��������Ҫ��ѯ�Ĳ˵���ţ� ");
       scanf("%d",&k);
       switch(k)
       {
       case 1: system("cls"); sort_1(head); break;
       case 2: system("cls"); sort_2(head); break;
       case 3: system("cls"); sort_3(head); break;
       case 4: system("cls"); sort_4(head); break;
       case 5: system("cls"); return(main());break;
       default:printf("error\n");
       }
       printf("\n");
   }

}

int sort_1(struct student* head)
{
   int len,i,j;
   struct student* curp,* prep,* p,* pprep;
   len=LengthList(head);
   curp=prep=p=pprep=(struct student*)malloc(LEN);
   for(i=0,curp=head;i<len-1;i++)
  {
     for(j=0,prep=curp;j<len-i-1;j++)
      {

        curp=prep->next;
        if(curp->aver>=prep->aver)
          {
            if(j==0)
            {
             pprep=head;
             p=curp->next;
             head=curp;
             curp->next=pprep;
             prep->next=p;
             pprep=prep;
              break;
            }else if(j!=0)
            {

               p=curp->next;
               pprep->next=curp;
               curp->next=prep;
               prep->next=p;
                break;
            }
          }
          pprep=prep;
          prep=prep->next;
      }

      curp=head;
   }
   p=head;
   i=0;
    printf("���ܷ�����\n");
     while(1)
     {
         printf("\nNO.%d \n",i+1);
       if(p->next!=NULL)
        {
         print(p);
         p=p->next;
         i++;
        }else if(p->next==NULL)
        {
            print(p);
            break;
        }
     }
     printf("\n");
     system("pause");
     return(sort(head));
}
int sort_2(struct student* head)
{
   int k;
   printf("\n*********************\n");
   printf("1����ѧ\n2������\n3��Ӣ��\n4���˳�\n");
   printf("��������Ҫ��ѯ�ɼ��Ŀ�Ŀ��");
   scanf("%d",&k);
   switch(k)
    {
       case 1: system("cls"); sort_2_1(head); break;
       case 2: system("cls"); sort_2_2(head); break;
       case 3: system("cls"); sort_2_3(head); break;
       case 4: system("cls"); return(sort(head)); break;
       default: printf("error!!!\n"); break;
    }
}
int sort_2_1(struct student* head)
{
    int len,i,j;
   struct student* curp,* prep,* p,* pprep;
   len=LengthList(head);
   curp=prep=p=pprep=(struct student*)malloc(LEN);
   for(i=0,curp=head;i<len-1;i++,curp=head)
  {
     for(j=0,prep=curp;j<len-i-1;j++)
      {

        curp=prep->next;

        if(curp->M_total>=prep->M_total)
          {
            if(j==0)
            {
             p=curp->next;
             head=curp;
             curp->next=prep;
             prep->next=p;
             pprep=prep;
             break;
            }else if(j!=0)
            {

               p=curp->next;
               pprep->next=curp;
               curp->next=prep;
               prep->next=p;
               break;
            }
          }
          pprep=prep;
          prep=prep->next;
      }
      curp=head;
   }
   p=head;
   i=0;
    printf("����ѧ�ɼ�����\n");
     while(1)
     {
         printf("\nNO.%d\n",i+1);
       if(p->next!=NULL)
        {
         print(p);
         p=p->next;
         i++;
        }else if(p->next==NULL)
        {
            print(p);
            break;
        }
     }
     printf("\n");
     system("pause");
     return(sort(head));
}

int sort_2_2(struct student* head)
{
   int len,i,j;
   struct student* curp,* prep,* p,* pprep;
   len=LengthList(head);
   curp=prep=p=pprep=(struct student*)malloc(LEN);
   for(i=0,curp=head;i<len-1;i++)
  {
     for(j=0,prep=curp;j<len-i-1;j++)
      {
        curp=prep->next;
        if(curp->C_total>=prep->C_total)
          {
            if(j==0)
            {
             pprep=head;
             p=curp->next;
             head=curp;
             curp->next=pprep;
             prep->next=p;
             pprep=prep;
              break;
            }else if(j!=0)
            {

               p=curp->next;
               pprep->next=curp;
               curp->next=prep;
               prep->next=p;
                break;
            }
          }
          pprep=prep;
          prep=prep->next;
      }

      curp=head;
   }
   p=head;
   i=0;
    printf("�����ĳɼ�����\n");
     while(1)
     {
          printf("\nNO.%d\n",i+1);
       if(p->next!=NULL)
        {
         print(p);
         p=p->next;
         i++;
        }else if(p->next==NULL)
        {
            print(p);
            break;
        }
     }
     printf("\n");
     system("pause");
     return(sort(head));
}
int sort_2_3(struct student* head)
{
   int len,i,j;
   struct student* curp,* prep,* p,* pprep;
   len=LengthList(head);
   curp=prep=p=pprep=(struct student*)malloc(LEN);
   for(i=0,curp=head;i<len-1;i++)
  {
     for(j=0,prep=curp;j<len-i-1;j++)
      {
        curp=prep->next;
        if(curp->E_total>=prep->E_total)
          {
            if(j==0)
            {
             pprep=head;
             p=curp->next;
             head=curp;
             curp->next=pprep;
             prep->next=p;
             pprep=prep;
              break;
            }else if(j!=0)
            {

               p=curp->next;
               pprep->next=curp;
               curp->next=prep;
               prep->next=p;
                break;
            }
          }
          pprep=prep;
          prep=prep->next;
      }

      curp=head;
   }
   p=head;
   i=0;
    printf("��Ӣ��ɼ�����\n");
     while(1)
     {
          printf("\nNO.%d\n",i+1);
       if(p->next!=NULL)
        {
         print(p);
         p=p->next;
         i++;
        }else if(p->next==NULL)
        {
            print(p);
            break;
        }
     }
     printf("\n");
     system("pause");
     return(sort(head));
}
int sort_3(struct student* head)
{
   char a[10];
   int len,i,j,k;
   struct student* curp,* curp1,* prep,* p,* pprep;
   len=LengthList(head);
   curp=curp1=prep=p=pprep=(struct student*)malloc(LEN);
   printf("\n����������Ҫ��ѯ�İ༶��");
   scanf("%s",&a);
   printf("\n");
   p=head;
     for(i=0;i<len;i++)
     {
        if(i==0&&p->next!=NULL)
       {
         if(strcmp(p->class_s,a)!=0)
         {
           k=1;
           head=p->next;
        }
          else prep=p;
          p=p->next;
       }else if(i==1&&k==1)
       {
           if(strcmp(p->class_s,a)!=0)
             head=p->next;
             else prep=p;
             p=p->next;
       }
        else if(i!=0&&p->next!=NULL)
        {
            if(strcmp(p->class_s,a)!=0)
                 prep->next=p->next;
             else prep=p;
             p=p->next;
        }
        else if(i!=0&&p->next==NULL)
        {
           if(strcmp(p->class_s,a)!=0)
            prep->next=NULL;
        }
     }

len=LengthList(head);

   for(i=0,curp=head;i<len-1;i++)
  {
     for(j=0,prep=curp;j<len-i-1;j++)
      {
        curp=prep->next;
        if(curp->aver>=prep->aver)
          {
            if(j==0)
            {
             pprep=head;
             p=curp->next;
             head=curp;
             curp->next=pprep;
             prep->next=p;
             pprep=prep;
             break;
            }else if(j!=0)
            {
               curp1=curp;
               curp=prep;
               prep=curp1;
               p=prep->next;
               pprep->next=curp->next;
               curp->next=p;
               prep->next=curp;
               break;
            }
          }
          pprep=prep;
          prep=prep->next;
      }

      curp=head;
   }
    p=head;
    i=0;
    printf("�ð�ɼ�����\n");
     while(1)
     {
         printf("\nNO.%d\n",i+1);
       if(p->next!=NULL)
        {
         print(p);
         p=p->next;
         i++;
        }else if(p->next==NULL)
        {
            print(p);
            break;
        }
     }
     printf("\n");
     system("pause");
     return(sort(head));
}
int sort_4(struct student* head)
{
   char a[10];
   int len,i,j,k=0;
   float s1,s2,a1,b1;
   struct student* curp,* prep,* p,* pprep;
   len=LengthList(head);
   curp=prep=p=pprep=(struct student*)malloc(LEN);
   printf("\n����������Ҫ��ѯ�İ༶��");
   scanf("%s",&a);
   printf("\n");
   p=head;
     for(i=0;i<len;i++)
     {
        if(i==0&&p->next!=NULL)
       {
         if(strcmp(p->class_s,a)!=0)
         {
           k=1;
           head=p->next;
        }
          else prep=p;
          p=p->next;
       }else if(i==1&&k==1)
       {
           if(strcmp(p->class_s,a)!=0)
             head=p->next;
             else prep=p;
             p=p->next;
       }
        else if(i!=0&&p->next!=NULL)
        {
            if(strcmp(p->class_s,a)!=0)
              prep->next=p->next;
             else prep=p;
             p=p->next;
        }
        else if(i!=0&&p->next==NULL)
        {
           if(strcmp(p->class_s,a)!=0)
            prep->next=NULL;
        }
     }

   p=head;
   i=0;
   s1=s2=0;
     while(1)
     {
       if(p->next!=NULL)
        {
            i++;
         if(p->aver>=80)
            s1++;
         if(p->aver<60)
            s2++;
         p=p->next;

        }else if(p->next==NULL)
        {
            i++;
          if(p->aver>=80)
            s1++;
          if(p->aver<60)
            s2++;
            break;
        }
     }
     a1=s1/i;
     b1=s2/i;
     printf("\n�ð�������Ϊ��    %.2f%%",100*a1);
     printf("\n�ð಻������Ϊ��  %.2f%%",100*b1);
     printf("\n\n\n");
     system("pause");
     return(sort(head));
}


