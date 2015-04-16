#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef int DataType;
typedef struct{
    DataType* elem;
    int top, maxSize;
}SeqStack;

//The first setp is to malloc a space for SeqStack itself!!!
void initStack(SeqStack* &S, int maxSize){
    S = (SeqStack*)malloc(sizeof(SeqStack));
    S->elem = (DataType*)malloc(maxSize * sizeof(DataType));
    S->top = -1;
    S->maxSize = maxSize;
}

int StackEmpty(SeqStack* &S){
    if(S->top==-1){
        return 1;
    }
    return 0;
}

//Pay attention to the S->top. it equals to the offset in the array.
int StackFull(SeqStack* &S){
    if(S->top == S->maxSize - 1){
        return 1;
    }
    return 0;
}

int push(SeqStack* &S, DataType &e){
    if(StackFull(S)){
        return 0;
    }
    S->elem[++S->top] = e;
    return 1;
}

//The data is saved in e, and the state is returnd. Next function is the same;
int pop(SeqStack* &S, DataType &e){
    if(StackEmpty(S)){
        return 0;
    }
    e = S->elem[S->top--];
    return 1;
}

int gettop(SeqStack* &S, DataType &e){
    if(StackEmpty(S)){
        return 0;
    }
    e = S->elem[S->top];
    return 1;
}

int StackSize(SeqStack* &S){
    return S->top + 1;
}

int main(){
    SeqStack *S;
    initStack(S, 6);
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
    int tmp = push(S, a);
    printf("%d\n", tmp);
    printf("%d\n", StackSize(S));
    a = 6;
    push(S, a);
    tmp = push(S, a);
    printf("%d\n", tmp);
    printf("%d\n", StackSize(S));
    for(int i = 1;i<=5;i++){
        pop(S, e);
        printf("%d\n", e);
    }
    return 0;
}
