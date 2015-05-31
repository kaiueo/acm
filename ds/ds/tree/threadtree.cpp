#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef char TTElemType;
typedef struct node{
    int ltag, rtag;
    struct node* lchild;
    struct node* rchild;
    TTElemType data;
}ThreadNode;

typedef ThreadNode* InThreadTree;

InThreadTree First(InThreadTree p){
    while(p->ltag == 0){
        p = p->lchild;
    }
    return p;
}

InThreadTree Next(InThreadTree p){
    if(p->rtag == 0){
        return First(p->rchild);
    }
    else{
        return p->rchild;
    }
}

void InOrder(InThreadTree root){
    for(InThreadTree p = First(root);p!=NULL;p=Next(p)){
        cout<<p->data;
    }
    cout<<endl;
}

void InThreaded(InThreadTree p, InThreadTree &pre){
    if(p!=NULL){
        InThreaded(p->lchild, pre);
        if(p->lchild==NULL){
            p->lchild = pre;
            p->ltag = 1;
        }
        if(pre!=NULL&&pre->rchild==NULL){
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        InThreaded(p->lchild, pre);
    }
}

void createInThread(InThreadTree BT){
    InThreadTree pre = NULL;
    if(BT!=NULL){
        InThreaded(BT, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

int main(){

}
