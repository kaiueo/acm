#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef string DataType;
typedef struct node{
    DataType* data;
    DataType* data1;
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
    Q = (LinkQueue*)malloc( sizeof(LinkQueue));
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
void EnQueue(LinkQueue* &Q, DataType* e, DataType* e1){
    LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
    p->data = e;
    p->data1 = e1;
    p->next = Q->rear->next;
    Q->rear->next = p;
    Q->rear = p;
}

int DeQueue(LinkQueue* &Q, string* &s2, string* &s3){
    if(QueueEmpty(Q)){
        return 0;
    }
    LinkNode* p = Q->front->next;
    s2 = p->data;
    s3 = p->data1;
    Q->front->next = p->next;
    free(p);
    return 1;
}

void show(LinkQueue* &Q)
{
    LinkNode* p = Q->front->next;
    while(p)
    {
        //string* s = p->data;
        cout<<*(p->data)<<" "<<*(p->data1)<<endl;
        p = p->next;
    }
    cout<<endl;
}



int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
        LinkQueue* q;
        initQueue(q);
        for(int i = 0;i<n;i++){
            string s1;
            cin>>s1;
            if(s1=="Add"){
                string* s2 = new string;
                string* s3 = new string;
                cin>>(*s2)>>(*s3);
                EnQueue(q, s2, s3);
            }
            else if(s1=="Reverse"){
                string* s2;
                string* s3;
                DeQueue(q, s2, s3);
                EnQueue(q, s2, s3);
            }
            else{
                show(q);

            }
        }
    }

}

