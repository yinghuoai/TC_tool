#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define OK 1
#define ERROR 0

typedef int Status;
typedef int TElemType;


typedef struct BiTNode
{
    TElemType data;   
    struct BiTNode *lchild, *rchild;
	int depth;
	
	
}BiTNode, *BiTree;


Status CreateBiTree(BiTree *T)
{
    TElemType e;
    scanf("%d", &e);
    if (e == 0)
    {
        *T = NULL;
    }
    else
    {
        *T = (BiTree) malloc(sizeof(BiTNode));
        if (!T)
        {
            exit(OVERFLOW);
        }
        (*T)->data = e;
        CreateBiTree(&(*T)->lchild);   
        CreateBiTree(&(*T)->rchild);    
    }
    return OK;
}


void visit(TElemType e)
{
    printf("%d ", e);
}


Status PreOrderTraverse(BiTree T, void (*visit)(TElemType))
{
    if (T)
    {
        visit(T->data);
        PreOrderTraverse(T->lchild, visit);
        PreOrderTraverse(T->rchild, visit);
    }
}


Status InOrderTraverse(BiTree T, void (*visit)(TElemType))
{
    if (T)
    {
        InOrderTraverse(T->lchild, visit);
        visit(T->data);
        InOrderTraverse(T->rchild, visit);
    }
}


Status PostOrderTraverse(BiTree T, void (*visit)(TElemType))
{
    if (T)
    {
        PostOrderTraverse(T->lchild, visit);
        PostOrderTraverse(T->rchild, visit);
        visit(T->data);
    }
}

int main()
{
    BiTree T;
    printf("shu:\n");
    CreateBiTree(&T);
    printf("preorder:");
    PreOrderTraverse(T, *visit);
    printf("\ninorder:");
    InOrderTraverse(T, *visit);
    printf("\npostorder:");
    PostOrderTraverse(T, *visit);
    printf("\n");

    return 0;
}












