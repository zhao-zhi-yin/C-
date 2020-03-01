#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "create.h"


void RangedRandDemo( int range_min, int range_max, int n ,int *num)
{

   int i;
   for ( i = 0; i < n; i++ )
   {
      int u = (double)rand() / (RAND_MAX + 1) * (range_max - range_min)+ range_min;
      //printf( "  %6d  ", u);
      num[i]=u;
   }
}

