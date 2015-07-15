#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef struct node{
    int data;
    node* next;
}LinkNode, *LinkList;

void initList(LinkList &first){
    first = (LinkNode*)malloc(sizeof(LinkNode));
    first->next = NULL;
}

int remove(LinkList &first, int i, int e){
    LinkNode* p = first;
    int j = 0;
    while(p->next&&j<i-1){
        p = p->next;
        j++;
    }
    if(!(p->next)||j>i-1){
        return 0;
    }
    LinkNode* q = (LinkNode*)malloc(sizeof(LinkNode));
    q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
}

int mx(LinkList &l, int &idx, int &e){
    if(l){
        idx = -1;
        e = 0x3f3f3f3f;
        LinkNode* p =l->next;
        int i = 1;
        while(p){
            if(p->data<e){
                e = p->data;
                idx = i;
            }
            p = p->next;
            i++;
        }
        int a;
        remove(l, idx, a);
        return 1;
    }
    return 0;
}

LinkList sortit(LinkList &l){
    int idx, e;
    LinkList a;
    initList(a);
    while(mx(l, idx, e)){
        LinkNode* p =(LinkNode*)malloc(sizeof(LinkNode));
        p->data = e;
        LinkNode* q = l->next;
        p->next = q->next;
        q->next = p;
    }
}

LinkList create(int n){
    LinkList a;
    initList(a);
    for(int i = 1;i<=n;i++){
        int b;
        scanf("%d", &b);
        LinkNode* p =(LinkNode*)malloc(sizeof(LinkNode));
        p->data = b;
        LinkNode* q = a->next;
        p->next = q->next;
        q->next = p;
    }
}

void dis(LinkList &l){
    LinkNode* p = l->next;
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
        LinkList a = create(n);
        sortit(a);
        dis(a);

    }
}
