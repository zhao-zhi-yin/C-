#include <stdio.h>

int main()
{
    int A,B,C,X,Y,Z;
    A=1;B=2;C=3;
    for(X=1;X<=3;X++)
     for(Y=1;Y<=3;Y++)
      for(Z=1;Z<=3;Z++)
      if(A!=X&&C!=X&&C!=Z&&X!=Y&&Y!=Z&&X!=Z)
      {
          switch(X)
           {
          case 1:printf("X��A����\n");break;
          case 2:printf("X��B����\n");break;
          case 3:printf("X��C����\n");break;
           }
          switch(Y)
          {
          case 1:printf("Y��A����\n");break;
          case 2:printf("Y��B����\n");break;
          case 3:printf("Y��C����\n");break;
          }
          switch(Z)
          {
          case 1:printf("Z��A����\n");break;
          case 2:printf("Z��B����\n");break;
          case 3:printf("Z��C����\n");break;
          }
          printf("\n");
      }
}
