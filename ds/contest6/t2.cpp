#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
const int MAXN = 1005;
struct BTNode
{
    int data;
    BTNode *lchild, *rchild;
};
bool f;

BTNode* CreateBT(int *pre, int *in, int n)
{
    if(n<=0)
    {
        return NULL;
    }
    BTNode *b = (BTNode*)malloc(sizeof(BTNode));
    b->data = *pre;
    int *p;
    int cnt = 0;
    for(p = in; p<in+n; p++)
    {
        if(*p==*pre)
        {
            cnt++;
            break;
        }
    }
    if(cnt==0)
    {
        f= false;
    }
    int k = p-in;
    b->lchild = CreateBT(pre+1, in, k);
    b->rchild = CreateBT(pre+k+1, p+1, n-k-1);
    return b;
}

void PostOrder(BTNode *b)
{
    BTNode* St[MAXN], *p;
    int top = -1;
    bool flag;
    do
    {
        while(b)
        {
            St[++top] = b;
            b = b->lchild;
        }
        p=NULL;
        flag = true;
        while(top>-1&&flag)
        {
            b = St[top];
            if(b->rchild==p)
            {
                cout<<b->data<<" ";
                --top;
                p=b;
            }
            else
            {
                b = b->rchild;
                flag = false;
            }
        }
    }
    while(top>-1);
    putchar('\n');
}

void Destroy(BTNode *&b)
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

    while(scanf("%d", &n)!=EOF)
    {
        //scanf("%s%s", a, b);
        int a[MAXN], b[MAXN];
        f = true;

        for(int i = 0; i<n; i++)
        {
            scanf("%d", &a[i]);
        }
        for(int i = 0; i<n; i++)
        {
            scanf("%d", &b[i]);
        }
        BTNode *t = CreateBT(a, b, n);
        if(f)
        {
            PostOrder(t);
        }
        else
        {
            printf("No\n");
        }

        Destroy(t);
    }
}

