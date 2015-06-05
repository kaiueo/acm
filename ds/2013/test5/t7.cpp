#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct BTNode{
    char data;
    BTNode* lchild;
    BTNode* rchild;
};

const int MAXN = 30005;

char str[MAXN];
char SqBTree[MAXN<<1];

void createBTNode(BTNode* &b){
    BTNode* St[MAXN];
    BTNode* p;
    b = NULL;
    int k, l = strlen(str);
    int top = -1;
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
                k = 2;
                break;
            default:
                p = (BTNode*)malloc(sizeof(BTNode));
                p->data = str[i];
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

void PreOrder(BTNode* b, int i){
    if(!b){
        return;
    }
    else{
        SqBTree[i] = b->data;
        PreOrder(b->lchild, i<<1);
        PreOrder(b->rchild, i<<1|1);
    }
}

int BTNodeHeight(BTNode* b){
    int lheight, rheight;
    if(!b){
        return 0;
    }
    lheight = BTNodeHeight(b->lchild);
    rheight = BTNodeHeight(b->rchild);
    return max(lheight, rheight) +1;
}

int isCBT(BTNode* b){
    int cnt = 1;
    int h = BTNodeHeight(b);
    while(--h){
        cnt<<=1;
    }
    for(int i = 1;i<cnt;i++){
        if(SqBTree[i]=='#'){
            return 0;
        }
    }
    for(int i = cnt;i<(cnt<<1);i++){
        if(SqBTree[i]=='#'){
            for(;i<(cnt<<1);i++){
                if(SqBTree[i]!='#'){
                    return 0;
                }
            }
        }
    }
    return 1;
}

int Destroy(BTNode* &b){
    if(b->lchild){
        Destroy(b->lchild);
    }
    if(b->rchild){
        Destroy(b->rchild);
    }
    free(b);
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%s", str);
        memset(SqBTree, '#', sizeof(SqBTree));
        BTNode* b;
        createBTNode(b);
        PreOrder(b, 1);
        puts(isCBT(b)?"YES":"NO");
        Destroy(b);
    }
}
