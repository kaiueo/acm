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

void creat(LinkList &first, int n){
    for(int i = 0;i<n;i++){
        LinkList q = (LinkList)malloc(sizeof(LinkNode));
        int tmp;
        scanf("%d", &tmp);
        q->data=tmp;
        q->next = first->next;
        first->next = q;
    }
}
int search(LinkList &l1, LinkList &l2){
    LinkList p = l1->next;
    LinkList q = l2->next;
    int a = p->data;
    bool b = false;
    while(p&&q&&(p->data==q->data)){
        a = p->data;
        p = p->next;
        q = q->next;
        b = true;

    }
    if(b){
        return a;
    }
    else{
        return -1;
    }
}
int main(){
    int m, n;
    while(scanf("%d%d", &m, &n)!=EOF){
        LinkList l1;
        LinkList l2;
        initList(l1);
        initList(l2);
        creat(l1,m);
        creat(l2,n);
        int a = search(l1, l2);
        if(a!=-1){
            printf("%d\n", a);
        }
        else{
            printf("My God\n");
        }
    }
}
