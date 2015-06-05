#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAXN = 1005;
struct BTNode{
    int data;
    BTNode *lchild, *rchild;
};

int num[MAXN];

BTNode* trans(int n, int i){
    if(i>n||num[i]==-1){
        return NULL;
    }
    BTNode * p = (BTNode*)malloc(sizeof(BTNode));
    p->data = num[i];
    p->lchild = trans(n, i<<1);
    p->rchild = trans(n, i<<1|1);
    return p;
}

void Display(BTNode* p){
    if(p){
        printf("%d", p->data);
        if(p->lchild||p->rchild){
            putchar('(');
            Display(p->lchild);
            if(p->rchild){
                putchar(',');
            }
            Display(p->rchild);
            putchar(')');
        }
    }
}

void Distroy(BTNode* &b){
    if(b->lchild){
        Distroy(b->lchild);
    }
    if(b->rchild){
        Distroy(b->rchild);
    }
    free(b);
}

int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
        for(int i = 1;i<=n;i++){
            scanf("%d", &num[i]);
        }
        BTNode* b = trans(n, 1);
        Display(b);
        Distroy(b);
    }

}
