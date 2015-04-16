#include <iostream>
#include <cstdio>
#include <cstdlib>

typedef int Datatype;
typedef struct node{
    Datatype data;
    node* next;
}LinkNode, *LinkStack;

void initStack(LinkStack &S){
    S = (LinkStack)malloc(sizeof(LinkNode));
    S->next = NULL;
}

//Pay attention to the judgement.
int StackEmpty(LinkStack &S){
    if(S->next){
        return 0;
    }
    return 1;
}

//The e here, don't need the &.
void push(LinkStack &S, Datatype e){
    LinkStack p = (LinkStack)malloc(sizeof(LinkNode));
    p->data = e;
    p->next = S->next;
    S->next = p;
}

int pop(LinkStack &S, Datatype &e){
    if(StackEmpty(S)){
        return 0;
    }
    LinkStack p = S->next;
    e = p->data;
    S->next = p->next;
    free(p);
    return 1;
}

int gettop(LinkStack &S, Datatype &e){
    if(StackEmpty(S)){
        return 0;
    }
    LinkStack p = S->next;
    e = p->data;
    return 1;
}

int StackSize(LinkStack &S){
    LinkStack p = S->next;
    int length = 0;
    while(p){
        p = p->next;
        length++;
    }
    return length;
}

int main(){
    LinkStack S;
    initStack(S);
    int a;
    a = 1;
    push(S,a);
    a = 5;
    push(S,a);
    int e;
    gettop(S, e);
    printf("%d\n", e);
    printf("%d\n", StackSize(S));
    pop(S,e);
    printf("%d\n", e);
    printf("%d\n", StackSize(S));
    a = 2;
    push(S, a);
    a = 3;
    push(S, a);
    a = 4;
    push(S, a);
    printf("%d\n", StackSize(S));
    a = 9;
    push(S, a);
    printf("%d\n", StackSize(S));
    a = 6;
    push(S, a);
    printf("%d\n", StackSize(S));
    while(!StackEmpty(S)){
        pop(S, e);
        printf("%d\n", e);
    }
    return 0;
}

