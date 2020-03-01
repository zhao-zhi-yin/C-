#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"

int main()
{
    GraphMatrix* graphMatrix=NULL;
    int* distance=NULL;
    int i;
    graphMatrix =InitGraph(6);
    ReadGraph(graphMatrix);
    distance=dijkstra(0,graphMatrix);
    for(i=0;i<graphMatrix->size;i++)
    {
        if(distance[i]<100)
            printf("0�Žڵ㵽%d�Žڵ���̾���Ϊ��%d\n",i,distance[i]);
        else printf("0�Žڵ㵽%d�Žڵ㲻��ͨ\n",i);
    }
    return 0;
}
