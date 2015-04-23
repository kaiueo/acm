#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;
typedef struct node{
    int data;
    node* next;
}StackNode, *Stack;

void initStack(Stack &S){
    S = (Stack)malloc(sizeof(StackNode));
    S->next = NULL;
}

int StackEmpty(Stack &S){
    if(S->next){
        return 0;
    }
    return 1;
}

int push(Stack &S, int e){
    Stack p = (Stack)malloc(sizeof(StackNode));
    p->data = e;
    p->next = S->next;
    S->next = p;
    return 1;
}

int pop(Stack &S, int &e){
    if(StackEmpty(S)){
        return 0;
    }
    Stack p = S->next;
    e = p->data;
    S->next = p->next;
    free(p);
}

int gettop(Stack &S, int &e){
    if(StackEmpty(S)){
        return 0;
    }
    Stack p = S->next;
    e = p->data;
}

int main(){

    string s;
    while(cin>>s){
        Stack S;
        initStack(S);
        for(int i = 0;i<s.length();i++){
            if(s[i] == '*'){
                push(S, s[i]);
            }
            else if(s[i]>='a'&&s[i]<='z'){
                int e;
                gettop(S, e);
                if(s[i]-'a' == e-'A'||e == '%'){
                    pop(S, e);
                }
                else{
                    push(S, s[i]);
                }
            }
            else if(s[i]>='A'&&s[i]<='Z'){
                int e;
                gettop(S, e);
                if(s[i]-'A' == e-'a'){
                    pop(S, e);
                }
                else{
                    push(S,s[i]);
                }
            }
            else if(s[i] == '%'){
                int e;
                gettop(S, e);
                if(e>='a'&&e<='z'){
                    pop(S, e);
                }
                else{
                    push(S, '%');
                }
            }
            else{
                int e;
                gettop(S, e);
                if(e == '*'){
                    printf("Yes\n");
                }
                else{
                    printf("No\n");
                }
            }
        }

    }

}
