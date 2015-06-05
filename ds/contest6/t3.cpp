#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef char TElemType;
typedef struct node{
    TElemType data;
    struct node* lchild;
    struct node* rchild;
}BiTNode, *BinTree;
const int MAXN = 200005;
char str[MAXN];
typedef BinTree Datatype;
typedef struct snode{
    Datatype data;
    snode* next;
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


int Height(BinTree &T){
    if(T==NULL){
        return 0;
    }
    else{
        int i = Height(T->lchild);
        int j = Height(T->rchild);
        if(i<j){
            return j+1;
        }
        else{
            return i+1;
        }
    }
}


void PreOrderS(BinTree &BT){
    LinkStack S;
    initStack(S);
    BinTree p = BT;
    while(p!=NULL||!StackEmpty(S)){
        while(p!=NULL){
            cout<<p->data;
            push(S, p);
            p = p->lchild;
        }
        if(!StackEmpty(S)){
            pop(S,p);
            p = p->rchild;
        }
    }
}

void InOrderS(BinTree BT){
    LinkStack S;
    initStack(S);
    BinTree p = BT;
    while(p!=NULL||!StackEmpty(S)){
        while(p!=NULL){
            push(S, p);
            p = p->lchild;
        }
        if(!StackEmpty(S)){
            pop(S, p);
            cout<<p->data;
            p = p->rchild;
        }
    }
}

void PostOrderS(BinTree BT){
    LinkStack S;
    initStack(S);
    BinTree cur;
    BinTree pre = NULL;
    if(BT){
        push(S, BT);
    }
    while(!StackEmpty(S)){
        gettop(S, cur);
        if((cur->lchild==NULL&&cur->rchild==NULL)||(pre!=NULL&&(pre==cur->lchild||pre==cur->rchild))){
            cout<<cur->data;
            BinTree tmp;
            pop(S, tmp);
            pre = cur;
        }
        else{
            if(cur->rchild!=NULL){
                push(S, cur->rchild);
            }
            if(cur->lchild!=NULL){
                push(S, cur->lchild);
            }
        }
    }
}



void CreateBinTreeT(BinTree &b){
    BinTree St[MAXN], p;
    int top = -1;
    int k, l = strlen(str);
    b = NULL;
    for(int i = 0;i<l;i++){
        switch(str[i]){
            case '(':
                St[++top] = p;
                k = 1;
                break;
            case ')':
                top--;
                break;
            case ',':
                k =2;
                break;
            default:
                p = (BinTree)malloc(sizeof(BiTNode));
                p->data=str[i];
                p->lchild = p->rchild = NULL;
                if(!b){
                    b = p;
                }
                else{
                    switch(k){
                        case 1:
                            St[top]->lchild = p;
                            break;
                        case 2:
                            St[top]->rchild = p;
                            break;
                    }
                }
        }
    }
}




void Destroy(BinTree &b){
    if(b->lchild){
        Destroy(b->lchild);
    }
    if(b->rchild){
        Destroy(b->rchild);
    }
    free(b);
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        BinTree b;
        scanf("%s", str);
        CreateBinTreeT(b);
        PreOrderS(b);
        cout<<endl;
        InOrderS(b);
        cout<<endl;
        Destroy(b);
    }
}

