#include <iostream>
#include <cstdlib>
#include <cstdio>
typedef struct node
{
    int data;
    node* next;
    node* pre;
} LinkNode, *LinkList;

void initList(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LinkNode));
    L->next = NULL;
    L->pre = NULL;
}
void creat(LinkList &first, int n)
{
    LinkList p = first;
    for(int i = 1; i<=n; i++)
    {
        LinkList q = (LinkList)malloc(sizeof(LinkNode));
        q->data = i;
        q->next = p->next;
        q->pre = p;
        p->next = q;
        p = q;
    }
    p->next = first->next;
    first->pre = p;
}
int john(LinkList &first, int k, int n)
{
    int tmp = n;
    LinkList p = first;
    if(n==1) return p->data;
    LinkList p1 = first;
    bool b = false;
    while(n>1)
    {
        for(int i = 1; i<=n; i++)
        {
            if(tmp == 1)
            {
                break;
            }
            for(int j = 1; j<k&&i<=n; j++,i++)
            {
                p = p->next;
                if(i==n&&j<k){
                    b = true;
                }

            }
            LinkList q = p->next;
            //printf("%d\n", q->data);
            p->next = q->next;
            free(q);
            tmp--;

        }
        if(tmp == 1)
        {
            break;
        }
        n = tmp;
        k++;
        if(!b){
            p = p->pre;
        }



    }

    return p->data;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        LinkList l;
        initList(l);
        creat(l, n);
        int c = john(l,2,n);
        printf("%d\n", c);
    }
}
