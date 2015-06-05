#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
const int MAXN = 50005;
struct BTNode{
    char data[15];
    int level;
    BTNode* parent, *lchild, *rchild;
};

char str[MAXN];
void createBTNode(BTNode* &b){
    BTNode* St[MAXN], *p;
    b=NULL;
    int k, l= strlen(str);
    int level = 1;
    int top = -1;
    for(int i = 0;i<l;i++){
        switch(str[i]){
            case '(':
                level++;
                St[++top] = p;
                k = 1;
                break;
            case ')':
                level--;
                top--;
                break;
            case ',':
                k = 2;
                break;
            default:
                p = (BTNode*)malloc(sizeof(BTNode));
                int j =0;
                while(i<l&&str[i]!='('&&str[i]!=')'&&str[i]!=','){
                    p->data[j++] = str[i++];
                }
                i--;
                p->data[j] = '\0';
                p->level = level;
                p->parent = p->lchild = p->rchild = NULL;
                if(!b){
                    b = p;
                }
                else{
                    p->parent = St[top];
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

BTNode* FindNode(BTNode* b, char* s){
    BTNode* St[MAXN];
    BTNode* p;
    int top = -1;
    St[++top] = b;
    while(top>-1){
        p = St[top--];
        if(strcmp(p->data, s)==0){
            return p;
        }
        if(p->rchild){
            St[++top] = p->rchild;
        }
        if(p->lchild){
            St[++top] = p->lchild;
        }
    }
    return NULL;
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
    int n;
    scanf("%d", &n);
    while(n--){
        char an[15], bn[15];
        BTNode* t, *a, *b;
        bool flag = false;
        scanf("%s%s%s", str, an, bn);
        createBTNode(t);
        a = FindNode(t, an);
        b = FindNode(t, bn);
        if(a&&b){
            while(strcmp(a->data, b->data)!=0){
                a->level>b->level?a=a->parent:b=b->parent;
            }
            puts(a->data);
        }
        else{
            puts("Sorry,They have not the same ancestor!");
        }
        Destroy(t);
    }
}
