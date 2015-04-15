#include <iostream>
#include <cstdlib>
#include <cstdio>

typedef struct node{
    int data;
    node* next;
}LinkNode, *LinkList;

void initList(LinkList &L){
    L = (LinkList)malloc(sizeof(LinkNode));
    L->next = NULL;
}

void creat(LinkList &L, int n){
    LinkList e = L;
    for(int i = 1;i<=n;i++){
        LinkList p = (LinkList)malloc(sizeof(LinkNode));
        p->data = i;
        p->next = e->next;
        e->next = p;
        e = p;
    }
    e->next = L->next;

}

int john(LinkList &first, int m, int n){
    LinkList p = first;
    for(int i = 1;i<n;i++){
        for(int i = 1;i<m;i++){
            p = p->next;
        }
        LinkList q = p->next;
        p->next = q->next;
        free(q);
    }
    return p->data;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d%d", &n, &m);
        LinkList l;
        initList(l);
        creat(l, n);
        int a = john(l, m, n);
        printf("%d\n", a);
    }
}
