#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
typedef struct mint{
    int n;
    int o;
};
mint data[100005];
int data1[100005];
typedef struct node
{
    mint data;
    node* next;
} StackNode, *Stack;

void initStack(Stack &S)
{
    S = (Stack)malloc(sizeof(StackNode));
    S->next = NULL;
}

int StackEmpty(Stack &S)
{
    return S->next == NULL;
}

int Push(Stack &S, mint e)
{
    Stack p = (Stack)malloc(sizeof(StackNode));
    p->data = e;
    p->next = S->next;
    S->next = p;
}

int Pop(Stack &S, mint &e)
{
    if(StackEmpty(S))
    {
        return 0;
    }
    Stack p = S->next;
    e = p->data;
    S->next = p->next;
    free(p);
    return 1;
}

mint Top(Stack &S)
{
    Stack p = S->next;
    return p->data;
}

int main()
{
    int n;
    while(scanf("%d", &n)!=EOF)
    {
        memset(data, 0, sizeof(data));
        for(int i = 0; i<n; i++)
        {
            scanf("%d", &data[i].n);
            data[i].o = i;
        }
        Stack s;
        initStack(s);
        Stack d;
        initStack(d);
        Push(s, data[0]);

        for(int i = 1; i<n; i++)
        {

            mint next = data[i];
            mint top = Top(s);
            while(!StackEmpty(s) && top.n<next.n)
            {
                data1[top.o] = next.n;

                mint tmp;
                Pop(s, tmp);
                if(!StackEmpty(s))
                {
                    top = Top(s);
                }
            }
            Push(s, next);
        }

        while(!StackEmpty(s))
        {

            mint tmp;
            Pop(s, tmp);
            data1[tmp.o] = -1;
        }
        for(int i = 0;i<n;i++){
            printf("%d\n", data1[i]);
        }
    }

}

