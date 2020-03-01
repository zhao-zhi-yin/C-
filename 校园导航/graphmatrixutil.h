#ifndef GRAPHMATRIXUTIL_H_
#define GRAPHMATRIXUTIL_H_
typedef struct GRAPHMATRIX_STRU
{
    int size;
    int **graph;
}GraphMatrix;
GraphMatrix* InitGraph(int num);
void ReadGraph(GraphMatrix* graphMatrix);
void WriteGraph(GraphMatrix* graphMatrix);
#endif // GRAPHMATRIXUTIL_H_
