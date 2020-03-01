#include <stdio.h>

int main()
{
    int A,B,C,D,E,F;
    for(A=1;A>=0;A--)
     for(B=1;B>=0;B--)
      for(C=1;C>=0;C--)
       for(D=1;D>=0;D--)
        for(E=1;E>=0;E--)
         for(F=1;F>=0;F--)
         if(((A+B)>=1)&&((A+E+F)>=2)&&((A+D)==1)&&((B+C)==2||(B+C)==0)&&((C+D)==1))
         {
        if(D==0)
          E=0;
          printf("作案人员有:");
            if(A) printf("A ");
            if(B) printf("B ");
            if(C) printf("C ");
            if(D) printf("D ");
            if(E) printf("E ");
            if(F) printf("F ");
            printf("\n");
         }
   return 0;
}
