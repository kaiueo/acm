#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef struct node{
    char* data;
    node* next;
}QueueNode;

typedef struct{
    QueueNode* front;
    QueueNode* rear;
}Queue;

void initQueue(Queue* &Q){
    QueueNode* q = (QueueNode*)malloc(sizeof(QueueNode));
    Q = (Queue*)malloc(sizeof(Queue));
    q->next = NULL;
    Q->front = Q->rear = q;
}

int QueueEmpty(Queue* &Q){
    if(Q->front->next==NULL){
        return 1;
    }
    return 0;
}

void EnQueue(Queue* &Q, char* &e){
    QueueNode* q = (QueueNode*)malloc(sizeof(QueueNode));
    q->data = e;
    q->next = Q->rear->next;
    Q->rear->next = q;
    Q->rear = q;
}

int DeQueue(Queue* &Q, char* &e){
    if(QueueEmpty(Q)){
        return 0;
    }
    QueueNode* q = Q->front->next;
    e = q->data;
    Q->front->next = q->next;
    free(q);
    return 1;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Queue* male;
        Queue* female;
        initQueue(male);
        initQueue(female);

        for(int i = 1;i<=n;i++){
            char s1, *s2;
            s2 = new char[100];
            cin>>s1>>s2;
            if(s1=='m'){
                EnQueue(male, s2);
            }
            else{
                EnQueue(female, s2);
            }
        }
        for(int i = 1;!QueueEmpty(male)&&!QueueEmpty(female);i++){
            char *s1;
            char *s2;
            DeQueue(female, s1);
            DeQueue(male, s2);
            cout<<s1<<" "<<s2<<endl;
        }
    }
}
