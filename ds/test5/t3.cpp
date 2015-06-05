#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

const int MAXN = 105;

struct HuffmanTree{
    int parent[MAXN];
    int lchild[MAXN];
    int rchild[MAXN];
    double weight[MAXN];
}ht;
double data[105];
void createHT(int n){
    int lnode, rnode;
    double min1,min2;

    memset(ht.parent, 0xff, sizeof(ht.parent));
    memset(ht.lchild, 0xff, sizeof(ht.lchild));
    memset(ht.rchild, 0xff, sizeof(ht.rchild));
    for(int i = n;i<(n<<1)-1;i++){
        min1 = min2 = 2.0;
        lnode= rnode = -1;
        for(int j =0;j<i;j++){
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
        ht.weight[i] = ht.weight[lnode]+ht.weight[rnode];
        ht.lchild[i] = lnode;
        ht.rchild[i] = rnode;
        ht.parent[lnode] = ht.parent[rnode] = i;
    }
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for(int i = 0;i<n;i++){
            scanf("%lf", &data[i]);
        }

        for(int i = 0;i<n;i++){
            ht.weight[i] = data[i];
        }
        createHT(n);
        double ans = 0.0;
        for(int i = n;i<(n<<1)-1;i++){
            ans += ht.weight[i];
        }
        printf("%.2f\n", ans);
    }
}
