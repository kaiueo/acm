#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;
typedef struct node
{
    char data;
    int num;
    node* lchild;
    node* rchild;
} BTNode;

string str;

BTNode* search(BTNode* BT, char x, BTNode* &father, int &a)
{
    BTNode* p =BT;
    father = NULL;
    while(p!=NULL)
    {
        father = p;
        if(x<p->data)
        {
            p = p->lchild;
        }
        else if(x==p->data)
        {
            p->num++;
            a = 1;
            return p;
        }
        else
        {
            p = p->rchild;
        }
    }
    return p;
}

int insert(BTNode* &BT, char x)
{
    BTNode* s, *p, *f;
    int a = 0;
    p = search(BT, x, f, a);
    if(a)
    {
        return 0;
    }

    s = new BTNode;
    s->data = x;
    s->num = 1;
    s->lchild = s->rchild = NULL;
    if(f==NULL)
    {
        BT = s;
    }
    else if(x<f->data)
    {
        f->lchild = s;
    }
    else
    {
        f->rchild = s;
    }
    return 1;
}

void Inorder(BTNode* T)
{
    if(T!=NULL)
    {
        Inorder(T->lchild);

        printf("%c(%d)\n", T->data, T->num);

        Inorder(T->rchild);

    }
}

void create(BTNode* &BT, int n)
{
    char x;
    BT = NULL;
    int i = 0;
    x = str[i++];
    while(n--)
    {
        insert(BT, x);
        if(n>0)
        {
            x = str[i++];
        }
    }
}
void Destroy(BTNode* &b)
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
    int t;
    scanf("%d", &t);
    getchar();
    for(int i = 1; i<=t; i++)
    {
        printf("Case %d:\n", i);
        getline(cin, str);
        BTNode* b;
        create(b, str.length());
        Inorder(b);
        Destroy(b);
    }
}
