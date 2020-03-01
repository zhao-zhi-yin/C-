#include <stdio.h>
#include "dijkstra.h"
#include "graphmatrixutil.h"
int *dijkstra(int source,GraphMatrix *graphMatrix)
{
   int i,j;
   int vex;
   int min;
   int* found=(int*)malloc(sizeof(int)* graphMatrix->size);
   int* distance=(int*)malloc(sizeof(int)* graphMatrix->size);
   for(i=0;i<graphMatrix->size;i++)
    {
        found[i]=0;
        distance[i]=graphMatrix->graph[source][i];
    }
    found[source]=1;
    distance[source]=0;
    for(i=0;i<graphMatrix->size;i++)
    {
        min=100;
        for(j=0;j<graphMatrix->size;j++)
        {
            if(!found[j])
            {
                if(distance[j]<min)
                {
                    vex=j;
                    min=distance[j];
                }
            }
        }
        found[vex]=1;
        for(j=0;j<graphMatrix->size;j++)
            if(!found[j]&&graphMatrix->graph[vex][j]!=100)
             if(min+graphMatrix->graph[vex][j]<distance[j])
             distance[j]=min+graphMatrix->graph[vex][j];
    }
   return distance;
}
