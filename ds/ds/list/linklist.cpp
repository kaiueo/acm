#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef int DataType;
typedef struct node{
    DataType data;
    struct node* next;
}LinkNode, *LinkList;

void initList(LinkList &first){
    first = (LinkNode*)malloc(sizeof(LinkNode));
    first->next = NULL;
}

void clearList(LinkList &first){
    LinkNode* p =first->next;
    LinkNode* q;
    while(p){
        q = p->next;
        free(p);
        p = q;
    }
    first->next = NULL;
}

int isEmpty(LinkList &first){
    return first->next == NULL;
}

int length(LinkList &first){
    LinkNode* p = first->next;
    int length = 0;
    while(p){
        length++;
        p = p->next;
    }
    return length;
}

//i: ith
int search(LinkList &first, DataType e){
    LinkNode* p = first->next;
    int i = 1;
    while(p){
        if(p->data==e){
            return i;
        }
        p = p->next;
        i++;
    }
    return -1;
}

//i: ith
int insert(LinkList &first, int i, DataType e){
    LinkNode* p = first;
    int j = 0;
    while(p&&j<i-1){
        p = p->next;
        j++;
    }
    if(!p||j>i-1){
        return 0;
    }
    LinkNode* q = (LinkNode*)malloc(sizeof(LinkNode));
    q->data = e;
    q->next = p->next;
    p->next = q;

}

//i: ith
int remove(LinkList &first, int i, DataType &e){
    LinkNode* p = first;
    int j = 0;
    while(p&&j<i-1){
        p = p->next;
        j++;
    }
    if(!p||j>i-1){
        return 0;
    }
    LinkNode* q = (LinkNode*)malloc(sizeof(LinkNode));
    q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
}

//i: ith
int getElem(LinkList &first, int i, DataType &e){
    LinkNode* p = first;
    int j = 0;
    while(p&&j<i){
        p = p->next;
        j++;
    }
    if(!p||j>i){
        return 0;
    }
    e = p->data;
    return 1;
}

void copy(LinkList &L1, LinkList &L2){
    LinkNode* p2 = L2->next;
    LinkNode* p1 = L1->next;
    while(!p2){
        LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
        p->data = p2->data;
        p1->next = p;
        p->next = NULL;
        p2 = p2->next;
        p1 = p;
    }
}

int main(){
    LinkList L1;
    initList(L1);
    for(int i = 1;i<=10;i++){
        insert(L1, i,i);
    }

    int l = length(L1);
    for(int i = 1;i<=l;i++){
        DataType e;
        getElem(L1, i, e);
        printf("%d ", e);
    }
    printf("\n\n");
    insert(L1, 3,100);
    l = length(L1);
    for(int i = 1;i<=l;i++){
        DataType e;
        getElem(L1, i, e);
        printf("%d ", e);
    }
    printf("\n\n");
    DataType e1;

    remove(L1,5,e1);

    printf("%d\n\n", e1);
    l = length(L1);
    for(int i = 1;i<=l;i++){
        DataType e;
        getElem(L1, i, e);
        printf("%d ", e);
    }

    LinkList L2;
    initList(L2);
    copy(L2, L1);
    printf("\n\n");
    int l2 = length(L2);
    for(int i = 1;i<=l2;i++){
        DataType e;
        getElem(L2, i , e);
        printf("%d ", e);
    }
    printf("\n\n");
    printf("%d\n\n", search(L1, 100));
    clearList(L1);
    l = length(L1);
    for(int i = 1;i<=l;i++){
        DataType e;
        getElem(L1, i, e);
        printf("%d ", e);
    }
    printf("%d\n\n", isEmpty(L1));


    return 0;

}
