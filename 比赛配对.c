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
          case 1:printf("X与A对赛\n");break;
          case 2:printf("X与B对赛\n");break;
          case 3:printf("X与C对赛\n");break;
           }
          switch(Y)
          {
          case 1:printf("Y与A对赛\n");break;
          case 2:printf("Y与B对赛\n");break;
          case 3:printf("Y与C对赛\n");break;
          }
          switch(Z)
          {
          case 1:printf("Z与A对赛\n");break;
          case 2:printf("Z与B对赛\n");break;
          case 3:printf("Z与C对赛\n");break;
          }
          printf("\n");
      }
}
