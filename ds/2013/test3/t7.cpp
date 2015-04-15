#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

typedef struct node{
    int data;
    node* next;
}Stack;

void initStack(Stack* &S){
    S = (Stack*)malloc(sizeof(Stack));
    S->next = NULL;
}

int pop(Stack* S){
    if(S->next){
        return S->next->data;
    }
    else{
        return -1;
    }
}

void push(Stack* S, int e){
    Stack* p = (Stack*)malloc(sizeof(Stack));
    p->data = e;
    p->next = S->next;
    S->next = p;
}

void remov(Stack* S, int e){
    int tmp;
    while(tmp!=-1){
        tmp = pop(S);
        if(tmp == e){
            printf("SUCCEED\n");
            return;
        }
    }
    printf("ERROR\n");
}

int main(){
    int n, m;
    while(scanf("%d%d", &n, &m)!=EOF){
        Stack* a;
        initStack(a);
        string s;
        int k;
        cin>>s;
        if (s=="PLACE"){


            cin>>k;
            push(a, k);
            printf("SUCCEED\n");}
        else if(s=="REMOVE"){
            if(pop(a)!=-1){
                printf("SUCCEED\n");
            }
            else{
                printf("ERROR\n");
            }

        }
        else{cin>>k;
            remov(a, k);

        }


    }
}
