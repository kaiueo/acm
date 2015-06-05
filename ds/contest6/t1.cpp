#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef struct node
{
    char data;
    struct node* lchild;
    struct node* rchild;
} BiTNode, *BinTree;

void createBinTree(BinTree &T)
{
    char item;
    cin>>item;
    if(item=='\0')
    {
        return;
    }
    if(item!='#')
    {
        T = (BinTree)malloc(sizeof(BiTNode));
        T->data = item;
        createBinTree(T->lchild);
        createBinTree(T->rchild);
    }
    else
    {
        T = NULL;
    }
}

void printBinTree(BinTree &T)
{
    if(T!=NULL)
    {
        cout<<T->data;
        if(T->lchild!=NULL||T->rchild!=NULL)
        {
            cout<<'(';
            printBinTree(T->lchild);
            cout<<',';
            printBinTree(T->rchild);
            cout<<')';
        }
    }
}
void Destroy(BinTree &b)
{
    if(b->lchild)
    {
        Destroy(b->lchild);
    }
    if(b->rchild)
    {
        Destroy(b->rchild);
    }
    free(b);
}

int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        BinTree b;
        createBinTree(b);
        printBinTree(b);
        cout<<endl;
        Destroy(b);
    }
}

