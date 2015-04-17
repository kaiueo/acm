#include <iostream>
#include <cstdlib>
#include <cstdio>
#define maxSize 100

typedef int DataType;
typedef struct{
    DataType data[maxSize];
    int front, rear;
}CircQueue;

void initQueue(CircQueue* &Q){
    Q = (CircQueue*)malloc(sizeof(CircQueue));
    Q->front = Q->rear = 0;
}

int QueueEmpty(CircQueue* &Q){
    return Q->front == Q->rear;
}

int QueueFull(CircQueue* &Q){
    return (Q->rear + 1) == Q->front;
}

int QueueSize(CircQueue* &Q){
    return (Q->rear - Q->front + maxSize) % maxSize;
}

int EnQueue(CircQueue* &Q, DataType e){
    if(QueueFull(Q)){
        return 0;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % maxSize;
    return 1;
}

int DeQueue(CircQueue* &Q, DataType &e){
    if(QueueEmpty(Q)){
        return 0;
    }
    e = Q->data[Q->front];
    Q->front = (Q->front + 1) % maxSize;
    return 1;
}

int GetFront(CircQueue* &Q, DataType &e){
    if(QueueEmpty(Q)){
        return 0;
    }
    e = Q->data[Q->front];
    return 1;
}

int main(){
    CircQueue* Q;
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
