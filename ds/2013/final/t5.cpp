#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
typedef struct node
{
    char data;
    node* lchild;
    node* rchild;
} BTNode;
const int MAXN = 10005;
char str[MAXN];
void CreateBTNode(BTNode* &b)
{
    BTNode* St[MAXN], *p;
    int top = -1;
    b = NULL;
    int k, l = strlen(str);
    for(int i = 0; i<l; i++)
    {
        switch(str[i])
        {
        case '(':
            k = 1;
            St[++top] = p;
            break;
        case ')':
            top--;
            break;
        case ',':
            k = 2;
            break;
        default:
            p = (BTNode*)malloc(sizeof(BTNode));
            p->data = str[i];
            p->lchild= p->rchild = NULL;
            if(!b)
            {
                b = p;
            }
            else
            {
                switch(k)
                {
                case 1:
                    St[top]->lchild = p;
                    break;
                case 2:
                    St[top]->rchild = p;
                    break;
                }
            }
        }
    }
}

void Reverse(BTNode* &b)
{
    if(b)
    {
        BTNode* p = b->rchild;
        b->rchild = b->lchild;
        b->lchild = p;
        Reverse(b->lchild);
        Reverse(b->rchild);
    }
}

void print(BTNode* &b)
{
    if(b)
    {
        printf("%c", b->data);
        if(b->lchild||b->rchild)
        {

            printf("(");
            print(b->lchild);
            if(b->rchild)
            {
                printf(",");
                print(b->rchild);
            }
            printf(")");
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
    while(~scanf("%s", str))
    {
        BTNode* b;
        CreateBTNode(b);
        Reverse(b);
        print(b);
        printf("\n");
        Destroy(b);
    }
}
