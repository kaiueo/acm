#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef string DataType;
typedef struct node
{
    DataType* data;
    node* next;
} LinkNode;
typedef struct
{
    LinkNode* front;
    LinkNode* rear;
} LinkQueue;

//Pay attention that there is a head point!!!
void initQueue(LinkQueue* &Q)
{
    LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
    p->next = NULL;
    Q = (LinkQueue*)malloc( sizeof(LinkQueue));
    Q->rear = Q->front = p;
}

int QueueEmpty(LinkQueue* &Q)
{
    if(Q->front->next == NULL)
    {
        return 1;
    }
    return 0;
}

int QueueSize(LinkQueue* &Q)
{
    LinkNode* p = Q->front->next;
    int length = 0;
    while(p)
    {
        length++;
        p = p->next;
    }
    return length;
}

//Don't forget the final step: Move Q->rear to the final element!!!
void EnQueue(LinkQueue* &Q, DataType* e, int a)
{
    if(a)
    {
        LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
        p->data = e;
        p->next = Q->rear->next;
        Q->rear->next = p;
        Q->rear = p;

    }
    else
    {
        LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
        p->data = e;
        p->next = Q->front->next;
        Q->front->next = p;
        if(Q->front == Q->rear){
            Q->rear = p;
        }

    }

}

int DeQueue(LinkQueue* &Q, int a)
{
    if(QueueEmpty(Q))
    {
        return 0;
    }
    if(a)
    {

        LinkNode* p = Q->front->next;

        Q->front->next = p->next;
        free(p);
        return 1;
    }
    else
    {
        LinkNode* p = Q->front;
        while(p->next!=Q->rear)
        {
            p = p->next;
        }
        LinkNode* l = Q->rear;

        p->next = l->next;
        free(l);
        Q->rear = p;
        return 1;
    }
}


void show(LinkQueue* &Q)
{
    LinkNode* p = Q->front->next;
    while(p)
    {
        //string* s = p->data;
        cout<<*(p->data)<<endl;
        p = p->next;
    }
    cout<<endl;
}

int main()
{
    int n;
    while(scanf("%d", &n)!=EOF)
    {
        LinkQueue* q;
        initQueue(q);
        for(int i = 0; i<n; i++)
        {
            string a;
            cin>>a;
            if(a=="AS")
            {
                string* s1 = new string;
                cin>>(*s1);
                EnQueue(q, s1, 0);
            }
            else if(a=="AE")
            {
                string* s1 = new string;
                cin>>(*s1);
                EnQueue(q, s1, 1);
            }
            else if(a == "DS")
            {

                DeQueue(q,  1);
            }
            else if(a=="DE")
            {

                DeQueue(q,  0);
            }
            else
            {
                show(q);
            }

        }
    }

}

