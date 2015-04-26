#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef struct{
    int data[10005];
    int top;
}Stack;

void initStack(Stack* &S){
    S = (Stack*)malloc(sizeof(Stack));
    S->top = -1;
}

int StackEmpty(Stack* &S){
    if(S->top == -1){
        return 1;
    }
    return 0;
}

void push(Stack* &S, int e){
    S->data[++S->top] = e;
}

int pop(Stack* &S, int &e){
    if(StackEmpty(S)){
        return 0;
    }
    e = S->data[S->top--];
    return 1;
}

int get(Stack* &S, int &e){
    if(StackEmpty(S)){
        return 0;
    }
    e = S->data[S->top];
    return 1;
}

int main(){
    int n;
    while(cin>>n){
        if(n == 0){
            break;
        }
        Stack* S;
        initStack(S);

        for(int i = 1;i<=n;i++){
            string s;
            cin>>s;
            if(s=="O"){
                int e;
                pop(S,e);
            }
            else if(s=="P"){
                int e;
                cin>>e;
                push(S, e);
            }
            else if(s == "A"){
                int e;
                if(get(S, e)){
                    cout<<e<<endl;
                }
                else{
                    cout<<'E'<<endl;
                }
            }
        }
        cout<<endl;
    }
}

