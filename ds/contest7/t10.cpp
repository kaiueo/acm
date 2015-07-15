#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 105;
const int INF = 0x3f3f3f3f;
int g[MAXN][MAXN], lowc[MAXN], n;
int prim(){
    for(int i = 1;i<=n;i++){
        lowc[i] = g[1][i];
    }
    int ans = 0;
    for(int i = 1;i<n;i++){
        int k = -1;
        int min = INF;
        for(int j = 1;j<=n;j++){
            if(lowc[j]&&min>lowc[j]){
                min = lowc[j];
                k = j;
            }
        }
        ans+=min;
        lowc[k] = 0;
        for(int j = 1;j<=n;j++){
            if(lowc[j]&&lowc[j]>g[k][j]){
                lowc[j] = g[k][j];
            }
        }
    }
    return ans;
}

int main(){
    scanf("%d", &n);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            scanf("%d", &g[i][j]);
        }
    }

    int ans = prim();
    printf("%d\n", ans);
}
