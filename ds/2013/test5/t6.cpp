#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

const int MAXN = 1005;
struct BTNode{
    char data[10];
    BTNode* lchild;
    BTNode* rchild;
};

char str[MAXN];
void createBTNode(BTNode* &b){
    BTNode* St[MAXN], *p;
    int top = -1;
    int k, l =strlen(str);
    b=NULL;
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

void PreOrder(BTNode* b, int l){
    if(!b){
        return;
    }
    for(int i = 0;i<(l<<1);i++){
        putchar(' ');
    }
    puts(b->data);
    PreOrder(b->lchild, l+1);
    PreOrder(b->rchild, l+1);
}

void Destroy(BTNode* &b){
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
        BTNode* b;
        createBTNode(b);
        PreOrder(b, 0);
        Destroy(b);
    }
}
