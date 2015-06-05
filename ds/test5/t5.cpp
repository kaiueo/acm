#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAXN = 50005;

struct BTNode{
    char data[15];
    BTNode* lchild;
    BTNode* rchild;
};

char str[MAXN];
void createBTNode(BTNode* &b){
    BTNode* St[MAXN], *p;
    int k, l = strlen(str);
    int top = -1;
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
                    }
                }
        }
    }
}

int PreOrder(BTNode* b){
    int cnt = 0;
    BTNode* St[MAXN];
    BTNode* p = b;
    int top = -1;
    top++;
    St[top] = b;
    while(top>-1){
        p = St[top--];
        if(p->lchild==NULL&&p->rchild==NULL){
            cnt++;
        }
        if(p->rchild){
            St[++top] = p->rchild;
        }
        if(p->lchild){
            St[++top] = p->lchild;
        }
    }
    return cnt;
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
        int n = PreOrder(b);
        printf("%d\n", n);
        Destroy(b);
    }
}

