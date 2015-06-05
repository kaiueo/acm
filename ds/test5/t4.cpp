#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

const int MAXN = 1005;
using namespace std;

char str[MAXN];
int cnt[MAXN];

struct BTNode{
    char data[10];
    BTNode* lchild;
    BTNode* rchild;
};

void createBTNode(BTNode* &b){
    BTNode* St[MAXN];
    BTNode* p;
    b = NULL;
    int top = -1;
    int k;
    int level = 0;
    int l = strlen(str);
    int i;
    for(i = 0;i<l;i++){
        switch(str[i]){
            case '(':
                St[++top] = p;
                k = 1;
                level++;
                break;
            case ')':
                top--;
                level--;
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
                p->data[j]='\0';
                p->lchild = p->rchild = NULL;
                cnt[level]++;
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

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%s", str);
        BTNode* b;
        memset(cnt, 0, sizeof(cnt));
        createBTNode(b);
        int imax = 0;
        int idx = 0;
        int i = -1;
        while(cnt[++i]>0){
            if(cnt[i]>imax){
                imax = cnt[i];
                idx = i;
            }
        }
        if(idx!=0&&idx!=i-1){
            printf("%d %d %d\n", cnt[idx-1], cnt[idx], cnt[idx+1]);
        }
        else{
            printf("Invalid tree!\n");
        }
    }
}
