#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
typedef struct node{
    char data[105];
    node* next;
}LinkNode, *LinkList;

void initList(LinkList &L){
    L = (LinkList)malloc(sizeof(LinkNode));
    L->next = NULL;
}

void creat(LinkList &L, int n){
    LinkList p = L;
    for(int i = 1;i<=n;i++){
        LinkList q = (LinkList)malloc(sizeof(LinkNode));
        gets(q->data);
        q->next = p->next;
        p->next = q;
    }
}

void display(LinkList &L){
    LinkList p = L;
    while(p->next){
        p = p->next;
        printf("%s\n", p->data);
    }
}

int main()
{
    int n;
    while(scanf("%d", &n)!=EOF){
        getchar();
        LinkList l;
        initList(l);
        creat(l, n);
        display(l);
    }

    return 0;
}

