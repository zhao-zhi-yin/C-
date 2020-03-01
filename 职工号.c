#include <stdio.h>
#include <string.h>
void input(char name[][20],int num[]);
void sort(char name[][20],int num[]);
void search(char name[][20],int num[],int x);
int main()
{
    char name[10][20];
    int num[10];
    int x,i;
    input(name,num);
    for (i=0; i<10; i++){
        printf("%s  ", name[i]);
        printf("%d\n", num[i]);
    }

    sort(name,num);
    printf("\nPlease input number:\n");
    scanf("%d",&x);
    search(name,num,x);
}
 void input(char name[][20],int num[10])
 {
     int i;
     for(i=0;i<10;i++)
     {
      printf("Please input name:\n");
      scanf("%s",&name[i]);
      printf("Please input number:\n");
      scanf("%d",&num[i]);
      }
 }
 void sort(char name[][20],int num[10])
 {
     int i,j,a;
     char b[20];
     for(i=0;i<10;i++)
        for(j=i+1;j<10;j++)
        if(num[i]>num[j])
        a=num[i];
     num[i]=num[j];
     num[j]=a;
     strcpy(b,name[i]);
     strcpy(name[i],name[j]);
     strcpy(name[j],b);
 }
 void search(char name[][20],int num[10],int x)
 {
     int low,high,mid;
     low=0;
     high=9;
     while(low<=high)
     {
         mid=(low+high)/2;
         if(x>num[mid])
            low=mid+1;
         else if(x<num[mid])
            high=mid-1;
         else if(x==num[mid])
         {
             printf("%s\n",name[mid]);
             break;
         }
     }
     if(x!=num[mid])
        printf("Can't find!\n");
 }
