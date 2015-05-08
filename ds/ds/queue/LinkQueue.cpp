#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef int DataType;
typedef struct node{
    DataType data;
    node* next;
}LinkNode;
typedef struct{
    LinkNode* front;
    LinkNode* rear;
}LinkQueue;

//Pay attention that there is a head point!!!
void initQueue(LinkQueue* &Q){
    LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
    p->next = NULL;
    Q = (LinkQueue*)malloc(sizeof(LinkQueue));
    Q->rear = Q->front = p;
}

int QueueEmpty(LinkQueue* &Q){
    if(Q->front->next == NULL){
        return 1;
    }
    return 0;
}

int QueueSize(LinkQueue* &Q){
    LinkNode* p = Q->front->next;
    int length = 0;
    while(p){
        length++;
        p = p->next;
    }
    return length;
}

//Don't forget the final step: Move Q->rear to the final element!!!
void EnQueue(LinkQueue* &Q, DataType e){
    LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
    p->data = e;
    p->next = Q->rear->next;
    Q->rear->next = p;
    Q->rear = p;
}

int DeQueue(LinkQueue* &Q, DataType &e){
    if(QueueEmpty(Q)){
        return 0;
    }
    LinkNode* p = Q->front->next;
    e = p->data;
    Q->front->next = p->next;
    free(p);
    return 1;
}

int GetFront(LinkQueue* &Q, DataType &e){
    if(QueueEmpty(Q)){
        return 0;
    }
    LinkNode* p = Q->front->next;
    e = p->data;
    return 1;
}

int main(){
    LinkQueue* Q;
    initQueue(Q);
    for(int i = 1;i<10;i++){
        EnQueue(Q, i);
    }

    for(int i = 1;i<10;i++){
        printf("%d\n",QueueSize(Q));
        int tmp;
        GetFront(Q, tmp);
        printf("%d\n", tmp);
    }

    for(int i = 1;i<10;i++){
        printf("%d\n",QueueSize(Q));
        int tmp;
        DeQueue(Q, tmp);
        printf("%d\n", tmp);
    }

}
