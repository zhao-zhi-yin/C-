#include <stdio.h>
#include <stdlib.h>
#include "graphmatrixutil.h"
GraphMatrix* InitGraph(int num)
{
    int i,j;

    GraphMatrix* graphMatrix = (GraphMatrix*)malloc(sizeof(GraphMatrix));
    graphMatrix->size=num;
    graphMatrix->graph=(int**)malloc(sizeof(int*)* graphMatrix->size);
    for(i=0;i<graphMatrix->size;i++)
    {
        graphMatrix->graph[i]=(int*)malloc(sizeof(int)* graphMatrix->size);
    }
    for(i=0;i<graphMatrix->size;i++)
       for(j=0;j<graphMatrix->size;j++)
        graphMatrix->graph[i][j]=100;

    return graphMatrix;
}
void ReadGraph(GraphMatrix* graphmatrix)
{
    int vex1,vex2,weight;
    printf("请输入（点 点 权值），权值为0时输入结束：\n");
    //scanf("%d %d %d ",&vex1,&vex2,&weight);
    //(0,1,1)(1,0,1)(0,4,1)(4,0,1)(1,4,1)(4,1,1)(1,2,1)(2,1,1)(1,3,1)(3,1,1)(2,3,1)(3,2,1)(4,5,1)(5,4,1)(4,6,1)(6,4,1)(0,0,0)
    //while(weight!=0)
    //{
        //graphmatrix->graph[vex1][vex2]=weight;
        //scanf(" %d %d %d ",&vex1,&vex2,&weight);
    //}
    graphmatrix->graph[0][1]=5;graphmatrix->graph[0][2]=30;graphmatrix->graph[0][3]=35;graphmatrix->graph[1][2]=24;
    graphmatrix->graph[1][5]=10;graphmatrix->graph[1][4]=29;graphmatrix->graph[2][5]=17;
    graphmatrix->graph[3][0]=15;graphmatrix->graph[4][5]=25;graphmatrix->graph[5][4]=12;graphmatrix->graph[5][3]=8;
}
void WriteGraph(GraphMatrix* graphmatrix)
{
    int i,j;
    printf("图的结构如下（点,点,权值）：\n");
    for(i=0;i<graphmatrix->size;i++)
       for(j=0;j<graphmatrix->size;j++)
            if(graphmatrix->graph[i][j]>0)
             printf("(%d,%d,%d)\n",i,j,graphmatrix->graph[i][j]);
}
