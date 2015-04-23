#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
typedef struct{
    int* data;
    int front, rear;
    int size;
}Queue;

void initQuene(Queue* &q, int n){
    q = (Queue*)malloc(sizeof(Queue));
    q->data = (int*)malloc(sizeof(int) * n);
    q->front = 0;
    q->rear = 0;
    q->size = n;
}

int QueneEmpty(Queue* &q){
    if(q->rear == q->front){
        return 1;
    }
    return 0;
}
int QueueFull(Queue* &q){
    return (q->rear + 1) % q->size == q->front;
}
int EnQuene(Queue* &q, int e){
    if(QueueFull(q)){
        return 0;
    }
    q->data[q->rear] = e;
    q->rear = (q->rear + 1)% q->size;
    return 1;
}

int DeQueue(Queue* &q, int &e){
    if(QueneEmpty(q)){
        return 0;
    }
    e = q->data[q->front];
    q->front = (q->front + 1) % q->size;
    return 1;
}

int main(){
    int n;
    scanf("%d", &n);
        Queue *q;
        initQuene(q, n);
        int t;
        scanf("%d", &t);
        for(int i = 1;i<=t;i++){

            string s;
            cin>>s;
            if(s=="E"){
                int e;
                cin>>e;
                if(!EnQuene(q, e)){
                    printf("I Am Full!\n");
                }
            }
            else{
                int e;
                if(!DeQueue(q, e)){
                    printf("Has No Element!\n");
                    return 0;
                }
            }
        }
        int w;
        while(DeQueue(q, w)){
            printf("%d ", w);
        }
        printf("\n");


}
