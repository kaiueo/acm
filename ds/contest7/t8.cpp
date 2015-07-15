#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 1005;
int g[MAXN][MAXN], lowc[MAXN],n;
const int INF = 0x3f3f3f3f;

int prim(){
    for(int i = 1;i<=n;i++){
        lowc[i] = g[1][i];
    }
    int ans = 0;
    for(int i = 1;i<n;i++){
        int k = -1, min = INF;
        for(int j = 1;j<=n;j++){
            if(lowc[j]&&min>lowc[j]){
                k = j;
                min = lowc[j];
            }
        }
        ans += lowc[k];
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
    int m;
    while(scanf("%d%d", &n,&m)!=EOF){
        memset(g, 0x3f,sizeof(g));
        for(int i = 1;i<=n;i++){
            g[i][i] = 0;
        }
        while(m--){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            if(c<g[a][b])
                g[a][b] = g[b][a] = c;
        }
        int ans = prim();
        printf("%d\n", ans);
    }
}
