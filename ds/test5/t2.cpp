#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 30;
const int MAXM = 2005;
const int inf = 0x3f3f3f3f;
struct HuffmanTree{
    int parent[MAXN<<1];
    int lchild[MAXN<<1];
    int rchild[MAXN<<1];
    int weight[MAXN<<1];
} ht;

char str[MAXM];
int cnt[MAXN], n;
void createHT(){
    int lnode, rnode, min1, min2;
    memset(ht.parent, 0xff, sizeof(ht.parent));
    memset(ht.lchild, 0xff, sizeof(ht.lchild));
    memset(ht.rchild, 0xff, sizeof(ht.rchild));
    for(int i = n;i<(n<<1)-1;i++){
        min1 = min2 = inf;
        lnode = rnode = -1;
        for(int j = 0;j<i;j++){
            if(!~ht.parent[j]){
                if(ht.weight[j]<min1){
                    min2 = min1;
                    rnode = lnode;
                    min1 = ht.weight[j];
                    lnode = j;
                }
                else if(ht.weight[j]<min2){
                    min2 = ht.weight[j];
                    rnode = j;
                }
            }
        }
        ht.weight[i] = ht.weight[lnode] + ht.weight[rnode];
        ht.lchild[i] = lnode;
        ht.rchild[i] = rnode;
        ht.parent[lnode] = ht.parent[rnode] = i;
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%s", str);
        int l= strlen(str);
        n = 0;
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0;i<l;i++){
            ++cnt[str[i]-'a'];
        }
        for(int i = 0;i<26;i++){
            if(cnt[i]>0){
                ht.weight[n++] = cnt[i];
            }
        }
        createHT();
        int ans = 0;
        for(int i = n;i<(n<<1)-1;i++){
            ans+=ht.weight[i];
        }
        printf("%d\n", ans);
    }
}
