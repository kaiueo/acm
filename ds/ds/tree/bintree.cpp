#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef char TElemType;
typedef struct node{
    TElemType data;
    struct node* lchild;
    struct node* rchild;
}BiTNode, *BinTree;

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


void InOrder(BinTree &T){
    if(T!=NULL){
        InOrder(T->lchild);
        cout<<T->data<<endl;
        InOrder(T->rchild);
    }
}

void PreOrder(BinTree &T){
    if(T!=NULL){
        cout<<T->data<<endl;
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void PostOrder(BinTree &T){
    if(T!=NULL){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        cout<<T->data<<endl;
    }
}

void createBinTree(BinTree &T){
    TElemType item;
    cin>>item;
    if(item==';'){
        return;
    }
    if(item!='#'){
        T = (BinTree)malloc(sizeof(BiTNode));
        T->data = item;
        createBinTree(T->lchild);
        createBinTree(T->rchild);
    }else{
        T = NULL;
    }
}

void printBinTree(BinTree &T){
    if(T!=NULL){
        cout<<T->data;
        if(T->lchild!=NULL||T->rchild!=NULL){
            cout<<'(';
            printBinTree(T->lchild);
            cout<<',';
            printBinTree(T->rchild);
            cout<<')';
        }
    }
}

void clearBinTree(BinTree &T){
    if(T!=NULL){
        clearBinTree(T->lchild);
        clearBinTree(T->rchild);
        delete T;
        T=NULL;
    }
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

int Equal(BinTree &S, BinTree &T){
    if(S==NULL&&T==NULL){
        return 1;
    }
    if(S==NULL||T==NULL){
        return 0;
    }
    if(S->data!=T->data){
        return 0;
    }
    if(!Equal(S->lchild, T->lchild)){
        return 0;
    }
    if(!Equal(S->rchild, T->rchild)){
        return 0;
    }
    return 1;
}

void PreOrderS(BinTree &BT){
    LinkStack S;
    initStack(S);
    BinTree p = BT;
    while(p!=NULL||!StackEmpty(S)){
        while(p!=NULL){
            cout<<p->data<<endl;
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
            cout<<p->data<<endl;
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
            cout<<cur->data<<endl;
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

BinTree Parent(BinTree BT, BinTree p){
    if(BT==p){
        return NULL;
    }
    LinkStack S;
    initStack(S);
    push(S, BT);
    BinTree t;
    while(!StackEmpty(S)){
        pop(S, t);
        if(t->lchild==p||t->rchild==p){
            return t;
        }
        if(t->rchild!=NULL){
            push(S, t->rchild);
        }
        if(t->lchild!=NULL){
            push(S, t->lchild);
        }
    }
    return NULL;
}

void CreateBinTreeT(BinTree &BT){
    LinkStack S;
    initStack(S);
    BinTree p, t;
    int flag;
    char ch;
    BT = NULL;
    cin>>ch;
    while(ch!='#'){
        switch(ch){
            case '(':
                push(S, p);
                flag = 1;
                break;
            case ')':
                pop(S, t);
                break;
            case ',':
                flag = 2;
                break;
            default:
                p = (BinTree)malloc(sizeof(BiTNode));
                p ->data = ch;
                p->lchild = NULL;
                p->rchild = NULL;
                if(BT==NULL){
                    BT = p;
                }
                else{
                    gettop(S, t);
                    if(flag == 1){
                        t->lchild = p;
                    }
                    else{
                        t->rchild = p;
                    }
                }
        }
        cin>>ch;
    }
}

BinTree CreateBinTreePI(TElemType* PRE, TElemType* IN, int n){
    if(n==0){
        return NULL;
    }
    TElemType* p = IN;
    int k = 0;
    while(*PRE!=*p){
        p++;
        k++;
    }
    BinTree t = (BinTree)malloc(sizeof(BiTNode));
    t->data = *PRE;
    t->lchild = CreateBinTreePI(PRE+1, IN, k);
    t->rchild = CreateBinTreePI(PRE+k+1, IN+k+1, n-k-1);
    return t;
}

int main(){
    BinTree T;
    createBinTree(T);

    PostOrder(T);
    cout<<endl;
    PostOrderS(T);
    printBinTree(T);
    cout<<endl;
    cout<<Height(T)<<endl;
}
