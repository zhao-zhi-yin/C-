#ifndef BSTree_H
#define BSTree_H

typedef int DataType;

typedef struct TreeNode
{	DataType data;
    struct TreeNode *lchild,*rchild;
}TreeNode,*BiTree;

BiTree createBiTree(int *elem);//����������

int CountLeaf(BiTree bt);//��ӡҶ�ӽڵ�

void InOrder_Recursion(BiTree ptree);//�������������

BiTree Search(BiTree bt,DataType key);//����������

int BinInsert(BiTree bt,DataType key);//����������

int BinDelete(BiTree *bt,DataType key);//������ɾ��

int BinDestroy(BiTree *bt);//���ٶ�����

#endif // BSTree_H
