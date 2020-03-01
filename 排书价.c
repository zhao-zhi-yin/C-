#include <stdio.h>
#include <string.h>
#define n 3
    struct Book_store
    {
        char name[10];
        float price;
    }book[n];
    int Input(struct Book_store book[])
    {
        int i;
        for(i=0;i<n;i++)
        {
            printf("NO.%d Book's name:",i+1);
            scanf("%s",&book[i].name);
            printf("NO.%d Book's price:",i+1);
            scanf("%f",&book[i].price);
            printf("\n");
        }

    }
    int compare(struct Book_store book[])
    {
        int i,j;
        struct Book_store pt;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n-i;j++)
            if(book[i].price<=book[i+1].price)
            {
               pt=book[i+1];
               book[i+1]=book[i];
               book[i]=pt;
            }

        }
    }
    int Output(struct Book_store book[n])
    {
        int i;
        for(i=0;i<n;i++)
         printf("%5s  %.2f\n",book[i].name,book[i].price);
    }
    int main()
    {
        struct Book_store book[n];
        Input(book);
        compare(book);
        printf("  book name   book  price  \n");
        Output(book);
    }
