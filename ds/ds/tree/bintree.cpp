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

int main(){
    BinTree T;
    createBinTree(T);
    PreOrder(T);
    InOrder(T);
    PostOrder(T);
    printBinTree(T);
    cout<<endl;
    cout<<Height(T)<<endl;
}
