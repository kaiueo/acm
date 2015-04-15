#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;

typedef struct node
{
    char data[20];
    node* next;
} LinkNode, *LinkList;
void initList(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LinkNode));
    // L->data="";
    L->next = NULL;
}
void creat(LinkList &first, int n)
{
    LinkList p = first;
    for(int i = 1; i<=n; i++)
    {
        LinkList q = (LinkList)malloc(sizeof(LinkNode));
        scanf("%s",(q->data));
        q->next = p->next;
        p->next = q;
        p = q;
    }
    //LinkList a = first->next;
    p->next = first->next;
}
void john(LinkList &first, int w, int m, int n)
{
    LinkList p = first;
    for(int i = 1; i<w; i++)
    {
        p = p->next;
        //printf("%s\n", (p->data));
    }
    for(int i = 1; i<=n; i++)
    {
        //printf("%s\n", (p->data));
        for(int i = 1; i<m; i++)
        {
            p = p->next;
            //printf("%s\n", (p->data));
        }
        LinkList q = p->next;
        printf("%s\n", (q->data));
        p->next = q->next;
        free(q);
    }
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        LinkList l;
        initList(l);
        creat(l, n);
        int w, m;
        scanf("%d,%d", &w, &m);
        john(l,w,m,n);
    }
}

