#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
int data[5005];


typedef struct node
{
    int data;
    int m;
    node* next;
} LinkNode, *LinkList;

void initList(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LinkNode));
    L->next = NULL;
}

void insert(LinkList &L, int n)
{
    int data2;
    int m;

    LinkList p = L;
    for(int i = 2; i<=n; i++)
    {
        if(data[i]!=0)
        {
            data2 = i;
            m = data[i];
        }
        else
        {
            continue;
        }
        LinkList q = (LinkList)malloc(sizeof(LinkNode));
        q->data = data2;
        q->m = m;
        q->next = p->next;
        p->next = q;
        p = q;
    }

}

void display(LinkList &L)
{
    LinkList p = L;
    while(p->next)
    {
        p = p->next;
        if(p->m==1)
        {
            printf("%d", p->data);
        }
        else
        {
            printf("%d^%d", p->data, p->m);
        }
        if(p->next)
        {
            printf("*");
        }
    }
    printf("\n");
}
void clear(LinkList &L)
{
    LinkList p = L;
    while(p->next)
    {
        LinkList q = p->next;
        p->next = q->next;
        free(q);
    }
}

int main()
{
    LinkList l;
    initList(l);
    int m;
    scanf("%d", &m);
    while(m--)
    {
        clear(l);

        memset(data,0,sizeof(data));
        int n;
        scanf("%d", &n);

        int cnt = 0;
        for(int i = 2; i<=n; i++)
        {
            int z = i;
            int j = 2;
            while(z!=1)
            {
                while(z%j==0)
                {
                    z/=j;
                    data[j]++;
                }
                j++;
            }
        }

                insert(l, n);
                display(l);

        }


    }

