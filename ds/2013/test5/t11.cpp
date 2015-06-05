#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
const int MAXN = 105;
struct BTNode{
    char data;
    BTNode *lchild, *rchild;
};

BTNode* CreateBT(char *pre, char *in, int n){
    if(n<=0){
        return NULL;
    }
    BTNode *b = (BTNode*)malloc(sizeof(BTNode));
    b->data = *pre;
    char *p;
    for(p = in; p<in+n;p++){
        if(*p==*pre){
            break;
        }
    }
    int k = p-in;
    b->lchild = CreateBT(pre+1, in, k);
    b->rchild = CreateBT(pre+k+1, p+1, n-k-1);
    return b;
}

void PostOrder(BTNode *b){
    BTNode* St[MAXN], *p;
    int top = -1;
    bool flag;
    do{
        while(b){
            St[++top] = b;
            b = b->lchild;
        }
        p=NULL;
        flag = true;
        while(top>-1&&flag){
            b = St[top];
            if(b->rchild==p){
                putchar(b->data);
                --top;
                p=b;
            }
            else{
                b = b->rchild;
                flag = false;
            }
        }
    }while(top>-1);
    putchar('\n');
}

void Destroy(BTNode *&b){
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
    char a[MAXN], b[MAXN];
    scanf("%d", &n);
    while(n--){
        scanf("%s%s", a, b);
        BTNode *t = CreateBT(a, b, strlen(a));
        PostOrder(t);
        Destroy(t);
    }
}
