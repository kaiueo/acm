#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
typedef struct{
    char data[10000];
    int top;
}Stack;

void init(Stack* &S){
    S = (Stack*)malloc(sizeof(Stack));
    S->top = -1;
}

int pop(Stack* &s, char &e){
    if(s->top == -1){
        return 0;
    }
    else{
        e = s->data[s->top--];
        return 1;
    }
}
int push(Stack * &s, char &e){
    s->data[++s->top] = e;
}

int match(Stack* &s){

    string a;
    cin>>a;
    for(int i = 0;i<a.length();i++){
        if(a[i] == '\('||a[i] == '\['||a[i] == '\{'){
           push(s, a[i]);
        }
        else if(a[i] == '\)'||a[i] == '\]'||a[i] == '\}')
        {
            char e;
            if(pop(s, e)){
                if(a[i] == ')'&&e =='\('||a[i] == ']'&&e =='\['||a[i] == '}'&&e =='\{')
                {
                    continue;
                }
                else{
                    return 0;
                }
            }else{
                return 0;
            }


        }
    }
    if(s->top != -1){
    return 0;
    }
    else{
        return 1;
    }
}

int main()
{
    int n;
    cin>>n;
    while(n--){

    Stack* s;
    init(s);
    if(match(s)){
        printf("Yes\n");
    }
    else
    {

        printf("No\n");
    }
    }
    return 0;
}

