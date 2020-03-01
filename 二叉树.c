#include <stdio.h>
char elem[20];
typedef char DataType;

typedef struct TreeNode
{	DataType data;
    struct TreeNode *lchild,*rchild;
}TreeNode,*BiTree;

typedef struct StackNode
{	TreeNode *data;
	struct StackNode *next;
}StackNode,*LinkStack;

void createBiTree(BiTree &t)
{//括号内的 BiTree &t等价于BiTNode* &t
    DataType c;
    for(int i=0;elem[i]!='\0';i++)
    {
        c=eiem[i];
    	if(c == '#')//当遇到 #时，令根节点为NULL，结束掉该分支的递归
                    t = NULL;
        else{
                t = new TreeNode;
        		t->data = c;
                createBiTree(t->lchild);
        		createBiTree(t->rchild);
            }
    }

}
int main()
{
    printf("输入树的先序遍历序列：\n");
    gets(elem);
}
