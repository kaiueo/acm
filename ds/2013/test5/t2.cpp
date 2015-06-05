#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std; const int MAXN = 10005;
typedef struct BTNode{
    char data[10];
    BTNode* lchild;
    BTNode* rchild;
};
char str[MAXN];
void createBinTree(BTNode* &b){
    BTNode* St[MAXN];
    int top = -1;
    b = NULL;
    BTNode* p = NULL;
    int k;
    int l = strlen(str);
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
                int j = 0;
                while(i<l&&str[i]!='('&&str[i]!=')'&&str[i]!=','){
                    p->data[j++] = str[i++];
                }
                i--;
                p->data[j] = '\0';
                p->lchild = NULL;
                p->rchild = NULL;
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

void PreOrder(BTNode* b){
    BTNode* St[MAXN], *p;
    int top  = -1;
    St[++top] = b;
    while(top>-1){
        p = St[top--];
        printf("%s", p->data);
        if(p->rchild){
            St[++top] = p->rchild;
        }
        if(p->lchild){
            St[++top] = p->lchild;
        }
    }
    printf("\n");
}

void DestroyBT(BTNode* &b){
    if(b->lchild){
        DestroyBT(b->lchild);
    }
    if(b->rchild){
        DestroyBT(b->rchild);
    }
    free(b);
}


int main(){ int t;
    scanf("%d", &t);
    while(t--){
        BTNode* b;
        scanf("%s", str);
        createBinTree(b);
        PreOrder(b);
        DestroyBT(b);
    }
}
