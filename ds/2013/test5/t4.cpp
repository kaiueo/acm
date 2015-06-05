#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 1005;
struct BTNode{
    char data[10];
    BTNode* lchild;
    BTNode* rchild;
};
int cnt[MAXN];
char str[MAXN];
void createBTNode(BTNode* &b){
    BTNode* St[MAXN], *p;
    b = NULL;
    int top = -1;
    int l = strlen(str);
    int k;
    int i;
    int level = 0;
    for(i = 0;i<l;i++){
        switch(str[i]){
            case '(':
                St[++top] = p;
                k =1;
                level++;
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
                int j = 0;
                cnt[level]++;
                while(i<l&&str[i]!='('&&str[i]!=')'&&str[i]!=','){
                    p->data[j++] = str[i++];
                }
                i--;
                p->data[j] = '\0';
                p->lchild = p->rchild =NULL;
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
        memset(cnt, 0, sizeof(cnt));
        scanf("%s", str);
        BTNode* b;
        createBTNode(b);
        int i = -1;
        int cmax = 0;
        int idx;
        while(cnt[++i]>0){
            if(cnt[i]>cmax){
                cmax = cnt[i];
                idx = i;
            }
        }

        if(idx!=0&&idx!=i-1){
            printf("%d %d %d\n", cnt[idx-1], cnt[idx], cnt[idx+1]);
        }
        else{
            printf("Invalid tree!\n");
        }
        Destroy(b);
    }
}
