#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
const int MAXN = 10005;
int num[MAXN];
struct BTNode{
    int data;
    BTNode* lchild;
    BTNode* rchild;
};

BTNode* trans(int n, int i){
    if(i>=n){
        return NULL;
    }
    BTNode* b = (BTNode*)malloc(sizeof(BTNode));
    b->data = num[i];
    b->lchild = trans(n, i<<1);
    b->rchild = trans(n, i<<1|1);
    return b;
}

int LevelOrder(BTNode* b){
    BTNode* qu[MAXN], *p;
    int front, rear, cnt = 1;
    front = rear = -1;
    qu[++rear] = b;
    while(front!=rear){
        front = (front+1)%MAXN;
        p = qu[front];
        if(p->data==-1){
            break;
        }
        cnt++;
        if(p->lchild){
            rear = (rear+1)%MAXN;
            qu[rear] = p->lchild;
        }
        if(p->rchild){
            rear = (rear+1)%MAXN;
            qu[rear] = p->rchild;
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
    int n;
    BTNode* b;
    while(scanf("%d", &n)!=EOF){
        for(int i = 0;i<n;i++){
            scanf("%d", &num[i]);
        }
        b = trans(n, 1);
        int ans = -1;
        for(int cnt = LevelOrder(b);cnt>0;cnt>>=1){
            ++ans;
        }
        printf("%d\n", ans);
        Destroy(b);

    }
}
