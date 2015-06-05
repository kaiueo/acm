#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
const int MAXN = 1005;
struct BTNode{
    char data[10];
    BTNode *lchild, *rchild;
};

char str[MAXN], k[10];

void createBTNode(BTNode* &b){
    BTNode* St[MAXN], *p;
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

int PreOrder(BTNode *b){
    BTNode* St[MAXN], *p;
    int top = -1;
    int level[MAXN];
    int l = 0;
    St[++top] = b;
    level[top] = l;
    while(top>-1){
        p = St[top];
        l = level[top--];
        if(strcmp(p->data, k)==0){
            return l;
        }
        if(p->rchild){
            St[++top] = p->rchild;
            level[top] = l+1;
        }
        if(p->lchild){
            St[++top] = p->lchild;
            level[top] = l+1;
        }
    }
    return -1;
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
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d%s%s", &n, k, str);
        BTNode* b;
        createBTNode(b);
        int l = PreOrder(b);
        puts(l!=-1&&n>=2*l?"Yes":"No");
        Destroy(b);
    }
}
