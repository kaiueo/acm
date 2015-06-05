#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
typedef int BSTElemType;
typedef struct node{
    BSTElemType data;
    node* lchild;
    node* rchild;
}BSTNode, *BSTree;
BSTNode* search(BSTNode* BT, BSTElemType x, BSTNode* & father){
    BSTNode* p =BT;
    father = NULL;
    while(p!=NULL){
        father = p;
        if(x<p->data){
            p = p->lchild;
        }
        else{
            p = p->rchild;
        }
    }
    return p;
}

int insert(BSTree& BT, BSTElemType x){
    BSTNode* s, *p, *f;
    p = search(BT, x, f);
    s= new BSTNode;
    s->data = x;
    s->lchild = s->rchild = NULL;
    if(f==NULL){
        BT = s;
    }
    else if(x<f->data)
        f->lchild = s;
    else {
        f->rchild = s;
    }
    return 1;
}

void InOrder(BSTNode* T){
    if(T!=NULL){
        InOrder(T->lchild);
        cout<<T->data<<" ";
        InOrder(T->rchild);
    }
}

void PreOrder(BSTNode* T){
    if(T!=NULL){
        cout<<T->data<<" ";
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void PostOrder(BSTNode* T){
    if(T!=NULL){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        cout<<T->data<<" ";
    }
}

void createBST(BSTree &BT, int n){
    BSTElemType x;
    BT = NULL;
    cin>>x;
    while(n--){
        insert(BT, x);
        if(n>0){
        cin>>x;
        }

    }
}
void Destroy(BSTree &b){
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
    while(scanf("%d", &n)!=EOF){
        BSTree b;
        createBST(b, n);
        PreOrder(b);
        cout<<endl;
        InOrder(b);
        cout<<endl;
        PostOrder(b);
        cout<<endl;
        Destroy(b);

    }


}

