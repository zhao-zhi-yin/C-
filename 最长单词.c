#include <stdio.h>

char str[80];
int longest_word(char str[],char word[]);
int main()
{
    char t[80],word[80];
    puts("Please in put some words:");
    gets(t);
    longest_word(t,word);
    puts(word);
}

int longest_word(char str[],char word[])
{
    int stp[80];
    int n=0,i=0,j=0,k=0;
    for(i=0;str[i]!='\0';i++)
    {
          if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))
          {
              n++;
              stp[j]=n;
          }
          if(str[i+1]==' ')
             {
               j++;n=0;
             }else if(str[i+1]=='\0') stp[j+1]='\0';
    }
    for(i=0;stp[i]!='\0';i++)
    printf("%d ",stp[i]);
    n=0;j=0;
    for(i=0;stp[i]!='\0';i++)
        if(stp[i]>=stp[j])
             j=i;
 printf("\n%d",j);
    for(i=0;str[i]!='\0';i++)
        if(str[i]==' ')
          {

            printf("\n %d",n);
            n++;
            printf("\n %d",n);
            if(n==j)
               if(str[i+1]!=' ')
             {
                word[k]=str[i+1];
                printf("%c",word[k]);
                 k++;
                 i++;
             }
          }

}
