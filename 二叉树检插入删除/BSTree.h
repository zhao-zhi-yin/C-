#ifndef BSTree_H
#define BSTree_H

typedef int DataType;

typedef struct TreeNode
{	DataType data;
    struct TreeNode *lchild,*rchild;
}TreeNode,*BiTree;

BiTree createBiTree(int *elem);//创建二叉树

int CountLeaf(BiTree bt);//打印叶子节点

void InOrder_Recursion(BiTree ptree);//中序遍历二叉树

BiTree Search(BiTree bt,DataType key);//二叉树检索

int BinInsert(BiTree bt,DataType key);//二叉树插入

int BinDelete(BiTree *bt,DataType key);//二叉树删除

int BinDestroy(BiTree *bt);//销毁二叉树

#endif // BSTree_H
