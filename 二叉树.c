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
{//�����ڵ� BiTree &t�ȼ���BiTNode* &t
    DataType c;
    for(int i=0;elem[i]!='\0';i++)
    {
        c=eiem[i];
    	if(c == '#')//������ #ʱ������ڵ�ΪNULL���������÷�֧�ĵݹ�
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
    printf("������������������У�\n");
    gets(elem);
}
